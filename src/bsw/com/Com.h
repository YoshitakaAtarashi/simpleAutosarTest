/**
 * @file Com.h
 * @brief AUTOSAR Communication Module
 * 
 * コンポーネント間通信のシグナルベース実装
 */

#ifndef COM_H
#define COM_H

#include "Std_Types.h"

/* シグナルID型 */
typedef uint16_t Com_SignalIdType;

/* シグナルデータ型 */
typedef uint32_t Com_SignalDataType;

/* 最大シグナル数 */
#define COM_MAX_SIGNALS 50

/* COM API */
void Com_Init(void);
Std_ReturnType Com_SendSignal(Com_SignalIdType signalId, Com_SignalDataType signalData);
Std_ReturnType Com_ReceiveSignal(Com_SignalIdType signalId, Com_SignalDataType* signalData);

#endif /* COM_H */
