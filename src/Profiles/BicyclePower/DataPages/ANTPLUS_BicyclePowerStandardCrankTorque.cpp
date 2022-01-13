#include <Profiles/BicyclePower/DataPages/ANTPLUS_BicyclePowerStandardCrankTorque.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>

#define CRANKTICKS_BYTE             2
#define INSTANTANEOUSCADENCE_BYTE   3
#define PERIOD_LSB_BYTE        4
#define PERIOD_MSB_BYTE        5
#define ACCUMULATEDTORQUE_LSB_BYTE  6
#define ACCUMULATEDTORQUE_MSB_BYTE  7

template<class T>
BicyclePowerBaseStandardCrankTorque<T>::BicyclePowerBaseStandardCrankTorque() :
    CoreDataPage<T>() {}

template<class T>
uint8_t BicyclePowerBaseStandardCrankTorque<T>::getCrankTicks() {
    return this->get8BitValue(CRANKTICKS_BYTE);
}

template<class T>
uint8_t BicyclePowerBaseStandardCrankTorque<T>::getInstantaneousCadence() {
    return this->get8BitValue(INSTANTANEOUSCADENCE_BYTE);
}

template<class T>
uint16_t BicyclePowerBaseStandardCrankTorque<T>::getCrankPeriod() {
    return this->get16BitValue(PERIOD_LSB_BYTE, PERIOD_MSB_BYTE);
}

template<class T>
uint16_t BicyclePowerBaseStandardCrankTorque<T>::getAccumulatedTorque() {
    return this->get16BitValue(
            ACCUMULATEDTORQUE_LSB_BYTE, ACCUMULATEDTORQUE_MSB_BYTE);
}

template class BicyclePowerBaseStandardCrankTorque<BroadcastData>;
template class BicyclePowerBaseStandardCrankTorque<BroadcastDataMsg>;

BicyclePowerStandardCrankTorque::BicyclePowerStandardCrankTorque(AntRxDataResponse& dp) :
    BicyclePowerBaseMainDataPage(dp),
    BicyclePowerBaseStandardCrankTorque() {}

BicyclePowerStandardCrankTorqueMsg::BicyclePowerStandardCrankTorqueMsg() :
    BicyclePowerBaseMainDataPageMsg(BICYCLEPOWER_STANDARDCRANKTORQUE_NUMBER),
    BicyclePowerBaseStandardCrankTorque() {}

void BicyclePowerStandardCrankTorqueMsg::setCrankTicks(uint8_t ticks) {
    set8BitValue(ticks, CRANKTICKS_BYTE);
}
void BicyclePowerStandardCrankTorqueMsg::setInstantaneousCadence(uint8_t cadence) {
    set8BitValue(cadence, INSTANTANEOUSCADENCE_BYTE);
}

void BicyclePowerStandardCrankTorqueMsg::setCrankPeriod(uint16_t period) {
    set16BitValue(period, PERIOD_LSB_BYTE, PERIOD_MSB_BYTE);
}

void BicyclePowerStandardCrankTorqueMsg::setAccumulatedTorque(uint16_t torque) {
    set16BitValue(torque, ACCUMULATEDTORQUE_LSB_BYTE, ACCUMULATEDTORQUE_MSB_BYTE);
}
