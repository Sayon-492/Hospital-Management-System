#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../include/utils.h"

void utils_clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void utils_pause(void) {
    printf("Press any key to continue...\n");
    getchar();
}

int utils_get_int(void) {
    int num;
    while (scanf("%d", &num) != 1) {
        printf("Invalid input. Please enter an integer: ");
        utils_clear_input_buffer();
    }
    utils_clear_input_buffer();
    return num;
}

float utils_get_float(void) {
    float num;
    while (scanf("%f", &num) != 1) {
        printf("Invalid input. Please enter a float: ");
        utils_clear_input_buffer();
    }
    utils_clear_input_buffer();
    return num;
}

double utils_get_double(void) {
    double num;
    while (scanf("%lf", &num) != 1) {
        printf("Invalid input. Please enter a double: ");
        utils_clear_input_buffer();
    }
    utils_clear_input_buffer();
    return num;
}

char utils_get_char(void) {
    char ch;
    scanf(" %c", &ch);
    utils_clear_input_buffer();
    return ch;
}

char* utils_get_string(char *str, size_t size) {
    if (fgets(str, size, stdin) != NULL) {
        str[strcspn(str, "\n")] = '\0';
    } else {
        return NULL;
    }
    return str;
}

/**
 *==========================================================
 *                    Validity Functions                    
 *==========================================================
 */

bool utils_is_valid_phone(const char *phone) {
    if (phone == NULL || phone[0] == '\0') return false;
    
    int digit_count = 0;
    for (size_t i = 0; phone[i] != '\0'; i++) {
        if (!isdigit(phone[i])) return false;
        digit_count++;
    }

    if (digit_count != 11) return false;
    if (phone[0] != '0' || phone[1] != '1') return false;
    if (phone[2] < '3' || phone[2] > '9') return false;
    
    return true;
}

bool utils_is_valid_email(const char *email) {
    if (email == NULL || email[0] == '\0') return false;
    
    int at_count = 0;
    int at_position = -1;
    int last_dot_position = -1;
    int length = 0;
    
    for (size_t i = 0; email[i] != '\0'; i++) {
        char c = email[i];
        
        if (c == ' ') return false;
        if (c == '@') {
            at_count++;
            at_position = i;
        }
        if (c == '.') {
            last_dot_position = i;
        }
        length++;
    }
    
    if (at_count != 1) return false;
    if (at_position == 0) return false;
    if (last_dot_position <= at_position) return false;
    if (last_dot_position == length - 1) return false;
    
    return true;
}

bool utils_is_valid_name(const char *name) {
    if (name == NULL || name[0] == '\0') return false;
    
    for (size_t i = 0; name[i] != '\0'; i++) {
        if (!isalpha(name[i]) && name[i] != ' ') {
            return false;
        }
    }
    
    return true;
}
