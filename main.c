#include <stdio.h>
#include <string.h>
#include "include/utils.h"
#include "include/ui.h"
#include "include/hospital.h"
#include "include/patient.h"
#include "include/doctor.h"
#include "include/appointment.h"
#include "include/receptionist.h"
#include "include/admin.h"
#include "include/doctor_portal.h"
#include "include/auth.h"

void hospital_init(void) {
    patient_load_from_file();
    doctor_load_from_file();
    appointment_load_from_file();
    auth_load_from_file();
    auth_init_default_admin();
}

void admin_main_menu(void) {
    int choice;
    
    do {
        ui_clear_screen();
        ui_print_banner();
        
        const char* menu_items[] = {
            "Patient Management",
            "Doctor Management",
            "User Management",
            "Logout",
            "Enter your choice: "
        };
        
        ui_print_menu("Admin Portal", menu_items, 5, UI_SIZE);
        choice = utils_get_int();
        
        switch (choice) {
            case 1:
                admin_patient_menu();
                break;
            case 2:
                admin_doctor_menu();
                break;
            case 3:
                auth_user_menu();
                break;
            case 4:
                ui_print_info("Logging out...");
                ui_pause();
                break;
            default:
                ui_print_error("Invalid choice!");
                ui_pause();
        }
    } while (choice != 4);
}

void show_about(void) {
    ui_clear_screen();
    ui_print_banner();
    
    const char* about_items[] = {
        "Healthcare Management System (HMS)",
        "Version: 1.0",
        "Developed for efficient hospital management",
        "including patient, doctor, and appointment",
        "tracking with role-based access control.",
        "Roles: Admin, Receptionist, Doctor",
        ""
    };
    
    ui_print_menu_unnumbered("About HMS", about_items, 7, UI_SIZE);
    ui_pause();
}

void doctor_login(void) {
    char username[USERNAME_SIZE];
    char password[PASSWORD_SIZE];
    
    ui_clear_screen();
    ui_print_banner();
    
    const char* menu_items[] = {
        "Username:",
        ">> "
    };
    ui_print_menu("Doctor Login", menu_items, 2, UI_SIZE);
    utils_get_string(username, USERNAME_SIZE);
    
    ui_clear_screen();
    ui_print_banner();
    
    char user_line[80];
    snprintf(user_line, sizeof(user_line), "Username: %s", username);
    const char* pass_items[] = {
        user_line,
        "Password:",
        ">> "
    };
    ui_print_menu("Doctor Login", pass_items, 3, UI_SIZE);
    utils_get_string(password, PASSWORD_SIZE);
    
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 &&
            strcmp(users[i].password, password) == 0 &&
            users[i].is_active &&
            users[i].role == ROLE_DOCTOR) {
            current_user = &users[i];
            doctor_portal_menu(users[i].id, username);
            current_user = NULL;
            return;
        }
    }
    
    ui_print_error("Invalid credentials or not a doctor!");
    ui_pause();
}

void receptionist_login(void) {
    char username[USERNAME_SIZE];
    char password[PASSWORD_SIZE];
    
    ui_clear_screen();
    ui_print_banner();
    
    const char* menu_items[] = {
        "Username:",
        ">> "
    };
    ui_print_menu("Receptionist Login", menu_items, 2, UI_SIZE);
    utils_get_string(username, USERNAME_SIZE);
    
    ui_clear_screen();
    ui_print_banner();
    
    char user_line[80];
    snprintf(user_line, sizeof(user_line), "Username: %s", username);
    const char* pass_items[] = {
        user_line,
        "Password:",
        ">> "
    };
    ui_print_menu("Receptionist Login", pass_items, 3, UI_SIZE);
    utils_get_string(password, PASSWORD_SIZE);
    
    // Find user
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 &&
            strcmp(users[i].password, password) == 0 &&
            users[i].is_active &&
            users[i].role == ROLE_RECEPTIONIST) {
            current_user = &users[i];
            receptionist_menu();
            current_user = NULL;
            return;
        }
    }
    
    ui_print_error("Invalid credentials or not a receptionist!");
    ui_pause();
}

void admin_login(void) {
    char username[USERNAME_SIZE];
    char password[PASSWORD_SIZE];
    
    ui_clear_screen();
    ui_print_banner();
    
    const char* menu_items[] = {
        "Username:",
        ">> "
    };
    ui_print_menu("Admin Login", menu_items, 2, UI_SIZE);
    utils_get_string(username, USERNAME_SIZE);
    
    ui_clear_screen();
    ui_print_banner();
    
    char user_line[80];
    snprintf(user_line, sizeof(user_line), "Username: %s", username);
    const char* pass_items[] = {
        user_line,
        "Password:",
        ">> "
    };
    ui_print_menu("Admin Login", pass_items, 3, UI_SIZE);
    utils_get_string(password, PASSWORD_SIZE);
    
    // Find user
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 &&
            strcmp(users[i].password, password) == 0 &&
            users[i].is_active &&
            users[i].role == ROLE_ADMIN) {
            current_user = &users[i];
            admin_main_menu();
            current_user = NULL;
            return;
        }
    }
    
    ui_print_error("Invalid credentials or not an admin!");
    ui_pause();
}

void login_menu(void) {
    int choice;
    
    do {
        ui_clear_screen();
        ui_print_banner();
        
        const char* menu_items[] = {
            "Admin Login",
            "Receptionist Login",
            "Doctor Login",
            "Back",
            "Enter your choice: "
        };
        
        ui_print_menu("Login", menu_items, 5, UI_SIZE);
        choice = utils_get_int();
        
        switch (choice) {
            case 1:
                admin_login();
                break;
            case 2:
                receptionist_login();
                break;
            case 3:
                doctor_login();
                break;
            case 4:
                return;
            default:
                ui_print_error("Invalid choice!");
                ui_pause();
        }
    } while (choice != 4);
}

int main() {
    hospital_init();
    
    int choice;

    do {
        ui_clear_screen();
        ui_print_banner();
        
        const char* menu_items[] = {
            "Login",
            "About",
            "Exit",
            "Enter your choice: "
        };
        
        ui_print_menu("Main Menu", menu_items, 4, UI_SIZE);
        choice = utils_get_int();
        
        switch (choice) {
            case 1:
                login_menu();
                break;
            case 2:
                show_about();
                break;
            case 3:
                ui_print_success("Goodbye!");
                ui_pause();
                break;
            default:
                ui_print_error("Invalid choice!");
                ui_pause();
        }
    } while (choice != 3);

    return 0;
}