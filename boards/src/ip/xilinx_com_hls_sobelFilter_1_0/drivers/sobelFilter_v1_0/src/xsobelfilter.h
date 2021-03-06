// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2018.2
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

#ifndef XSOBELFILTER_H
#define XSOBELFILTER_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xsobelfilter_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Axilites_BaseAddress;
} XSobelfilter_Config;
#endif

typedef struct {
    u32 Axilites_BaseAddress;
    u32 IsReady;
} XSobelfilter;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XSobelfilter_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XSobelfilter_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XSobelfilter_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XSobelfilter_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XSobelfilter_Initialize(XSobelfilter *InstancePtr, u16 DeviceId);
XSobelfilter_Config* XSobelfilter_LookupConfig(u16 DeviceId);
int XSobelfilter_CfgInitialize(XSobelfilter *InstancePtr, XSobelfilter_Config *ConfigPtr);
#else
int XSobelfilter_Initialize(XSobelfilter *InstancePtr, const char* InstanceName);
int XSobelfilter_Release(XSobelfilter *InstancePtr);
#endif

void XSobelfilter_Start(XSobelfilter *InstancePtr);
u32 XSobelfilter_IsDone(XSobelfilter *InstancePtr);
u32 XSobelfilter_IsIdle(XSobelfilter *InstancePtr);
u32 XSobelfilter_IsReady(XSobelfilter *InstancePtr);
void XSobelfilter_EnableAutoRestart(XSobelfilter *InstancePtr);
void XSobelfilter_DisableAutoRestart(XSobelfilter *InstancePtr);

void XSobelfilter_Set_rows(XSobelfilter *InstancePtr, u32 Data);
u32 XSobelfilter_Get_rows(XSobelfilter *InstancePtr);
void XSobelfilter_Set_cols(XSobelfilter *InstancePtr, u32 Data);
u32 XSobelfilter_Get_cols(XSobelfilter *InstancePtr);
void XSobelfilter_Set_order(XSobelfilter *InstancePtr, u32 Data);
u32 XSobelfilter_Get_order(XSobelfilter *InstancePtr);

void XSobelfilter_InterruptGlobalEnable(XSobelfilter *InstancePtr);
void XSobelfilter_InterruptGlobalDisable(XSobelfilter *InstancePtr);
void XSobelfilter_InterruptEnable(XSobelfilter *InstancePtr, u32 Mask);
void XSobelfilter_InterruptDisable(XSobelfilter *InstancePtr, u32 Mask);
void XSobelfilter_InterruptClear(XSobelfilter *InstancePtr, u32 Mask);
u32 XSobelfilter_InterruptGetEnabled(XSobelfilter *InstancePtr);
u32 XSobelfilter_InterruptGetStatus(XSobelfilter *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
