#include <stdio.h>
#include "../include/utils.h"

int main() {
    // // testing utils_get_int()
    // printf("Enter an integer: ");
    // int test = utils_get_int();
    // printf("Expected: 5, actual: %d\n\n", test);
    
    // // testing utils_get_char()
    // printf("Enter a character: ");
    // char ch = utils_get_char();
    // printf("Expected: c, actual: %c\n\n", ch);
    
    // // testing utils_get_float()
    // printf("Enter a float: ");
    // float fnum = utils_get_float();
    // printf("Expected: 3.14, actual: %.2f\n\n", fnum);
    
    // // testing utils_get_double()
    // printf("Enter a double: ");
    // double dnum = utils_get_float();
    // printf("Expected: 3.141593, actual: %.6f\n\n", dnum);

    // testing utils_get_string()
    printf("Enter a string: ");
    char string[50]; 
    utils_get_string(string, 50);
    printf("Expected: happy birthday, actual: %s\n\n", string);
    
    // testing utils_is_valid_phone()
    if (utils_is_valid_phone("01315648613")) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }
    
    // testing utils_is_valid_email()
    if (utils_is_valid_email("this.is.an.email@gmail.com")) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }
    return 0;
}