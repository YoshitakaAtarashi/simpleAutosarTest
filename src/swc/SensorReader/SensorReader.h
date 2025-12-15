/**
 * @file SensorReader.h
 * @brief Sensor Reader Software Component
 * 
 * センサーデータを読み取り、RTEを通じて他のSWCに提供
 */

#ifndef SENSOR_READER_H
#define SENSOR_READER_H

#include "Std_Types.h"

/* SWC初期化 */
void SensorReader_Init(void);

/* Runnable - 周期的に呼ばれる */
void SensorReader_Run(void);

#endif /* SENSOR_READER_H */
