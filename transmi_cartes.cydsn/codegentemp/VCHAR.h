/*******************************************************************************
* File Name: VCHAR.h  
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

#if !defined(CY_PINS_VCHAR_H) /* Pins VCHAR_H */
#define CY_PINS_VCHAR_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "VCHAR_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 VCHAR__PORT == 15 && ((VCHAR__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    VCHAR_Write(uint8 value);
void    VCHAR_SetDriveMode(uint8 mode);
uint8   VCHAR_ReadDataReg(void);
uint8   VCHAR_Read(void);
void    VCHAR_SetInterruptMode(uint16 position, uint16 mode);
uint8   VCHAR_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the VCHAR_SetDriveMode() function.
     *  @{
     */
        #define VCHAR_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define VCHAR_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define VCHAR_DM_RES_UP          PIN_DM_RES_UP
        #define VCHAR_DM_RES_DWN         PIN_DM_RES_DWN
        #define VCHAR_DM_OD_LO           PIN_DM_OD_LO
        #define VCHAR_DM_OD_HI           PIN_DM_OD_HI
        #define VCHAR_DM_STRONG          PIN_DM_STRONG
        #define VCHAR_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define VCHAR_MASK               VCHAR__MASK
#define VCHAR_SHIFT              VCHAR__SHIFT
#define VCHAR_WIDTH              1u

/* Interrupt constants */
#if defined(VCHAR__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in VCHAR_SetInterruptMode() function.
     *  @{
     */
        #define VCHAR_INTR_NONE      (uint16)(0x0000u)
        #define VCHAR_INTR_RISING    (uint16)(0x0001u)
        #define VCHAR_INTR_FALLING   (uint16)(0x0002u)
        #define VCHAR_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define VCHAR_INTR_MASK      (0x01u) 
#endif /* (VCHAR__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define VCHAR_PS                     (* (reg8 *) VCHAR__PS)
/* Data Register */
#define VCHAR_DR                     (* (reg8 *) VCHAR__DR)
/* Port Number */
#define VCHAR_PRT_NUM                (* (reg8 *) VCHAR__PRT) 
/* Connect to Analog Globals */                                                  
#define VCHAR_AG                     (* (reg8 *) VCHAR__AG)                       
/* Analog MUX bux enable */
#define VCHAR_AMUX                   (* (reg8 *) VCHAR__AMUX) 
/* Bidirectional Enable */                                                        
#define VCHAR_BIE                    (* (reg8 *) VCHAR__BIE)
/* Bit-mask for Aliased Register Access */
#define VCHAR_BIT_MASK               (* (reg8 *) VCHAR__BIT_MASK)
/* Bypass Enable */
#define VCHAR_BYP                    (* (reg8 *) VCHAR__BYP)
/* Port wide control signals */                                                   
#define VCHAR_CTL                    (* (reg8 *) VCHAR__CTL)
/* Drive Modes */
#define VCHAR_DM0                    (* (reg8 *) VCHAR__DM0) 
#define VCHAR_DM1                    (* (reg8 *) VCHAR__DM1)
#define VCHAR_DM2                    (* (reg8 *) VCHAR__DM2) 
/* Input Buffer Disable Override */
#define VCHAR_INP_DIS                (* (reg8 *) VCHAR__INP_DIS)
/* LCD Common or Segment Drive */
#define VCHAR_LCD_COM_SEG            (* (reg8 *) VCHAR__LCD_COM_SEG)
/* Enable Segment LCD */
#define VCHAR_LCD_EN                 (* (reg8 *) VCHAR__LCD_EN)
/* Slew Rate Control */
#define VCHAR_SLW                    (* (reg8 *) VCHAR__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define VCHAR_PRTDSI__CAPS_SEL       (* (reg8 *) VCHAR__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define VCHAR_PRTDSI__DBL_SYNC_IN    (* (reg8 *) VCHAR__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define VCHAR_PRTDSI__OE_SEL0        (* (reg8 *) VCHAR__PRTDSI__OE_SEL0) 
#define VCHAR_PRTDSI__OE_SEL1        (* (reg8 *) VCHAR__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define VCHAR_PRTDSI__OUT_SEL0       (* (reg8 *) VCHAR__PRTDSI__OUT_SEL0) 
#define VCHAR_PRTDSI__OUT_SEL1       (* (reg8 *) VCHAR__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define VCHAR_PRTDSI__SYNC_OUT       (* (reg8 *) VCHAR__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(VCHAR__SIO_CFG)
    #define VCHAR_SIO_HYST_EN        (* (reg8 *) VCHAR__SIO_HYST_EN)
    #define VCHAR_SIO_REG_HIFREQ     (* (reg8 *) VCHAR__SIO_REG_HIFREQ)
    #define VCHAR_SIO_CFG            (* (reg8 *) VCHAR__SIO_CFG)
    #define VCHAR_SIO_DIFF           (* (reg8 *) VCHAR__SIO_DIFF)
#endif /* (VCHAR__SIO_CFG) */

/* Interrupt Registers */
#if defined(VCHAR__INTSTAT)
    #define VCHAR_INTSTAT            (* (reg8 *) VCHAR__INTSTAT)
    #define VCHAR_SNAP               (* (reg8 *) VCHAR__SNAP)
    
	#define VCHAR_0_INTTYPE_REG 		(* (reg8 *) VCHAR__0__INTTYPE)
#endif /* (VCHAR__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_VCHAR_H */


/* [] END OF FILE */
