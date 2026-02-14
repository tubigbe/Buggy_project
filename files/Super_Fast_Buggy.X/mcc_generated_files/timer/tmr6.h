/**
 * TMR6 Generated Driver API Header File
 * 
 * @file tmr6.h
 * 
 * @ingroup timerdriver
 * 
 * @brief This file contains the API prototypes and other data types for the Timer2 (TMR6) driver.
 *
 * @version TMR6 Driver Version 2.0.0
 *
 * @version Package Version 2.0.0
*/
 
/*
? [2026] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef TMR6_H
#define TMR6_H

#include <stdint.h>
#include <stdbool.h>
#include "timer_interface.h"

/**
 * @misradeviation{@advisory,2.5}
 * MCC Melody drivers provide macros that can be added to an application. 
 * It depends on the application whether a macro is used or not. 
 */

/**
 * @ingroup timerdriver
 * @brief Defines the maximum count value of the timer.
 */
#define TMR6_MAX_COUNT (255U)
/**
 * @ingroup timerdriver
 * @brief Defines the timer prescaled clock frequency in hertz.
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define TMR6_CLOCK_FREQ (750000UL)

/**
 * @ingroup timerdriver
 * @brief Defines the Custom Name for the \ref TMR6_MAX_COUNT
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define TIMER6_MAX_COUNT TMR6_MAX_COUNT
/**
 * @ingroup timerdriver
 * @brief Defines the Custom Name for the \ref TMR6_CLOCK_FREQ
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define TIMER6_CLOCK_FREQ TMR6_CLOCK_FREQ
/**
 * @ingroup timerdriver
 * @brief Defines the Custom Name for the \ref TMR6_Initialize API.
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer6_Initialize TMR6_Initialize
/**
 * @ingroup timerdriver
 * @brief Defines the Custom Name for the \ref TMR6_Deinitialize API.
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer6_Deinitialize TMR6_Deinitialize
/**
 * @ingroup timerdriver
 * @brief Defines the Custom Name for the \ref TMR6_Start API.
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer6_Start TMR6_Start
/**
 * @ingroup timerdriver
 * @brief Defines the Custom Name for the \ref TMR6_Stop API.
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer6_Stop TMR6_Stop
/**
 * @ingroup timerdriver
 * @brief Defines the Custom Name for the \ref TMR6_CounterGet API.
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer6_CounterGet TMR6_CounterGet
/**
 * @ingroup timerdriver
 * @brief Defines the Custom Name for the \ref TMR6_CounterSet API.
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer6_CounterSet TMR6_CounterSet
/**
 * @ingroup timerdriver
 * @brief Defines the Custom Name for the \ref TMR6_PeriodSet API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer6_PeriodSet TMR6_PeriodSet
/**
 * @ingroup timerdriver
 * @brief Defines the Custom Name for the \ref TMR6_PeriodGet API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer6_PeriodGet TMR6_PeriodGet
/**
 * @ingroup timerdriver
 * @brief Defines the Custom Name for the \ref TMR6_MaxCountGet API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer6_MaxCountGet TMR6_MaxCountGet
/**
 * @ingroup timerdriver
 * @brief Defines the Custom Name for the \ref TMR6_PeriodMatchCallbackRegister API
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer6_PeriodMatchCallbackRegister TMR6_PeriodMatchCallbackRegister
/**
 * @ingroup timerdriver
 * @brief Defines the Custom Name for the \ref TMR6_Tasks API
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer6_Tasks TMR6_Tasks

/**
 @ingroup tmr6driver
 @struct TIMER_INTERFACE
 @brief Declares an instance of TIMER_INTERFACE for the TMR6 module.
 */
extern const struct TIMER_INTERFACE Timer6;

/**
 * @ingroup timerdriver
 * @brief Initializes the Timer2 (TMR6) module.
 *        This routine must be called before any other TMR6 routines.
 * @param None.
 * @return None.
 */
void TMR6_Initialize(void);

/**
 * @ingroup timerdriver
 * @brief Deinitializes the TMR6 module.
 * @param None.
 * @return None.
 */
void TMR6_Deinitialize(void);

/**
 * @ingroup timerdriver
 * @brief Starts the TMR6 timer.
 * @pre Initialize TMR6 with TMR6_Initialize() before calling this API.
 * @param None.
 * @return None.
 */
void TMR6_Start(void);

/**
 * @ingroup timerdriver
 * @brief Stops the TMR6 timer.
 * @pre Initialize TMR6 with TMR6_Initialize() before calling this API.
 * @param None.
 * @return None.
 */
void TMR6_Stop(void);

/**
 * @ingroup timer
 * @brief Returns the current counter value.
 * @pre Initialize TMR6 with TMR6_Initialize() before calling this API.
 * @param None.
 * @return Counter value from the TMR6 register
 */
uint32_t TMR6_CounterGet(void);

/**
 * @ingroup timerdriver
 * @brief Sets the counter value.
 * @pre Initialize TMR6 with TMR6_Initialize() before calling this API.
 * @param counterValue - Counter value to be written to the TMR6 register
 * @return None.
 */
void TMR6_CounterSet(uint32_t counterValue);

/**
 * @ingroup timerdriver
 * @brief Sets the period count value.
 * @pre Initialize TMR6 with TMR6_Initialize() before calling this API.
 * @param periodCount - Period count value to be written to the PR6 register
 * @return None.
 */
void TMR6_PeriodSet(uint32_t periodCount);

/**
 * @ingroup timerdriver
 * @brief Returns the current period value.
 * @pre Initialize TMR6 with TMR6_Initialize() before calling this API.
 * @param None.
 * @return Period count value
 */
uint32_t TMR6_PeriodGet(void);

/**
 * @ingroup timerdriver
 * @brief Returns the maximum count value.
 * @param None.
 * @return Maximum count value
 */
uint32_t TMR6_MaxCountGet(void);


/**
 * @ingroup timerdriver
 * @brief Registers a callback function for the TMR6 period match callback.
 * @param CallbackHandler - Address of the custom callback function
 * @return None.
 */
void TMR6_PeriodMatchCallbackRegister(void (* CallbackHandler)(void));

/**
 * @ingroup timerdriver
 * @brief Performs tasks to be executed during the TMR6 period match event.
 * @param None.
 * @return None.
 */
void TMR6_Tasks(void);

#endif // TMR6_H
/**
 End of File
*/
