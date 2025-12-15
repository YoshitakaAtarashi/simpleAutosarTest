/**
 * @file Com.c
 * @brief AUTOSAR Communication Module Implementation
 */

#include "Com.h"
#include <stdio.h>
#include <string.h>

/* Signal buffer */
typedef struct {
    Com_SignalIdType signalId;
    Com_SignalDataType data;
    bool isValid;
} Com_SignalBufferType;

static Com_SignalBufferType signalBuffer[COM_MAX_SIGNALS];

/**
 * @brief COM initialization
 */
void Com_Init(void) {
    memset(signalBuffer, 0, sizeof(signalBuffer));
    
    for (int i = 0; i < COM_MAX_SIGNALS; i++) {
        signalBuffer[i].isValid = false;
    }
    
    printf("[COM] Initialized\n");
}

/**
 * @brief Send signal
 */
Std_ReturnType Com_SendSignal(Com_SignalIdType signalId, Com_SignalDataType signalData) {
    if (signalId >= COM_MAX_SIGNALS) {
        return E_NOT_OK;
    }
    
    signalBuffer[signalId].signalId = signalId;
    signalBuffer[signalId].data = signalData;
    signalBuffer[signalId].isValid = true;
    
    return E_OK;
}

/**
 * @brief Receive signal
 */
Std_ReturnType Com_ReceiveSignal(Com_SignalIdType signalId, Com_SignalDataType* signalData) {
    if (signalId >= COM_MAX_SIGNALS || signalData == NULL) {
        return E_NOT_OK;
    }
    
    if (!signalBuffer[signalId].isValid) {
        return E_NOT_OK;
    }
    
    *signalData = signalBuffer[signalId].data;
    
    return E_OK;
}
