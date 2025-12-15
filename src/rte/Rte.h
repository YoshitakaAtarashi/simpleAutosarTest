/**
 * @file Rte.h
 * @brief AUTOSAR Runtime Environment
 * 
 * Interface abstraction layer between SWC and BSW
 */

#ifndef RTE_H
#define RTE_H

#include "Std_Types.h"
#include "Com.h"

/* Port definitions - Signal ID mapping */
#define RTE_PORT_SensorValue        0
#define RTE_PORT_EngineSpeed        1
#define RTE_PORT_ThrottlePosition   2
#define RTE_PORT_EngineCommand      3

/* RTE API - Sender/Receiver communication */
Std_ReturnType Rte_Write_SensorValue(uint32_t value);
Std_ReturnType Rte_Read_SensorValue(uint32_t* value);

Std_ReturnType Rte_Write_EngineSpeed(uint32_t value);
Std_ReturnType Rte_Read_EngineSpeed(uint32_t* value);

Std_ReturnType Rte_Write_ThrottlePosition(uint32_t value);
Std_ReturnType Rte_Read_ThrottlePosition(uint32_t* value);

Std_ReturnType Rte_Write_EngineCommand(uint32_t value);
Std_ReturnType Rte_Read_EngineCommand(uint32_t* value);

/* RTE initialization */
void Rte_Init(void);

#endif /* RTE_H */
