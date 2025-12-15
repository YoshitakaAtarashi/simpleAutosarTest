/**
 * @file EngineControl.h
 * @brief Engine Control Software Component
 * 
 * エンジン制御ロジックを実装するSWC
 */

#ifndef ENGINE_CONTROL_H
#define ENGINE_CONTROL_H

#include "Std_Types.h"

/* SWC初期化 */
void EngineControl_Init(void);

/* Runnable - 周期的に呼ばれる */
void EngineControl_Run(void);

#endif /* ENGINE_CONTROL_H */
