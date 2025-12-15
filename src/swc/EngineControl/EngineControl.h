/**
 * @file EngineControl.h
 * @brief Engine Control Software Component
 * 
 * SWC that implements engine control logic
 */

#ifndef ENGINE_CONTROL_H
#define ENGINE_CONTROL_H

#include "Std_Types.h"

/* SWC initialization */
void EngineControl_Init(void);

/* Runnable - called periodically */
void EngineControl_Run(void);

#endif /* ENGINE_CONTROL_H */
