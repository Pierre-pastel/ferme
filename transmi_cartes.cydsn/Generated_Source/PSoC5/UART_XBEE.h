/*******************************************************************************
* File Name: UART_XBEE.h
* Version 2.50
*
* Description:
*  Contains the function prototypes and constants available to the UART
*  user module.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/


#if !defined(CY_UART_UART_XBEE_H)
#define CY_UART_UART_XBEE_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */


/***************************************
* Conditional Compilation Parameters
***************************************/

#define UART_XBEE_RX_ENABLED                     (1u)
#define UART_XBEE_TX_ENABLED                     (1u)
#define UART_XBEE_HD_ENABLED                     (0u)
#define UART_XBEE_RX_INTERRUPT_ENABLED           (0u)
#define UART_XBEE_TX_INTERRUPT_ENABLED           (0u)
#define UART_XBEE_INTERNAL_CLOCK_USED            (1u)
#define UART_XBEE_RXHW_ADDRESS_ENABLED           (0u)
#define UART_XBEE_OVER_SAMPLE_COUNT              (8u)
#define UART_XBEE_PARITY_TYPE                    (0u)
#define UART_XBEE_PARITY_TYPE_SW                 (0u)
#define UART_XBEE_BREAK_DETECT                   (0u)
#define UART_XBEE_BREAK_BITS_TX                  (13u)
#define UART_XBEE_BREAK_BITS_RX                  (13u)
#define UART_XBEE_TXCLKGEN_DP                    (1u)
#define UART_XBEE_USE23POLLING                   (1u)
#define UART_XBEE_FLOW_CONTROL                   (0u)
#define UART_XBEE_CLK_FREQ                       (0u)
#define UART_XBEE_TX_BUFFER_SIZE                 (4u)
#define UART_XBEE_RX_BUFFER_SIZE                 (4u)

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component UART_v2_50 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */

#if defined(UART_XBEE_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG)
    #define UART_XBEE_CONTROL_REG_REMOVED            (0u)
#else
    #define UART_XBEE_CONTROL_REG_REMOVED            (1u)
#endif /* End UART_XBEE_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG */


/***************************************
*      Data Structure Definition
***************************************/

/* Sleep Mode API Support */
typedef struct UART_XBEE_backupStruct_
{
    uint8 enableState;

    #if(UART_XBEE_CONTROL_REG_REMOVED == 0u)
        uint8 cr;
    #endif /* End UART_XBEE_CONTROL_REG_REMOVED */

} UART_XBEE_BACKUP_STRUCT;


/***************************************
*       Function Prototypes
***************************************/

void UART_XBEE_Start(void) ;
void UART_XBEE_Stop(void) ;
uint8 UART_XBEE_ReadControlRegister(void) ;
void UART_XBEE_WriteControlRegister(uint8 control) ;

void UART_XBEE_Init(void) ;
void UART_XBEE_Enable(void) ;
void UART_XBEE_SaveConfig(void) ;
void UART_XBEE_RestoreConfig(void) ;
void UART_XBEE_Sleep(void) ;
void UART_XBEE_Wakeup(void) ;

/* Only if RX is enabled */
#if( (UART_XBEE_RX_ENABLED) || (UART_XBEE_HD_ENABLED) )

    #if (UART_XBEE_RX_INTERRUPT_ENABLED)
        #define UART_XBEE_EnableRxInt()  CyIntEnable (UART_XBEE_RX_VECT_NUM)
        #define UART_XBEE_DisableRxInt() CyIntDisable(UART_XBEE_RX_VECT_NUM)
        CY_ISR_PROTO(UART_XBEE_RXISR);
    #endif /* UART_XBEE_RX_INTERRUPT_ENABLED */

    void UART_XBEE_SetRxAddressMode(uint8 addressMode)
                                                           ;
    void UART_XBEE_SetRxAddress1(uint8 address) ;
    void UART_XBEE_SetRxAddress2(uint8 address) ;

    void  UART_XBEE_SetRxInterruptMode(uint8 intSrc) ;
    uint8 UART_XBEE_ReadRxData(void) ;
    uint8 UART_XBEE_ReadRxStatus(void) ;
    uint8 UART_XBEE_GetChar(void) ;
    uint16 UART_XBEE_GetByte(void) ;
    uint8 UART_XBEE_GetRxBufferSize(void)
                                                            ;
    void UART_XBEE_ClearRxBuffer(void) ;

    /* Obsolete functions, defines for backward compatible */
    #define UART_XBEE_GetRxInterruptSource   UART_XBEE_ReadRxStatus

#endif /* End (UART_XBEE_RX_ENABLED) || (UART_XBEE_HD_ENABLED) */

