#include <exec/types.h>
#include <dos/bptr.h>
#include <workbench/startup.h>
#include <exec/libraries.h>

#include "compatibility.h"

#include <string.h>

#ifndef HAVE_STRMID
int strmid(const char *source, char *dest, int pos, int len) {
    // Validate input parameters
    if (source == NULL || dest == NULL || pos < 0 || len <= 0) {
        return -1; // Invalid input, treat as error
    }

    int source_length = strlen(source);

    // If the starting position is beyond the source length, return an error (-1)
    if (pos >= source_length) {
        dest[0] = '\0'; // Ensure the destination string is empty
        return -1;
    }

    // Determine the number of characters to copy
    int copy_length = (pos + len > source_length) ? source_length - pos : len;

    // Copy the substring to the destination
    strncpy(dest, source + pos, copy_length);

    // Null-terminate the destination string
    dest[copy_length] = '\0';

    // Return 0 indicating success
    return 0;
}
#endif

#ifndef HAVE_WBPATH
BPTR cloneWorkbenchPath(struct Library *sysb, struct Library *dosb, struct WBStartup *sm)
{
	// FIXME
	return (BPTR)NULL;
}

void freeWorkbenchPath(struct Library *sysb, struct Library *dosb, BPTR path)
{
	// FIXME
}
#endif

#ifndef HAVE_PROCESS
void process_starter(void)
{
	// FIXME
}

struct ProcMsg *start_process(long (*fp)(void), long prio, long stacksize)
{
	// FIXME
	return NULL;
}

long wait_process(struct ProcMsg *msg)
{
	// FIXME
	return 0;
}
#endif
