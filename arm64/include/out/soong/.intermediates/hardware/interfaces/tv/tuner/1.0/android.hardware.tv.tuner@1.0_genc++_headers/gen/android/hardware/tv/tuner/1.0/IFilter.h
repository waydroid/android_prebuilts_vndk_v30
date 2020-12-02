#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TV_TUNER_V1_0_IFILTER_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TV_TUNER_V1_0_IFILTER_H

#include <android/hardware/tv/tuner/1.0/types.h>
#include <android/hidl/base/1.0/IBase.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace tv {
namespace tuner {
namespace V1_0 {

/**
 * The Filter is used to filter wanted data according to the filter's
 * configuration.
 */
struct IFilter : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef ::android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.tv.tuner@1.0::IFilter"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Return callback for getQueueDesc
     */
    using getQueueDesc_cb = std::function<void(::android::hardware::tv::tuner::V1_0::Result result, const ::android::hardware::MQDescriptorSync<uint8_t>& queue)>;
    /**
     * Get the descriptor of the filter's FMQ
     *
     * It is used by the client to get the descriptor of the filter's Fast
     * Message Queue. The data in FMQ is filtered out from demux input or upper
     * stream's filter. The data is origanized to data blocks which may have
     * different length. The length's information of one or multiple data blocks
     * is sent to client through DemuxFilterEvent. The data in each block
     * follows the stardard specified by filter's type.
     * E.X. one data block from the filter with Main_Type==TS and Sub_Type==PES
     * is Packetized Elementary Stream from Transport Stream according to
     * ISO/IEC 13818-1.
     *
     *
     * @return result Result status of the operation.
     *         SUCCESS if successful,
     *         UNAVAILABLE if the filter doesn't have FMQ.
     *         INVALID_STATE if failed for wrong state.
     *         UNKNOWN_ERROR if failed for other reasons.
     * @return queue the descriptor of the filter's FMQ
     */
    virtual ::android::hardware::Return<void> getQueueDesc(getQueueDesc_cb _hidl_cb) = 0;

    /**
     * Configure the filter.
     *
     * It is used by the client to configure the filter so that it can filter out
     * intended data.
     *
     * @param settings the settings of the filter.
     * @return result Result status of the operation.
     *         SUCCESS if successful,
     *         INVALID_STATE if failed for wrong state.
     *         UNKNOWN_ERROR if failed for other reasons.
     */
    virtual ::android::hardware::Return<::android::hardware::tv::tuner::V1_0::Result> configure(const ::android::hardware::tv::tuner::V1_0::DemuxFilterSettings& settings) = 0;

    /**
     * Start the filter.
     *
     * It is used by the client to ask the filter to start filterring data.
     *
     * @return result Result status of the operation.
     *         SUCCESS if successful,
     *         INVALID_STATE if failed for wrong state.
     *         UNKNOWN_ERROR if failed for other reasons.
     */
    virtual ::android::hardware::Return<::android::hardware::tv::tuner::V1_0::Result> start() = 0;

    /**
     * Stop the filter.
     *
     * It is used by the client to ask the filter to stop filterring data.
     * It won't discard the data already filtered out by the filter. The filter
     * will be stopped and removed automatically if the demux is closed.
     *
     * @return result Result status of the operation.
     *         SUCCESS if successful,
     *         INVALID_STATE if failed for wrong state.
     *         UNKNOWN_ERROR if failed for other reasons.
     */
    virtual ::android::hardware::Return<::android::hardware::tv::tuner::V1_0::Result> stop() = 0;

    /**
     * Flush the filter.
     *
     * It is used by the client to ask the filter to flush the data which is
     * already produced but not consumed yet.
     *
     * @return result Result status of the operation.
     *         SUCCESS if successful,
     *         INVALID_STATE if failed for wrong state.
     *         UNKNOWN_ERROR if failed for other reasons.
     */
    virtual ::android::hardware::Return<::android::hardware::tv::tuner::V1_0::Result> flush() = 0;

