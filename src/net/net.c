#include <stdio.h>
#include <string.h>
#include "net/net.h"

int net_ping(const char *host)
{
    if (host == NULL || host[0] == '\0') {
        return -1;
    }
    printf("[net] ping %s (mock)\n", host);
    return 0;
}
