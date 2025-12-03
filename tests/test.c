#include <stdio.h>
#include "../include/utils.h"
#include <stdbool.h>

int main() {
    char phone[12];
    utils_get_string(phone, 12);
    if(utils_is_valid_phone(phone)) {
        printf("Valid phone number\n");
    } else {
        printf("Invalid phone number\n");
    }
    if (utils_is_valid_email("noice.nice@gmail.com")) {
        printf("Valid email\n");
    } else {
        printf("Invalid email\n");
    }
    return 0;
}