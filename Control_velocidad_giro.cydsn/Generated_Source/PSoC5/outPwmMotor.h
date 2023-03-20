/*******************************************************************************
* File Name: outPwmMotor.h  
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

#if !defined(CY_PINS_outPwmMotor_H) /* Pins outPwmMotor_H */
#define CY_PINS_outPwmMotor_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "outPwmMotor_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 outPwmMotor__PORT == 15 && ((outPwmMotor__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    outPwmMotor_Write(uint8 value);
void    outPwmMotor_SetDriveMode(uint8 mode);
uint8   outPwmMotor_ReadDataReg(void);
uint8   outPwmMotor_Read(void);
void    outPwmMotor_SetInterruptMode(uint16 position, uint16 mode);
uint8   outPwmMotor_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the outPwmMotor_SetDriveMode() function.
     *  @{
     */
        #define outPwmMotor_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define outPwmMotor_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define outPwmMotor_DM_RES_UP          PIN_DM_RES_UP
        #define outPwmMotor_DM_RES_DWN         PIN_DM_RES_DWN
        #define outPwmMotor_DM_OD_LO           PIN_DM_OD_LO
        #define outPwmMotor_DM_OD_HI           PIN_DM_OD_HI
        #define outPwmMotor_DM_STRONG          PIN_DM_STRONG
        #define outPwmMotor_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define outPwmMotor_MASK               outPwmMotor__MASK
#define outPwmMotor_SHIFT              outPwmMotor__SHIFT
#define outPwmMotor_WIDTH              1u

/* Interrupt constants */
#if defined(outPwmMotor__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in outPwmMotor_SetInterruptMode() function.
     *  @{
     */
        #define outPwmMotor_INTR_NONE      (uint16)(0x0000u)
        #define outPwmMotor_INTR_RISING    (uint16)(0x0001u)
        #define outPwmMotor_INTR_FALLING   (uint16)(0x0002u)
        #define outPwmMotor_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define outPwmMotor_INTR_MASK      (0x01u) 
#endif /* (outPwmMotor__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define outPwmMotor_PS                     (* (reg8 *) outPwmMotor__PS)
/* Data Register */
#define outPwmMotor_DR                     (* (reg8 *) outPwmMotor__DR)
/* Port Number */
#define outPwmMotor_PRT_NUM                (* (reg8 *) outPwmMotor__PRT) 
/* Connect to Analog Globals */                                                  
#define outPwmMotor_AG                     (* (reg8 *) outPwmMotor__AG)                       
/* Analog MUX bux enable */
#define outPwmMotor_AMUX                   (* (reg8 *) outPwmMotor__AMUX) 
/* Bidirectional Enable */                                                        
#define outPwmMotor_BIE                    (* (reg8 *) outPwmMotor__BIE)
/* Bit-mask for Aliased Register Access */
#define outPwmMotor_BIT_MASK               (* (reg8 *) outPwmMotor__BIT_MASK)
/* Bypass Enable */
#define outPwmMotor_BYP                    (* (reg8 *) outPwmMotor__BYP)
/* Port wide control signals */                                                   
#define outPwmMotor_CTL                    (* (reg8 *) outPwmMotor__CTL)
/* Drive Modes */
#define outPwmMotor_DM0                    (* (reg8 *) outPwmMotor__DM0) 
#define outPwmMotor_DM1                    (* (reg8 *) outPwmMotor__DM1)
#define outPwmMotor_DM2                    (* (reg8 *) outPwmMotor__DM2) 
/* Input Buffer Disable Override */
#define outPwmMotor_INP_DIS                (* (reg8 *) outPwmMotor__INP_DIS)
/* LCD Common or Segment Drive */
#define outPwmMotor_LCD_COM_SEG            (* (reg8 *) outPwmMotor__LCD_COM_SEG)
/* Enable Segment LCD */
#define outPwmMotor_LCD_EN                 (* (reg8 *) outPwmMotor__LCD_EN)
/* Slew Rate Control */
#define outPwmMotor_SLW                    (* (reg8 *) outPwmMotor__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define outPwmMotor_PRTDSI__CAPS_SEL       (* (reg8 *) outPwmMotor__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define outPwmMotor_PRTDSI__DBL_SYNC_IN    (* (reg8 *) outPwmMotor__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define outPwmMotor_PRTDSI__OE_SEL0        (* (reg8 *) outPwmMotor__PRTDSI__OE_SEL0) 
#define outPwmMotor_PRTDSI__OE_SEL1        (* (reg8 *) outPwmMotor__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define outPwmMotor_PRTDSI__OUT_SEL0       (* (reg8 *) outPwmMotor__PRTDSI__OUT_SEL0) 
#define outPwmMotor_PRTDSI__OUT_SEL1       (* (reg8 *) outPwmMotor__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define outPwmMotor_PRTDSI__SYNC_OUT       (* (reg8 *) outPwmMotor__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(outPwmMotor__SIO_CFG)
    #define outPwmMotor_SIO_HYST_EN        (* (reg8 *) outPwmMotor__SIO_HYST_EN)
    #define outPwmMotor_SIO_REG_HIFREQ     (* (reg8 *) outPwmMotor__SIO_REG_HIFREQ)
    #define outPwmMotor_SIO_CFG            (* (reg8 *) outPwmMotor__SIO_CFG)
    #define outPwmMotor_SIO_DIFF           (* (reg8 *) outPwmMotor__SIO_DIFF)
#endif /* (outPwmMotor__SIO_CFG) */

/* Interrupt Registers */
#if defined(outPwmMotor__INTSTAT)
    #define outPwmMotor_INTSTAT            (* (reg8 *) outPwmMotor__INTSTAT)
    #define outPwmMotor_SNAP               (* (reg8 *) outPwmMotor__SNAP)
    
	#define outPwmMotor_0_INTTYPE_REG 		(* (reg8 *) outPwmMotor__0__INTTYPE)
#endif /* (outPwmMotor__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_outPwmMotor_H */


/* [] END OF FILE */
