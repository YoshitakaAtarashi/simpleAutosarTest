/**
 * @file EngineControl.c
 * @brief Engine Control Software Component Implementation
 * 
 * SWC that performs engine control based on sensor values
 */

#include "EngineControl.h"
#include "Rte.h"
#include <stdio.h>

static uint32_t cycleCount = 0;
static uint32_t currentEngineSpeed = 0;

/**
 * @brief EngineControl initialization
 */
void EngineControl_Init(void) {
    cycleCount = 0;
    currentEngineSpeed = 800;  /* Idle RPM */
    printf("[SWC-EngineControl] Initialized (Idle RPM: %u)\n", currentEngineSpeed);
}

/**
 * @brief EngineControl execution (20ms cycle)
 */
void EngineControl_Run(void) {
    cycleCount++;
    
    uint32_t sensorValue = 0;
    uint32_t targetSpeed = 0;
    
    /* Read sensor value from RTE */
    Std_ReturnType result = Rte_Read_SensorValue(&sensorValue);
    
    if (result == E_OK) {
        /* Calculate engine speed based on sensor value */
        /* Simple control logic: sensor value * 20 */
        targetSpeed = sensorValue * 20;
        
        /* Smoothly change from current value to target value */
        if (currentEngineSpeed < targetSpeed) {
            currentEngineSpeed += 10;
        } else if (currentEngineSpeed > targetSpeed) {
            currentEngineSpeed -= 10;
        }
        
        /* Write engine speed to RTE */
        Rte_Write_EngineSpeed(currentEngineSpeed);
        
        if (cycleCount % 50 == 0) {  /* Display every 1 second */
            printf("[SWC-EngineControl] Sensor: %u, Engine RPM: %u -> %u (cycle: %u)\n",
                   sensorValue, currentEngineSpeed, targetSpeed, cycleCount);
        }
    } else {
        /* Maintain idle speed if sensor value cannot be obtained */
        currentEngineSpeed = 800;
    }
}
