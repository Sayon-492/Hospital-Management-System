/**
 * @file utils.c
 * @brief Utility functions for Healthcare Management System
 * 
 * This file contains the implementation of utility functions
 * used throughout the HMS application.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../include/utils.h"

void utils_clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void utils_pause(void) {
    printf("\nPress any key to continue...");
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
    while (1) {
        if (fgets(str, size, stdin) != NULL) {
            str[strcspn(str, "\n")] = '\0';
            if (str[0] != '\0') {
                return str;
            }
            printf("Input cannot be empty. Try again: ");
        } else {
            return NULL;
        }
    }
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

        if (c != '@' && !(isdigit(c)) && !(isalpha(c)) && c != '.') return false;
        
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

char* utils_str_to_upper(char *str) {
    if (str == NULL) return NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
    return str;
}

char* utils_fix_name(char *name) {
    if (name == NULL || name[0] == '\0') return name;
    
    bool new_word = true;
    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] == ' ') {
            new_word = true;
        } else if (new_word) {
            name[i] = toupper(name[i]);
            new_word = false;
        } else {
            name[i] = tolower(name[i]);
        }
    }
    return name;
}

bool utils_is_valid_blood_group(const char *blood_group) {
    if (blood_group == NULL || blood_group[0] == '\0') return false;
    
    const char* valid_blood_groups[] = {
        "A+", "A-", "B+", "B-", "AB+", "AB-", "O+", "O-", "U",
        "a+", "a-", "b+", "b-", "ab+", "ab-", "o+", "o-", "u"
    };
    int count = sizeof(valid_blood_groups) / sizeof(valid_blood_groups[0]);

    for (int i = 0; i < count; i++) {
        if (strcmp(blood_group, valid_blood_groups[i]) == 0) {
            return true;
        }
    }
    
    return false;
}

bool utils_is_valid_address(const char *address) {
    if (address == NULL || address[0] == '\0') return false;
    
    for (int i = 0; address[i] != '\0'; i++) {
        char c = address[i];
        if (!isalnum(c) && c != ' ' && c != ',' && c != '.') {
            return false;
        }
    }
    return true;
}