#include <iostream>

using namespace std;
//function prototypes
void normalUser();
void administrator();

int main()
{
    //variable definition
    int option;
    cout << "*****WELCOME TO BBIT2020 E-CASH SERVICES*****" << endl;
    cout << "1. Normal User Login: " << endl;
    cout << "2. Administrator Login: " << endl;
    cout << "Choose an Option to proceed: " << endl;
    cin >> option;
    switch(option)
    {
    case 1:
        normalUser();
        break;
    case 2:
        administrator();
        break;
    default:
        cout << "Invalid Input TRY AGAIN with 1 or 2 " << endl;
    }
    return 0;
}

void normalUser()
{
    cout << "----------------------------------------------" << endl;
    cout << "Welcome to Normal User Login Page: " << endl;
    cout << "Enter Username: " << endl;
    cout << "Enter Password: " << endl;
    cout << "----------------------------------------------" << endl;
}
void administrator()
{
    cout << "----------------------------------------------" << endl;
    cout << "Welcome to Registration and Deposit Page: " << endl;
    cout << "Enter Administrator Username: " << endl;
    cout << "Enter Administrator Password: " << endl;
    cout << "----------------------------------------------" << endl;
}
