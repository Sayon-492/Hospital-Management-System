#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>
#include <stdbool.h>

/**
 * Clears the input buffer to prevent leftover characters.
 */
void utils_clear_input_buffer(void);

/**
 * Pauses the program execution until the user presses a key.
 */
void utils_pause(void);

/**
 * Scans an integer value from the user with validation.
 *
 * @return The valid integer entered by the user.
 */
int utils_get_int(void);


/**
 * Scans a float value from the user with validation.
 *
 * @return The valid float entered by the user.
 */

float utils_get_float(void);

/**
 * Scans a double value from the user with validation.
 *
 * @return The valid double entered by the user.
 */
double utils_get_double(void);

/**
 * Scans a char value from the user.
 *
 * @return The valid char entered by the user.
 */
char utils_get_char(void);

/**
 * Scans a string value from the user.
 *
 * @param str The buffer to store the string.
 * @param size The maximum number of characters to read.
 *
 * @return Pointer to string on success, NULL on failure.
 */
char* utils_get_string(char *str, size_t size);

/**
 *==========================================================
 *                    Validity Functions                    
 *==========================================================
 */

/**
 * Validates if a phone number is in correct format.
 * 
 * @param phone The phone number string to validate.
 * @return true if valid, false otherwise.
 */
bool utils_is_valid_phone(const char *phone);

/**
 * Validates if an email contains @ and .
 * 
 * @param email The email string to validate.
 * @return true if valid, false otherwise.
 */
bool utils_is_valid_email(const char *email);

/**
 * Validates if a name contains only letters and spaces.
 * 
 * @param name The name to validate.
 * @return true if valid name, false otherwise.
 */
bool utils_is_valid_name(const char *name);

#endif