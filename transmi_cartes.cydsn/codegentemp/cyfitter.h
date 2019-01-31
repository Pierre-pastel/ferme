/*******************************************************************************
* File Name: cyfitter.h
* 
* PSoC Creator  4.1 Update 1
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2017 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice.h"
#include "cydevice_trm.h"

/* Clock_2 */
#define Clock_2__CFG0 CYREG_CLKDIST_DCFG0_CFG0
#define Clock_2__CFG1 CYREG_CLKDIST_DCFG0_CFG1
#define Clock_2__CFG2 CYREG_CLKDIST_DCFG0_CFG2
#define Clock_2__CFG2_SRC_SEL_MASK 0x07u
#define Clock_2__INDEX 0x00u
#define Clock_2__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define Clock_2__PM_ACT_MSK 0x01u
#define Clock_2__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define Clock_2__PM_STBY_MSK 0x01u

/* PWM_LED */
#define PWM_LED_PWMUDB_genblk1_ctrlreg__7__MASK 0x80u
#define PWM_LED_PWMUDB_genblk1_ctrlreg__7__POS 7
#define PWM_LED_PWMUDB_genblk1_ctrlreg__CONTROL_AUX_CTL_REG CYREG_B0_UDB15_ACTL
#define PWM_LED_PWMUDB_genblk1_ctrlreg__CONTROL_REG CYREG_B0_UDB15_CTL
#define PWM_LED_PWMUDB_genblk1_ctrlreg__CONTROL_ST_REG CYREG_B0_UDB15_ST_CTL
#define PWM_LED_PWMUDB_genblk1_ctrlreg__COUNT_REG CYREG_B0_UDB15_CTL
#define PWM_LED_PWMUDB_genblk1_ctrlreg__COUNT_ST_REG CYREG_B0_UDB15_ST_CTL
#define PWM_LED_PWMUDB_genblk1_ctrlreg__MASK 0x80u
#define PWM_LED_PWMUDB_genblk1_ctrlreg__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB15_MSK_ACTL
#define PWM_LED_PWMUDB_genblk1_ctrlreg__PER_CTL_AUX_CTL_REG CYREG_B0_UDB15_MSK_ACTL
#define PWM_LED_PWMUDB_genblk1_ctrlreg__PERIOD_REG CYREG_B0_UDB15_MSK
#define PWM_LED_PWMUDB_genblk8_stsreg__0__MASK 0x01u
#define PWM_LED_PWMUDB_genblk8_stsreg__0__POS 0
#define PWM_LED_PWMUDB_genblk8_stsreg__2__MASK 0x04u
#define PWM_LED_PWMUDB_genblk8_stsreg__2__POS 2
#define PWM_LED_PWMUDB_genblk8_stsreg__3__MASK 0x08u
#define PWM_LED_PWMUDB_genblk8_stsreg__3__POS 3
#define PWM_LED_PWMUDB_genblk8_stsreg__MASK 0x0Du
#define PWM_LED_PWMUDB_genblk8_stsreg__MASK_REG CYREG_B0_UDB15_MSK
#define PWM_LED_PWMUDB_genblk8_stsreg__MASK_ST_AUX_CTL_REG CYREG_B0_UDB15_MSK_ACTL
#define PWM_LED_PWMUDB_genblk8_stsreg__PER_ST_AUX_CTL_REG CYREG_B0_UDB15_MSK_ACTL
#define PWM_LED_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG CYREG_B0_UDB15_ACTL
#define PWM_LED_PWMUDB_genblk8_stsreg__STATUS_CNT_REG CYREG_B0_UDB15_ST_CTL
#define PWM_LED_PWMUDB_genblk8_stsreg__STATUS_CONTROL_REG CYREG_B0_UDB15_ST_CTL
#define PWM_LED_PWMUDB_genblk8_stsreg__STATUS_REG CYREG_B0_UDB15_ST
#define PWM_LED_PWMUDB_sP8_pwmdp_u0__16BIT_A0_REG CYREG_B0_UDB12_13_A0
#define PWM_LED_PWMUDB_sP8_pwmdp_u0__16BIT_A1_REG CYREG_B0_UDB12_13_A1
#define PWM_LED_PWMUDB_sP8_pwmdp_u0__16BIT_D0_REG CYREG_B0_UDB12_13_D0
#define PWM_LED_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG CYREG_B0_UDB12_13_D1
#define PWM_LED_PWMUDB_sP8_pwmdp_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB12_13_ACTL
#define PWM_LED_PWMUDB_sP8_pwmdp_u0__16BIT_F0_REG CYREG_B0_UDB12_13_F0
#define PWM_LED_PWMUDB_sP8_pwmdp_u0__16BIT_F1_REG CYREG_B0_UDB12_13_F1
#define PWM_LED_PWMUDB_sP8_pwmdp_u0__A0_A1_REG CYREG_B0_UDB12_A0_A1
#define PWM_LED_PWMUDB_sP8_pwmdp_u0__A0_REG CYREG_B0_UDB12_A0
#define PWM_LED_PWMUDB_sP8_pwmdp_u0__A1_REG CYREG_B0_UDB12_A1
#define PWM_LED_PWMUDB_sP8_pwmdp_u0__D0_D1_REG CYREG_B0_UDB12_D0_D1
#define PWM_LED_PWMUDB_sP8_pwmdp_u0__D0_REG CYREG_B0_UDB12_D0
#define PWM_LED_PWMUDB_sP8_pwmdp_u0__D1_REG CYREG_B0_UDB12_D1
#define PWM_LED_PWMUDB_sP8_pwmdp_u0__DP_AUX_CTL_REG CYREG_B0_UDB12_ACTL
#define PWM_LED_PWMUDB_sP8_pwmdp_u0__F0_F1_REG CYREG_B0_UDB12_F0_F1
#define PWM_LED_PWMUDB_sP8_pwmdp_u0__F0_REG CYREG_B0_UDB12_F0
#define PWM_LED_PWMUDB_sP8_pwmdp_u0__F1_REG CYREG_B0_UDB12_F1

