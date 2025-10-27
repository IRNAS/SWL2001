/**
 * @file      smtc_modem_utilities.h
 *
 * @brief   modem utilities
 *
 * The Clear BSD License
 * Copyright Semtech Corporation 2021. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted (subject to the limitations in the disclaimer
 * below) provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Semtech corporation nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY
 * THIS LICENSE. THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 * CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT
 * NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL SEMTECH CORPORATION BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SMTC_MODEM_UTILITIES_H__
#define SMTC_MODEM_UTILITIES_H__

#ifdef __cplusplus
extern "C" {
#endif

/*
 * -----------------------------------------------------------------------------
 * --- DEPENDENCIES ------------------------------------------------------------
 */

#include <stdint.h>   // C99 types
#include <stdbool.h>  // bool type

#include "smtc_modem_api.h"

/*
 * -----------------------------------------------------------------------------
 * --- PUBLIC MACROS -----------------------------------------------------------
 */

/*
 * -----------------------------------------------------------------------------
 * --- PUBLIC CONSTANTS --------------------------------------------------------
 */

/*
 * -----------------------------------------------------------------------------
 * --- PUBLIC TYPES ------------------------------------------------------------
 */

/*
 * -----------------------------------------------------------------------------
 * --- PUBLIC FUNCTIONS PROTOTYPES ---------------------------------------------
 */

/**
 * @brief Init the soft modem and set the modem event chosen callback
 * @remark The callback will be called each time an modem event is raised internally - for all stacks
 *
 * @param [in] event_callback User event callback prototype
 */
void smtc_modem_init_common( void ( *event_callback )( void ) );

/**
 * @brief Init the soft modem for a given stack and radio
 *
 * @param [in] stack_id stack identifier
 */
void smtc_modem_init( uint8_t stack_id );

/**
 * @brief Run the modem engine
 * @remark This function must be called in main loop. It returns an amount of ms after which the function must at least
 * be called again
 *
 * @param [in] stack_id stack identifier
 *
 * @return  the time in ms after which the function must at least be called again
 */
uint32_t smtc_modem_run_engine( uint8_t stack_id );

/**
 * @brief Check if some modem irq flags are pending
 *
 * @param [in] stack_id stack identifier
 *
 * @return true if some flags are pending, false otherwise
 */
bool smtc_modem_is_irq_flag_pending( uint8_t stack_id );

/**
 * @brief Set optional user radio context that can be retrieved in radio drivers hal calls
 *
 * @param [in] stack_id stack identifier
 * @param [in] radio_ctx pointer on context
 */
void smtc_modem_set_radio_context( uint8_t stack_id, const void* radio_ctx );

/**
 * @brief Get optional user radio context
 *
 * @returns Radio context reference
 */
const void* smtc_modem_get_radio_context( uint8_t stack_id );

/**
 * @brief Check if the radio is used by the radio planner
 *
 * @param [in] stack_id stack identifier
 *
 * @returns true if the radio isn't used by the radio planner, false otherwise
*/
bool smtc_modem_radio_is_free(uint8_t stack_id);
#ifdef __cplusplus
}
#endif

#endif  // SMTC_MODEM_UTILITIES_H__

/* --- EOF ------------------------------------------------------------------ */
