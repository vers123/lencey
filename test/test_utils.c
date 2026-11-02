#include <assert.h>
#include <stdio.h>
#include "utils/utils.h"

int main(void)
{
    assert(utils_add(1, 2) == 3);
    assert(utils_add(-5, 2) == 2);   /* 负数被 clamp 成 0 */
    printf("test_utils: all passed\n");
    return 0;
}