/* Relais */
#define Relais__0__INTTYPE CYREG_PICU2_INTTYPE1
#define Relais__0__MASK 0x02u
#define Relais__0__PC CYREG_PRT2_PC1
#define Relais__0__PORT 2u
#define Relais__0__SHIFT 1u
#define Relais__AG CYREG_PRT2_AG
#define Relais__AMUX CYREG_PRT2_AMUX
#define Relais__BIE CYREG_PRT2_BIE
#define Relais__BIT_MASK CYREG_PRT2_BIT_MASK
#define Relais__BYP CYREG_PRT2_BYP
#define Relais__CTL CYREG_PRT2_CTL
#define Relais__DM0 CYREG_PRT2_DM0
#define Relais__DM1 CYREG_PRT2_DM1
#define Relais__DM2 CYREG_PRT2_DM2
#define Relais__DR CYREG_PRT2_DR
#define Relais__INP_DIS CYREG_PRT2_INP_DIS
#define Relais__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define Relais__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define Relais__LCD_EN CYREG_PRT2_LCD_EN
#define Relais__MASK 0x02u
#define Relais__PORT 2u
#define Relais__PRT CYREG_PRT2_PRT
#define Relais__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define Relais__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define Relais__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define Relais__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define Relais__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define Relais__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define Relais__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define Relais__PS CYREG_PRT2_PS
#define Relais__SHIFT 1u
#define Relais__SLW CYREG_PRT2_SLW

/* Rx_SIG */
#define Rx_SIG__0__INTTYPE CYREG_PICU2_INTTYPE5
#define Rx_SIG__0__MASK 0x20u
#define Rx_SIG__0__PC CYREG_PRT2_PC5
#define Rx_SIG__0__PORT 2u
#define Rx_SIG__0__SHIFT 5u
#define Rx_SIG__AG CYREG_PRT2_AG
#define Rx_SIG__AMUX CYREG_PRT2_AMUX
#define Rx_SIG__BIE CYREG_PRT2_BIE
#define Rx_SIG__BIT_MASK CYREG_PRT2_BIT_MASK
#define Rx_SIG__BYP CYREG_PRT2_BYP
#define Rx_SIG__CTL CYREG_PRT2_CTL
#define Rx_SIG__DM0 CYREG_PRT2_DM0
#define Rx_SIG__DM1 CYREG_PRT2_DM1
#define Rx_SIG__DM2 CYREG_PRT2_DM2
#define Rx_SIG__DR CYREG_PRT2_DR
#define Rx_SIG__INP_DIS CYREG_PRT2_INP_DIS
#define Rx_SIG__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define Rx_SIG__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define Rx_SIG__LCD_EN CYREG_PRT2_LCD_EN
#define Rx_SIG__MASK 0x20u
#define Rx_SIG__PORT 2u
#define Rx_SIG__PRT CYREG_PRT2_PRT
#define Rx_SIG__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define Rx_SIG__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define Rx_SIG__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define Rx_SIG__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define Rx_SIG__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define Rx_SIG__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define Rx_SIG__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define Rx_SIG__PS CYREG_PRT2_PS
#define Rx_SIG__SHIFT 5u
#define Rx_SIG__SLW CYREG_PRT2_SLW

/* Tx_SIG */
#define Tx_SIG__0__INTTYPE CYREG_PICU2_INTTYPE6
#define Tx_SIG__0__MASK 0x40u
#define Tx_SIG__0__PC CYREG_PRT2_PC6
#define Tx_SIG__0__PORT 2u
#define Tx_SIG__0__SHIFT 6u
#define Tx_SIG__AG CYREG_PRT2_AG
#define Tx_SIG__AMUX CYREG_PRT2_AMUX
#define Tx_SIG__BIE CYREG_PRT2_BIE
#define Tx_SIG__BIT_MASK CYREG_PRT2_BIT_MASK
#define Tx_SIG__BYP CYREG_PRT2_BYP
#define Tx_SIG__CTL CYREG_PRT2_CTL
#define Tx_SIG__DM0 CYREG_PRT2_DM0
#define Tx_SIG__DM1 CYREG_PRT2_DM1
#define Tx_SIG__DM2 CYREG_PRT2_DM2
#define Tx_SIG__DR CYREG_PRT2_DR
#define Tx_SIG__INP_DIS CYREG_PRT2_INP_DIS
#define Tx_SIG__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define Tx_SIG__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define Tx_SIG__LCD_EN CYREG_PRT2_LCD_EN
#define Tx_SIG__MASK 0x40u
#define Tx_SIG__PORT 2u
#define Tx_SIG__PRT CYREG_PRT2_PRT
#define Tx_SIG__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define Tx_SIG__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define Tx_SIG__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define Tx_SIG__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define Tx_SIG__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define Tx_SIG__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define Tx_SIG__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define Tx_SIG__PS CYREG_PRT2_PS
#define Tx_SIG__SHIFT 6u
#define Tx_SIG__SLW CYREG_PRT2_SLW

