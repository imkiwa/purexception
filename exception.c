#include <stdio.h>
#include <string.h>

#include "exception.h"

static const void *current_exception;

const void* exception_get()
{
    return current_exception;
}

void exception_set(const void *exception)
{
    current_exception = exception;
}

void exception_clear()
{
    current_exception = NULL;
}
