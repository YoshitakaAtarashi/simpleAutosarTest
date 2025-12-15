/**
 * @file SensorReader.c
 * @brief Sensor Reader Software Component Implementation
 * 
 * SWC that reads data from sensors
 * Generates simulation values instead of actual hardware
 */

#include "SensorReader.h"
#include "Rte.h"
#include <stdio.h>
#include <stdlib.h>

static uint32_t cycleCount = 0;

/**
 * @brief SensorReader initialization
 */
void SensorReader_Init(void) {
    cycleCount = 0;
    printf("[SWC-SensorReader] Initialized\n");
}

/**
 * @brief SensorReader execution (10ms cycle)
 */
void SensorReader_Run(void) {
    cycleCount++;
    
    /* Simulation: Generate sensor value (varies in range 50-150) */
    uint32_t sensorValue = 100 + (rand() % 50) - 25;
    
    /* Send sensor value via RTE */
    Std_ReturnType result = Rte_Write_SensorValue(sensorValue);
    
    if (result == E_OK) {
        if (cycleCount % 100 == 0) {  /* Display every 1 second */
            printf("[SWC-SensorReader] Sensor Value: %u (cycle: %u)\n", 
                   sensorValue, cycleCount);
        }
    }
}
