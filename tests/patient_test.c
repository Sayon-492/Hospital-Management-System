#include <stdio.h>
#include "../include/patient.h"
#include "../include/hospital.h"
#include "../include/ui.h"

void hospital_init(void) {
    patient_load_from_file();
}

int main() {
    hospital_init();
    patient_receptionist_menu();
    return 0;
}