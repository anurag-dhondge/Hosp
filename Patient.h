#pragma once
#include <iostream>
using namespace std;

class Patient
{
    protected:
        int id, age, noda;
        string name;
        static int rateperday;

    public:
        Patient(int id , int age, int noda, string name)
        {
            this -> id = id;
            this -> age = age;
            this -> noda = noda;
            this -> name = name;
        }

        virtual void AcceptPatientDetails()
        {
            cout << "Enter ID : " << endl;
            cin >> id;

            cout << "Enter Age : "<< endl;
            cin >> age;

            cout << "Enter Name : "<< endl;
            cin >> name;

            cout << "Enter No of Days Admitted : "<< endl;
            cin >> noda;
        }

        virtual float CalculateBill() const
        {
            return noda*rateperday;
        }

        virtual float DisplayPatientDEtails()
        {
            cout << "Enter ID : " << id << endl;

            cout << "Enter Age : "<< age << endl;

            cout << "Enter Name : "<< name << endl;

            cout << "Enter No of Days Admitted : " << noda << endl;
        }
        
        virtual ~Patient()
        {
            cout << "Destructor calls ....";
        }

};
int Patient::rateperday = 100;