/**
 * @file patient.c
 * @brief Patient management implementation for Healthcare Management System
 * 
 * This file contains the implementation of all patient CRUD operations.
 */

#include <stdio.h>
#include <string.h>
#include "../include/patient.h"
#include "../include/utils.h"
#include "../include/ui.h"
#include "../include/hospital.h"

int generate_patient_id(void) {
    return PATIENT_ID_START + patient_count;
}

void search_patient_by(void) {
    int choice;
    
    do {
        ui_clear_screen();
        ui_print_banner();
        
        const char* menu_items[] = {
            "Search by patient ID",
            "Search by patient name",
            "Search by patient phone",
            "Back to Patient Menu"
        };
        
        ui_print_menu("Search Patient", menu_items, 4, 72);
        choice = utils_get_int();
        
        switch (choice) {
            case 1:
                // patient_search_by_id();
                break;
            case 2:
                // patient_search_by_name();
                break;
            case 3:
                // patient_search_by_phone();
                break;
            case 4:
                ui_print_info("Returning to patient menu...");
                break;
            default:
                ui_print_error("Invalid choice! Please try again.");
                ui_pause();
        }
    } while (choice != 4);
}

void receptionist_menu(void) {
    int choice;
    
    do {
        ui_clear_screen();
        ui_print_banner();
        
        const char* menu_items[] = {
            "Add Patient",
            "View All Patients",
            "Search Patient",
            "Update Patient",
            "Delete Patient",
            "Back to Main Menu"
        };
        
        ui_print_menu("Receptionist Menu", menu_items, 6, 72);
        choice = utils_get_int();
        
        switch (choice) {
            case 1:
                // patient_add();
                break;
            case 2:
                // patient_view_all();
                break;
            case 3: {
                ui_clear_screen();
                ui_print_banner();
                
                // Way of searching {ID, name, phone} 
                search_patient_by();
                ui_pause();
                break;
            }
            case 4:
                // patient_update();
                break;
            case 5:
                // patient_delete();
                break;
            case 6:
                ui_print_info("Returning to main menu...");
                break;
            default:
                ui_print_error("Invalid choice! Please try again.");
                ui_pause();
        }
    } while (choice != 6);
}