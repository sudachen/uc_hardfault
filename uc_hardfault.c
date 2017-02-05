
#include <~sudachen/uc_hardfault/import.h>
#include <hardfault.h>

#ifdef __nRF5x_UC__

void HardFault_c_handler(HardFault_stack_t *stk)
{
    PRINT_ERROR("Hardfault PC: #%?",$x(stk->pc));

    // Debugger detection is only possible on NRF52 (Cortex-M4), on NRF51
    // (Cortex-M0) the processor has no access to CoreDebug registers.
    #if __CORTEX_M == 0x04
        // C_DEBUGEN == 1 -> Debugger Connected
        if (CoreDebug->DHCSR & CoreDebug_DHCSR_C_DEBUGEN_Msk)
        {
            /* Generate breakpoint if debugger is connected */
            NRF_BREAKPOINT;
        }
    #endif // __CORTEX_M == 0x04

    for (;;) __WFI();
}

#elif defined __stm32Fx_UC__
#endif
