#include <stdio.h>
#include "../include/utils.h"
#include <stdbool.h>

int test_validate_validphone() {
    char phone[]="01312381636";
   int expected=1;
   int actual=utils_is_valid_phone(phone);
    int succes= actual==expected;
    printf("actual: %d, expected: %d,succes:%d",actual,expected,actual==expected);

}



int main()
{
    test_validate_validphone();
}