/* Only if TX is enabled */
#if(UART_XBEE_TX_ENABLED || UART_XBEE_HD_ENABLED)

    #if(UART_XBEE_TX_INTERRUPT_ENABLED)
        #define UART_XBEE_EnableTxInt()  CyIntEnable (UART_XBEE_TX_VECT_NUM)
        #define UART_XBEE_DisableTxInt() CyIntDisable(UART_XBEE_TX_VECT_NUM)
        #define UART_XBEE_SetPendingTxInt() CyIntSetPending(UART_XBEE_TX_VECT_NUM)
        #define UART_XBEE_ClearPendingTxInt() CyIntClearPending(UART_XBEE_TX_VECT_NUM)
        CY_ISR_PROTO(UART_XBEE_TXISR);
    #endif /* UART_XBEE_TX_INTERRUPT_ENABLED */

    void UART_XBEE_SetTxInterruptMode(uint8 intSrc) ;
    void UART_XBEE_WriteTxData(uint8 txDataByte) ;
    uint8 UART_XBEE_ReadTxStatus(void) ;
    void UART_XBEE_PutChar(uint8 txDataByte) ;
    void UART_XBEE_PutString(const char8 string[]) ;
    void UART_XBEE_PutArray(const uint8 string[], uint8 byteCount)
                                                            ;
    void UART_XBEE_PutCRLF(uint8 txDataByte) ;
    void UART_XBEE_ClearTxBuffer(void) ;
    void UART_XBEE_SetTxAddressMode(uint8 addressMode) ;
    void UART_XBEE_SendBreak(uint8 retMode) ;
    uint8 UART_XBEE_GetTxBufferSize(void)
                                                            ;
    /* Obsolete functions, defines for backward compatible */
    #define UART_XBEE_PutStringConst         UART_XBEE_PutString
    #define UART_XBEE_PutArrayConst          UART_XBEE_PutArray
    #define UART_XBEE_GetTxInterruptSource   UART_XBEE_ReadTxStatus

#endif /* End UART_XBEE_TX_ENABLED || UART_XBEE_HD_ENABLED */

#if(UART_XBEE_HD_ENABLED)
    void UART_XBEE_LoadRxConfig(void) ;
    void UART_XBEE_LoadTxConfig(void) ;
#endif /* End UART_XBEE_HD_ENABLED */


/* Communication bootloader APIs */
#if defined(CYDEV_BOOTLOADER_IO_COMP) && ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_UART_XBEE) || \
                                          (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))
    /* Physical layer functions */
    void    UART_XBEE_CyBtldrCommStart(void) CYSMALL ;
    void    UART_XBEE_CyBtldrCommStop(void) CYSMALL ;
    void    UART_XBEE_CyBtldrCommReset(void) CYSMALL ;
    cystatus UART_XBEE_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut) CYSMALL
             ;
    cystatus UART_XBEE_CyBtldrCommRead(uint8 pData[], uint16 size, uint16 * count, uint8 timeOut) CYSMALL
             ;

    #if (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_UART_XBEE)
        #define CyBtldrCommStart    UART_XBEE_CyBtldrCommStart
        #define CyBtldrCommStop     UART_XBEE_CyBtldrCommStop
        #define CyBtldrCommReset    UART_XBEE_CyBtldrCommReset
        #define CyBtldrCommWrite    UART_XBEE_CyBtldrCommWrite
        #define CyBtldrCommRead     UART_XBEE_CyBtldrCommRead
    #endif  /* (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_UART_XBEE) */

    /* Byte to Byte time out for detecting end of block data from host */
    #define UART_XBEE_BYTE2BYTE_TIME_OUT (25u)
    #define UART_XBEE_PACKET_EOP         (0x17u) /* End of packet defined by bootloader */
    #define UART_XBEE_WAIT_EOP_DELAY     (5u)    /* Additional 5ms to wait for End of packet */
    #define UART_XBEE_BL_CHK_DELAY_MS    (1u)    /* Time Out quantity equal 1mS */

#endif /* CYDEV_BOOTLOADER_IO_COMP */


/***************************************
*          API Constants
***************************************/
/* Parameters for SetTxAddressMode API*/
#define UART_XBEE_SET_SPACE      (0x00u)
#define UART_XBEE_SET_MARK       (0x01u)

/* Status Register definitions */
#if( (UART_XBEE_TX_ENABLED) || (UART_XBEE_HD_ENABLED) )
    #if(UART_XBEE_TX_INTERRUPT_ENABLED)
        #define UART_XBEE_TX_VECT_NUM            (uint8)UART_XBEE_TXInternalInterrupt__INTC_NUMBER
        #define UART_XBEE_TX_PRIOR_NUM           (uint8)UART_XBEE_TXInternalInterrupt__INTC_PRIOR_NUM
    #endif /* UART_XBEE_TX_INTERRUPT_ENABLED */

    #define UART_XBEE_TX_STS_COMPLETE_SHIFT          (0x00u)
    #define UART_XBEE_TX_STS_FIFO_EMPTY_SHIFT        (0x01u)
    #define UART_XBEE_TX_STS_FIFO_NOT_FULL_SHIFT     (0x03u)
    #if(UART_XBEE_TX_ENABLED)
        #define UART_XBEE_TX_STS_FIFO_FULL_SHIFT     (0x02u)
    #else /* (UART_XBEE_HD_ENABLED) */
        #define UART_XBEE_TX_STS_FIFO_FULL_SHIFT     (0x05u)  /* Needs MD=0 */
    #endif /* (UART_XBEE_TX_ENABLED) */

    #define UART_XBEE_TX_STS_COMPLETE            (uint8)(0x01u << UART_XBEE_TX_STS_COMPLETE_SHIFT)
    #define UART_XBEE_TX_STS_FIFO_EMPTY          (uint8)(0x01u << UART_XBEE_TX_STS_FIFO_EMPTY_SHIFT)
    #define UART_XBEE_TX_STS_FIFO_FULL           (uint8)(0x01u << UART_XBEE_TX_STS_FIFO_FULL_SHIFT)
    #define UART_XBEE_TX_STS_FIFO_NOT_FULL       (uint8)(0x01u << UART_XBEE_TX_STS_FIFO_NOT_FULL_SHIFT)
