#include <stdint.h>
#ifndef FLAMESENSOR_H_
#define FLAMESENSOR_H_


void EnableFlameSensor(void);
uint16_t ReadFlameValues(void);
uint16_t DetectMaxFlameValue(void);
uint16_t GetThresholdValue(void);
uint16_t BeginScanning(void);




#endif /* FLAMESENSOR_H_ */
