#pragma once
#include "InPatient.h"

class EmergencyPatient : public InPatient
{
    protected :
        float emergencyCharges,AmbulanceCharges;
    
    public : 
        EmergencyPatient(int id , int age, int noda, string name, float emergencyCharges , float AmbulanceCharges)
        :InPatient(id, age, noda, name,roomcharges,doctorconsultation,medicine,treatment)
        {
            this -> emergencyCharges = emergencyCharges;
            this -> AmbulanceCharges = AmbulanceCharges;
        }

        void AcceptPatientDetatils()
        {
            cout << "Enter emergencyCharges : "<< endl;
            cin >> emergencyCharges;

            cout << "Enter AmbulanceCharges : "<< endl;
            cin >> AmbulanceCharges;
        }

        void DisplayPatientDetatils()
        {
            cout << "Enter emergencyCharges : "<< emergencyCharges;

            cout << "Enter AmbulanceCharges : "<< AmbulanceCharges;
        }

        float CalculateBill() const
        {
            float EmergencyPatient = Patient :: CalculateBill();
            EmergencyPatient = EmergencyPatient + emergencyCharges + AmbulanceCharges;
            return EmergencyPatient;
        }

        void emergency() const 
        {
            cout << "Emergency Charges: " << emergencyCharges << endl;
            cout << "Ambulance Charges: " << AmbulanceCharges << endl;
        }

        ~EmergencyPatient()
        {
            cout << "Destructor calls EmergencyPatient....";
        }

    
};