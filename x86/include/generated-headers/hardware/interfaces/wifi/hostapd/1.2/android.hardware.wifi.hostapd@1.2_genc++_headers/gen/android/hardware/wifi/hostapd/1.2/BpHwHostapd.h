#ifndef HIDL_GENERATED_ANDROID_HARDWARE_WIFI_HOSTAPD_V1_2_BPHWHOSTAPD_H
#define HIDL_GENERATED_ANDROID_HARDWARE_WIFI_HOSTAPD_V1_2_BPHWHOSTAPD_H

#include <hidl/HidlTransportSupport.h>

#include <android/hardware/wifi/hostapd/1.2/IHwHostapd.h>

namespace android {
namespace hardware {
namespace wifi {
namespace hostapd {
namespace V1_2 {

struct BpHwHostapd : public ::android::hardware::BpInterface<IHostapd>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwHostapd(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    /**
     * The pure class is what this class wraps.
     */
    typedef IHostapd Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'proxy' class.
     */
    typedef ::android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    void onLastStrongRef(const void* id) override;

    // Methods from ::android::hardware::wifi::hostapd::V1_2::IHostapd follow.
    static ::android::hardware::Return<void>  _hidl_addAccessPoint_1_2(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::wifi::hostapd::V1_2::IHostapd::IfaceParams& ifaceParams, const ::android::hardware::wifi::hostapd::V1_2::IHostapd::NetworkParams& nwParams, addAccessPoint_1_2_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_forceClientDisconnect(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_string& ifaceName, const ::android::hardware::hidl_array<uint8_t, 6>& clientAddress, ::android::hardware::wifi::hostapd::V1_2::Ieee80211ReasonCode reasonCode, forceClientDisconnect_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_setDebugParams(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::wifi::hostapd::V1_2::DebugLevel level, setDebugParams_cb _hidl_cb);

    // Methods from ::android::hardware::wifi::hostapd::V1_0::IHostapd follow.
    ::android::hardware::Return<void> addAccessPoint(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::IfaceParams& ifaceParams, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::NetworkParams& nwParams, addAccessPoint_cb _hidl_cb) override;
    ::android::hardware::Return<void> removeAccessPoint(const ::android::hardware::hidl_string& ifaceName, removeAccessPoint_cb _hidl_cb) override;
    ::android::hardware::Return<void> terminate() override;

    // Methods from ::android::hardware::wifi::hostapd::V1_1::IHostapd follow.
    ::android::hardware::Return<void> addAccessPoint_1_1(const ::android::hardware::wifi::hostapd::V1_1::IHostapd::IfaceParams& ifaceParams, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::NetworkParams& nwParams, addAccessPoint_1_1_cb _hidl_cb) override;
    ::android::hardware::Return<void> registerCallback(const ::android::sp<::android::hardware::wifi::hostapd::V1_1::IHostapdCallback>& callback, registerCallback_cb _hidl_cb) override;

    // Methods from ::android::hardware::wifi::hostapd::V1_2::IHostapd follow.
    ::android::hardware::Return<void> addAccessPoint_1_2(const ::android::hardware::wifi::hostapd::V1_2::IHostapd::IfaceParams& ifaceParams, const ::android::hardware::wifi::hostapd::V1_2::IHostapd::NetworkParams& nwParams, addAccessPoint_1_2_cb _hidl_cb) override;
    ::android::hardware::Return<void> forceClientDisconnect(const ::android::hardware::hidl_string& ifaceName, const ::android::hardware::hidl_array<uint8_t, 6>& clientAddress, ::android::hardware::wifi::hostapd::V1_2::Ieee80211ReasonCode reasonCode, forceClientDisconnect_cb _hidl_cb) override;
    ::android::hardware::Return<void> setDebugParams(::android::hardware::wifi::hostapd::V1_2::DebugLevel level, setDebugParams_cb _hidl_cb) override;

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> interfaceChain(interfaceChain_cb _hidl_cb) override;
    ::android::hardware::Return<void> debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options) override;
    ::android::hardware::Return<void> interfaceDescriptor(interfaceDescriptor_cb _hidl_cb) override;
    ::android::hardware::Return<void> getHashChain(getHashChain_cb _hidl_cb) override;
    ::android::hardware::Return<void> setHALInstrumentation() override;
    ::android::hardware::Return<bool> linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie) override;
    ::android::hardware::Return<void> ping() override;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb) override;
    ::android::hardware::Return<void> notifySyspropsChanged() override;
    ::android::hardware::Return<bool> unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient) override;

private:
    std::mutex _hidl_mMutex;
    std::vector<::android::sp<::android::hardware::hidl_binder_death_recipient>> _hidl_mDeathRecipients;
};

}  // namespace V1_2
}  // namespace hostapd
}  // namespace wifi
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_WIFI_HOSTAPD_V1_2_BPHWHOSTAPD_H