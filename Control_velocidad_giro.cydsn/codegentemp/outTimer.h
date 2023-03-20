/*******************************************************************************
* File Name: outTimer.h  
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

#if !defined(CY_PINS_outTimer_H) /* Pins outTimer_H */
#define CY_PINS_outTimer_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "outTimer_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 outTimer__PORT == 15 && ((outTimer__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    outTimer_Write(uint8 value);
void    outTimer_SetDriveMode(uint8 mode);
uint8   outTimer_ReadDataReg(void);
uint8   outTimer_Read(void);
void    outTimer_SetInterruptMode(uint16 position, uint16 mode);
uint8   outTimer_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the outTimer_SetDriveMode() function.
     *  @{
     */
        #define outTimer_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define outTimer_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define outTimer_DM_RES_UP          PIN_DM_RES_UP
        #define outTimer_DM_RES_DWN         PIN_DM_RES_DWN
        #define outTimer_DM_OD_LO           PIN_DM_OD_LO
        #define outTimer_DM_OD_HI           PIN_DM_OD_HI
        #define outTimer_DM_STRONG          PIN_DM_STRONG
        #define outTimer_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define outTimer_MASK               outTimer__MASK
#define outTimer_SHIFT              outTimer__SHIFT
#define outTimer_WIDTH              1u

/* Interrupt constants */
#if defined(outTimer__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in outTimer_SetInterruptMode() function.
     *  @{
     */
        #define outTimer_INTR_NONE      (uint16)(0x0000u)
        #define outTimer_INTR_RISING    (uint16)(0x0001u)
        #define outTimer_INTR_FALLING   (uint16)(0x0002u)
        #define outTimer_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define outTimer_INTR_MASK      (0x01u) 
#endif /* (outTimer__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define outTimer_PS                     (* (reg8 *) outTimer__PS)
/* Data Register */
#define outTimer_DR                     (* (reg8 *) outTimer__DR)
/* Port Number */
#define outTimer_PRT_NUM                (* (reg8 *) outTimer__PRT) 
/* Connect to Analog Globals */                                                  
#define outTimer_AG                     (* (reg8 *) outTimer__AG)                       
/* Analog MUX bux enable */
#define outTimer_AMUX                   (* (reg8 *) outTimer__AMUX) 
/* Bidirectional Enable */                                                        
#define outTimer_BIE                    (* (reg8 *) outTimer__BIE)
/* Bit-mask for Aliased Register Access */
#define outTimer_BIT_MASK               (* (reg8 *) outTimer__BIT_MASK)
/* Bypass Enable */
#define outTimer_BYP                    (* (reg8 *) outTimer__BYP)
/* Port wide control signals */                                                   
#define outTimer_CTL                    (* (reg8 *) outTimer__CTL)
/* Drive Modes */
#define outTimer_DM0                    (* (reg8 *) outTimer__DM0) 
#define outTimer_DM1                    (* (reg8 *) outTimer__DM1)
#define outTimer_DM2                    (* (reg8 *) outTimer__DM2) 
/* Input Buffer Disable Override */
#define outTimer_INP_DIS                (* (reg8 *) outTimer__INP_DIS)
/* LCD Common or Segment Drive */
#define outTimer_LCD_COM_SEG            (* (reg8 *) outTimer__LCD_COM_SEG)
/* Enable Segment LCD */
#define outTimer_LCD_EN                 (* (reg8 *) outTimer__LCD_EN)
/* Slew Rate Control */
#define outTimer_SLW                    (* (reg8 *) outTimer__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define outTimer_PRTDSI__CAPS_SEL       (* (reg8 *) outTimer__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define outTimer_PRTDSI__DBL_SYNC_IN    (* (reg8 *) outTimer__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define outTimer_PRTDSI__OE_SEL0        (* (reg8 *) outTimer__PRTDSI__OE_SEL0) 
#define outTimer_PRTDSI__OE_SEL1        (* (reg8 *) outTimer__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define outTimer_PRTDSI__OUT_SEL0       (* (reg8 *) outTimer__PRTDSI__OUT_SEL0) 
#define outTimer_PRTDSI__OUT_SEL1       (* (reg8 *) outTimer__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define outTimer_PRTDSI__SYNC_OUT       (* (reg8 *) outTimer__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(outTimer__SIO_CFG)
    #define outTimer_SIO_HYST_EN        (* (reg8 *) outTimer__SIO_HYST_EN)
    #define outTimer_SIO_REG_HIFREQ     (* (reg8 *) outTimer__SIO_REG_HIFREQ)
    #define outTimer_SIO_CFG            (* (reg8 *) outTimer__SIO_CFG)
    #define outTimer_SIO_DIFF           (* (reg8 *) outTimer__SIO_DIFF)
#endif /* (outTimer__SIO_CFG) */

/* Interrupt Registers */
#if defined(outTimer__INTSTAT)
    #define outTimer_INTSTAT            (* (reg8 *) outTimer__INTSTAT)
    #define outTimer_SNAP               (* (reg8 *) outTimer__SNAP)
    
	#define outTimer_0_INTTYPE_REG 		(* (reg8 *) outTimer__0__INTTYPE)
#endif /* (outTimer__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_outTimer_H */


/* [] END OF FILE */
