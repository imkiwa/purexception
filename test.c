#include <stdio.h>
#include "exception.h"

int main(int argc, char const *argv[])
{
    typedef struct
    {
        char *ex;
        int status;
    } MyException;

    try {
        MyException e;

        printf("About to throw the first exception with finally block\n");

        e.ex = "Fuck!!";
        e.status = 520;
        throw(&e);

        printf("This line will never be reached\n");

    } catch {
        const MyException *e = current_exception(const MyException*);
        printf("Exception: status: %d, msg: %s\n", e->status, e->ex);

    } finally {
        printf("finally\n");

    } endtry;

    try {
        printf("About to throw the second exception\n");

        throw("BOOM!");

        printf("This line will never be reached\n");

    } catch {
        const char *e = current_exception(const char*);
        printf("Exception: %s\n", e);

    } endtry;

    return 0;
}
