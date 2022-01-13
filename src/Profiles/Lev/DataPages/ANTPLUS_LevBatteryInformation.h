#ifndef ANTPLUS_LEVBATTERYINFORMATION_h
#define ANTPLUS_LEVBATTERYINFORMATION_h

#include <Profiles/Lev/DataPages/ANTPLUS_LevBaseMainDataPage.h>

class LevBatteryInformation : public LevBaseMainDataPage {
public:
    explicit LevBatteryInformation(AntRxDataResponse& dp);
    uint16_t getChargingCycleCount();
    uint16_t getFuelConsumption();
    uint8_t getBatteryVoltage();
    uint16_t getDistanceOnCurrentCharge();
};

#endif // ANTPLUS_LEVBATTERYINFORMATION_h