#endif /* End (UART_XBEE_TX_ENABLED) || (UART_XBEE_HD_ENABLED)*/

#if( (UART_XBEE_RX_ENABLED) || (UART_XBEE_HD_ENABLED) )
    #if(UART_XBEE_RX_INTERRUPT_ENABLED)
        #define UART_XBEE_RX_VECT_NUM            (uint8)UART_XBEE_RXInternalInterrupt__INTC_NUMBER
        #define UART_XBEE_RX_PRIOR_NUM           (uint8)UART_XBEE_RXInternalInterrupt__INTC_PRIOR_NUM
    #endif /* UART_XBEE_RX_INTERRUPT_ENABLED */
    #define UART_XBEE_RX_STS_MRKSPC_SHIFT            (0x00u)
    #define UART_XBEE_RX_STS_BREAK_SHIFT             (0x01u)
    #define UART_XBEE_RX_STS_PAR_ERROR_SHIFT         (0x02u)
    #define UART_XBEE_RX_STS_STOP_ERROR_SHIFT        (0x03u)
    #define UART_XBEE_RX_STS_OVERRUN_SHIFT           (0x04u)
    #define UART_XBEE_RX_STS_FIFO_NOTEMPTY_SHIFT     (0x05u)
    #define UART_XBEE_RX_STS_ADDR_MATCH_SHIFT        (0x06u)
    #define UART_XBEE_RX_STS_SOFT_BUFF_OVER_SHIFT    (0x07u)

    #define UART_XBEE_RX_STS_MRKSPC           (uint8)(0x01u << UART_XBEE_RX_STS_MRKSPC_SHIFT)
    #define UART_XBEE_RX_STS_BREAK            (uint8)(0x01u << UART_XBEE_RX_STS_BREAK_SHIFT)
    #define UART_XBEE_RX_STS_PAR_ERROR        (uint8)(0x01u << UART_XBEE_RX_STS_PAR_ERROR_SHIFT)
    #define UART_XBEE_RX_STS_STOP_ERROR       (uint8)(0x01u << UART_XBEE_RX_STS_STOP_ERROR_SHIFT)
    #define UART_XBEE_RX_STS_OVERRUN          (uint8)(0x01u << UART_XBEE_RX_STS_OVERRUN_SHIFT)
    #define UART_XBEE_RX_STS_FIFO_NOTEMPTY    (uint8)(0x01u << UART_XBEE_RX_STS_FIFO_NOTEMPTY_SHIFT)
    #define UART_XBEE_RX_STS_ADDR_MATCH       (uint8)(0x01u << UART_XBEE_RX_STS_ADDR_MATCH_SHIFT)
    #define UART_XBEE_RX_STS_SOFT_BUFF_OVER   (uint8)(0x01u << UART_XBEE_RX_STS_SOFT_BUFF_OVER_SHIFT)
    #define UART_XBEE_RX_HW_MASK                     (0x7Fu)
#endif /* End (UART_XBEE_RX_ENABLED) || (UART_XBEE_HD_ENABLED) */

/* Control Register definitions */
#define UART_XBEE_CTRL_HD_SEND_SHIFT                 (0x00u) /* 1 enable TX part in Half Duplex mode */
#define UART_XBEE_CTRL_HD_SEND_BREAK_SHIFT           (0x01u) /* 1 send BREAK signal in Half Duplez mode */
#define UART_XBEE_CTRL_MARK_SHIFT                    (0x02u) /* 1 sets mark, 0 sets space */
#define UART_XBEE_CTRL_PARITY_TYPE0_SHIFT            (0x03u) /* Defines the type of parity implemented */
#define UART_XBEE_CTRL_PARITY_TYPE1_SHIFT            (0x04u) /* Defines the type of parity implemented */
#define UART_XBEE_CTRL_RXADDR_MODE0_SHIFT            (0x05u)
#define UART_XBEE_CTRL_RXADDR_MODE1_SHIFT            (0x06u)
#define UART_XBEE_CTRL_RXADDR_MODE2_SHIFT            (0x07u)

#define UART_XBEE_CTRL_HD_SEND               (uint8)(0x01u << UART_XBEE_CTRL_HD_SEND_SHIFT)
#define UART_XBEE_CTRL_HD_SEND_BREAK         (uint8)(0x01u << UART_XBEE_CTRL_HD_SEND_BREAK_SHIFT)
#define UART_XBEE_CTRL_MARK                  (uint8)(0x01u << UART_XBEE_CTRL_MARK_SHIFT)
#define UART_XBEE_CTRL_PARITY_TYPE_MASK      (uint8)(0x03u << UART_XBEE_CTRL_PARITY_TYPE0_SHIFT)
#define UART_XBEE_CTRL_RXADDR_MODE_MASK      (uint8)(0x07u << UART_XBEE_CTRL_RXADDR_MODE0_SHIFT)

