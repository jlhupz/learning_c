#include <stdio.h>

int main() {
    printf("%9d %3d\n",1000, 9999999);
    printf("%9d %9d\n",1000, 999);
    printf("%9d %1d\n",1000000, 9999999);
    printf("%9d %d\n",1000, 999);

    return 0;
}
