#ifndef HIDL_GENERATED_ANDROID_HARDWARE_CONFIRMATIONUI_V1_0_BNHWCONFIRMATIONRESULTCALLBACK_H
#define HIDL_GENERATED_ANDROID_HARDWARE_CONFIRMATIONUI_V1_0_BNHWCONFIRMATIONRESULTCALLBACK_H

#include <android/hardware/confirmationui/1.0/IHwConfirmationResultCallback.h>

namespace android {
namespace hardware {
namespace confirmationui {
namespace V1_0 {

struct BnHwConfirmationResultCallback : public ::android::hidl::base::V1_0::BnHwBase {
    explicit BnHwConfirmationResultCallback(const ::android::sp<IConfirmationResultCallback> &_hidl_impl);
    explicit BnHwConfirmationResultCallback(const ::android::sp<IConfirmationResultCallback> &_hidl_impl, const std::string& HidlInstrumentor_package, const std::string& HidlInstrumentor_interface);

    virtual ~BnHwConfirmationResultCallback();

    ::android::status_t onTransact(
            uint32_t _hidl_code,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            uint32_t _hidl_flags = 0,
            TransactCallback _hidl_cb = nullptr) override;


    /**
     * The pure class is what this class wraps.
     */
    typedef IConfirmationResultCallback Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'native' class.
     */
    typedef ::android::hardware::details::bnhw_tag _hidl_tag;

    ::android::sp<IConfirmationResultCallback> getImpl() { return _hidl_mImpl; }
    // Methods from ::android::hardware::confirmationui::V1_0::IConfirmationResultCallback follow.
    static ::android::status_t _hidl_result(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);



private:
    // Methods from ::android::hardware::confirmationui::V1_0::IConfirmationResultCallback follow.

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> ping();
    using getDebugInfo_cb = ::android::hidl::base::V1_0::IBase::getDebugInfo_cb;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb);

    ::android::sp<IConfirmationResultCallback> _hidl_mImpl;
};

}  // namespace V1_0
}  // namespace confirmationui
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_CONFIRMATIONUI_V1_0_BNHWCONFIRMATIONRESULTCALLBACK_H