/* StatusI Register Interrupt Enable Control Bits. As defined by the Register map for the AUX Control Register */
#define UART_XBEE_INT_ENABLE                         (0x10u)

/* Bit Counter (7-bit) Control Register Bit Definitions. As defined by the Register map for the AUX Control Register */
#define UART_XBEE_CNTR_ENABLE                        (0x20u)

/*   Constants for SendBreak() "retMode" parameter  */
#define UART_XBEE_SEND_BREAK                         (0x00u)
#define UART_XBEE_WAIT_FOR_COMPLETE_REINIT           (0x01u)
#define UART_XBEE_REINIT                             (0x02u)
#define UART_XBEE_SEND_WAIT_REINIT                   (0x03u)

#define UART_XBEE_OVER_SAMPLE_8                      (8u)
#define UART_XBEE_OVER_SAMPLE_16                     (16u)

#define UART_XBEE_BIT_CENTER                         (UART_XBEE_OVER_SAMPLE_COUNT - 2u)

#define UART_XBEE_FIFO_LENGTH                        (4u)
#define UART_XBEE_NUMBER_OF_START_BIT                (1u)
#define UART_XBEE_MAX_BYTE_VALUE                     (0xFFu)

/* 8X always for count7 implementation */
#define UART_XBEE_TXBITCTR_BREAKBITS8X   ((UART_XBEE_BREAK_BITS_TX * UART_XBEE_OVER_SAMPLE_8) - 1u)
/* 8X or 16X for DP implementation */
#define UART_XBEE_TXBITCTR_BREAKBITS ((UART_XBEE_BREAK_BITS_TX * UART_XBEE_OVER_SAMPLE_COUNT) - 1u)

#define UART_XBEE_HALF_BIT_COUNT   \
                            (((UART_XBEE_OVER_SAMPLE_COUNT / 2u) + (UART_XBEE_USE23POLLING * 1u)) - 2u)
#if (UART_XBEE_OVER_SAMPLE_COUNT == UART_XBEE_OVER_SAMPLE_8)
    #define UART_XBEE_HD_TXBITCTR_INIT   (((UART_XBEE_BREAK_BITS_TX + \
                            UART_XBEE_NUMBER_OF_START_BIT) * UART_XBEE_OVER_SAMPLE_COUNT) - 1u)

    /* This parameter is increased on the 2 in 2 out of 3 mode to sample voting in the middle */
    #define UART_XBEE_RXBITCTR_INIT  ((((UART_XBEE_BREAK_BITS_RX + UART_XBEE_NUMBER_OF_START_BIT) \
                            * UART_XBEE_OVER_SAMPLE_COUNT) + UART_XBEE_HALF_BIT_COUNT) - 1u)

#else /* UART_XBEE_OVER_SAMPLE_COUNT == UART_XBEE_OVER_SAMPLE_16 */
    #define UART_XBEE_HD_TXBITCTR_INIT   ((8u * UART_XBEE_OVER_SAMPLE_COUNT) - 1u)
    /* 7bit counter need one more bit for OverSampleCount = 16 */
    #define UART_XBEE_RXBITCTR_INIT      (((7u * UART_XBEE_OVER_SAMPLE_COUNT) - 1u) + \
                                                      UART_XBEE_HALF_BIT_COUNT)
#endif /* End UART_XBEE_OVER_SAMPLE_COUNT */

#define UART_XBEE_HD_RXBITCTR_INIT                   UART_XBEE_RXBITCTR_INIT


/***************************************
* Global variables external identifier
***************************************/

extern uint8 UART_XBEE_initVar;
#if (UART_XBEE_TX_INTERRUPT_ENABLED && UART_XBEE_TX_ENABLED)
    extern volatile uint8 UART_XBEE_txBuffer[UART_XBEE_TX_BUFFER_SIZE];
    extern volatile uint8 UART_XBEE_txBufferRead;
    extern uint8 UART_XBEE_txBufferWrite;
#endif /* (UART_XBEE_TX_INTERRUPT_ENABLED && UART_XBEE_TX_ENABLED) */
#if (UART_XBEE_RX_INTERRUPT_ENABLED && (UART_XBEE_RX_ENABLED || UART_XBEE_HD_ENABLED))
    extern uint8 UART_XBEE_errorStatus;
    extern volatile uint8 UART_XBEE_rxBuffer[UART_XBEE_RX_BUFFER_SIZE];
    extern volatile uint8 UART_XBEE_rxBufferRead;
    extern volatile uint8 UART_XBEE_rxBufferWrite;
    extern volatile uint8 UART_XBEE_rxBufferLoopDetect;
    extern volatile uint8 UART_XBEE_rxBufferOverflow;
    #if (UART_XBEE_RXHW_ADDRESS_ENABLED)
        extern volatile uint8 UART_XBEE_rxAddressMode;
        extern volatile uint8 UART_XBEE_rxAddressDetected;
    #endif /* (UART_XBEE_RXHW_ADDRESS_ENABLED) */
