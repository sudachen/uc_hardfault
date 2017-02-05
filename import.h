
#pragma once
#include <uccm/board.h>

#ifdef __nRF5x_UC__

#pragma uccm require(source) += [@inc]/~sudachen/uc_hardfault/uc_hardfault.c
#pragma uccm cflags += -I "{NRF_LIBRARIES}/hardfault"

#pragma uccm file(sdk_config_1.h) += \
#ifndef HARDFAULT_HANDLER_ENABLED\n\
#define HARDFAULT_HANDLER_ENABLED 1\n\
#endif\n\

#ifdef NRF51

#ifdef __keil_v5
#pragma uccm require(module) += {NRF_LIBRARIES}/hardfault/nrf51/handler/hardfault_handler_keil.c
#else 
#pragma uccm require(module) += {NRF_LIBRARIES}/hardfault/nrf51/handler/hardfault_handler_gcc.c 
#endif

#elif defined NRF52

#ifdef __keil_v5
#pragma uccm require(module) += {NRF_LIBRARIES}/hardfault/nrf52/handler/hardfault_handler_keil.c
#else 
#pragma uccm require(module) += {NRF_LIBRARIES}/hardfault/nrf52/handler/hardfault_handler_gcc.c 
#endif

#endif

#elif defined __stm32Fx_UC__

#endif

