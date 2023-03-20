/*******************************************************************************
* File Name: rigth.h  
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

#if !defined(CY_PINS_rigth_H) /* Pins rigth_H */
#define CY_PINS_rigth_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "rigth_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 rigth__PORT == 15 && ((rigth__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    rigth_Write(uint8 value);
void    rigth_SetDriveMode(uint8 mode);
uint8   rigth_ReadDataReg(void);
uint8   rigth_Read(void);
void    rigth_SetInterruptMode(uint16 position, uint16 mode);
uint8   rigth_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the rigth_SetDriveMode() function.
     *  @{
     */
        #define rigth_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define rigth_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define rigth_DM_RES_UP          PIN_DM_RES_UP
        #define rigth_DM_RES_DWN         PIN_DM_RES_DWN
        #define rigth_DM_OD_LO           PIN_DM_OD_LO
        #define rigth_DM_OD_HI           PIN_DM_OD_HI
        #define rigth_DM_STRONG          PIN_DM_STRONG
        #define rigth_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define rigth_MASK               rigth__MASK
#define rigth_SHIFT              rigth__SHIFT
#define rigth_WIDTH              1u

/* Interrupt constants */
#if defined(rigth__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in rigth_SetInterruptMode() function.
     *  @{
     */
        #define rigth_INTR_NONE      (uint16)(0x0000u)
        #define rigth_INTR_RISING    (uint16)(0x0001u)
        #define rigth_INTR_FALLING   (uint16)(0x0002u)
        #define rigth_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define rigth_INTR_MASK      (0x01u) 
#endif /* (rigth__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define rigth_PS                     (* (reg8 *) rigth__PS)
/* Data Register */
#define rigth_DR                     (* (reg8 *) rigth__DR)
/* Port Number */
#define rigth_PRT_NUM                (* (reg8 *) rigth__PRT) 
/* Connect to Analog Globals */                                                  
#define rigth_AG                     (* (reg8 *) rigth__AG)                       
/* Analog MUX bux enable */
#define rigth_AMUX                   (* (reg8 *) rigth__AMUX) 
/* Bidirectional Enable */                                                        
#define rigth_BIE                    (* (reg8 *) rigth__BIE)
/* Bit-mask for Aliased Register Access */
#define rigth_BIT_MASK               (* (reg8 *) rigth__BIT_MASK)
/* Bypass Enable */
#define rigth_BYP                    (* (reg8 *) rigth__BYP)
/* Port wide control signals */                                                   
#define rigth_CTL                    (* (reg8 *) rigth__CTL)
/* Drive Modes */
#define rigth_DM0                    (* (reg8 *) rigth__DM0) 
#define rigth_DM1                    (* (reg8 *) rigth__DM1)
#define rigth_DM2                    (* (reg8 *) rigth__DM2) 
/* Input Buffer Disable Override */
#define rigth_INP_DIS                (* (reg8 *) rigth__INP_DIS)
/* LCD Common or Segment Drive */
#define rigth_LCD_COM_SEG            (* (reg8 *) rigth__LCD_COM_SEG)
/* Enable Segment LCD */
#define rigth_LCD_EN                 (* (reg8 *) rigth__LCD_EN)
/* Slew Rate Control */
#define rigth_SLW                    (* (reg8 *) rigth__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define rigth_PRTDSI__CAPS_SEL       (* (reg8 *) rigth__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define rigth_PRTDSI__DBL_SYNC_IN    (* (reg8 *) rigth__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define rigth_PRTDSI__OE_SEL0        (* (reg8 *) rigth__PRTDSI__OE_SEL0) 
#define rigth_PRTDSI__OE_SEL1        (* (reg8 *) rigth__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define rigth_PRTDSI__OUT_SEL0       (* (reg8 *) rigth__PRTDSI__OUT_SEL0) 
#define rigth_PRTDSI__OUT_SEL1       (* (reg8 *) rigth__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define rigth_PRTDSI__SYNC_OUT       (* (reg8 *) rigth__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(rigth__SIO_CFG)
    #define rigth_SIO_HYST_EN        (* (reg8 *) rigth__SIO_HYST_EN)
    #define rigth_SIO_REG_HIFREQ     (* (reg8 *) rigth__SIO_REG_HIFREQ)
    #define rigth_SIO_CFG            (* (reg8 *) rigth__SIO_CFG)
    #define rigth_SIO_DIFF           (* (reg8 *) rigth__SIO_DIFF)
#endif /* (rigth__SIO_CFG) */

/* Interrupt Registers */
#if defined(rigth__INTSTAT)
    #define rigth_INTSTAT            (* (reg8 *) rigth__INTSTAT)
    #define rigth_SNAP               (* (reg8 *) rigth__SNAP)
    
	#define rigth_0_INTTYPE_REG 		(* (reg8 *) rigth__0__INTTYPE)
#endif /* (rigth__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_rigth_H */


/* [] END OF FILE */
