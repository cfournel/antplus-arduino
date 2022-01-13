#ifndef ANTPLUS_PROFILEHEARTRATEDISPLAY_h
#define ANTPLUS_PROFILEHEARTRATEDISPLAY_h

#include <BaseClasses/ANTPLUS_BaseSlaveProfile.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRateDataPages.h>
#include <CommonDataPages/ANTPLUS_CommonDataPages.h>

class ProfileHeartRateDisplay : public BaseSlaveProfile {
public:
    ProfileHeartRateDisplay();
    explicit ProfileHeartRateDisplay(uint16_t deviceNumber);
    explicit ProfileHeartRateDisplay(uint16_t deviceNumber, uint8_t transmissionType);
    void onHeartRateBatteryStatus(void (*func)(HeartRateBatteryStatus&, uintptr_t), uintptr_t data = 0) { _onHeartRateBatteryStatus.set(func, data); }
    void onHeartRateCapabilities(void (*func)(HeartRateCapabilities&, uintptr_t), uintptr_t data = 0) { _onHeartRateCapabilities.set(func, data); }
    void onHeartRateCumulativeOperatingTime(void (*func)(HeartRateCumulativeOperatingTime&, uintptr_t), uintptr_t data = 0) { _onHeartRateCumulativeOperatingTime.set(func, data); }
    void onHeartRateDefault(void (*func)(HeartRateDefault&, uintptr_t), uintptr_t data = 0) { _onHeartRateDefault.set(func, data); }
    void onHeartRateManufacturerInformation(void (*func)(HeartRateManufacturerInformation&, uintptr_t), uintptr_t data = 0) { _onHeartRateManufacturerInformation.set(func, data); }
    void onHeartRatePreviousHeartBeat(void (*func)(HeartRatePreviousHeartBeat&, uintptr_t), uintptr_t data = 0) { _onHeartRatePreviousHeartBeat.set(func, data); }
    void onHeartRateProductInformation(void (*func)(HeartRateProductInformation&, uintptr_t), uintptr_t data = 0) { _onHeartRateProductInformation.set(func, data); }
    void onHeartRateSwimIntervalSummary(void (*func)(HeartRateSwimIntervalSummary&, uintptr_t), uintptr_t data = 0) { _onHeartRateSwimIntervalSummary.set(func, data); }

private:
    void setChannelConfig();
    void onBroadcastData(BroadcastData& msg) override;
    void onAcknowledgedData(AcknowledgedData& msg) override;

    bool handleDataPage(HeartRateBaseMainDataPage& dp);

    bool handleBatteryStatus(HeartRateBaseMainDataPage& dataPage);
    bool handleCapabilities(HeartRateBaseMainDataPage& dataPage);
    bool handleCumulativeOperatingTime(HeartRateBaseMainDataPage& dataPage);
    bool handleDefault(HeartRateBaseMainDataPage& dataPage);
    bool handleManufacturerInformation(HeartRateBaseMainDataPage& dataPage);
    bool handlePreviousHeartBeat(HeartRateBaseMainDataPage& dataPage);
    bool handleProductInformation(HeartRateBaseMainDataPage& dataPage);
    bool handleSwimIntervalSummary(HeartRateBaseMainDataPage& dataPage);
    AntCallback<HeartRateBatteryStatus&> _onHeartRateBatteryStatus = { .func = NULL };
    AntCallback<HeartRateCapabilities&> _onHeartRateCapabilities = { .func = NULL };
    AntCallback<HeartRateCumulativeOperatingTime&> _onHeartRateCumulativeOperatingTime = { .func = NULL };
    AntCallback<HeartRateDefault&> _onHeartRateDefault = { .func = NULL };
    AntCallback<HeartRateManufacturerInformation&> _onHeartRateManufacturerInformation = { .func = NULL };
    AntCallback<HeartRatePreviousHeartBeat&> _onHeartRatePreviousHeartBeat = { .func = NULL };
    AntCallback<HeartRateProductInformation&> _onHeartRateProductInformation = { .func = NULL };
    AntCallback<HeartRateSwimIntervalSummary&> _onHeartRateSwimIntervalSummary = { .func = NULL };
};

#endif // ANTPLUS_PROFILEHEARTRATEDISPLAY_h