#endif /* (UART_XBEE_RX_INTERRUPT_ENABLED && (UART_XBEE_RX_ENABLED || UART_XBEE_HD_ENABLED)) */


/***************************************
* Enumerated Types and Parameters
***************************************/

#define UART_XBEE__B_UART__AM_SW_BYTE_BYTE 1
#define UART_XBEE__B_UART__AM_SW_DETECT_TO_BUFFER 2
#define UART_XBEE__B_UART__AM_HW_BYTE_BY_BYTE 3
#define UART_XBEE__B_UART__AM_HW_DETECT_TO_BUFFER 4
#define UART_XBEE__B_UART__AM_NONE 0

#define UART_XBEE__B_UART__NONE_REVB 0
#define UART_XBEE__B_UART__EVEN_REVB 1
#define UART_XBEE__B_UART__ODD_REVB 2
#define UART_XBEE__B_UART__MARK_SPACE_REVB 3



/***************************************
*    Initial Parameter Constants
***************************************/

/* UART shifts max 8 bits, Mark/Space functionality working if 9 selected */
#define UART_XBEE_NUMBER_OF_DATA_BITS    ((8u > 8u) ? 8u : 8u)
#define UART_XBEE_NUMBER_OF_STOP_BITS    (1u)

#if (UART_XBEE_RXHW_ADDRESS_ENABLED)
    #define UART_XBEE_RX_ADDRESS_MODE    (0u)
    #define UART_XBEE_RX_HW_ADDRESS1     (0u)
    #define UART_XBEE_RX_HW_ADDRESS2     (0u)
#endif /* (UART_XBEE_RXHW_ADDRESS_ENABLED) */

#define UART_XBEE_INIT_RX_INTERRUPTS_MASK \
                                  (uint8)((0 << UART_XBEE_RX_STS_FIFO_NOTEMPTY_SHIFT) \
                                        | (0 << UART_XBEE_RX_STS_MRKSPC_SHIFT) \
                                        | (0 << UART_XBEE_RX_STS_ADDR_MATCH_SHIFT) \
                                        | (0 << UART_XBEE_RX_STS_PAR_ERROR_SHIFT) \
                                        | (0 << UART_XBEE_RX_STS_STOP_ERROR_SHIFT) \
                                        | (0 << UART_XBEE_RX_STS_BREAK_SHIFT) \
                                        | (0 << UART_XBEE_RX_STS_OVERRUN_SHIFT))

#define UART_XBEE_INIT_TX_INTERRUPTS_MASK \
                                  (uint8)((0 << UART_XBEE_TX_STS_COMPLETE_SHIFT) \
                                        | (0 << UART_XBEE_TX_STS_FIFO_EMPTY_SHIFT) \
                                        | (0 << UART_XBEE_TX_STS_FIFO_FULL_SHIFT) \
                                        | (0 << UART_XBEE_TX_STS_FIFO_NOT_FULL_SHIFT))


/***************************************
*              Registers
***************************************/

#ifdef UART_XBEE_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG
    #define UART_XBEE_CONTROL_REG \
                            (* (reg8 *) UART_XBEE_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG )
    #define UART_XBEE_CONTROL_PTR \
                            (  (reg8 *) UART_XBEE_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG )
#endif /* End UART_XBEE_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG */

