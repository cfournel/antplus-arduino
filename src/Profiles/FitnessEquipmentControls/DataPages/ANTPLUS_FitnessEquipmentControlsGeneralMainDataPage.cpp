#include <Profiles/FitnessEquipmentControls/DataPages/ANTPLUS_FitnessEquipmentControlsGeneralMainDataPage.h>
#include <Profiles/FitnessEquipmentControls/ANTPLUS_FitnessEquipmentControlsPrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

// TODO this is a mixture of datapages
#define EQUIPMENTTYPEBITS_BYTE 1
#define ELAPSEDTIME_BYTE 2
#define DISTANCETRAVELED_BYTE 3
#define SPEED_LSB_BYTE 4
#define SPEED_MSB_BYTE 5
#define HEARTRATE_BYTE 6
#define CAPABILITIESBITFIELD_BYTE 7
#define CAPABILITIESBITFIELD_MASK 0x0F
#define FESTATEBITFIELD_BYTE  7
#define FESTATEBITFIELD_MASK  0xF0
#define FESTATEBITFIELD_SHIFT 4

template<class T>
FECGeneralMainDataPage<T>::FECGeneralMainDataPage() :
    CoreDataPage<T>() {}

template<class T>
uint8_t FECGeneralMainDataPage<T>::getDataPageNumber() {
    return this->get8BitValue(ANTPLUS_DEFAULT_DATAPAGE_BYTE);
}

template<class T>
uint8_t FECGeneralMainDataPage<T>::getEquipmentTypeBits() {
    return this->get8BitValue(EQUIPMENTTYPEBITS_BYTE);
}

template<class T>
uint8_t FECGeneralMainDataPage<T>::getElapsedTime() {
    return this->get8BitValue(ELAPSEDTIME_BYTE);
}

template<class T>
uint8_t FECGeneralMainDataPage<T>::getDistanceTraveled() {
    return this->get8BitValue(DISTANCETRAVELED_BYTE);
}

template<class T>
uint8_t FECGeneralMainDataPage<T>::getHeartRate() {
    return this->get8BitValue(HEARTRATE_BYTE);
}

template<class T>
uint8_t FECGeneralMainDataPage<T>::getCapabilitiesBits() {
    return this->get8BitValue(CAPABILITIESBITFIELD_BYTE,
            CAPABILITIESBITFIELD_MASK);
}

template<class T>
uint8_t FECGeneralMainDataPage<T>::getFEStateBits() {
    return this->get8BitValue(FESTATEBITFIELD_BYTE, FESTATEBITFIELD_MASK,
            FESTATEBITFIELD_SHIFT);
}

template<class T>
uint16_t FECGeneralMainDataPage<T>::getSpeed() {
    return this->get16BitValue(SPEED_LSB_BYTE, SPEED_MSB_BYTE);
}

template class FECGeneralMainDataPage<BroadcastData>;
template class FECGeneralMainDataPage<BroadcastDataMsg>;