/* UART_SIG_BUART */
#define UART_SIG_BUART_sRX_RxBitCounter__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB10_11_ACTL
#define UART_SIG_BUART_sRX_RxBitCounter__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB10_11_CTL
#define UART_SIG_BUART_sRX_RxBitCounter__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB10_11_CTL
#define UART_SIG_BUART_sRX_RxBitCounter__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB10_11_CTL
#define UART_SIG_BUART_sRX_RxBitCounter__16BIT_COUNT_COUNT_REG CYREG_B0_UDB10_11_CTL
#define UART_SIG_BUART_sRX_RxBitCounter__16BIT_MASK_MASK_REG CYREG_B0_UDB10_11_MSK
#define UART_SIG_BUART_sRX_RxBitCounter__16BIT_MASK_PERIOD_REG CYREG_B0_UDB10_11_MSK
#define UART_SIG_BUART_sRX_RxBitCounter__16BIT_PERIOD_MASK_REG CYREG_B0_UDB10_11_MSK
#define UART_SIG_BUART_sRX_RxBitCounter__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB10_11_MSK
#define UART_SIG_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG CYREG_B0_UDB10_ACTL
#define UART_SIG_BUART_sRX_RxBitCounter__CONTROL_REG CYREG_B0_UDB10_CTL
#define UART_SIG_BUART_sRX_RxBitCounter__CONTROL_ST_REG CYREG_B0_UDB10_ST_CTL
#define UART_SIG_BUART_sRX_RxBitCounter__COUNT_REG CYREG_B0_UDB10_CTL
#define UART_SIG_BUART_sRX_RxBitCounter__COUNT_ST_REG CYREG_B0_UDB10_ST_CTL
#define UART_SIG_BUART_sRX_RxBitCounter__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB10_MSK_ACTL
#define UART_SIG_BUART_sRX_RxBitCounter__PER_CTL_AUX_CTL_REG CYREG_B0_UDB10_MSK_ACTL
#define UART_SIG_BUART_sRX_RxBitCounter__PERIOD_REG CYREG_B0_UDB10_MSK
#define UART_SIG_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB10_11_ACTL
#define UART_SIG_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_REG CYREG_B0_UDB10_11_ST
#define UART_SIG_BUART_sRX_RxBitCounter_ST__MASK_REG CYREG_B0_UDB10_MSK
#define UART_SIG_BUART_sRX_RxBitCounter_ST__MASK_ST_AUX_CTL_REG CYREG_B0_UDB10_MSK_ACTL
#define UART_SIG_BUART_sRX_RxBitCounter_ST__PER_ST_AUX_CTL_REG CYREG_B0_UDB10_MSK_ACTL
#define UART_SIG_BUART_sRX_RxBitCounter_ST__STATUS_AUX_CTL_REG CYREG_B0_UDB10_ACTL
#define UART_SIG_BUART_sRX_RxBitCounter_ST__STATUS_CNT_REG CYREG_B0_UDB10_ST_CTL
#define UART_SIG_BUART_sRX_RxBitCounter_ST__STATUS_CONTROL_REG CYREG_B0_UDB10_ST_CTL
#define UART_SIG_BUART_sRX_RxBitCounter_ST__STATUS_REG CYREG_B0_UDB10_ST
#define UART_SIG_BUART_sRX_RxShifter_u0__16BIT_A0_REG CYREG_B0_UDB14_15_A0
#define UART_SIG_BUART_sRX_RxShifter_u0__16BIT_A1_REG CYREG_B0_UDB14_15_A1
#define UART_SIG_BUART_sRX_RxShifter_u0__16BIT_D0_REG CYREG_B0_UDB14_15_D0
#define UART_SIG_BUART_sRX_RxShifter_u0__16BIT_D1_REG CYREG_B0_UDB14_15_D1
#define UART_SIG_BUART_sRX_RxShifter_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB14_15_ACTL
#define UART_SIG_BUART_sRX_RxShifter_u0__16BIT_F0_REG CYREG_B0_UDB14_15_F0
#define UART_SIG_BUART_sRX_RxShifter_u0__16BIT_F1_REG CYREG_B0_UDB14_15_F1
#define UART_SIG_BUART_sRX_RxShifter_u0__A0_A1_REG CYREG_B0_UDB14_A0_A1
#define UART_SIG_BUART_sRX_RxShifter_u0__A0_REG CYREG_B0_UDB14_A0
#define UART_SIG_BUART_sRX_RxShifter_u0__A1_REG CYREG_B0_UDB14_A1
#define UART_SIG_BUART_sRX_RxShifter_u0__D0_D1_REG CYREG_B0_UDB14_D0_D1
#define UART_SIG_BUART_sRX_RxShifter_u0__D0_REG CYREG_B0_UDB14_D0
#define UART_SIG_BUART_sRX_RxShifter_u0__D1_REG CYREG_B0_UDB14_D1
#define UART_SIG_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG CYREG_B0_UDB14_ACTL
#define UART_SIG_BUART_sRX_RxShifter_u0__F0_F1_REG CYREG_B0_UDB14_F0_F1
#define UART_SIG_BUART_sRX_RxShifter_u0__F0_REG CYREG_B0_UDB14_F0
#define UART_SIG_BUART_sRX_RxShifter_u0__F1_REG CYREG_B0_UDB14_F1
#define UART_SIG_BUART_sRX_RxSts__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB13_14_ACTL
#define UART_SIG_BUART_sRX_RxSts__16BIT_STATUS_REG CYREG_B0_UDB13_14_ST
#define UART_SIG_BUART_sRX_RxSts__3__MASK 0x08u
#define UART_SIG_BUART_sRX_RxSts__3__POS 3
#define UART_SIG_BUART_sRX_RxSts__4__MASK 0x10u
#define UART_SIG_BUART_sRX_RxSts__4__POS 4
#define UART_SIG_BUART_sRX_RxSts__5__MASK 0x20u
#define UART_SIG_BUART_sRX_RxSts__5__POS 5
#define UART_SIG_BUART_sRX_RxSts__MASK 0x38u
#define UART_SIG_BUART_sRX_RxSts__MASK_REG CYREG_B0_UDB13_MSK
#define UART_SIG_BUART_sRX_RxSts__STATUS_AUX_CTL_REG CYREG_B0_UDB13_ACTL
#define UART_SIG_BUART_sRX_RxSts__STATUS_REG CYREG_B0_UDB13_ST
#define UART_SIG_BUART_sTX_sCLOCK_TxBitClkGen__A0_A1_REG CYREG_B0_UDB15_A0_A1
#define UART_SIG_BUART_sTX_sCLOCK_TxBitClkGen__A0_REG CYREG_B0_UDB15_A0
#define UART_SIG_BUART_sTX_sCLOCK_TxBitClkGen__A1_REG CYREG_B0_UDB15_A1
#define UART_SIG_BUART_sTX_sCLOCK_TxBitClkGen__D0_D1_REG CYREG_B0_UDB15_D0_D1
#define UART_SIG_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG CYREG_B0_UDB15_D0
#define UART_SIG_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG CYREG_B0_UDB15_D1
#define UART_SIG_BUART_sTX_sCLOCK_TxBitClkGen__DP_AUX_CTL_REG CYREG_B0_UDB15_ACTL
#define UART_SIG_BUART_sTX_sCLOCK_TxBitClkGen__F0_F1_REG CYREG_B0_UDB15_F0_F1
#define UART_SIG_BUART_sTX_sCLOCK_TxBitClkGen__F0_REG CYREG_B0_UDB15_F0
#define UART_SIG_BUART_sTX_sCLOCK_TxBitClkGen__F1_REG CYREG_B0_UDB15_F1
#define UART_SIG_BUART_sTX_sCLOCK_TxBitClkGen__MSK_DP_AUX_CTL_REG CYREG_B0_UDB15_MSK_ACTL
#define UART_SIG_BUART_sTX_sCLOCK_TxBitClkGen__PER_DP_AUX_CTL_REG CYREG_B0_UDB15_MSK_ACTL
#define UART_SIG_BUART_sTX_TxShifter_u0__16BIT_A0_REG CYREG_B0_UDB11_12_A0
#define UART_SIG_BUART_sTX_TxShifter_u0__16BIT_A1_REG CYREG_B0_UDB11_12_A1
#define UART_SIG_BUART_sTX_TxShifter_u0__16BIT_D0_REG CYREG_B0_UDB11_12_D0
#define UART_SIG_BUART_sTX_TxShifter_u0__16BIT_D1_REG CYREG_B0_UDB11_12_D1
#define UART_SIG_BUART_sTX_TxShifter_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB11_12_ACTL
#define UART_SIG_BUART_sTX_TxShifter_u0__16BIT_F0_REG CYREG_B0_UDB11_12_F0
#define UART_SIG_BUART_sTX_TxShifter_u0__16BIT_F1_REG CYREG_B0_UDB11_12_F1
#define UART_SIG_BUART_sTX_TxShifter_u0__A0_A1_REG CYREG_B0_UDB11_A0_A1
#define UART_SIG_BUART_sTX_TxShifter_u0__A0_REG CYREG_B0_UDB11_A0
#define UART_SIG_BUART_sTX_TxShifter_u0__A1_REG CYREG_B0_UDB11_A1
#define UART_SIG_BUART_sTX_TxShifter_u0__D0_D1_REG CYREG_B0_UDB11_D0_D1
#define UART_SIG_BUART_sTX_TxShifter_u0__D0_REG CYREG_B0_UDB11_D0
#define UART_SIG_BUART_sTX_TxShifter_u0__D1_REG CYREG_B0_UDB11_D1
#define UART_SIG_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG CYREG_B0_UDB11_ACTL
#define UART_SIG_BUART_sTX_TxShifter_u0__F0_F1_REG CYREG_B0_UDB11_F0_F1
#define UART_SIG_BUART_sTX_TxShifter_u0__F0_REG CYREG_B0_UDB11_F0
#define UART_SIG_BUART_sTX_TxShifter_u0__F1_REG CYREG_B0_UDB11_F1
#define UART_SIG_BUART_sTX_TxSts__0__MASK 0x01u
#define UART_SIG_BUART_sTX_TxSts__0__POS 0
#define UART_SIG_BUART_sTX_TxSts__1__MASK 0x02u
#define UART_SIG_BUART_sTX_TxSts__1__POS 1
#define UART_SIG_BUART_sTX_TxSts__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB12_13_ACTL
#define UART_SIG_BUART_sTX_TxSts__16BIT_STATUS_REG CYREG_B0_UDB12_13_ST
#define UART_SIG_BUART_sTX_TxSts__2__MASK 0x04u
#define UART_SIG_BUART_sTX_TxSts__2__POS 2
#define UART_SIG_BUART_sTX_TxSts__3__MASK 0x08u
#define UART_SIG_BUART_sTX_TxSts__3__POS 3
#define UART_SIG_BUART_sTX_TxSts__MASK 0x0Fu
#define UART_SIG_BUART_sTX_TxSts__MASK_REG CYREG_B0_UDB12_MSK
#define UART_SIG_BUART_sTX_TxSts__STATUS_AUX_CTL_REG CYREG_B0_UDB12_ACTL
#define UART_SIG_BUART_sTX_TxSts__STATUS_REG CYREG_B0_UDB12_ST

