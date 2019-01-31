/*******************************************************************************
* File Name: PWM_TIMER_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM_TIMER.h"

static PWM_TIMER_backupStruct PWM_TIMER_backup;


/*******************************************************************************
* Function Name: PWM_TIMER_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_TIMER_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_TIMER_SaveConfig(void) 
{

    #if(!PWM_TIMER_UsingFixedFunction)
        #if(!PWM_TIMER_PWMModeIsCenterAligned)
            PWM_TIMER_backup.PWMPeriod = PWM_TIMER_ReadPeriod();
        #endif /* (!PWM_TIMER_PWMModeIsCenterAligned) */
        PWM_TIMER_backup.PWMUdb = PWM_TIMER_ReadCounter();
        #if (PWM_TIMER_UseStatus)
            PWM_TIMER_backup.InterruptMaskValue = PWM_TIMER_STATUS_MASK;
        #endif /* (PWM_TIMER_UseStatus) */

        #if(PWM_TIMER_DeadBandMode == PWM_TIMER__B_PWM__DBM_256_CLOCKS || \
            PWM_TIMER_DeadBandMode == PWM_TIMER__B_PWM__DBM_2_4_CLOCKS)
            PWM_TIMER_backup.PWMdeadBandValue = PWM_TIMER_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_TIMER_KillModeMinTime)
             PWM_TIMER_backup.PWMKillCounterPeriod = PWM_TIMER_ReadKillTime();
        #endif /* (PWM_TIMER_KillModeMinTime) */

        #if(PWM_TIMER_UseControl)
            PWM_TIMER_backup.PWMControlRegister = PWM_TIMER_ReadControlRegister();
        #endif /* (PWM_TIMER_UseControl) */
    #endif  /* (!PWM_TIMER_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_TIMER_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_TIMER_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_TIMER_RestoreConfig(void) 
{
        #if(!PWM_TIMER_UsingFixedFunction)
            #if(!PWM_TIMER_PWMModeIsCenterAligned)
                PWM_TIMER_WritePeriod(PWM_TIMER_backup.PWMPeriod);
            #endif /* (!PWM_TIMER_PWMModeIsCenterAligned) */

            PWM_TIMER_WriteCounter(PWM_TIMER_backup.PWMUdb);

            #if (PWM_TIMER_UseStatus)
                PWM_TIMER_STATUS_MASK = PWM_TIMER_backup.InterruptMaskValue;
            #endif /* (PWM_TIMER_UseStatus) */

            #if(PWM_TIMER_DeadBandMode == PWM_TIMER__B_PWM__DBM_256_CLOCKS || \
                PWM_TIMER_DeadBandMode == PWM_TIMER__B_PWM__DBM_2_4_CLOCKS)
                PWM_TIMER_WriteDeadTime(PWM_TIMER_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_TIMER_KillModeMinTime)
                PWM_TIMER_WriteKillTime(PWM_TIMER_backup.PWMKillCounterPeriod);
            #endif /* (PWM_TIMER_KillModeMinTime) */

            #if(PWM_TIMER_UseControl)
                PWM_TIMER_WriteControlRegister(PWM_TIMER_backup.PWMControlRegister);
            #endif /* (PWM_TIMER_UseControl) */
        #endif  /* (!PWM_TIMER_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_TIMER_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_TIMER_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_TIMER_Sleep(void) 
{
    #if(PWM_TIMER_UseControl)
        if(PWM_TIMER_CTRL_ENABLE == (PWM_TIMER_CONTROL & PWM_TIMER_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_TIMER_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_TIMER_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_TIMER_UseControl) */

    /* Stop component */
    PWM_TIMER_Stop();

    /* Save registers configuration */
    PWM_TIMER_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_TIMER_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_TIMER_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_TIMER_Wakeup(void) 
{
     /* Restore registers values */
    PWM_TIMER_RestoreConfig();

    if(PWM_TIMER_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_TIMER_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
