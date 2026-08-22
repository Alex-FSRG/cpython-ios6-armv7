/*
 * Minimal signal compatibility layer for Python 3.10 on iOS 6 / ARMv7.
 *
 * The real signalmodule.c cannot currently be compiled with the old
 * ARMv7/iOS toolchain because of its atomic implementation.
 *
 * Signals are intentionally disabled in this build.
 */

#include "Python.h"


/*
 * Check for pending Python signals.
 *
 * Signals are disabled, so there is never anything to handle.
 */
int
_PyErr_CheckSignalsTstate(PyThreadState *tstate)
{
    (void)tstate;
    return 0;
}


/*
 * Public/internal wrapper used by some CPython code.
 */
int
PyErr_CheckSignals(void)
{
    return 0;
}


/*
 * Set a pending signal.
 *
 * The real implementation records the signal number.
 * We intentionally ignore it on this iOS build.
 */
int
PyErr_SetInterruptEx(int signum)
{
    (void)signum;
    return 0;
}


/*
 * Legacy wrapper.
 */
void
PyErr_SetInterrupt(void)
{
}


/*
 * Initialize Python signal handling.
 */
void
PyOS_InitInterrupts(void)
{
}


/*
 * Finalize Python signal handling.
 */
void
PyOS_FiniInterrupts(void)
{
}


/*
 * Internal signal initialization/finalization hooks
 * used by Python 3.10's runtime lifecycle.
 */
int
_PySignal_Init(void)
{
    return 0;
}


void
_PySignal_Fini(void)
{
}


/*
 * Check whether SIGINT occurred.
 */
int
_PyOS_InterruptOccurred(PyThreadState *tstate)
{
    (void)tstate;
    return 0;
}


/*
 * Clear signal state after fork.
 */
void
_PySignal_AfterFork(void)
{
}


/*
 * Dummy module initializer.
 *
 * The actual _signal module is not functional in this build.
 */
PyMODINIT_FUNC
PyInit__signal(void)
{
    return NULL;
}