/* UART_SIG_IntClock */
#define UART_SIG_IntClock__CFG0 CYREG_CLKDIST_DCFG1_CFG0
#define UART_SIG_IntClock__CFG1 CYREG_CLKDIST_DCFG1_CFG1
#define UART_SIG_IntClock__CFG2 CYREG_CLKDIST_DCFG1_CFG2
#define UART_SIG_IntClock__CFG2_SRC_SEL_MASK 0x07u
#define UART_SIG_IntClock__INDEX 0x01u
#define UART_SIG_IntClock__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define UART_SIG_IntClock__PM_ACT_MSK 0x02u
#define UART_SIG_IntClock__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define UART_SIG_IntClock__PM_STBY_MSK 0x02u

/* UART_SIG_RXInternalInterrupt */
#define UART_SIG_RXInternalInterrupt__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define UART_SIG_RXInternalInterrupt__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define UART_SIG_RXInternalInterrupt__INTC_MASK 0x01u
#define UART_SIG_RXInternalInterrupt__INTC_NUMBER 0u
#define UART_SIG_RXInternalInterrupt__INTC_PRIOR_NUM 7u
#define UART_SIG_RXInternalInterrupt__INTC_PRIOR_REG CYREG_NVIC_PRI_0
#define UART_SIG_RXInternalInterrupt__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define UART_SIG_RXInternalInterrupt__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* VBAT1 */
#define VBAT1__0__INTTYPE CYREG_PICU15_INTTYPE3
#define VBAT1__0__MASK 0x08u
#define VBAT1__0__PC CYREG_IO_PC_PRT15_PC3
#define VBAT1__0__PORT 15u
#define VBAT1__0__SHIFT 3u
#define VBAT1__AG CYREG_PRT15_AG
#define VBAT1__AMUX CYREG_PRT15_AMUX
#define VBAT1__BIE CYREG_PRT15_BIE
#define VBAT1__BIT_MASK CYREG_PRT15_BIT_MASK
#define VBAT1__BYP CYREG_PRT15_BYP
#define VBAT1__CTL CYREG_PRT15_CTL
#define VBAT1__DM0 CYREG_PRT15_DM0
#define VBAT1__DM1 CYREG_PRT15_DM1
#define VBAT1__DM2 CYREG_PRT15_DM2
#define VBAT1__DR CYREG_PRT15_DR
#define VBAT1__INP_DIS CYREG_PRT15_INP_DIS
#define VBAT1__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU15_BASE
#define VBAT1__LCD_COM_SEG CYREG_PRT15_LCD_COM_SEG
#define VBAT1__LCD_EN CYREG_PRT15_LCD_EN
#define VBAT1__MASK 0x08u
#define VBAT1__PORT 15u
#define VBAT1__PRT CYREG_PRT15_PRT
#define VBAT1__PRTDSI__CAPS_SEL CYREG_PRT15_CAPS_SEL
#define VBAT1__PRTDSI__DBL_SYNC_IN CYREG_PRT15_DBL_SYNC_IN
#define VBAT1__PRTDSI__OE_SEL0 CYREG_PRT15_OE_SEL0
#define VBAT1__PRTDSI__OE_SEL1 CYREG_PRT15_OE_SEL1
#define VBAT1__PRTDSI__OUT_SEL0 CYREG_PRT15_OUT_SEL0
#define VBAT1__PRTDSI__OUT_SEL1 CYREG_PRT15_OUT_SEL1
#define VBAT1__PRTDSI__SYNC_OUT CYREG_PRT15_SYNC_OUT
#define VBAT1__PS CYREG_PRT15_PS
#define VBAT1__SHIFT 3u
#define VBAT1__SLW CYREG_PRT15_SLW

