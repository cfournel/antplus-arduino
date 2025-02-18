#ifndef ANTPLUS_BICYCLEPOWERPROFILEPRIVATEDEFINES_h
#define ANTPLUS_BICYCLEPOWERPROFILEPRIVATEDEFINES_h

#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerDefines.h>

/* Channel Config */
#define BICYCLEPOWER_CHANNELPERIOD                          8182
// 30 / 2.5 = 12
#define BICYCLEPOWER_SEARCHTIMEOUT                          12

#define BICYCLEPOWER_GENERALCALIBRATION_NUMBER     								0x01
#define BICYCLEPOWER_STANDARDPOWERONLY_NUMBER 											0x10
#define BICYCLEPOWER_STANDARDWHEELTORQUE_NUMBER 										0x11
#define BICYCLEPOWER_STANDARDCRANKTORQUE_NUMBER 										0x12
#define BICYCLEPOWER_TORQUEEFFECTIVENESSANDPEDALSMOOTHNESS_NUMBER 	0x13
#define BICYCLEPOWER_CRANKTORQUEFREQUENCY_NUMBER 									0x20

#endif // ANTPLUS_BICYCLEPOWERPROFILEPRIVATEDEFINES_h
