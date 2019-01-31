/*******************************************************************************
* File Name: niveau.h  
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

#if !defined(CY_PINS_niveau_ALIASES_H) /* Pins niveau_ALIASES_H */
#define CY_PINS_niveau_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define niveau_0			(niveau__0__PC)
#define niveau_0_INTR	((uint16)((uint16)0x0001u << niveau__0__SHIFT))

#define niveau_1			(niveau__1__PC)
#define niveau_1_INTR	((uint16)((uint16)0x0001u << niveau__1__SHIFT))

#define niveau_2			(niveau__2__PC)
#define niveau_2_INTR	((uint16)((uint16)0x0001u << niveau__2__SHIFT))

#define niveau_3			(niveau__3__PC)
#define niveau_3_INTR	((uint16)((uint16)0x0001u << niveau__3__SHIFT))

#define niveau_4			(niveau__4__PC)
#define niveau_4_INTR	((uint16)((uint16)0x0001u << niveau__4__SHIFT))

#define niveau_5			(niveau__5__PC)
#define niveau_5_INTR	((uint16)((uint16)0x0001u << niveau__5__SHIFT))

#define niveau_6			(niveau__6__PC)
#define niveau_6_INTR	((uint16)((uint16)0x0001u << niveau__6__SHIFT))

#define niveau_7			(niveau__7__PC)
#define niveau_7_INTR	((uint16)((uint16)0x0001u << niveau__7__SHIFT))

#define niveau_INTR_ALL	 ((uint16)(niveau_0_INTR| niveau_1_INTR| niveau_2_INTR| niveau_3_INTR| niveau_4_INTR| niveau_5_INTR| niveau_6_INTR| niveau_7_INTR))

#endif /* End Pins niveau_ALIASES_H */


/* [] END OF FILE */
