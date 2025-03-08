// #############################################################################
// #### Copyright ##############################################################
// #############################################################################

/*
 * Copyright 2024 BaSSeM
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// #############################################################################
// #### Description ############################################################
// #############################################################################

/**
 *  @file
 *
 *  @brief Platform RAM Module
 */

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

/**
 *  @addtogroup Platform_Module
 *
 *  @{
 */

/**
 *  @defgroup Platform_RAM RAM
 *
 *  @note Default port is STUB if Unspecified
 *
 *  @{
 */

/**
 *  @defgroup Platform_RAM_Driver Driver
 *
 *  @{
 *  @}
 */

#ifndef RAM_H_
    #define RAM_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include <stdint.h>

    #include "RAM_Port.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    /**
     *  @brief RAM Operation Status
     *
     *  @enum RAM_Status_t
     */
    typedef enum RAM_Status
    {
        RAM_Status_Success = 0,     ///< Success
        RAM_Status_ArgumentInvalid, ///< Argument Invalid
        RAM_Status_NotSupported,    ///< Not Supported
        RAM_Status_Error,           ///< General Error
        RAM_Status_Busy,            ///< Busy
        RAM_Status_Timeout,         ///< Timeout
        RAM_Status_OutOfMemory,     ///< Out Of Memory
    } RAM_Status_t;

    /**
     *  @brief RAM Reference
     */
    typedef uint8_t * RAM_Reference_t;

    /**
     *  @brief RAM Size
     */
    typedef uint32_t RAM_Size_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    /**
     *  @brief Initialize RAM instance
     *
     *  @note MUST BE called before using any RAM API
     *
     *  @param[in] RAMx Instance
     *
     *  @return RAM_Status_t
     */
    RAM_Status_t RAM_Initialize( RAM_t RAMx );

    /**
     *  @brief Cycle RAM instance
     *
     *  @param[in] RAMx Instance
     *
     *  @return RAM_Status_t
     */
    RAM_Status_t RAM_Cycle( RAM_t RAMx );

    /**
     *  @brief DeInitialize RAM instance
     *
     *  @param[in] RAMx Instance
     *
     *  @return RAM_Status_t
     */
    RAM_Status_t RAM_DeInitialize( RAM_t RAMx );

    /**
     *  @brief Allocate memory-size from RAM instance
     *
     *  @param[in]     RAMx      Instance
     *  @param[in,out] Reference Handle used for the to be allocated memory
     *  @param[in]     Size      Allocation size
     *
     *  @return RAM_Status_t
     */
    RAM_Status_t RAM_Allocate( RAM_t RAMx, RAM_Reference_t * Reference, RAM_Size_t Size );

    /**
     *  @brief DeAllocate reference of RAM instance
     *
     *  @param[in]     RAMx      Instance
     *  @param[in,out] Reference Handle used for the to be de-allocated memory
     *
     *  @return RAM_Status_t
     */
    RAM_Status_t RAM_DeAllocate( RAM_t RAMx, RAM_Reference_t * Reference );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    /**
     *  @brief Version
     */
    extern const char RAM_VERSION[];

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* RAM_H_ */

/**
 *  @}
 *
 *  @}
 */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