/* VBAT2 */
#define VBAT2__0__INTTYPE CYREG_PICU15_INTTYPE2
#define VBAT2__0__MASK 0x04u
#define VBAT2__0__PC CYREG_IO_PC_PRT15_PC2
#define VBAT2__0__PORT 15u
#define VBAT2__0__SHIFT 2u
#define VBAT2__AG CYREG_PRT15_AG
#define VBAT2__AMUX CYREG_PRT15_AMUX
#define VBAT2__BIE CYREG_PRT15_BIE
#define VBAT2__BIT_MASK CYREG_PRT15_BIT_MASK
#define VBAT2__BYP CYREG_PRT15_BYP
#define VBAT2__CTL CYREG_PRT15_CTL
#define VBAT2__DM0 CYREG_PRT15_DM0
#define VBAT2__DM1 CYREG_PRT15_DM1
#define VBAT2__DM2 CYREG_PRT15_DM2
#define VBAT2__DR CYREG_PRT15_DR
#define VBAT2__INP_DIS CYREG_PRT15_INP_DIS
#define VBAT2__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU15_BASE
#define VBAT2__LCD_COM_SEG CYREG_PRT15_LCD_COM_SEG
#define VBAT2__LCD_EN CYREG_PRT15_LCD_EN
#define VBAT2__MASK 0x04u
#define VBAT2__PORT 15u
#define VBAT2__PRT CYREG_PRT15_PRT
#define VBAT2__PRTDSI__CAPS_SEL CYREG_PRT15_CAPS_SEL
#define VBAT2__PRTDSI__DBL_SYNC_IN CYREG_PRT15_DBL_SYNC_IN
#define VBAT2__PRTDSI__OE_SEL0 CYREG_PRT15_OE_SEL0
#define VBAT2__PRTDSI__OE_SEL1 CYREG_PRT15_OE_SEL1
#define VBAT2__PRTDSI__OUT_SEL0 CYREG_PRT15_OUT_SEL0
#define VBAT2__PRTDSI__OUT_SEL1 CYREG_PRT15_OUT_SEL1
#define VBAT2__PRTDSI__SYNC_OUT CYREG_PRT15_SYNC_OUT
#define VBAT2__PS CYREG_PRT15_PS
#define VBAT2__SHIFT 2u
#define VBAT2__SLW CYREG_PRT15_SLW