    /**
     * Return callback for getId
     */
    using getId_cb = std::function<void(::android::hardware::tv::tuner::V1_0::Result result, uint32_t filterId)>;
    /**
     * Get the filter Id.
     *
     * It is used by the client to ask the hardware resource id for the filter.
     *
     * @return result Result status of the operation.
     *         SUCCESS if successful,
     *         INVALID_STATE if failed for wrong state.
     *         UNKNOWN_ERROR if failed for other reasons.
     * @return filterId the hardware resource Id for the filter.
     */
    virtual ::android::hardware::Return<void> getId(getId_cb _hidl_cb) = 0;

    /**
     * Release the handle reported by the HAL for AV memory.
     *
     * It is used by the client to notify the HAL that the AV handle won't be
     * used any more in client side, so that the HAL can mark the memory
     * presented by file descripor in the handle as released.
     *
     * @param avMemory A handle associated to the memory for audio or video.
     * @param avDataId An Id provides additional information for AV data.
     * @return result Result status of the operation.
     *         SUCCESS if successful,
     *         INVALID_ARGUMENT if failed for wrong parameter.
     *         UNKNOWN_ERROR if failed for other reasons.
     */
    virtual ::android::hardware::Return<::android::hardware::tv::tuner::V1_0::Result> releaseAvHandle(const ::android::hardware::hidl_handle& avMemory, uint64_t avDataId) = 0;

    /**
     * Set the filter's data source.
     *
     * A filter uses demux as data source by default. If the data was packetized
     * by multiple protocols, multiple filters may need to work together to
     * extract all protocols' header. Then a filter's data source can be output
     * from another filter.
     *
     * @param filter the filter instance which provides data input. Switch to
     * use demux as data source if the filter instance is NULL.
     * @return result Result status of the operation.
     *         SUCCESS if successful,
     *         INVALID_STATE if failed for wrong state.
     *         UNKNOWN_ERROR if failed for other reasons.
     */
    virtual ::android::hardware::Return<::android::hardware::tv::tuner::V1_0::Result> setDataSource(const ::android::sp<::android::hardware::tv::tuner::V1_0::IFilter>& filter) = 0;

    /**
     * Release the Filter instance
     *
     * It is used by the client to release the Filter instance. HAL clear
     * underneath resource. client mustn't access the instance any more.
     *
     * @return result Result status of the operation.
     *         SUCCESS if successful,
     *         UNKNOWN_ERROR if failed for other reasons.
     */
    virtual ::android::hardware::Return<::android::hardware::tv::tuner::V1_0::Result> close() = 0;

    /**
     * Return callback for interfaceChain
     */
    using interfaceChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& descriptors)>;
    /*
     * Provides run-time type information for this object.
     * For example, for the following interface definition:
     *     package android.hardware.foo@1.0;
     *     interface IParent {};
     *     interface IChild extends IParent {};
     * Calling interfaceChain on an IChild object must yield the following:
     *     ["android.hardware.foo@1.0::IChild",
     *      "android.hardware.foo@1.0::IParent"
     *      "android.hidl.base@1.0::IBase"]
     *
     * @return descriptors a vector of descriptors of the run-time type of the
     *         object.
     */
    virtual ::android::hardware::Return<void> interfaceChain(interfaceChain_cb _hidl_cb) override;

