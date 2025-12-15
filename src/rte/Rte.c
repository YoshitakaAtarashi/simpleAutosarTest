/**
 * @file Rte.c
 * @brief AUTOSAR Runtime Environment Implementation
 * 
 * RTE mediates communication between SWC and BSW
 */

#include "Rte.h"
#include <stdio.h>

/**
 * @brief RTE initialization
 */
void Rte_Init(void) {
    printf("[RTE] Runtime Environment Initialized\n");
}

/**
 * @brief Write sensor value
 */
Std_ReturnType Rte_Write_SensorValue(uint32_t value) {
    return Com_SendSignal(RTE_PORT_SensorValue, value);
}

/**
 * @brief Read sensor value
 */
Std_ReturnType Rte_Read_SensorValue(uint32_t* value) {
    return Com_ReceiveSignal(RTE_PORT_SensorValue, value);
}

/**
 * @brief Write engine speed
 */
Std_ReturnType Rte_Write_EngineSpeed(uint32_t value) {
    return Com_SendSignal(RTE_PORT_EngineSpeed, value);
}

/**
 * @brief Read engine speed
 */
Std_ReturnType Rte_Read_EngineSpeed(uint32_t* value) {
    return Com_ReceiveSignal(RTE_PORT_EngineSpeed, value);
}

/**
 * @brief Write throttle position
 */
Std_ReturnType Rte_Write_ThrottlePosition(uint32_t value) {
    return Com_SendSignal(RTE_PORT_ThrottlePosition, value);
}

/**
 * @brief Read throttle position
 */
Std_ReturnType Rte_Read_ThrottlePosition(uint32_t* value) {
    return Com_ReceiveSignal(RTE_PORT_ThrottlePosition, value);
}

/**
 * @brief Write engine command
 */
Std_ReturnType Rte_Write_EngineCommand(uint32_t value) {
    return Com_SendSignal(RTE_PORT_EngineCommand, value);
}

/**
 * @brief Read engine command
 */
Std_ReturnType Rte_Read_EngineCommand(uint32_t* value) {
    return Com_ReceiveSignal(RTE_PORT_EngineCommand, value);
}