#if(UART_XBEE_TX_ENABLED)
    #define UART_XBEE_TXDATA_REG          (* (reg8 *) UART_XBEE_BUART_sTX_TxShifter_u0__F0_REG)
    #define UART_XBEE_TXDATA_PTR          (  (reg8 *) UART_XBEE_BUART_sTX_TxShifter_u0__F0_REG)
    #define UART_XBEE_TXDATA_AUX_CTL_REG  (* (reg8 *) UART_XBEE_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG)
    #define UART_XBEE_TXDATA_AUX_CTL_PTR  (  (reg8 *) UART_XBEE_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG)
    #define UART_XBEE_TXSTATUS_REG        (* (reg8 *) UART_XBEE_BUART_sTX_TxSts__STATUS_REG)
    #define UART_XBEE_TXSTATUS_PTR        (  (reg8 *) UART_XBEE_BUART_sTX_TxSts__STATUS_REG)
    #define UART_XBEE_TXSTATUS_MASK_REG   (* (reg8 *) UART_XBEE_BUART_sTX_TxSts__MASK_REG)
    #define UART_XBEE_TXSTATUS_MASK_PTR   (  (reg8 *) UART_XBEE_BUART_sTX_TxSts__MASK_REG)
    #define UART_XBEE_TXSTATUS_ACTL_REG   (* (reg8 *) UART_XBEE_BUART_sTX_TxSts__STATUS_AUX_CTL_REG)
    #define UART_XBEE_TXSTATUS_ACTL_PTR   (  (reg8 *) UART_XBEE_BUART_sTX_TxSts__STATUS_AUX_CTL_REG)

    /* DP clock */
    #if(UART_XBEE_TXCLKGEN_DP)
        #define UART_XBEE_TXBITCLKGEN_CTR_REG        \
                                        (* (reg8 *) UART_XBEE_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG)
        #define UART_XBEE_TXBITCLKGEN_CTR_PTR        \
                                        (  (reg8 *) UART_XBEE_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG)
        #define UART_XBEE_TXBITCLKTX_COMPLETE_REG    \
                                        (* (reg8 *) UART_XBEE_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG)
        #define UART_XBEE_TXBITCLKTX_COMPLETE_PTR    \
                                        (  (reg8 *) UART_XBEE_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG)
    #else     /* Count7 clock*/
        #define UART_XBEE_TXBITCTR_PERIOD_REG    \
                                        (* (reg8 *) UART_XBEE_BUART_sTX_sCLOCK_TxBitCounter__PERIOD_REG)
        #define UART_XBEE_TXBITCTR_PERIOD_PTR    \
                                        (  (reg8 *) UART_XBEE_BUART_sTX_sCLOCK_TxBitCounter__PERIOD_REG)
        #define UART_XBEE_TXBITCTR_CONTROL_REG   \
                                        (* (reg8 *) UART_XBEE_BUART_sTX_sCLOCK_TxBitCounter__CONTROL_AUX_CTL_REG)
        #define UART_XBEE_TXBITCTR_CONTROL_PTR   \
                                        (  (reg8 *) UART_XBEE_BUART_sTX_sCLOCK_TxBitCounter__CONTROL_AUX_CTL_REG)
        #define UART_XBEE_TXBITCTR_COUNTER_REG   \
                                        (* (reg8 *) UART_XBEE_BUART_sTX_sCLOCK_TxBitCounter__COUNT_REG)
        #define UART_XBEE_TXBITCTR_COUNTER_PTR   \
                                        (  (reg8 *) UART_XBEE_BUART_sTX_sCLOCK_TxBitCounter__COUNT_REG)
    #endif /* UART_XBEE_TXCLKGEN_DP */

#endif /* End UART_XBEE_TX_ENABLED */

#if(UART_XBEE_HD_ENABLED)

    #define UART_XBEE_TXDATA_REG             (* (reg8 *) UART_XBEE_BUART_sRX_RxShifter_u0__F1_REG )
    #define UART_XBEE_TXDATA_PTR             (  (reg8 *) UART_XBEE_BUART_sRX_RxShifter_u0__F1_REG )
    #define UART_XBEE_TXDATA_AUX_CTL_REG     (* (reg8 *) UART_XBEE_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG)
    #define UART_XBEE_TXDATA_AUX_CTL_PTR     (  (reg8 *) UART_XBEE_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG)

    #define UART_XBEE_TXSTATUS_REG           (* (reg8 *) UART_XBEE_BUART_sRX_RxSts__STATUS_REG )
    #define UART_XBEE_TXSTATUS_PTR           (  (reg8 *) UART_XBEE_BUART_sRX_RxSts__STATUS_REG )
    #define UART_XBEE_TXSTATUS_MASK_REG      (* (reg8 *) UART_XBEE_BUART_sRX_RxSts__MASK_REG )
    #define UART_XBEE_TXSTATUS_MASK_PTR      (  (reg8 *) UART_XBEE_BUART_sRX_RxSts__MASK_REG )
    #define UART_XBEE_TXSTATUS_ACTL_REG      (* (reg8 *) UART_XBEE_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
    #define UART_XBEE_TXSTATUS_ACTL_PTR      (  (reg8 *) UART_XBEE_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
#endif /* End UART_XBEE_HD_ENABLED */

#if( (UART_XBEE_RX_ENABLED) || (UART_XBEE_HD_ENABLED) )
    #define UART_XBEE_RXDATA_REG             (* (reg8 *) UART_XBEE_BUART_sRX_RxShifter_u0__F0_REG )
    #define UART_XBEE_RXDATA_PTR             (  (reg8 *) UART_XBEE_BUART_sRX_RxShifter_u0__F0_REG )
    #define UART_XBEE_RXADDRESS1_REG         (* (reg8 *) UART_XBEE_BUART_sRX_RxShifter_u0__D0_REG )
    #define UART_XBEE_RXADDRESS1_PTR         (  (reg8 *) UART_XBEE_BUART_sRX_RxShifter_u0__D0_REG )
    #define UART_XBEE_RXADDRESS2_REG         (* (reg8 *) UART_XBEE_BUART_sRX_RxShifter_u0__D1_REG )
    #define UART_XBEE_RXADDRESS2_PTR         (  (reg8 *) UART_XBEE_BUART_sRX_RxShifter_u0__D1_REG )
    #define UART_XBEE_RXDATA_AUX_CTL_REG     (* (reg8 *) UART_XBEE_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG)

    #define UART_XBEE_RXBITCTR_PERIOD_REG    (* (reg8 *) UART_XBEE_BUART_sRX_RxBitCounter__PERIOD_REG )
    #define UART_XBEE_RXBITCTR_PERIOD_PTR    (  (reg8 *) UART_XBEE_BUART_sRX_RxBitCounter__PERIOD_REG )
    #define UART_XBEE_RXBITCTR_CONTROL_REG   \
                                        (* (reg8 *) UART_XBEE_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG )
    #define UART_XBEE_RXBITCTR_CONTROL_PTR   \
                                        (  (reg8 *) UART_XBEE_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG )
    #define UART_XBEE_RXBITCTR_COUNTER_REG   (* (reg8 *) UART_XBEE_BUART_sRX_RxBitCounter__COUNT_REG )
    #define UART_XBEE_RXBITCTR_COUNTER_PTR   (  (reg8 *) UART_XBEE_BUART_sRX_RxBitCounter__COUNT_REG )

    #define UART_XBEE_RXSTATUS_REG           (* (reg8 *) UART_XBEE_BUART_sRX_RxSts__STATUS_REG )
    #define UART_XBEE_RXSTATUS_PTR           (  (reg8 *) UART_XBEE_BUART_sRX_RxSts__STATUS_REG )
    #define UART_XBEE_RXSTATUS_MASK_REG      (* (reg8 *) UART_XBEE_BUART_sRX_RxSts__MASK_REG )
    #define UART_XBEE_RXSTATUS_MASK_PTR      (  (reg8 *) UART_XBEE_BUART_sRX_RxSts__MASK_REG )
    #define UART_XBEE_RXSTATUS_ACTL_REG      (* (reg8 *) UART_XBEE_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
    #define UART_XBEE_RXSTATUS_ACTL_PTR      (  (reg8 *) UART_XBEE_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
