/*
 * Copyright (C) 2020 The Android Open Source Project
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

#pragma once

#include <mutex>
#include <memory>

#include "host/frontend/webrtc/cvd_video_frame_buffer.h"
#include "host/frontend/webrtc/lib/video_sink.h"
#include "host/libs/screen_connector/screen_connector.h"

namespace cuttlefish {
/**
 * ScreenConnectorImpl will generate this, and enqueue
 *
 * It's basically a (processed) frame, so it:
 *   must be efficiently std::move-able
 * Also, for the sake of algorithm simplicity:
 *   must be default-constructable & assignable
 *
 */
struct WebRtcScProcessedFrame : ScreenConnectorFrameInfo {
  // must support move semantic
  std::unique_ptr<CvdVideoFrameBuffer> buf_;
};

class DisplayHandler {
 public:
  using ScreenConnector = cuttlefish::ScreenConnector<WebRtcScProcessedFrame>;
  using GenerateProcessedFrameCallback = ScreenConnector::GenerateProcessedFrameCallback;

  DisplayHandler(
      std::shared_ptr<webrtc_streaming::VideoSink> display_sink,
      std::unique_ptr<ScreenConnector> screen_connector);
  ~DisplayHandler() = default;

  [[noreturn]] void Loop();
  void SendLastFrame();

  void IncClientCount();
  void DecClientCount();

 private:
  GenerateProcessedFrameCallback GetScreenConnectorCallback();
  std::shared_ptr<webrtc_streaming::VideoSink> display_sink_;
  std::unique_ptr<ScreenConnector> screen_connector_;
  std::shared_ptr<webrtc_streaming::VideoFrameBuffer> last_buffer_;
  std::mutex last_buffer_mutex_;
  std::mutex next_frame_mutex_;
  int client_count_ = 0;
};
}  // namespace cuttlefish
