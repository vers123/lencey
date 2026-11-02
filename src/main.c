#include <stdio.h>
#include "utils/utils.h"
#include "net/net.h"

int main(void)
{
    printf("lencey %s\n", utils_version());
    printf("1 + 2 = %d\n", utils_add(1, 2));
    return net_ping("127.0.0.1");
}
