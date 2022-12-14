/*
 * Copyright (C) 2019 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <aidl/metadata.h>
#include <android-base/logging.h>
#include <android-base/strings.h>
#include <gtest/gtest.h>
#include <hidl-util/FQName.h>
#include <hidl/metadata.h>
#include <vintf/VintfObject.h>

using namespace android;

// clang-format off
static const std::set<std::string> kKnownMissingHidl = {
    "android.frameworks.cameraservice.device@2.1",
    "android.frameworks.displayservice@1.0", // deprecated, see b/141930622
    "android.frameworks.schedulerservice@1.0", // deprecated, see b/37226359
    "android.frameworks.vr.composer@1.0",
    "android.frameworks.vr.composer@2.0",
    "android.frameworks.automotive.display@1.0",
    "android.frameworks.stats@1.0",  // converted to AIDL, see b/177667419
    "android.hardware.audio@2.0",
    "android.hardware.audio@4.0",
    "android.hardware.audio@5.0",
    "android.hardware.audio@6.0",
    "android.hardware.audio.effect@2.0",
    "android.hardware.audio.effect@4.0",
    "android.hardware.audio.effect@5.0",
    "android.hardware.audio.effect@6.0",
    "android.hardware.automotive.audiocontrol@1.0",
    "android.hardware.automotive.audiocontrol@2.0",
    "android.hardware.automotive.can@1.0",
    "android.hardware.automotive.evs@1.1",
    "android.hardware.automotive.sv@1.0",
    "android.hardware.automotive.vehicle@2.0",
    "android.hardware.biometrics.fingerprint@2.3",
    "android.hardware.bluetooth.a2dp@1.0",
    "android.hardware.bluetooth.audio@2.1", // converted to AIDL, see b/203490261
    "android.hardware.broadcastradio@1.1",
    "android.hardware.broadcastradio@2.0",
    "android.hardware.camera.provider@2.7", // Camera converted to AIDL, b/196432585
    "android.hardware.cas.native@1.0",
    "android.hardware.configstore@1.1", // deprecated, see b/149050985, b/149050733
    "android.hardware.contexthub@1.2",
    "android.hardware.drm@1.4", // converted to AIDL, b/200055138
    "android.hardware.fastboot@1.1",
    "android.hardware.dumpstate@1.1", // deprecated, see b/205760700
    "android.hardware.gnss@1.1", // GNSS converted to AIDL, b/206670536
    "android.hardware.gnss@2.1", // GNSS converted to AIDL, b/206670536
    "android.hardware.gnss.measurement_corrections@1.1", // is sub-interface of gnss
    "android.hardware.gnss.visibility_control@1.0",
    "android.hardware.graphics.allocator@2.0",
    "android.hardware.graphics.allocator@3.0",
    "android.hardware.graphics.allocator@4.0", // converted to AIDL, see b/205761012
    "android.hardware.graphics.bufferqueue@1.0",
    "android.hardware.graphics.bufferqueue@2.0",
    "android.hardware.graphics.composer@2.4", // converted to AIDL, see b/193240715
    "android.hardware.graphics.mapper@2.1",
    "android.hardware.graphics.mapper@3.0",
    "android.hardware.health.storage@1.0", // converted to AIDL, see b/177470478
    "android.hardware.health@2.1", // converted to AIDL, see b/177269435
    "android.hardware.input.classifier@1.0", // converted to AIDL, see b/205761620
    "android.hardware.ir@1.0", // converted to AIDL, see b/205000342
    "android.hardware.keymaster@3.0",
    "android.hardware.keymaster@4.1", // Replaced by KeyMint
    "android.hardware.light@2.0",
    "android.hardware.media.bufferpool@1.0",
    "android.hardware.media.bufferpool@2.0",
    "android.hardware.memtrack@1.0",
    "android.hardware.nfc@1.2",
    "android.hardware.oemlock@1.0",
    "android.hardware.power@1.3",
    "android.hardware.power.stats@1.0",
    "android.hardware.radio@1.6", // converted to AIDL
    "android.hardware.radio.config@1.3", // converted to AIDL
    "android.hardware.radio.deprecated@1.0",
    "android.hardware.renderscript@1.0",
    "android.hardware.soundtrigger@2.3",
    "android.hardware.secure_element@1.2",
    "android.hardware.sensors@1.0",
    "android.hardware.sensors@2.1",
    "android.hardware.tetheroffload.config@1.0",
    "android.hardware.tetheroffload.control@1.1", // see b/170699770
    "android.hardware.thermal@1.1",
    "android.hardware.tv.cec@1.1",
    "android.hardware.tv.input@1.0",
    "android.hardware.tv.tuner@1.1",
    "android.hardware.usb@1.3", // migrated to AIDL see b/200993386
    "android.hardware.usb.gadget@1.2",
    "android.hardware.vibrator@1.3",
    "android.hardware.vr@1.0",
    "android.hardware.weaver@1.0",
    "android.hardware.wifi.hostapd@1.3",
    "android.hardware.wifi.supplicant@1.4",
    "android.hardware.wifi.offload@1.0",
    "android.hidl.base@1.0",
    "android.hidl.memory.token@1.0",
    "android.system.suspend@1.0", // Converted to AIDL (see b/170260236)
};
// clang-format on

struct VersionedAidlPackage {
  std::string name;
  size_t version;
  bool operator<(const VersionedAidlPackage& rhs) const {
    return (name < rhs.name || (name == rhs.name && version < rhs.version));
  }
};

static const std::set<VersionedAidlPackage> kKnownMissingAidl = {
    // Cuttlefish Identity Credential HAL implementation is currently
    // stuck at version 3 while RKP support is being added. Will be
    // updated soon.
    {"android.hardware.identity.", 4},

    // types-only packages, which never expect a default implementation
    {"android.hardware.audio.common.", 1},
    {"android.hardware.biometrics.common.", 1},
    {"android.hardware.biometrics.common.", 2},
    {"android.hardware.common.", 1},
    {"android.hardware.common.", 2},
    {"android.hardware.common.fmq.", 1},

    {"android.hardware.graphics.common.", 1},
    {"android.hardware.graphics.common.", 2},
    {"android.hardware.graphics.common.", 3},
    {"android.hardware.input.common.", 1},

    // android.hardware.camera.device is an interface returned by
    // android.hardware.camera.provider.
    // android.hardware.camera.common and android.hardware.camera.metadata are
    // types used by android.hardware.camera.provider and
    // android.hardware.camera.device.
    {"android.hardware.camera.common.", 1},
    {"android.hardware.camera.device.", 1},
    {"android.hardware.camera.metadata.", 1},

    // No implementations on cuttlefish for omapi aidl hal
    {"android.se.omapi.", 1},

    // These KeyMaster types are in an AIDL types-only HAL because they're used
    // by the Identity Credential AIDL HAL. Remove this when fully porting
    // KeyMaster to AIDL.
    {"android.hardware.keymaster.", 1},
    {"android.hardware.keymaster.", 2},
    {"android.hardware.keymaster.", 3},

    // Sound trigger doesn't have a default implementation.
    {"android.hardware.soundtrigger3.", 1},
    {"android.media.soundtrigger.", 1},
    {"android.media.audio.common.", 1},

    // These types are only used in Automotive.
    {"android.automotive.computepipe.registry.", 1},
    {"android.automotive.computepipe.runner.", 1},
    {"android.automotive.watchdog.", 2},
    {"android.automotive.watchdog.", 3},
    {"android.frameworks.automotive.display.", 1},
    {"android.frameworks.automotive.powerpolicy.", 1},
    {"android.frameworks.automotive.powerpolicy.internal.", 1},
    {"android.frameworks.automotive.telemetry.", 1},
    {"android.hardware.automotive.audiocontrol.", 1},
    {"android.hardware.automotive.audiocontrol.", 2},
    {"android.hardware.automotive.evs.", 1},
    {"android.hardware.automotive.occupant_awareness.", 1},
    {"android.hardware.automotive.vehicle.", 1},

    // These types are only used in TV.
    {"android.hardware.tv.tuner.", 1},

    // types-only packages, which never expect a default implementation
    {"android.hardware.radio.", 1},

    // types-only packages, which never expect a default implementation
    {"android.hardware.uwb.fira_android.", 1},
};

static const std::set<VersionedAidlPackage> kComingSoonAidl = {
};

// AOSP packages which are never considered
static bool isHidlPackageConsidered(const FQName& name) {
  static std::vector<std::string> gAospExclude = {
      // packages not implemented now that we never expect to be implemented
      "android.hardware.tests",
      // packages not registered with hwservicemanager, usually sub-interfaces
      "android.hardware.camera.device",
  };
  for (const std::string& package : gAospExclude) {
    if (name.inPackage(package)) {
      return false;
    }
  }
  return true;
}

static bool isAospHidlInterface(const FQName& name) {
  static const std::vector<std::string> kAospPackages = {
      "android.hidl",
      "android.hardware",
      "android.frameworks",
      "android.system",
  };
  for (const std::string& package : kAospPackages) {
    if (name.inPackage(package)) {
      return true;
    }
  }
  return false;
}

static std::set<FQName> allTreeHidlInterfaces() {
  std::set<FQName> ret;
  for (const auto& iface : HidlInterfaceMetadata::all()) {
    FQName f;
    CHECK(f.setTo(iface.name)) << iface.name;
    ret.insert(f);
  }
  return ret;
}

static std::set<FQName> allHidlManifestInterfaces() {
  std::set<FQName> ret;
  auto setInserter = [&](const vintf::ManifestInstance& i) -> bool {
    if (i.format() != vintf::HalFormat::HIDL) {
      return true;  // continue
    }
    ret.insert(i.getFqInstance().getFqName());
    return true;  // continue
  };
  vintf::VintfObject::GetDeviceHalManifest()->forEachInstance(setInserter);
  vintf::VintfObject::GetFrameworkHalManifest()->forEachInstance(setInserter);
  return ret;
}

static bool isAospAidlInterface(const std::string& name) {
  return base::StartsWith(name, "android.") &&
         !base::StartsWith(name, "android.hardware.tests.") &&
         !base::StartsWith(name, "android.aidl.tests");
}

static std::set<VersionedAidlPackage> allAidlManifestInterfaces() {
  std::set<VersionedAidlPackage> ret;
  auto setInserter = [&](const vintf::ManifestInstance& i) -> bool {
    if (i.format() != vintf::HalFormat::AIDL) {
      return true;  // continue
    }
    ret.insert({i.package() + "." + i.interface(), i.version().minorVer});
    return true;  // continue
  };
  vintf::VintfObject::GetDeviceHalManifest()->forEachInstance(setInserter);
  vintf::VintfObject::GetFrameworkHalManifest()->forEachInstance(setInserter);
  return ret;
}

TEST(Hal, AllHidlInterfacesAreInAosp) {
  for (const FQName& name : allHidlManifestInterfaces()) {
    EXPECT_TRUE(isAospHidlInterface(name))
        << "This device should only have AOSP interfaces, not: "
        << name.string();
  }
}

TEST(Hal, HidlInterfacesImplemented) {
  // instances -> major version -> minor versions
  std::map<std::string, std::map<size_t, std::set<size_t>>> unimplemented;

  for (const FQName& f : allTreeHidlInterfaces()) {
    if (!isAospHidlInterface(f)) continue;
    if (!isHidlPackageConsidered(f)) continue;

    unimplemented[f.package()][f.getPackageMajorVersion()].insert(
        f.getPackageMinorVersion());
  }

  // we'll be removing items from this which we know are missing
  // in order to be left with those elements which we thought we
  // knew were missing but are actually present
  std::set<std::string> thoughtMissing = kKnownMissingHidl;

  for (const FQName& f : allHidlManifestInterfaces()) {
    if (thoughtMissing.erase(f.getPackageAndVersion().string()) > 0) {
      ADD_FAILURE() << "Instance in missing list, but available: "
                    << f.string();
    }

    std::set<size_t>& minors =
        unimplemented[f.package()][f.getPackageMajorVersion()];
    size_t minor = f.getPackageMinorVersion();

    auto it = minors.find(minor);
    if (it == minors.end()) continue;

    // if 1.2 is implemented, also considere 1.0, 1.1 implemented
    minors.erase(minors.begin(), std::next(it));
  }

  for (const auto& [package, minorsPerMajor] : unimplemented) {
    for (const auto& [major, minors] : minorsPerMajor) {
      if (minors.empty()) continue;

      size_t maxMinor = *minors.rbegin();

      FQName missing;
      ASSERT_TRUE(missing.setTo(package, major, maxMinor));

      if (thoughtMissing.erase(missing.string()) > 0) continue;

      ADD_FAILURE() << "Missing implementation from " << missing.string();
    }
  }

  for (const std::string& missing : thoughtMissing) {
    ADD_FAILURE() << "Instance in missing list and cannot find it anywhere: "
                  << missing << " (multiple versions in missing list?)";
  }
}

TEST(Hal, AllAidlInterfacesAreInAosp) {
  for (const auto& package : allAidlManifestInterfaces()) {
    EXPECT_TRUE(isAospAidlInterface(package.name))
        << "This device should only have AOSP interfaces, not: "
        << package.name;
  }
}

// android.hardware.foo.IFoo -> android.hardware.foo.
std::string getAidlPackage(const std::string& aidlType) {
  size_t lastDot = aidlType.rfind('.');
  CHECK(lastDot != std::string::npos);
  return aidlType.substr(0, lastDot + 1);
}

struct AidlPackageCheck {
  bool hasRegistration;
  bool knownMissing;
};

TEST(Hal, AidlInterfacesImplemented) {
  std::set<VersionedAidlPackage> manifest = allAidlManifestInterfaces();
  std::set<VersionedAidlPackage> thoughtMissing = kKnownMissingAidl;
  std::set<VersionedAidlPackage> comingSoon = kComingSoonAidl;

  for (const auto& treePackage : AidlInterfaceMetadata::all()) {
    ASSERT_FALSE(treePackage.types.empty()) << treePackage.name;
    if (std::none_of(treePackage.types.begin(), treePackage.types.end(),
                     isAospAidlInterface))
      continue;
    if (treePackage.stability != "vintf") continue;

    // expect versions from 1 to latest version. If the package has development
    // the latest version is the latest known version + 1. Each of these need
    // to be checked for registration and knownMissing.
    std::map<size_t, AidlPackageCheck> expectedVersions;
    for (const auto version : treePackage.versions) {
      expectedVersions[version] = {false, false};
    }
    if (treePackage.has_development) {
      size_t version =
          treePackage.versions.empty() ? 1 : *treePackage.versions.rbegin() + 1;
      expectedVersions[version] = {false, false};
    }

    // Check all types and versions defined by the package for registration.
    // The package version is considered registered if any of those types are
    // present in the manifest with the same version.
    // The package version is considered known missing if it is found in
    // thoughtMissing.
    bool latestRegistered = false;
    for (const std::string& type : treePackage.types) {
      for (auto& [version, check] : expectedVersions) {
        if (manifest.erase({type, version}) > 0) {
          if (version == expectedVersions.rbegin()->first) {
            latestRegistered = true;
          }
          check.hasRegistration = true;
        }
        if (thoughtMissing.erase({getAidlPackage(type), version}) > 0)
          check.knownMissing = true;
      }
    }

    if (!latestRegistered && !expectedVersions.rbegin()->second.knownMissing) {
      ADD_FAILURE() << "The latest version ("
                    << expectedVersions.rbegin()->first
                    << ") of the package is not implemented: "
                    << treePackage.name
                    << " which declares the following types:\n    "
                    << base::Join(treePackage.types, "\n    ");
    }

    for (const auto& [version, check] : expectedVersions) {
      if (check.knownMissing) {
        if (check.hasRegistration) {
          ADD_FAILURE() << "Package in missing list, but available: "
                        << treePackage.name << " V" << version
                        << " which declares the following types:\n    "
                        << base::Join(treePackage.types, "\n    ");
        }

        continue;
      }
    }
  }

  for (const auto& package : thoughtMissing) {
    // TODO: b/194806512 : Remove after Wifi hostapd AIDL interface lands on aosp
    if (comingSoon.erase(package) == 0) {
      ADD_FAILURE() << "Interface in missing list and cannot find it anywhere: "
                    << package.name << " V" << package.version;
    }
  }

  for (const auto& package : manifest) {
    ADD_FAILURE() << "Can't find manifest entry in tree: " << package.name
                  << " version: " << package.version;
  }
}
