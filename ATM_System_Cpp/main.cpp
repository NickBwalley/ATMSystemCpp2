#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//function prototypes
void normalUser();
void administrator();
void guestAccount();
void adminAccount();

//Main-Method
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
//normalUser Function
void normalUser()
{
    //variables definition
    string guestUsername;
    int guestPassword;
    cout << "----------------------------------------------" << endl;
    cout << "Welcome to Normal Guest's Portal: " << endl;
    cout << "Enter Your User-name: " << endl;
    cin >> guestUsername;
    cout << "Enter Your Password: " << endl;
    cin >> guestPassword;
    guestAccount();

}
//Administrator Function
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
        adminAccount();
    }
    else{
        cout << "Incorrect password!.. TRY AGAIN" << endl;
    }
}

//adminAccount Function
void adminAccount(){
    cout << "----------------------------------" << endl;
    cout << "WELCOME ADMIN!.." << endl;
    cout << "1. Deposit money for Clients!.." << endl;
    cout << "2. Register New Client!.." << endl;
    cout << "3. Reset Your Password!.." << endl;
}
