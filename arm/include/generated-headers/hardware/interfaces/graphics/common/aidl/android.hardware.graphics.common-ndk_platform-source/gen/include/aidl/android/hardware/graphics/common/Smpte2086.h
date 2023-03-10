#pragma once
#include <android/binder_interface_utils.h>

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT
#include <aidl/android/hardware/graphics/common/XyColor.h>
namespace aidl {
namespace android {
namespace hardware {
namespace graphics {
namespace common {
class Smpte2086 {
public:
  static const char* descriptor;

  ::aidl::android::hardware::graphics::common::XyColor primaryRed;
  ::aidl::android::hardware::graphics::common::XyColor primaryGreen;
  ::aidl::android::hardware::graphics::common::XyColor primaryBlue;
  ::aidl::android::hardware::graphics::common::XyColor whitePoint;
  float maxLuminance = {};
  float minLuminance = {};

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;
};
}  // namespace common
}  // namespace graphics
}  // namespace hardware
}  // namespace android
}  // namespace aidl
