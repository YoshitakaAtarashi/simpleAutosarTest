/**
 * @file Det.h
 * @brief AUTOSAR Default Error Tracer
 * 
 * 開発時のエラー検出とトレース機能
 */

#ifndef DET_H
#define DET_H

#include "Std_Types.h"

/* モジュールID定義 */
#define DET_MODULE_ID_OS    0x01
#define DET_MODULE_ID_COM   0x02
#define DET_MODULE_ID_RTE   0x03
#define DET_MODULE_ID_ECUM  0x04

/* エラーID定義 */
#define DET_E_PARAM_POINTER     0x01
#define DET_E_PARAM_CONFIG      0x02
#define DET_E_PARAM_VALUE       0x03
#define DET_E_UNINIT            0x04

/* DET API */
void Det_Init(void);
Std_ReturnType Det_ReportError(uint16_t moduleId, uint8_t instanceId, 
                                uint8_t apiId, uint8_t errorId);

#endif /* DET_H */
