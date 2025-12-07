/**
 * @file patient.h
 * @brief Patient management functions for Healthcare Management System
 * 
 * This header declares all patient-related CRUD operations.
 */

#ifndef PATIENT_H
#define PATIENT_H

#include "hospital.h"

/**
* Generates a unique patient ID.
* @return The generated patient ID.
*/
int generate_patient_id(void);

/**
 * Handles the search choice for patient.
 */
 void search_patient_by(void);

/**
 * Displays the patient management menu and handles user input.
 */
 void receptionist_menu(void);


#endif