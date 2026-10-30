#include "Patient.h"
#include "InPatient.h"
#include "OutPatient.h"
#include "EmergencyPatient.h"

#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

int main()
{
    int nop;

    cout << "Enter the maximum number of patients: " << endl;
    cin >> nop;

    if (nop <= 0)
    {
        cout << "Invalid number of patients!" << endl;
        return 0;
    }

    Patient **parr = new Patient *[nop];

    for (int i = 0; i < nop; i++)
    {
        parr[i] = nullptr;
    }

    int i = 0;
    char again;

    do
    {
        if (i >= nop)
        {
            cout << "Maximum patient limit reached!" << endl;
            break;
        }

        int p_id, age, nod, choice;
        string p_name;

        float roomcharges = 0.0f;
        float doctorcharges = 0.0f;
        float medicinecharges = 0.0f;
        float treatmentcharges = 0.0f;

        float consultationcharges = 0.0f;
        float diagnosticcharges = 0.0f;
        float medicinescharges = 0.0f;

        float emergency_services_charges = 0.0f;
        float ambulance_charges = 0.0f;

        cout << "\n--------------------MENU--------------------" << endl;
        cout << "1. InPatient" << endl;
        cout << "2. OutPatient" << endl;
        cout << "3. Emergency Patient" << endl;
        cout << "Enter Your Choice: " << endl;
        cin >> choice;

        cout << "Enter the Patient ID: " << endl;
        cin >> p_id;

        cout << "Enter the Patient Name: " << endl;
        cin >> p_name;

        cout << "Enter the Patient Age: " << endl;
        cin >> age;

        switch (choice)
        {
            case 1:
            {
                cout << "Enter the Details for InPatient: " << endl;

                cout << "Enter the Number of Days Admitted: " << endl;
                cin >> nod;

                cout << "Enter the Room Charges: " << endl;
                cin >> roomcharges;

                cout << "Enter the Doctor Consultation Charges: " << endl;
                cin >> doctorcharges;

                cout << "Enter the Medicine Charges: " << endl;
                cin >> medicinecharges;

                cout << "Enter the Treatment Charges: " << endl;
                cin >> treatmentcharges;

                parr[i] = new InPatient(
                    p_id, age, nod, p_name,
                    roomcharges, doctorcharges,
                    medicinecharges, treatmentcharges
                );

                break;
            }

            case 2:
            {
                cout << "Enter the Details for OutPatient: " << endl;

                cout << "Enter the Number of Days Visited: " << endl;
                cin >> nod;

                cout << "Enter the Consultation Charges: " << endl;
                cin >> consultationcharges;

                cout << "Enter the Diagnostic Charges: " << endl;
                cin >> diagnosticcharges;

                cout << "Enter the Medicine Charges: " << endl;
                cin >> medicinescharges;

                parr[i] = new OutPatient(
                    p_id, age, nod, p_name,
                    consultationcharges,
                    diagnosticcharges,
                    medicinescharges
                );

                break;
            }

            case 3:
            {
                cout << "Enter the Details for Emergency Patient: " << endl;

                cout << "Enter the Number of Days Admitted: " << endl;
                cin >> nod;

                cout << "Enter the Room Charges: " << endl;
                cin >> roomcharges;

                cout << "Enter the Doctor Consultation Charges: " << endl;
                cin >> doctorcharges;

                cout << "Enter the Medicine Charges: " << endl;
                cin >> medicinecharges;

                cout << "Enter the Treatment Charges: " << endl;
                cin >> treatmentcharges;

                cout << "Enter the Emergency Service Charges: " << endl;
                cin >> emergency_services_charges;

                cout << "Enter the Ambulance Charges: " << endl;
                cin >> ambulance_charges;

                parr[i] = new EmergencyPatient
                (
                    p_id, age, nod, p_name,
                    emergency_services_charges,
                    ambulance_charges
                );

                break;
            }

            default:
            {
                cout << "Invalid choice!" << endl;
                parr[i] = nullptr;
                break;
            }
        }

        if (parr[i] != nullptr)
        {
            i++;
        }

        if (i < nop)
        {
            cout << "\nDo you want to add another patient? (y/n): ";
            cin >> again;
        }
        else
        {
            again = 'n';
        }

    } while (again == 'y' || again == 'Y');

    cout << "\n========== DISPLAYING ALL PATIENTS ==========" << endl;

    for (int j = 0; j < i; j++)
    {
        if (parr[j] == nullptr)
        {
            continue;
        }

        Patient *ptr = parr[j];

        ptr->DisplayPatientDEtails();

        float total_bill = ptr->CalculateBill();

        cout << "Total Bill: " << total_bill << endl;

        if (typeid(*ptr) == typeid(EmergencyPatient))
        {
            EmergencyPatient *eptr =
                dynamic_cast<EmergencyPatient *>(ptr);

            if (eptr != nullptr)
            {
                cout << "Type: Emergency Patient" << endl;
                eptr -> emergency();
            }
        }
        else if (typeid(*ptr) == typeid(InPatient))
        {
            InPatient *iptr = dynamic_cast<InPatient *>(ptr);

            if (iptr != nullptr)
            {
                cout << "Type: In-Patient" << endl;
                iptr->admitted();
            }
        }
        else if (typeid(*ptr) == typeid(OutPatient))
        {
            OutPatient *optr = dynamic_cast<OutPatient *>(ptr);

            if (optr != nullptr)
            {
                cout << "Type: Out-Patient" << endl;
                optr->visitor();
            }
        }

        cout << "\n";
    }

    for (int j = 0; j < nop; j++)
    {
        delete parr[j];
    }

    delete[] parr;

    return 0;
}