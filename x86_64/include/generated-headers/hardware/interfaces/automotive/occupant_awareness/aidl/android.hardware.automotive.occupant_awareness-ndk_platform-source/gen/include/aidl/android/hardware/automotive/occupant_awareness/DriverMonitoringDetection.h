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
#include <aidl/android/hardware/automotive/occupant_awareness/ConfidenceLevel.h>
namespace aidl {
namespace android {
namespace hardware {
namespace automotive {
namespace occupant_awareness {
class DriverMonitoringDetection {
public:
  static const char* descriptor;

  ::aidl::android::hardware::automotive::occupant_awareness::ConfidenceLevel confidenceScore = ::aidl::android::hardware::automotive::occupant_awareness::ConfidenceLevel(0);
  bool isLookingOnRoad = {};
  int64_t gazeDurationMillis = {};

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;
};
}  // namespace occupant_awareness
}  // namespace automotive
}  // namespace hardware
}  // namespace android
}  // namespace aidl
