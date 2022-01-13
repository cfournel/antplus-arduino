#ifndef ANTPLUS_LEVSPEEDSYSTEMINFORMATION2_h
#define ANTPLUS_LEVSPEEDSYSTEMINFORMATION2_h

#include <Profiles/Lev/DataPages/ANTPLUS_LevBaseSpeedSystemInformation.h>

class LevSpeedSystemInformation2 : public LevBaseSpeedSystemInformation {
public:
    explicit LevSpeedSystemInformation2(AntRxDataResponse& dp);
    uint8_t getBatterySOC();
    uint8_t getBatteryEmptyWarning();
    uint8_t getPercentAssist();
};

#endif // ANTPLUS_LEVSPEEDSYSTEMINFORMATION2_h