/* VCHAR */
#define VCHAR__0__INTTYPE CYREG_PICU15_INTTYPE1
#define VCHAR__0__MASK 0x02u
#define VCHAR__0__PC CYREG_IO_PC_PRT15_PC1
#define VCHAR__0__PORT 15u
#define VCHAR__0__SHIFT 1u
#define VCHAR__AG CYREG_PRT15_AG
#define VCHAR__AMUX CYREG_PRT15_AMUX
#define VCHAR__BIE CYREG_PRT15_BIE
#define VCHAR__BIT_MASK CYREG_PRT15_BIT_MASK
#define VCHAR__BYP CYREG_PRT15_BYP
#define VCHAR__CTL CYREG_PRT15_CTL
#define VCHAR__DM0 CYREG_PRT15_DM0
#define VCHAR__DM1 CYREG_PRT15_DM1
#define VCHAR__DM2 CYREG_PRT15_DM2
#define VCHAR__DR CYREG_PRT15_DR
#define VCHAR__INP_DIS CYREG_PRT15_INP_DIS
#define VCHAR__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU15_BASE
#define VCHAR__LCD_COM_SEG CYREG_PRT15_LCD_COM_SEG
#define VCHAR__LCD_EN CYREG_PRT15_LCD_EN
#define VCHAR__MASK 0x02u
#define VCHAR__PORT 15u
#define VCHAR__PRT CYREG_PRT15_PRT
#define VCHAR__PRTDSI__CAPS_SEL CYREG_PRT15_CAPS_SEL
#define VCHAR__PRTDSI__DBL_SYNC_IN CYREG_PRT15_DBL_SYNC_IN
#define VCHAR__PRTDSI__OE_SEL0 CYREG_PRT15_OE_SEL0
#define VCHAR__PRTDSI__OE_SEL1 CYREG_PRT15_OE_SEL1
#define VCHAR__PRTDSI__OUT_SEL0 CYREG_PRT15_OUT_SEL0
#define VCHAR__PRTDSI__OUT_SEL1 CYREG_PRT15_OUT_SEL1
#define VCHAR__PRTDSI__SYNC_OUT CYREG_PRT15_SYNC_OUT
#define VCHAR__PS CYREG_PRT15_PS
#define VCHAR__SHIFT 1u
#define VCHAR__SLW CYREG_PRT15_SLW

/* VPAN */
#define VPAN__0__INTTYPE CYREG_PICU15_INTTYPE0
#define VPAN__0__MASK 0x01u
#define VPAN__0__PC CYREG_IO_PC_PRT15_PC0
#define VPAN__0__PORT 15u
#define VPAN__0__SHIFT 0u
#define VPAN__AG CYREG_PRT15_AG
#define VPAN__AMUX CYREG_PRT15_AMUX
#define VPAN__BIE CYREG_PRT15_BIE
#define VPAN__BIT_MASK CYREG_PRT15_BIT_MASK
#define VPAN__BYP CYREG_PRT15_BYP
#define VPAN__CTL CYREG_PRT15_CTL
#define VPAN__DM0 CYREG_PRT15_DM0
#define VPAN__DM1 CYREG_PRT15_DM1
#define VPAN__DM2 CYREG_PRT15_DM2
#define VPAN__DR CYREG_PRT15_DR
#define VPAN__INP_DIS CYREG_PRT15_INP_DIS
#define VPAN__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU15_BASE
#define VPAN__LCD_COM_SEG CYREG_PRT15_LCD_COM_SEG
#define VPAN__LCD_EN CYREG_PRT15_LCD_EN
#define VPAN__MASK 0x01u
#define VPAN__PORT 15u
#define VPAN__PRT CYREG_PRT15_PRT
#define VPAN__PRTDSI__CAPS_SEL CYREG_PRT15_CAPS_SEL
#define VPAN__PRTDSI__DBL_SYNC_IN CYREG_PRT15_DBL_SYNC_IN
#define VPAN__PRTDSI__OE_SEL0 CYREG_PRT15_OE_SEL0
#define VPAN__PRTDSI__OE_SEL1 CYREG_PRT15_OE_SEL1
#define VPAN__PRTDSI__OUT_SEL0 CYREG_PRT15_OUT_SEL0
#define VPAN__PRTDSI__OUT_SEL1 CYREG_PRT15_OUT_SEL1
#define VPAN__PRTDSI__SYNC_OUT CYREG_PRT15_SYNC_OUT
#define VPAN__PS CYREG_PRT15_PS
#define VPAN__SHIFT 0u
#define VPAN__SLW CYREG_PRT15_SLW

