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

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

#include "Platform.h"

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

#ifndef RAM_INTERNAL_H_
    #define RAM_INTERNAL_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include "RAM_Port.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    #define RAM_TIM PLATFORM_DEFAULT_TIM

    #ifndef RAM_LOG
        #define RAM_LOG PLATFORM_DEFAULT_LOG
    #endif

    #define RAM_NAME       "RAM"
    #define RAM_LOG_PREFIX UTIL_StringConcatenateConstant( RAM_NAME, "> " )

    #ifdef DEBUG
        #define RAM_Raw( Level, Format, ... ) LOG_Raw( RAM_LOG, Level, Format, ##__VA_ARGS__ )
        #define RAM_Trace( Format, ... )      LOG_Trace( RAM_LOG, UTIL_StringConcatenateConstant( RAM_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define RAM_Debug( Format, ... )      LOG_Debug( RAM_LOG, UTIL_StringConcatenateConstant( RAM_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define RAM_Info( Format, ... )       LOG_Info( RAM_LOG, UTIL_StringConcatenateConstant( RAM_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define RAM_Warning( Format, ... )    LOG_Warning( RAM_LOG, UTIL_StringConcatenateConstant( RAM_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define RAM_Error( Format, ... )      LOG_Error( RAM_LOG, UTIL_StringConcatenateConstant( RAM_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define RAM_Fatal( Format, ... )      LOG_Fatal( RAM_LOG, UTIL_StringConcatenateConstant( RAM_LOG_PREFIX, Format ), ##__VA_ARGS__ )
    #else
        #define RAM_Raw( Level, Format, ... )
        #define RAM_Trace( Format, ... )
        #define RAM_Debug( Format, ... )
        #define RAM_Info( Format, ... )
        #define RAM_Warning( Format, ... )
        #define RAM_Error( Format, ... )
        #define RAM_Fatal( Format, ... )
    #endif

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    typedef struct RAM_Instance_Context_t RAM_Instance_Context_t;

    typedef struct RAM_Instance
    {
        RAM_t RAM;

        union
        {
            RAM_Instance_Context_t * Context;
        };
    } RAM_Instance_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    // The following APIs MUST be provided by the port
    RAM_Status_t RAM_IsValid( RAM_t RAMx );

    RAM_Status_t RAM_Instance_Initialize( RAM_Instance_t * Instance );
    RAM_Status_t RAM_Instance_Cycle( RAM_Instance_t * Instance );
    RAM_Status_t RAM_Instance_DeInitialize( RAM_Instance_t * Instance );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* RAM_INTERNAL_H_ */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