    /*
     * Emit diagnostic information to the given file.
     *
     * Optionally overriden.
     *
     * @param fd      File descriptor to dump data to.
     *                Must only be used for the duration of this call.
     * @param options Arguments for debugging.
     *                Must support empty for default debug information.
     */
    virtual ::android::hardware::Return<void> debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options) override;

    /**
     * Return callback for interfaceDescriptor
     */
    using interfaceDescriptor_cb = std::function<void(const ::android::hardware::hidl_string& descriptor)>;
    /*
     * Provides run-time type information for this object.
     * For example, for the following interface definition:
     *     package android.hardware.foo@1.0;
     *     interface IParent {};
     *     interface IChild extends IParent {};
     * Calling interfaceDescriptor on an IChild object must yield
     *     "android.hardware.foo@1.0::IChild"
     *
     * @return descriptor a descriptor of the run-time type of the
     *         object (the first element of the vector returned by
     *         interfaceChain())
     */
    virtual ::android::hardware::Return<void> interfaceDescriptor(interfaceDescriptor_cb _hidl_cb) override;

    /**
     * Return callback for getHashChain
     */
    using getHashChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_array<uint8_t, 32>>& hashchain)>;
    /*
     * Returns hashes of the source HAL files that define the interfaces of the
     * runtime type information on the object.
     * For example, for the following interface definition:
     *     package android.hardware.foo@1.0;
     *     interface IParent {};
     *     interface IChild extends IParent {};
     * Calling interfaceChain on an IChild object must yield the following:
     *     [(hash of IChild.hal),
     *      (hash of IParent.hal)
     *      (hash of IBase.hal)].
     *
     * SHA-256 is used as the hashing algorithm. Each hash has 32 bytes
     * according to SHA-256 standard.
     *
     * @return hashchain a vector of SHA-1 digests
     */
    virtual ::android::hardware::Return<void> getHashChain(getHashChain_cb _hidl_cb) override;

    /*
     * This method trigger the interface to enable/disable instrumentation based
     * on system property hal.instrumentation.enable.
     */
    virtual ::android::hardware::Return<void> setHALInstrumentation() override;

    /*
     * Registers a death recipient, to be called when the process hosting this
     * interface dies.
     *
     * @param recipient a hidl_death_recipient callback object
     * @param cookie a cookie that must be returned with the callback
     * @return success whether the death recipient was registered successfully.
     */
    virtual ::android::hardware::Return<bool> linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie) override;

    /*
     * Provides way to determine if interface is running without requesting
     * any functionality.
     */
    virtual ::android::hardware::Return<void> ping() override;

    /**
     * Return callback for getDebugInfo
     */
    using getDebugInfo_cb = std::function<void(const ::android::hidl::base::V1_0::DebugInfo& info)>;
    /*
     * Get debug information on references on this interface.
     * @return info debugging information. See comments of DebugInfo.
     */
    virtual ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb) override;

    /*
     * This method notifies the interface that one or more system properties
     * have changed. The default implementation calls
     * (C++)  report_sysprop_change() in libcutils or
     * (Java) android.os.SystemProperties.reportSyspropChanged,
     * which in turn calls a set of registered callbacks (eg to update trace
     * tags).
     */
    virtual ::android::hardware::Return<void> notifySyspropsChanged() override;

    /*
     * Unregisters the registered death recipient. If this service was registered
     * multiple times with the same exact death recipient, this unlinks the most
     * recently registered one.
     *
     * @param recipient a previously registered hidl_death_recipient callback
     * @return success whether the death recipient was unregistered successfully.
     */
    virtual ::android::hardware::Return<bool> unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient) override;

    // cast static functions
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::tv::tuner::V1_0::IFilter>> castFrom(const ::android::sp<::android::hardware::tv::tuner::V1_0::IFilter>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::tv::tuner::V1_0::IFilter>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

    // helper methods for interactions with the hwservicemanager
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is currently not available or not in the VINTF manifest on a Trebilized
     * device, this will return nullptr. This is useful when you don't want to block
     * during device boot. If getStub is true, this will try to return an unwrapped
     * passthrough implementation in the same process. This is useful when getting an
     * implementation from the same partition/compilation group.
     *
     * In general, prefer getService(std::string,bool)
     */
    static ::android::sp<IFilter> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IFilter> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IFilter> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IFilter> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IFilter> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IFilter> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IFilter> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IFilter> getService(bool getStub) { return getService("default", getStub); }
    /**
     * Registers a service with the service manager. For Trebilized devices, the service
     * must also be in the VINTF manifest.
     */
    __attribute__ ((warn_unused_result))::android::status_t registerAsService(const std::string &serviceName="default");
    /**
     * Registers for notifications for when a service is registered.
     */
    static bool registerForNotifications(
            const std::string &serviceName,
            const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification);
};

//
// type declarations for package
//

static inline std::string toString(const ::android::sp<::android::hardware::tv::tuner::V1_0::IFilter>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::tv::tuner::V1_0::IFilter>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::tv::tuner::V1_0::IFilter::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_0
}  // namespace tuner
}  // namespace tv
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TV_TUNER_V1_0_IFILTER_H