/* isr_1 */
#define isr_1__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define isr_1__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define isr_1__INTC_MASK 0x02u
#define isr_1__INTC_NUMBER 1u
#define isr_1__INTC_PRIOR_NUM 7u
#define isr_1__INTC_PRIOR_REG CYREG_NVIC_PRI_1
#define isr_1__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define isr_1__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* isr_rbat */
#define isr_rbat__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define isr_rbat__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define isr_rbat__INTC_MASK 0x04u
#define isr_rbat__INTC_NUMBER 2u
#define isr_rbat__INTC_PRIOR_NUM 7u
#define isr_rbat__INTC_PRIOR_REG CYREG_NVIC_PRI_2
#define isr_rbat__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define isr_rbat__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* isr_rch */
#define isr_rch__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define isr_rch__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define isr_rch__INTC_MASK 0x08u
#define isr_rch__INTC_NUMBER 3u
#define isr_rch__INTC_PRIOR_NUM 7u
#define isr_rch__INTC_PRIOR_REG CYREG_NVIC_PRI_3
#define isr_rch__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define isr_rch__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* isr_vbat */
#define isr_vbat__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define isr_vbat__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define isr_vbat__INTC_MASK 0x10u
#define isr_vbat__INTC_NUMBER 4u
#define isr_vbat__INTC_PRIOR_NUM 7u
#define isr_vbat__INTC_PRIOR_REG CYREG_NVIC_PRI_4
#define isr_vbat__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define isr_vbat__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* isr_vpan */
#define isr_vpan__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define isr_vpan__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define isr_vpan__INTC_MASK 0x20u
#define isr_vpan__INTC_NUMBER 5u
#define isr_vpan__INTC_PRIOR_NUM 7u
#define isr_vpan__INTC_PRIOR_REG CYREG_NVIC_PRI_5
#define isr_vpan__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define isr_vpan__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* niveau */
#define niveau__0__INTTYPE CYREG_PICU12_INTTYPE0
#define niveau__0__MASK 0x01u
#define niveau__0__PC CYREG_PRT12_PC0
#define niveau__0__PORT 12u
#define niveau__0__SHIFT 0u
#define niveau__1__INTTYPE CYREG_PICU12_INTTYPE1
#define niveau__1__MASK 0x02u
#define niveau__1__PC CYREG_PRT12_PC1
#define niveau__1__PORT 12u
#define niveau__1__SHIFT 1u
#define niveau__2__INTTYPE CYREG_PICU12_INTTYPE2
#define niveau__2__MASK 0x04u
#define niveau__2__PC CYREG_PRT12_PC2
#define niveau__2__PORT 12u
#define niveau__2__SHIFT 2u
#define niveau__3__INTTYPE CYREG_PICU12_INTTYPE3
#define niveau__3__MASK 0x08u
#define niveau__3__PC CYREG_PRT12_PC3
#define niveau__3__PORT 12u
#define niveau__3__SHIFT 3u
#define niveau__4__INTTYPE CYREG_PICU12_INTTYPE4
#define niveau__4__MASK 0x10u
#define niveau__4__PC CYREG_PRT12_PC4
#define niveau__4__PORT 12u
#define niveau__4__SHIFT 4u
#define niveau__5__INTTYPE CYREG_PICU12_INTTYPE5
#define niveau__5__MASK 0x20u
#define niveau__5__PC CYREG_PRT12_PC5
#define niveau__5__PORT 12u
#define niveau__5__SHIFT 5u
#define niveau__6__INTTYPE CYREG_PICU12_INTTYPE6
#define niveau__6__MASK 0x40u
#define niveau__6__PC CYREG_PRT12_PC6
#define niveau__6__PORT 12u
#define niveau__6__SHIFT 6u
#define niveau__7__INTTYPE CYREG_PICU12_INTTYPE7
#define niveau__7__MASK 0x80u
#define niveau__7__PC CYREG_PRT12_PC7
#define niveau__7__PORT 12u
#define niveau__7__SHIFT 7u
#define niveau__AG CYREG_PRT12_AG
#define niveau__BIE CYREG_PRT12_BIE
#define niveau__BIT_MASK CYREG_PRT12_BIT_MASK
#define niveau__BYP CYREG_PRT12_BYP
#define niveau__DM0 CYREG_PRT12_DM0
#define niveau__DM1 CYREG_PRT12_DM1
#define niveau__DM2 CYREG_PRT12_DM2
#define niveau__DR CYREG_PRT12_DR
#define niveau__INP_DIS CYREG_PRT12_INP_DIS
#define niveau__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU12_BASE
#define niveau__MASK 0xFFu
#define niveau__PORT 12u
#define niveau__PRT CYREG_PRT12_PRT
#define niveau__PRTDSI__DBL_SYNC_IN CYREG_PRT12_DBL_SYNC_IN
#define niveau__PRTDSI__OE_SEL0 CYREG_PRT12_OE_SEL0
#define niveau__PRTDSI__OE_SEL1 CYREG_PRT12_OE_SEL1
#define niveau__PRTDSI__OUT_SEL0 CYREG_PRT12_OUT_SEL0
#define niveau__PRTDSI__OUT_SEL1 CYREG_PRT12_OUT_SEL1
#define niveau__PRTDSI__SYNC_OUT CYREG_PRT12_SYNC_OUT
#define niveau__PS CYREG_PRT12_PS
#define niveau__SHIFT 0u
#define niveau__SIO_CFG CYREG_PRT12_SIO_CFG
#define niveau__SIO_DIFF CYREG_PRT12_SIO_DIFF
#define niveau__SIO_HYST_EN CYREG_PRT12_SIO_HYST_EN
#define niveau__SIO_REG_HIFREQ CYREG_PRT12_SIO_REG_HIFREQ
#define niveau__SLW CYREG_PRT12_SLW

