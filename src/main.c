#include <stdio.h>
#include "utils.h"

int main() {
    printf("Hello, World!\n");
    int num = utils_get_int();
    printf("You entered: %d\n", num);
    printf("Enter your name : ");
    char *name = utils_get_string(name, 100);
    printf("You entered: %s\n", name);
    utils_pause();
    return 0;
}