#include "utils/utils.h"
#include "lencey.h"

/* 仅本编译单元可见，外部无法调用 */
static int clamp_nonneg(int v)
{
    return v < 0 ? 0 : v;
}

int utils_add(int a, int b)
{
    return clamp_nonneg(a) + clamp_nonneg(b);
}

const char *utils_version(void)
{
    return LENCEY_VERSION;
}
