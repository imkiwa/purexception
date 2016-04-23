#pragma once

#include <stdlib.h>
#include <setjmp.h>


#ifdef __cplusplus
extern "C" {
#endif

/**
 * Get current exception
 *
 * @return error message 
 */
const void* exception_get();


/**
 * Set current exception
 *
 * @param exception error message
 */
void exception_set(const void *exception);


/**
 * Reset exception status
 */
void exception_clear();

#ifdef __cplusplus
}
#endif


/**
 * if we are using c++
 */
#ifdef __cplusplus

#define throw(exception) \
    exception_set(exception); \
    throw exception

#define catch catch(...)
#define endtry


#define current_exception(type) \
    static_cast<type>(exception_get());

#else /* __cplusplus */

#define EXCEPTION_SET   0
#define EXCEPTION_OCCUR 1

#define current_exception(type) \
    (type) exception_get()

#define try \
    { \
        jmp_buf _exception_catch_buf; \
        if (setjmp(_exception_catch_buf) == EXCEPTION_SET)

#define catch \
        else

#define endtry \
    }

#define throw(exception) \
    exception_set((void*) exception); \
    longjmp(_exception_catch_buf, EXCEPTION_OCCUR);

#endif /* __cplusplus */

#define finally
