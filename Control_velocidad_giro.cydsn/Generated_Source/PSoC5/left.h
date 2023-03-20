/*******************************************************************************
* File Name: left.h  
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

#if !defined(CY_PINS_left_H) /* Pins left_H */
#define CY_PINS_left_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "left_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 left__PORT == 15 && ((left__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    left_Write(uint8 value);
void    left_SetDriveMode(uint8 mode);
uint8   left_ReadDataReg(void);
uint8   left_Read(void);
void    left_SetInterruptMode(uint16 position, uint16 mode);
uint8   left_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the left_SetDriveMode() function.
     *  @{
     */
        #define left_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define left_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define left_DM_RES_UP          PIN_DM_RES_UP
        #define left_DM_RES_DWN         PIN_DM_RES_DWN
        #define left_DM_OD_LO           PIN_DM_OD_LO
        #define left_DM_OD_HI           PIN_DM_OD_HI
        #define left_DM_STRONG          PIN_DM_STRONG
        #define left_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define left_MASK               left__MASK
#define left_SHIFT              left__SHIFT
#define left_WIDTH              1u

/* Interrupt constants */
#if defined(left__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in left_SetInterruptMode() function.
     *  @{
     */
        #define left_INTR_NONE      (uint16)(0x0000u)
        #define left_INTR_RISING    (uint16)(0x0001u)
        #define left_INTR_FALLING   (uint16)(0x0002u)
        #define left_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define left_INTR_MASK      (0x01u) 
#endif /* (left__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define left_PS                     (* (reg8 *) left__PS)
/* Data Register */
#define left_DR                     (* (reg8 *) left__DR)
/* Port Number */
#define left_PRT_NUM                (* (reg8 *) left__PRT) 
/* Connect to Analog Globals */                                                  
#define left_AG                     (* (reg8 *) left__AG)                       
/* Analog MUX bux enable */
#define left_AMUX                   (* (reg8 *) left__AMUX) 
/* Bidirectional Enable */                                                        
#define left_BIE                    (* (reg8 *) left__BIE)
/* Bit-mask for Aliased Register Access */
#define left_BIT_MASK               (* (reg8 *) left__BIT_MASK)
/* Bypass Enable */
#define left_BYP                    (* (reg8 *) left__BYP)
/* Port wide control signals */                                                   
#define left_CTL                    (* (reg8 *) left__CTL)
/* Drive Modes */
#define left_DM0                    (* (reg8 *) left__DM0) 
#define left_DM1                    (* (reg8 *) left__DM1)
#define left_DM2                    (* (reg8 *) left__DM2) 
/* Input Buffer Disable Override */
#define left_INP_DIS                (* (reg8 *) left__INP_DIS)
/* LCD Common or Segment Drive */
#define left_LCD_COM_SEG            (* (reg8 *) left__LCD_COM_SEG)
/* Enable Segment LCD */
#define left_LCD_EN                 (* (reg8 *) left__LCD_EN)
/* Slew Rate Control */
#define left_SLW                    (* (reg8 *) left__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define left_PRTDSI__CAPS_SEL       (* (reg8 *) left__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define left_PRTDSI__DBL_SYNC_IN    (* (reg8 *) left__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define left_PRTDSI__OE_SEL0        (* (reg8 *) left__PRTDSI__OE_SEL0) 
#define left_PRTDSI__OE_SEL1        (* (reg8 *) left__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define left_PRTDSI__OUT_SEL0       (* (reg8 *) left__PRTDSI__OUT_SEL0) 
#define left_PRTDSI__OUT_SEL1       (* (reg8 *) left__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define left_PRTDSI__SYNC_OUT       (* (reg8 *) left__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(left__SIO_CFG)
    #define left_SIO_HYST_EN        (* (reg8 *) left__SIO_HYST_EN)
    #define left_SIO_REG_HIFREQ     (* (reg8 *) left__SIO_REG_HIFREQ)
    #define left_SIO_CFG            (* (reg8 *) left__SIO_CFG)
    #define left_SIO_DIFF           (* (reg8 *) left__SIO_DIFF)
#endif /* (left__SIO_CFG) */

/* Interrupt Registers */
#if defined(left__INTSTAT)
    #define left_INTSTAT            (* (reg8 *) left__INTSTAT)
    #define left_SNAP               (* (reg8 *) left__SNAP)
    
	#define left_0_INTTYPE_REG 		(* (reg8 *) left__0__INTTYPE)
#endif /* (left__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_left_H */


/* [] END OF FILE */
