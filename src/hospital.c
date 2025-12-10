/**
 * @file hospital.c
 * @brief Global data definitions for Healthcare Management System
 * 
 * This file contains the actual definitions of global variables
 * declared with extern in hospital.h.
 */

#include "../include/hospital.h"
#include <stddef.h>

Patient patients[MAX_PATIENTS];
Doctor doctors[MAX_DOCTORS];
User users[MAX_USERS];
Appointment appointments[MAX_APPOINTMENTS];

int patient_count = 0;
int patient_available = 0;
int patient_unavailable = 0;
int doctor_count = 0;
int doctor_available = 0;
int doctor_unavailable = 0;
int user_count = 0;
int appointment_count = 0;

User* current_user = NULL;
