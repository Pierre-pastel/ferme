/*******************************************************************************
* File Name: Sw_1.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Sw_1_ALIASES_H) /* Pins Sw_1_ALIASES_H */
#define CY_PINS_Sw_1_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Sw_1_0			(Sw_1__0__PC)
#define Sw_1_0_INTR	((uint16)((uint16)0x0001u << Sw_1__0__SHIFT))

#define Sw_1_1			(Sw_1__1__PC)
#define Sw_1_1_INTR	((uint16)((uint16)0x0001u << Sw_1__1__SHIFT))

#define Sw_1_2			(Sw_1__2__PC)
#define Sw_1_2_INTR	((uint16)((uint16)0x0001u << Sw_1__2__SHIFT))

#define Sw_1_3			(Sw_1__3__PC)
#define Sw_1_3_INTR	((uint16)((uint16)0x0001u << Sw_1__3__SHIFT))

#define Sw_1_4			(Sw_1__4__PC)
#define Sw_1_4_INTR	((uint16)((uint16)0x0001u << Sw_1__4__SHIFT))

#define Sw_1_5			(Sw_1__5__PC)
#define Sw_1_5_INTR	((uint16)((uint16)0x0001u << Sw_1__5__SHIFT))

#define Sw_1_6			(Sw_1__6__PC)
#define Sw_1_6_INTR	((uint16)((uint16)0x0001u << Sw_1__6__SHIFT))

#define Sw_1_7			(Sw_1__7__PC)
#define Sw_1_7_INTR	((uint16)((uint16)0x0001u << Sw_1__7__SHIFT))

#define Sw_1_INTR_ALL	 ((uint16)(Sw_1_0_INTR| Sw_1_1_INTR| Sw_1_2_INTR| Sw_1_3_INTR| Sw_1_4_INTR| Sw_1_5_INTR| Sw_1_6_INTR| Sw_1_7_INTR))

#endif /* End Pins Sw_1_ALIASES_H */


/* [] END OF FILE */
