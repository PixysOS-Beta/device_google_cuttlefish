#pragma once

#include <string>
//
#include <fruit/fruit.h>

#include "host/libs/config/cuttlefish_config.h"
#include "host/libs/config/feature.h"

namespace cuttlefish {

class DataImagePath {
 public:
  virtual ~DataImagePath() = default;
  virtual const std::string& Path() const = 0;
};

class InitializeDataImage : public Feature {};

fruit::Component<DataImagePath> FixedDataImagePathComponent(
    const std::string* path);
fruit::Component<fruit::Required<const CuttlefishConfig, DataImagePath>,
                 InitializeDataImage>
InitializeDataImageComponent();

class InitializeEspImage : public Feature {};

fruit::Component<InitializeEspImage> InitializeEspImageComponent(
    const std::string* esp_image, const std::string* kernel_path,
    const std::string* initramfs_path);

bool CreateBlankImage(
    const std::string& image, int num_mb, const std::string& image_fmt);

class MiscImagePath {
 public:
  virtual ~MiscImagePath() = default;
  virtual const std::string& Path() const = 0;
};

class InitializeMiscImage : public Feature {};

fruit::Component<MiscImagePath> FixedMiscImagePathComponent(
    const std::string* path);
fruit::Component<fruit::Required<MiscImagePath>, InitializeMiscImage>
InitializeMiscImageComponent();

} // namespace cuttlefish
