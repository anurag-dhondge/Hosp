#pragma once
#include "Patient.h"

class InPatient : public Patient
{
    protected :
        float roomcharges,doctorconsultation,medicine,treatment;
    
    public : 
        InPatient(int id , int age, int noda, string name,float roomcharges, float doctorconsultation , float medicine, float treatment)
        :Patient(id, age, noda, name)
        {
            this -> roomcharges = roomcharges;
            this -> doctorconsultation = doctorconsultation;
            this -> medicine = medicine;
            this -> treatment = treatment;
        }

        void AcceptPatientDetatils()
        {
            cout << "Enter RoomCharges : " << endl;
            cin >> roomcharges;

            cout << "Enter doctorconsultation : "<< endl;
            cin >> doctorconsultation;

            cout << "Enter Medicine : "<< endl;
            cin >> medicine;

            cout << "Enter Treatment fees : "<< endl;
            cin >> treatment;
        }

        void DisplayPatientDetatils()
        {
            cout << "Enter roomcharges : " << roomcharges;

            cout << "Enter doctorconsultation : "<< doctorconsultation;

            cout << "Enter medicine : "<< medicine;

            cout << "Enter treatment : " << treatment;
        }

        float CalculateBill() const
        {
            float inpatientbill = Patient :: CalculateBill();
            inpatientbill = inpatientbill + roomcharges + doctorconsultation + medicine + treatment;
            return inpatientbill;
        }

        void admitted() const 
        {
            cout << "Room Charges: " << roomcharges << endl;
            cout << "Doctor Consultation Charges: " << doctorconsultation << endl;
            cout << "Medicine Charges: " << medicine << endl;
            cout << "Treatment Charges: " << treatment << endl;
        }

        ~InPatient()
        {
            cout << "Destructor calls Inpatient....";
        }
};