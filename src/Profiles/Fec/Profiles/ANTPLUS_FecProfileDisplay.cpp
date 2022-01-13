#include <Profiles/Fec/Profiles/ANTPLUS_FecProfileDisplay.h>
#include <Profiles/Fec/ANTPLUS_FecPrivateDefines.h>

ProfileFecDisplay::ProfileFecDisplay(uint16_t deviceNumber, uint8_t transmissionType) : BaseSlaveProfile(deviceNumber, transmissionType) {
    setChannelConfig();
}

void ProfileFecDisplay::onBroadcastData(BroadcastData& msg) {
    BaseDataPage<BroadcastData> dp = BaseDataPage<BroadcastData>(msg);
    BaseSlaveProfile::onBroadcastData(msg);
    if (!handleDataPage(dp)) {
        callOnOtherDataPage(msg);
    }
}

bool ProfileFecDisplay::handleDataPage(BaseDataPage<BroadcastData>& dp) {
    uint8_t dataPage = dp.getDataPageNumber();
    bool called = false;

    switch (dataPage) {
    case ANTPLUS_FEC_DATAPAGE_TRAINER_DATA_NUMBER:
        called = handleTrainerData(dp);
        break;

    case ANTPLUS_FEC_MANUFACTURERINFORMATION_NUMBER:
        called = handleManufacturerInformation(dp);
        break;

    case ANTPLUS_FEC_PRODUCT_INFORMATION_NUMBER:
        called = handleProductInformation(dp);
        break;

    case ANTPLUS_FEC_GENERAL_INFORMATION_NUMBER:
        called = handleGeneralDataPage(dp);
        break;

    case ANTPLUS_FEC_GENERAL_SETTINGS_NUMBER:
        called = handleGeneralSettingsDataPage(dp);
        break;
    
    case ANTPLUS_FEC_TARGET_POWER_NUMBER:
        called = handleTargetPowerDataPage(dp);
        break;

    case ANTPLUS_FEC_CAPABILITIES_INFORMATION_NUMBER:
        called = handleCapabilitiesInformationDataPage(dp);
        break;

    case ANTPLUS_FEC_BASIC_RESISTANCE_NUMBER:
        called = handleBasicResistanceDataPage(dp);
        break;

    }

    return called;
}

void ProfileFecDisplay::onAcknowledgedData(AcknowledgedData& msg) {
    BaseDataPage<BroadcastData> dp = BaseDataPage<BroadcastData>(msg);
    BaseSlaveProfile::onAcknowledgedData(msg);
    if (!handleDataPage(dp)) {
        callOnOtherDataPage(msg);
    }
}


void ProfileFecDisplay::setChannelConfig() {
    setChannelType(ANTPLUS_FEC_DISPLAY_CHANNELTYPE);
    setDeviceType(ANTPLUS_FEC_DEVICETYPE);
    setChannelPeriod(ANTPLUS_FEC_CHANNELPERIOD);
    setSearchTimeout(ANTPLUS_FEC_SEARCHTIMEOUT);
}

bool ProfileFecDisplay::handleManufacturerInformation(BaseDataPage<BroadcastData>& dataPage) {
    FecManufacturerInformation dp(dataPage);
    return _onFecManufacturerInformation.call(dp);
}

bool ProfileFecDisplay::handleProductInformation(BaseDataPage<BroadcastData>& dataPage) {
    FecProductInformation dp(dataPage);
    return _onFecProductInformation.call(dp);
}

bool ProfileFecDisplay::handleGeneralDataPage(BaseDataPage<BroadcastData>& dataPage) {
    FecGeneralMainDataPage dp(dataPage);
    return _onFecGeneralDataPage.call(dp);
}

bool ProfileFecDisplay::handleGeneralSettingsDataPage(BaseDataPage<BroadcastData>& dataPage) {
    FecGeneralSettingsDataPage dp(dataPage);
    return _onFecGeneralSettingsDataPage.call(dp);
}
bool ProfileFecDisplay::handleTargetPowerDataPage(BaseDataPage<BroadcastData>& dataPage) {
    FecTargetPowerDataPage dp(dataPage);
    return _onFecTargetPowerDataPage.call(dp);
}

bool ProfileFecDisplay::handleBasicResistanceDataPage(BaseDataPage<BroadcastData>& dataPage) {
    FecBasicResistanceDataPage dp(dataPage);
    return _onFecBasicResistanceDataPage.call(dp);
}

bool ProfileFecDisplay::handleCapabilitiesInformationDataPage(BaseDataPage<BroadcastData>& dataPage) {
    FecCapabilitiesInformationDatapage dp(dataPage);
    return _onFecCapabilitiesInformationDataPage.call(dp);
}

bool ProfileFecDisplay::transmitFecTargetPowerMsg(uint16_t TargetPower) {
    FecTargetPowerDataMsg msg;
    msg.setTargetPower(TargetPower);
    send(msg);
    return false;
}

bool ProfileFecDisplay::transmitFecTrackResistanceMsg(uint16_t TargetGrade) {
    FecTrackResistanceDataMsg msg;
    msg.setTargetGrade(TargetGrade);
    send(msg);
    return false;
}

bool ProfileFecDisplay::transmitFecBasicResistanceMsg(uint8_t Power) {
    FecBasicResistanceDataMsg msg;
    msg.setPower(Power);
    send(msg);
    return false;
}

bool ProfileFecDisplay::transmitFecUserInformationMsg(uint16_t UserWeight, uint16_t BikeWeight) {
    FecUserInformationMsg msg;
    msg.setUserWeight(UserWeight);
    msg.setBikeWeight(BikeWeight);
    send(msg);
    return true;
}

bool ProfileFecDisplay::transmitFecCapabitiliesRequestMsg()
{
    FecCapabilitiesInformationMsg msg;
    msg.setCapabitilies(0);
    msg.setMaximumResistance(800);
    send(msg);
    return true;
}

bool ProfileFecDisplay::handleTrainerData(BaseDataPage<BroadcastData>& dataPage) {
    FecSpecificTrainerData dp(dataPage);
    return _onFecSpecificTrainerData.call(dp);
}

bool ProfileFecDisplay::handleUserInformationDataPage(BaseDataPage<BroadcastData>& dataPage) {
    FecUserInformationDatapage dp(dataPage);
    return _onFecUserInformationDataPage.call(dp);
}