/* Miscellaneous */
#define BCLK__BUS_CLK__HZ 24000000U
#define BCLK__BUS_CLK__KHZ 24000U
#define BCLK__BUS_CLK__MHZ 24U
#define CY_PROJECT_NAME "transmi_cartes"
#define CY_VERSION "PSoC Creator  4.1 Update 1"
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PSOC4A 16u
#define CYDEV_CHIP_DIE_PSOC5LP 2u
#define CYDEV_CHIP_DIE_PSOC5TM 3u
#define CYDEV_CHIP_DIE_TMA4 4u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_FM0P 5u
#define CYDEV_CHIP_FAMILY_FM3 6u
#define CYDEV_CHIP_FAMILY_FM4 7u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_PSOC6 4u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC5
#define CYDEV_CHIP_JTAG_ID 0x2E161069u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 16u
#define CYDEV_CHIP_MEMBER_4D 12u
#define CYDEV_CHIP_MEMBER_4E 6u
#define CYDEV_CHIP_MEMBER_4F 17u
#define CYDEV_CHIP_MEMBER_4G 4u
#define CYDEV_CHIP_MEMBER_4H 15u
#define CYDEV_CHIP_MEMBER_4I 21u
#define CYDEV_CHIP_MEMBER_4J 13u
#define CYDEV_CHIP_MEMBER_4K 14u
#define CYDEV_CHIP_MEMBER_4L 20u
#define CYDEV_CHIP_MEMBER_4M 19u
#define CYDEV_CHIP_MEMBER_4N 9u
#define CYDEV_CHIP_MEMBER_4O 7u
#define CYDEV_CHIP_MEMBER_4P 18u
#define CYDEV_CHIP_MEMBER_4Q 11u
#define CYDEV_CHIP_MEMBER_4R 8u
#define CYDEV_CHIP_MEMBER_4S 10u
#define CYDEV_CHIP_MEMBER_4U 5u
#define CYDEV_CHIP_MEMBER_5A 3u
#define CYDEV_CHIP_MEMBER_5B 2u
#define CYDEV_CHIP_MEMBER_6A 22u
#define CYDEV_CHIP_MEMBER_FM3 26u
#define CYDEV_CHIP_MEMBER_FM4 27u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 23u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 24u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 25u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_5B
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES0 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES1 1u
#define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4O_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4P_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4R_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4S_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_6A_NO_UDB 0u
#define CYDEV_CHIP_REVISION_6A_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_5B_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_FASTBOOT_ENABLED 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_DMA 0
#define CYDEV_CONFIGURATION_ECC 1
#define CYDEV_CONFIGURATION_IMOENABLED CYDEV_CONFIG_FASTBOOT_ENABLED
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_ENABLE_MASK 0x20u
#define CYDEV_DEBUG_ENABLE_REGISTER CYREG_MLOGIC_DEBUG
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_JTAG_4 1
#define CYDEV_DEBUGGING_DPS_JTAG_5 0
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD
#define CYDEV_DEBUGGING_DPS_SWD_SWV 6
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DEBUGGING_XRES 0
#define CYDEV_DMA_CHANNELS_AVAILABLE 24u
#define CYDEV_ECC_ENABLE 0
#define CYDEV_HEAP_SIZE 0x80
#define CYDEV_INSTRUCT_CACHE_ENABLED 1
#define CYDEV_INTR_RISING 0x0000003Fu
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_PROTECTION_ENABLE 0
#define CYDEV_STACK_SIZE 0x0800
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 0
#define CYDEV_VDDA 5.0
#define CYDEV_VDDA_MV 5000
#define CYDEV_VDDD 5.0
#define CYDEV_VDDD_MV 5000
#define CYDEV_VDDIO0 5.0
#define CYDEV_VDDIO0_MV 5000
#define CYDEV_VDDIO1 5.0
#define CYDEV_VDDIO1_MV 5000
#define CYDEV_VDDIO2 5.0
#define CYDEV_VDDIO2_MV 5000
#define CYDEV_VDDIO3 5.0
#define CYDEV_VDDIO3_MV 5000
#define CYDEV_VIO0 5.0
#define CYDEV_VIO0_MV 5000
#define CYDEV_VIO1 5.0
#define CYDEV_VIO1_MV 5000
#define CYDEV_VIO2 5.0
#define CYDEV_VIO2_MV 5000
#define CYDEV_VIO3 5.0
#define CYDEV_VIO3_MV 5000
#define CYIPBLOCK_ARM_CM3_VERSION 0
#define CYIPBLOCK_P3_ANAIF_VERSION 0
#define CYIPBLOCK_P3_CAN_VERSION 0
#define CYIPBLOCK_P3_CAPSENSE_VERSION 0
#define CYIPBLOCK_P3_COMP_VERSION 0
#define CYIPBLOCK_P3_DECIMATOR_VERSION 0
#define CYIPBLOCK_P3_DFB_VERSION 0
#define CYIPBLOCK_P3_DMA_VERSION 0
#define CYIPBLOCK_P3_DRQ_VERSION 0
#define CYIPBLOCK_P3_DSM_VERSION 0
#define CYIPBLOCK_P3_EMIF_VERSION 0
#define CYIPBLOCK_P3_I2C_VERSION 0
#define CYIPBLOCK_P3_LCD_VERSION 0
#define CYIPBLOCK_P3_LPF_VERSION 0
#define CYIPBLOCK_P3_OPAMP_VERSION 0
#define CYIPBLOCK_P3_PM_VERSION 0
#define CYIPBLOCK_P3_SCCT_VERSION 0
#define CYIPBLOCK_P3_TIMER_VERSION 0
#define CYIPBLOCK_P3_USB_VERSION 0
#define CYIPBLOCK_P3_VIDAC_VERSION 0
#define CYIPBLOCK_P3_VREF_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 0
#define CYIPBLOCK_S8_IRQ_VERSION 0
#define CYIPBLOCK_S8_SAR_VERSION 0
#define CYIPBLOCK_S8_SIO_VERSION 0
#define CYIPBLOCK_S8_UDB_VERSION 0
#define DMA_CHANNELS_USED__MASK0 0x00000000u
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
