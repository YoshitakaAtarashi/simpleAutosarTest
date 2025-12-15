/**
 * @file Com.h
 * @brief AUTOSAR Communication Module
 * 
 * Signal-based implementation for inter-component communication
 */

#ifndef COM_H
#define COM_H

#include "Std_Types.h"

/* Signal ID type */
typedef uint16_t Com_SignalIdType;

/* Signal data type */
typedef uint32_t Com_SignalDataType;

/* Maximum number of signals */
#define COM_MAX_SIGNALS 50

/* COM API */
void Com_Init(void);
Std_ReturnType Com_SendSignal(Com_SignalIdType signalId, Com_SignalDataType signalData);
Std_ReturnType Com_ReceiveSignal(Com_SignalIdType signalId, Com_SignalDataType* signalData);

#endif /* COM_H */
