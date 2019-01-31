/*******************************************************************************
* File Name: niveau.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_niveau_H) /* Pins niveau_H */
#define CY_PINS_niveau_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "niveau_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 niveau__PORT == 15 && ((niveau__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    niveau_Write(uint8 value);
void    niveau_SetDriveMode(uint8 mode);
uint8   niveau_ReadDataReg(void);
uint8   niveau_Read(void);
void    niveau_SetInterruptMode(uint16 position, uint16 mode);
uint8   niveau_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the niveau_SetDriveMode() function.
     *  @{
     */
        #define niveau_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define niveau_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define niveau_DM_RES_UP          PIN_DM_RES_UP
        #define niveau_DM_RES_DWN         PIN_DM_RES_DWN
        #define niveau_DM_OD_LO           PIN_DM_OD_LO
        #define niveau_DM_OD_HI           PIN_DM_OD_HI
        #define niveau_DM_STRONG          PIN_DM_STRONG
        #define niveau_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define niveau_MASK               niveau__MASK
#define niveau_SHIFT              niveau__SHIFT
#define niveau_WIDTH              8u

/* Interrupt constants */
#if defined(niveau__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in niveau_SetInterruptMode() function.
     *  @{
     */
        #define niveau_INTR_NONE      (uint16)(0x0000u)
        #define niveau_INTR_RISING    (uint16)(0x0001u)
        #define niveau_INTR_FALLING   (uint16)(0x0002u)
        #define niveau_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define niveau_INTR_MASK      (0x01u) 
#endif /* (niveau__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define niveau_PS                     (* (reg8 *) niveau__PS)
/* Data Register */
#define niveau_DR                     (* (reg8 *) niveau__DR)
/* Port Number */
#define niveau_PRT_NUM                (* (reg8 *) niveau__PRT) 
/* Connect to Analog Globals */                                                  
#define niveau_AG                     (* (reg8 *) niveau__AG)                       
/* Analog MUX bux enable */
#define niveau_AMUX                   (* (reg8 *) niveau__AMUX) 
/* Bidirectional Enable */                                                        
#define niveau_BIE                    (* (reg8 *) niveau__BIE)
/* Bit-mask for Aliased Register Access */
#define niveau_BIT_MASK               (* (reg8 *) niveau__BIT_MASK)
/* Bypass Enable */
#define niveau_BYP                    (* (reg8 *) niveau__BYP)
/* Port wide control signals */                                                   
#define niveau_CTL                    (* (reg8 *) niveau__CTL)
/* Drive Modes */
#define niveau_DM0                    (* (reg8 *) niveau__DM0) 
#define niveau_DM1                    (* (reg8 *) niveau__DM1)
#define niveau_DM2                    (* (reg8 *) niveau__DM2) 
/* Input Buffer Disable Override */
#define niveau_INP_DIS                (* (reg8 *) niveau__INP_DIS)
/* LCD Common or Segment Drive */
#define niveau_LCD_COM_SEG            (* (reg8 *) niveau__LCD_COM_SEG)
/* Enable Segment LCD */
#define niveau_LCD_EN                 (* (reg8 *) niveau__LCD_EN)
/* Slew Rate Control */
#define niveau_SLW                    (* (reg8 *) niveau__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define niveau_PRTDSI__CAPS_SEL       (* (reg8 *) niveau__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define niveau_PRTDSI__DBL_SYNC_IN    (* (reg8 *) niveau__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define niveau_PRTDSI__OE_SEL0        (* (reg8 *) niveau__PRTDSI__OE_SEL0) 
#define niveau_PRTDSI__OE_SEL1        (* (reg8 *) niveau__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define niveau_PRTDSI__OUT_SEL0       (* (reg8 *) niveau__PRTDSI__OUT_SEL0) 
#define niveau_PRTDSI__OUT_SEL1       (* (reg8 *) niveau__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define niveau_PRTDSI__SYNC_OUT       (* (reg8 *) niveau__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(niveau__SIO_CFG)
    #define niveau_SIO_HYST_EN        (* (reg8 *) niveau__SIO_HYST_EN)
    #define niveau_SIO_REG_HIFREQ     (* (reg8 *) niveau__SIO_REG_HIFREQ)
    #define niveau_SIO_CFG            (* (reg8 *) niveau__SIO_CFG)
    #define niveau_SIO_DIFF           (* (reg8 *) niveau__SIO_DIFF)
#endif /* (niveau__SIO_CFG) */

/* Interrupt Registers */
#if defined(niveau__INTSTAT)
    #define niveau_INTSTAT            (* (reg8 *) niveau__INTSTAT)
    #define niveau_SNAP               (* (reg8 *) niveau__SNAP)
    
	#define niveau_0_INTTYPE_REG 		(* (reg8 *) niveau__0__INTTYPE)
	#define niveau_1_INTTYPE_REG 		(* (reg8 *) niveau__1__INTTYPE)
	#define niveau_2_INTTYPE_REG 		(* (reg8 *) niveau__2__INTTYPE)
	#define niveau_3_INTTYPE_REG 		(* (reg8 *) niveau__3__INTTYPE)
	#define niveau_4_INTTYPE_REG 		(* (reg8 *) niveau__4__INTTYPE)
	#define niveau_5_INTTYPE_REG 		(* (reg8 *) niveau__5__INTTYPE)
	#define niveau_6_INTTYPE_REG 		(* (reg8 *) niveau__6__INTTYPE)
	#define niveau_7_INTTYPE_REG 		(* (reg8 *) niveau__7__INTTYPE)
#endif /* (niveau__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_niveau_H */


/* [] END OF FILE */