#endif /* End  (UART_XBEE_RX_ENABLED) || (UART_XBEE_HD_ENABLED) */

#if(UART_XBEE_INTERNAL_CLOCK_USED)
    /* Register to enable or disable the digital clocks */
    #define UART_XBEE_INTCLOCK_CLKEN_REG     (* (reg8 *) UART_XBEE_IntClock__PM_ACT_CFG)
    #define UART_XBEE_INTCLOCK_CLKEN_PTR     (  (reg8 *) UART_XBEE_IntClock__PM_ACT_CFG)

    /* Clock mask for this clock. */
    #define UART_XBEE_INTCLOCK_CLKEN_MASK    UART_XBEE_IntClock__PM_ACT_MSK
#endif /* End UART_XBEE_INTERNAL_CLOCK_USED */


/***************************************
*       Register Constants
***************************************/

#if(UART_XBEE_TX_ENABLED)
    #define UART_XBEE_TX_FIFO_CLR            (0x01u) /* FIFO0 CLR */
#endif /* End UART_XBEE_TX_ENABLED */

#if(UART_XBEE_HD_ENABLED)
    #define UART_XBEE_TX_FIFO_CLR            (0x02u) /* FIFO1 CLR */
#endif /* End UART_XBEE_HD_ENABLED */

#if( (UART_XBEE_RX_ENABLED) || (UART_XBEE_HD_ENABLED) )
    #define UART_XBEE_RX_FIFO_CLR            (0x01u) /* FIFO0 CLR */
#endif /* End  (UART_XBEE_RX_ENABLED) || (UART_XBEE_HD_ENABLED) */


/***************************************
* The following code is DEPRECATED and
* should not be used in new projects.
***************************************/

/* UART v2_40 obsolete definitions */
#define UART_XBEE_WAIT_1_MS      UART_XBEE_BL_CHK_DELAY_MS   

#define UART_XBEE_TXBUFFERSIZE   UART_XBEE_TX_BUFFER_SIZE
#define UART_XBEE_RXBUFFERSIZE   UART_XBEE_RX_BUFFER_SIZE

#if (UART_XBEE_RXHW_ADDRESS_ENABLED)
    #define UART_XBEE_RXADDRESSMODE  UART_XBEE_RX_ADDRESS_MODE
    #define UART_XBEE_RXHWADDRESS1   UART_XBEE_RX_HW_ADDRESS1
    #define UART_XBEE_RXHWADDRESS2   UART_XBEE_RX_HW_ADDRESS2
    /* Backward compatible define */
    #define UART_XBEE_RXAddressMode  UART_XBEE_RXADDRESSMODE
#endif /* (UART_XBEE_RXHW_ADDRESS_ENABLED) */

/* UART v2_30 obsolete definitions */
#define UART_XBEE_initvar                    UART_XBEE_initVar

#define UART_XBEE_RX_Enabled                 UART_XBEE_RX_ENABLED
#define UART_XBEE_TX_Enabled                 UART_XBEE_TX_ENABLED
#define UART_XBEE_HD_Enabled                 UART_XBEE_HD_ENABLED
#define UART_XBEE_RX_IntInterruptEnabled     UART_XBEE_RX_INTERRUPT_ENABLED
#define UART_XBEE_TX_IntInterruptEnabled     UART_XBEE_TX_INTERRUPT_ENABLED
#define UART_XBEE_InternalClockUsed          UART_XBEE_INTERNAL_CLOCK_USED
#define UART_XBEE_RXHW_Address_Enabled       UART_XBEE_RXHW_ADDRESS_ENABLED
#define UART_XBEE_OverSampleCount            UART_XBEE_OVER_SAMPLE_COUNT
#define UART_XBEE_ParityType                 UART_XBEE_PARITY_TYPE

