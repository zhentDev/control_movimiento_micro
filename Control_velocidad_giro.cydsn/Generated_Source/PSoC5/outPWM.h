/*******************************************************************************
* File Name: outPWM.h  
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

#if !defined(CY_PINS_outPWM_H) /* Pins outPWM_H */
#define CY_PINS_outPWM_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "outPWM_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 outPWM__PORT == 15 && ((outPWM__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    outPWM_Write(uint8 value);
void    outPWM_SetDriveMode(uint8 mode);
uint8   outPWM_ReadDataReg(void);
uint8   outPWM_Read(void);
void    outPWM_SetInterruptMode(uint16 position, uint16 mode);
uint8   outPWM_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the outPWM_SetDriveMode() function.
     *  @{
     */
        #define outPWM_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define outPWM_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define outPWM_DM_RES_UP          PIN_DM_RES_UP
        #define outPWM_DM_RES_DWN         PIN_DM_RES_DWN
        #define outPWM_DM_OD_LO           PIN_DM_OD_LO
        #define outPWM_DM_OD_HI           PIN_DM_OD_HI
        #define outPWM_DM_STRONG          PIN_DM_STRONG
        #define outPWM_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define outPWM_MASK               outPWM__MASK
#define outPWM_SHIFT              outPWM__SHIFT
#define outPWM_WIDTH              1u

/* Interrupt constants */
#if defined(outPWM__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in outPWM_SetInterruptMode() function.
     *  @{
     */
        #define outPWM_INTR_NONE      (uint16)(0x0000u)
        #define outPWM_INTR_RISING    (uint16)(0x0001u)
        #define outPWM_INTR_FALLING   (uint16)(0x0002u)
        #define outPWM_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define outPWM_INTR_MASK      (0x01u) 
#endif /* (outPWM__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define outPWM_PS                     (* (reg8 *) outPWM__PS)
/* Data Register */
#define outPWM_DR                     (* (reg8 *) outPWM__DR)
/* Port Number */
#define outPWM_PRT_NUM                (* (reg8 *) outPWM__PRT) 
/* Connect to Analog Globals */                                                  
#define outPWM_AG                     (* (reg8 *) outPWM__AG)                       
/* Analog MUX bux enable */
#define outPWM_AMUX                   (* (reg8 *) outPWM__AMUX) 
/* Bidirectional Enable */                                                        
#define outPWM_BIE                    (* (reg8 *) outPWM__BIE)
/* Bit-mask for Aliased Register Access */
#define outPWM_BIT_MASK               (* (reg8 *) outPWM__BIT_MASK)
/* Bypass Enable */
#define outPWM_BYP                    (* (reg8 *) outPWM__BYP)
/* Port wide control signals */                                                   
#define outPWM_CTL                    (* (reg8 *) outPWM__CTL)
/* Drive Modes */
#define outPWM_DM0                    (* (reg8 *) outPWM__DM0) 
#define outPWM_DM1                    (* (reg8 *) outPWM__DM1)
#define outPWM_DM2                    (* (reg8 *) outPWM__DM2) 
/* Input Buffer Disable Override */
#define outPWM_INP_DIS                (* (reg8 *) outPWM__INP_DIS)
/* LCD Common or Segment Drive */
#define outPWM_LCD_COM_SEG            (* (reg8 *) outPWM__LCD_COM_SEG)
/* Enable Segment LCD */
#define outPWM_LCD_EN                 (* (reg8 *) outPWM__LCD_EN)
/* Slew Rate Control */
#define outPWM_SLW                    (* (reg8 *) outPWM__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define outPWM_PRTDSI__CAPS_SEL       (* (reg8 *) outPWM__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define outPWM_PRTDSI__DBL_SYNC_IN    (* (reg8 *) outPWM__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define outPWM_PRTDSI__OE_SEL0        (* (reg8 *) outPWM__PRTDSI__OE_SEL0) 
#define outPWM_PRTDSI__OE_SEL1        (* (reg8 *) outPWM__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define outPWM_PRTDSI__OUT_SEL0       (* (reg8 *) outPWM__PRTDSI__OUT_SEL0) 
#define outPWM_PRTDSI__OUT_SEL1       (* (reg8 *) outPWM__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define outPWM_PRTDSI__SYNC_OUT       (* (reg8 *) outPWM__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(outPWM__SIO_CFG)
    #define outPWM_SIO_HYST_EN        (* (reg8 *) outPWM__SIO_HYST_EN)
    #define outPWM_SIO_REG_HIFREQ     (* (reg8 *) outPWM__SIO_REG_HIFREQ)
    #define outPWM_SIO_CFG            (* (reg8 *) outPWM__SIO_CFG)
    #define outPWM_SIO_DIFF           (* (reg8 *) outPWM__SIO_DIFF)
#endif /* (outPWM__SIO_CFG) */

/* Interrupt Registers */
#if defined(outPWM__INTSTAT)
    #define outPWM_INTSTAT            (* (reg8 *) outPWM__INTSTAT)
    #define outPWM_SNAP               (* (reg8 *) outPWM__SNAP)
    
	#define outPWM_0_INTTYPE_REG 		(* (reg8 *) outPWM__0__INTTYPE)
#endif /* (outPWM__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_outPWM_H */


/* [] END OF FILE */
