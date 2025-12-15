/**
 * @file SensorReader.h
 * @brief Sensor Reader Software Component
 * 
 * Reads sensor data and provides it to other SWCs via RTE
 */

#ifndef SENSOR_READER_H
#define SENSOR_READER_H

#include "Std_Types.h"

/* SWC initialization */
void SensorReader_Init(void);

/* Runnable - called periodically */
void SensorReader_Run(void);

#endif /* SENSOR_READER_H */
