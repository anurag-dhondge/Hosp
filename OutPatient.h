#pragma once
#include "Patient.h"

class OutPatient : public Patient
{
    protected :
        float doctorconsultation,medicine,treatment;
    
    public : 
        OutPatient(int id , int age, int noda, string name, float doctorconsultation , float medicine, float treatment)
        :Patient(id, age, noda, name)
        {
            this -> doctorconsultation = doctorconsultation;
            this -> medicine = medicine;
            this -> treatment = treatment;
        }

        void AcceptPatientDetatils()
        {
            cout << "Enter doctorconsultation : "<< endl;
            cin >> doctorconsultation;

            cout << "Enter Medicine : "<< endl;
            cin >> medicine;

            cout << "Enter Treatment fees : "<< endl;
            cin >> treatment;
        }

        void DisplayPatientDetatils()
        {
            cout << "Enter doctorconsultation : "<< doctorconsultation;

            cout << "Enter medicine : "<< medicine;

            cout << "Enter treatment : " << treatment;
        }

        float CalculateBill() const
        {
            float Outpatientbill = Patient :: CalculateBill();
            Outpatientbill = Outpatientbill + doctorconsultation + medicine + treatment;
            return Outpatientbill;
        }

        void visitor() const 
        {
            cout << "Doctor Consultation Charges: " << doctorconsultation << endl;
            cout << "Medicine Charges: " << medicine << endl;
            cout << "Treatment Charges: " << treatment << endl;
        }

        ~OutPatient()
        {
            cout << "Destructor calls Inpatient....";
        }
};