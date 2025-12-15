/**
 * @file Det.c
 * @brief AUTOSAR Default Error Tracer Implementation
 */

#include "Det.h"
#include <stdio.h>

static uint32_t errorCount = 0;

/**
 * @brief DET初期化
 */
void Det_Init(void) {
    errorCount = 0;
    printf("[DET] Initialized\n");
}

/**
 * @brief エラーレポート
 */
Std_ReturnType Det_ReportError(uint16_t moduleId, uint8_t instanceId, 
                                uint8_t apiId, uint8_t errorId) {
    errorCount++;
    
    printf("[DET ERROR #%u] Module: 0x%02X, Instance: %u, API: %u, Error: 0x%02X\n",
           errorCount, moduleId, instanceId, apiId, errorId);
    
    return E_OK;
}
