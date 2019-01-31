/*******************************************************************************
* File Name: VBAT1.h  
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

#if !defined(CY_PINS_VBAT1_H) /* Pins VBAT1_H */
#define CY_PINS_VBAT1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "VBAT1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 VBAT1__PORT == 15 && ((VBAT1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    VBAT1_Write(uint8 value);
void    VBAT1_SetDriveMode(uint8 mode);
uint8   VBAT1_ReadDataReg(void);
uint8   VBAT1_Read(void);
void    VBAT1_SetInterruptMode(uint16 position, uint16 mode);
uint8   VBAT1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the VBAT1_SetDriveMode() function.
     *  @{
     */
        #define VBAT1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define VBAT1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define VBAT1_DM_RES_UP          PIN_DM_RES_UP
        #define VBAT1_DM_RES_DWN         PIN_DM_RES_DWN
        #define VBAT1_DM_OD_LO           PIN_DM_OD_LO
        #define VBAT1_DM_OD_HI           PIN_DM_OD_HI
        #define VBAT1_DM_STRONG          PIN_DM_STRONG
        #define VBAT1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define VBAT1_MASK               VBAT1__MASK
#define VBAT1_SHIFT              VBAT1__SHIFT
#define VBAT1_WIDTH              1u

/* Interrupt constants */
#if defined(VBAT1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in VBAT1_SetInterruptMode() function.
     *  @{
     */
        #define VBAT1_INTR_NONE      (uint16)(0x0000u)
        #define VBAT1_INTR_RISING    (uint16)(0x0001u)
        #define VBAT1_INTR_FALLING   (uint16)(0x0002u)
        #define VBAT1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define VBAT1_INTR_MASK      (0x01u) 
#endif /* (VBAT1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define VBAT1_PS                     (* (reg8 *) VBAT1__PS)
/* Data Register */
#define VBAT1_DR                     (* (reg8 *) VBAT1__DR)
/* Port Number */
#define VBAT1_PRT_NUM                (* (reg8 *) VBAT1__PRT) 
/* Connect to Analog Globals */                                                  
#define VBAT1_AG                     (* (reg8 *) VBAT1__AG)                       
/* Analog MUX bux enable */
#define VBAT1_AMUX                   (* (reg8 *) VBAT1__AMUX) 
/* Bidirectional Enable */                                                        
#define VBAT1_BIE                    (* (reg8 *) VBAT1__BIE)
/* Bit-mask for Aliased Register Access */
#define VBAT1_BIT_MASK               (* (reg8 *) VBAT1__BIT_MASK)
/* Bypass Enable */
#define VBAT1_BYP                    (* (reg8 *) VBAT1__BYP)
/* Port wide control signals */                                                   
#define VBAT1_CTL                    (* (reg8 *) VBAT1__CTL)
/* Drive Modes */
#define VBAT1_DM0                    (* (reg8 *) VBAT1__DM0) 
#define VBAT1_DM1                    (* (reg8 *) VBAT1__DM1)
#define VBAT1_DM2                    (* (reg8 *) VBAT1__DM2) 
/* Input Buffer Disable Override */
#define VBAT1_INP_DIS                (* (reg8 *) VBAT1__INP_DIS)
/* LCD Common or Segment Drive */
#define VBAT1_LCD_COM_SEG            (* (reg8 *) VBAT1__LCD_COM_SEG)
/* Enable Segment LCD */
#define VBAT1_LCD_EN                 (* (reg8 *) VBAT1__LCD_EN)
/* Slew Rate Control */
#define VBAT1_SLW                    (* (reg8 *) VBAT1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define VBAT1_PRTDSI__CAPS_SEL       (* (reg8 *) VBAT1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define VBAT1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) VBAT1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define VBAT1_PRTDSI__OE_SEL0        (* (reg8 *) VBAT1__PRTDSI__OE_SEL0) 
#define VBAT1_PRTDSI__OE_SEL1        (* (reg8 *) VBAT1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define VBAT1_PRTDSI__OUT_SEL0       (* (reg8 *) VBAT1__PRTDSI__OUT_SEL0) 
#define VBAT1_PRTDSI__OUT_SEL1       (* (reg8 *) VBAT1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define VBAT1_PRTDSI__SYNC_OUT       (* (reg8 *) VBAT1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(VBAT1__SIO_CFG)
    #define VBAT1_SIO_HYST_EN        (* (reg8 *) VBAT1__SIO_HYST_EN)
    #define VBAT1_SIO_REG_HIFREQ     (* (reg8 *) VBAT1__SIO_REG_HIFREQ)
    #define VBAT1_SIO_CFG            (* (reg8 *) VBAT1__SIO_CFG)
    #define VBAT1_SIO_DIFF           (* (reg8 *) VBAT1__SIO_DIFF)
#endif /* (VBAT1__SIO_CFG) */

/* Interrupt Registers */
#if defined(VBAT1__INTSTAT)
    #define VBAT1_INTSTAT            (* (reg8 *) VBAT1__INTSTAT)
    #define VBAT1_SNAP               (* (reg8 *) VBAT1__SNAP)
    
	#define VBAT1_0_INTTYPE_REG 		(* (reg8 *) VBAT1__0__INTTYPE)
#endif /* (VBAT1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_VBAT1_H */


/* [] END OF FILE */
