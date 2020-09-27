#include <iostream>
#include <fstream>
#include <string>
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
    cout << "Welcome to the Guest Portal: " << endl;
    cout << "Enter User-name: " << endl;
    cout << "Enter Password: " << endl;
    cout << "----------------------------------------------" << endl;
}
void administrator()
{
    //variables definition
    string adminUsername;
    int adminPassword;
    cout << "----------------------------------------------" << endl;
    cout << "Welcome to Administrator's Portal: " << endl;
    cout << "Enter Administrator User-name: " << endl;
    cin >> adminUsername;
    cout << "Enter Administrator Password: " << endl;
    cin >> adminPassword;

    if(adminUsername == "admin" && adminPassword == 1234)
    {
        cout << "Correct password!.." << endl;
    }
    else{
        cout << "Incorrect password!.." << endl;
        system("pause");
    }
}