#if( UART_XBEE_TX_ENABLED && (UART_XBEE_TXBUFFERSIZE > UART_XBEE_FIFO_LENGTH))
    #define UART_XBEE_TXBUFFER               UART_XBEE_txBuffer
    #define UART_XBEE_TXBUFFERREAD           UART_XBEE_txBufferRead
    #define UART_XBEE_TXBUFFERWRITE          UART_XBEE_txBufferWrite
#endif /* End UART_XBEE_TX_ENABLED */
#if( ( UART_XBEE_RX_ENABLED || UART_XBEE_HD_ENABLED ) && \
     (UART_XBEE_RXBUFFERSIZE > UART_XBEE_FIFO_LENGTH) )
    #define UART_XBEE_RXBUFFER               UART_XBEE_rxBuffer
    #define UART_XBEE_RXBUFFERREAD           UART_XBEE_rxBufferRead
    #define UART_XBEE_RXBUFFERWRITE          UART_XBEE_rxBufferWrite
    #define UART_XBEE_RXBUFFERLOOPDETECT     UART_XBEE_rxBufferLoopDetect
    #define UART_XBEE_RXBUFFER_OVERFLOW      UART_XBEE_rxBufferOverflow
#endif /* End UART_XBEE_RX_ENABLED */

#ifdef UART_XBEE_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG
    #define UART_XBEE_CONTROL                UART_XBEE_CONTROL_REG
#endif /* End UART_XBEE_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG */

#if(UART_XBEE_TX_ENABLED)
    #define UART_XBEE_TXDATA                 UART_XBEE_TXDATA_REG
    #define UART_XBEE_TXSTATUS               UART_XBEE_TXSTATUS_REG
    #define UART_XBEE_TXSTATUS_MASK          UART_XBEE_TXSTATUS_MASK_REG
    #define UART_XBEE_TXSTATUS_ACTL          UART_XBEE_TXSTATUS_ACTL_REG
    /* DP clock */
    #if(UART_XBEE_TXCLKGEN_DP)
        #define UART_XBEE_TXBITCLKGEN_CTR        UART_XBEE_TXBITCLKGEN_CTR_REG
        #define UART_XBEE_TXBITCLKTX_COMPLETE    UART_XBEE_TXBITCLKTX_COMPLETE_REG
    #else     /* Count7 clock*/
        #define UART_XBEE_TXBITCTR_PERIOD        UART_XBEE_TXBITCTR_PERIOD_REG
        #define UART_XBEE_TXBITCTR_CONTROL       UART_XBEE_TXBITCTR_CONTROL_REG
        #define UART_XBEE_TXBITCTR_COUNTER       UART_XBEE_TXBITCTR_COUNTER_REG
    #endif /* UART_XBEE_TXCLKGEN_DP */
#endif /* End UART_XBEE_TX_ENABLED */

#if(UART_XBEE_HD_ENABLED)
    #define UART_XBEE_TXDATA                 UART_XBEE_TXDATA_REG
    #define UART_XBEE_TXSTATUS               UART_XBEE_TXSTATUS_REG
    #define UART_XBEE_TXSTATUS_MASK          UART_XBEE_TXSTATUS_MASK_REG
    #define UART_XBEE_TXSTATUS_ACTL          UART_XBEE_TXSTATUS_ACTL_REG
#endif /* End UART_XBEE_HD_ENABLED */

#if( (UART_XBEE_RX_ENABLED) || (UART_XBEE_HD_ENABLED) )
    #define UART_XBEE_RXDATA                 UART_XBEE_RXDATA_REG
    #define UART_XBEE_RXADDRESS1             UART_XBEE_RXADDRESS1_REG
    #define UART_XBEE_RXADDRESS2             UART_XBEE_RXADDRESS2_REG
    #define UART_XBEE_RXBITCTR_PERIOD        UART_XBEE_RXBITCTR_PERIOD_REG
    #define UART_XBEE_RXBITCTR_CONTROL       UART_XBEE_RXBITCTR_CONTROL_REG
    #define UART_XBEE_RXBITCTR_COUNTER       UART_XBEE_RXBITCTR_COUNTER_REG
    #define UART_XBEE_RXSTATUS               UART_XBEE_RXSTATUS_REG
    #define UART_XBEE_RXSTATUS_MASK          UART_XBEE_RXSTATUS_MASK_REG
    #define UART_XBEE_RXSTATUS_ACTL          UART_XBEE_RXSTATUS_ACTL_REG
#endif /* End  (UART_XBEE_RX_ENABLED) || (UART_XBEE_HD_ENABLED) */

#if(UART_XBEE_INTERNAL_CLOCK_USED)
    #define UART_XBEE_INTCLOCK_CLKEN         UART_XBEE_INTCLOCK_CLKEN_REG
#endif /* End UART_XBEE_INTERNAL_CLOCK_USED */

#define UART_XBEE_WAIT_FOR_COMLETE_REINIT    UART_XBEE_WAIT_FOR_COMPLETE_REINIT

#endif  /* CY_UART_UART_XBEE_H */


/* [] END OF FILE */
