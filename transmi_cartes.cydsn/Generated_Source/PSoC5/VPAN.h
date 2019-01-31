/*******************************************************************************
* File Name: VPAN.h  
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

#if !defined(CY_PINS_VPAN_H) /* Pins VPAN_H */
#define CY_PINS_VPAN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "VPAN_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 VPAN__PORT == 15 && ((VPAN__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    VPAN_Write(uint8 value);
void    VPAN_SetDriveMode(uint8 mode);
uint8   VPAN_ReadDataReg(void);
uint8   VPAN_Read(void);
void    VPAN_SetInterruptMode(uint16 position, uint16 mode);
uint8   VPAN_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the VPAN_SetDriveMode() function.
     *  @{
     */
        #define VPAN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define VPAN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define VPAN_DM_RES_UP          PIN_DM_RES_UP
        #define VPAN_DM_RES_DWN         PIN_DM_RES_DWN
        #define VPAN_DM_OD_LO           PIN_DM_OD_LO
        #define VPAN_DM_OD_HI           PIN_DM_OD_HI
        #define VPAN_DM_STRONG          PIN_DM_STRONG
        #define VPAN_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define VPAN_MASK               VPAN__MASK
#define VPAN_SHIFT              VPAN__SHIFT
#define VPAN_WIDTH              1u

/* Interrupt constants */
#if defined(VPAN__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in VPAN_SetInterruptMode() function.
     *  @{
     */
        #define VPAN_INTR_NONE      (uint16)(0x0000u)
        #define VPAN_INTR_RISING    (uint16)(0x0001u)
        #define VPAN_INTR_FALLING   (uint16)(0x0002u)
        #define VPAN_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define VPAN_INTR_MASK      (0x01u) 
#endif /* (VPAN__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define VPAN_PS                     (* (reg8 *) VPAN__PS)
/* Data Register */
#define VPAN_DR                     (* (reg8 *) VPAN__DR)
/* Port Number */
#define VPAN_PRT_NUM                (* (reg8 *) VPAN__PRT) 
/* Connect to Analog Globals */                                                  
#define VPAN_AG                     (* (reg8 *) VPAN__AG)                       
/* Analog MUX bux enable */
#define VPAN_AMUX                   (* (reg8 *) VPAN__AMUX) 
/* Bidirectional Enable */                                                        
#define VPAN_BIE                    (* (reg8 *) VPAN__BIE)
/* Bit-mask for Aliased Register Access */
#define VPAN_BIT_MASK               (* (reg8 *) VPAN__BIT_MASK)
/* Bypass Enable */
#define VPAN_BYP                    (* (reg8 *) VPAN__BYP)
/* Port wide control signals */                                                   
#define VPAN_CTL                    (* (reg8 *) VPAN__CTL)
/* Drive Modes */
#define VPAN_DM0                    (* (reg8 *) VPAN__DM0) 
#define VPAN_DM1                    (* (reg8 *) VPAN__DM1)
#define VPAN_DM2                    (* (reg8 *) VPAN__DM2) 
/* Input Buffer Disable Override */
#define VPAN_INP_DIS                (* (reg8 *) VPAN__INP_DIS)
/* LCD Common or Segment Drive */
#define VPAN_LCD_COM_SEG            (* (reg8 *) VPAN__LCD_COM_SEG)
/* Enable Segment LCD */
#define VPAN_LCD_EN                 (* (reg8 *) VPAN__LCD_EN)
/* Slew Rate Control */
#define VPAN_SLW                    (* (reg8 *) VPAN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define VPAN_PRTDSI__CAPS_SEL       (* (reg8 *) VPAN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define VPAN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) VPAN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define VPAN_PRTDSI__OE_SEL0        (* (reg8 *) VPAN__PRTDSI__OE_SEL0) 
#define VPAN_PRTDSI__OE_SEL1        (* (reg8 *) VPAN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define VPAN_PRTDSI__OUT_SEL0       (* (reg8 *) VPAN__PRTDSI__OUT_SEL0) 
#define VPAN_PRTDSI__OUT_SEL1       (* (reg8 *) VPAN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define VPAN_PRTDSI__SYNC_OUT       (* (reg8 *) VPAN__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(VPAN__SIO_CFG)
    #define VPAN_SIO_HYST_EN        (* (reg8 *) VPAN__SIO_HYST_EN)
    #define VPAN_SIO_REG_HIFREQ     (* (reg8 *) VPAN__SIO_REG_HIFREQ)
    #define VPAN_SIO_CFG            (* (reg8 *) VPAN__SIO_CFG)
    #define VPAN_SIO_DIFF           (* (reg8 *) VPAN__SIO_DIFF)
#endif /* (VPAN__SIO_CFG) */

/* Interrupt Registers */
#if defined(VPAN__INTSTAT)
    #define VPAN_INTSTAT            (* (reg8 *) VPAN__INTSTAT)
    #define VPAN_SNAP               (* (reg8 *) VPAN__SNAP)
    
	#define VPAN_0_INTTYPE_REG 		(* (reg8 *) VPAN__0__INTTYPE)
#endif /* (VPAN__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_VPAN_H */


/* [] END OF FILE */
