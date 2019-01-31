/*******************************************************************************
* File Name: Relais.h  
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

#if !defined(CY_PINS_Relais_H) /* Pins Relais_H */
#define CY_PINS_Relais_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Relais_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Relais__PORT == 15 && ((Relais__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Relais_Write(uint8 value);
void    Relais_SetDriveMode(uint8 mode);
uint8   Relais_ReadDataReg(void);
uint8   Relais_Read(void);
void    Relais_SetInterruptMode(uint16 position, uint16 mode);
uint8   Relais_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Relais_SetDriveMode() function.
     *  @{
     */
        #define Relais_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Relais_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Relais_DM_RES_UP          PIN_DM_RES_UP
        #define Relais_DM_RES_DWN         PIN_DM_RES_DWN
        #define Relais_DM_OD_LO           PIN_DM_OD_LO
        #define Relais_DM_OD_HI           PIN_DM_OD_HI
        #define Relais_DM_STRONG          PIN_DM_STRONG
        #define Relais_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Relais_MASK               Relais__MASK
#define Relais_SHIFT              Relais__SHIFT
#define Relais_WIDTH              1u

/* Interrupt constants */
#if defined(Relais__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Relais_SetInterruptMode() function.
     *  @{
     */
        #define Relais_INTR_NONE      (uint16)(0x0000u)
        #define Relais_INTR_RISING    (uint16)(0x0001u)
        #define Relais_INTR_FALLING   (uint16)(0x0002u)
        #define Relais_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Relais_INTR_MASK      (0x01u) 
#endif /* (Relais__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Relais_PS                     (* (reg8 *) Relais__PS)
/* Data Register */
#define Relais_DR                     (* (reg8 *) Relais__DR)
/* Port Number */
#define Relais_PRT_NUM                (* (reg8 *) Relais__PRT) 
/* Connect to Analog Globals */                                                  
#define Relais_AG                     (* (reg8 *) Relais__AG)                       
/* Analog MUX bux enable */
#define Relais_AMUX                   (* (reg8 *) Relais__AMUX) 
/* Bidirectional Enable */                                                        
#define Relais_BIE                    (* (reg8 *) Relais__BIE)
/* Bit-mask for Aliased Register Access */
#define Relais_BIT_MASK               (* (reg8 *) Relais__BIT_MASK)
/* Bypass Enable */
#define Relais_BYP                    (* (reg8 *) Relais__BYP)
/* Port wide control signals */                                                   
#define Relais_CTL                    (* (reg8 *) Relais__CTL)
/* Drive Modes */
#define Relais_DM0                    (* (reg8 *) Relais__DM0) 
#define Relais_DM1                    (* (reg8 *) Relais__DM1)
#define Relais_DM2                    (* (reg8 *) Relais__DM2) 
/* Input Buffer Disable Override */
#define Relais_INP_DIS                (* (reg8 *) Relais__INP_DIS)
/* LCD Common or Segment Drive */
#define Relais_LCD_COM_SEG            (* (reg8 *) Relais__LCD_COM_SEG)
/* Enable Segment LCD */
#define Relais_LCD_EN                 (* (reg8 *) Relais__LCD_EN)
/* Slew Rate Control */
#define Relais_SLW                    (* (reg8 *) Relais__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Relais_PRTDSI__CAPS_SEL       (* (reg8 *) Relais__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Relais_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Relais__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Relais_PRTDSI__OE_SEL0        (* (reg8 *) Relais__PRTDSI__OE_SEL0) 
#define Relais_PRTDSI__OE_SEL1        (* (reg8 *) Relais__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Relais_PRTDSI__OUT_SEL0       (* (reg8 *) Relais__PRTDSI__OUT_SEL0) 
#define Relais_PRTDSI__OUT_SEL1       (* (reg8 *) Relais__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Relais_PRTDSI__SYNC_OUT       (* (reg8 *) Relais__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Relais__SIO_CFG)
    #define Relais_SIO_HYST_EN        (* (reg8 *) Relais__SIO_HYST_EN)
    #define Relais_SIO_REG_HIFREQ     (* (reg8 *) Relais__SIO_REG_HIFREQ)
    #define Relais_SIO_CFG            (* (reg8 *) Relais__SIO_CFG)
    #define Relais_SIO_DIFF           (* (reg8 *) Relais__SIO_DIFF)
#endif /* (Relais__SIO_CFG) */

/* Interrupt Registers */
#if defined(Relais__INTSTAT)
    #define Relais_INTSTAT            (* (reg8 *) Relais__INTSTAT)
    #define Relais_SNAP               (* (reg8 *) Relais__SNAP)
    
	#define Relais_0_INTTYPE_REG 		(* (reg8 *) Relais__0__INTTYPE)
#endif /* (Relais__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Relais_H */


/* [] END OF FILE */
