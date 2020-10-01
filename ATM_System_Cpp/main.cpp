#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//function prototypes
void normalUser();
void administrator();
void guestAccount();
void adminAccount();
void Register();
//Main-Method
int main()
{
    //variable definition
    int option;
    S:
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
        goto S;
    }
    return 0;
    getchar();
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
    S:
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
        goto S;
    }
}

//adminAccount Function
void adminAccount(){
    int option;
    float deposit;
    float amount = 0;
    cout << "----------------------------------" << endl;
     S:
        cout << "WELCOME ADMIN!.." << endl;
        cout << "1. Deposit money for Clients!.." << endl;
        cout << "2. Register New Client!.." << endl;
        cout << "3. Reset Your Password!.." << endl;
        cout << "4. Exit" << endl;
        cout << "\n Enter Option to Proceed: " << endl;
        cin >> option;
    switch(option)
    {
    case 1:
        cout << "\nEnter Amount to Deposit: ";
        cin >> deposit;
        amount=amount+deposit;
        cout << "Successfully Deposited Ksh" << amount << endl;
        cout << "THANK YOU FOR BANKING WITH US!.." << endl;
        cout << "------------------------------------------------" << endl;
        goto S;

    case 2:
        Register();
        cout << "Successfully Registered!... THANK YOU!.." << endl;
        cout << "-----------------------------------------------" << endl;
        goto S;
    case 3:
        cout << "Awesome!.." << endl;
        goto S;
    case 4:
        cout << "THANK YOU FOR BANKING WITH US!.." << endl;
        cout << "------------------------------------------------" << endl;
        goto S;

    default:
        cout << "Invalid Choice PLEASE TRY AGAIN!.." << endl;
        goto S;

    }
}

//guestAccount function
void guestAccount()
{
    cout << "Welcome to the guest Account!" << endl;
}

// Administrator register NewUser
void Register()
{
    string user;
    string pass;
    int deposit;
    ifstream file;
    ofstream newuser;
    string username, password, passwordconfirm;
    file.open("users.txt", ios::app);
    newuser.open("users.txt", ios::app);
    bool uservalid=false;
    while (!uservalid)
    {
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
        cout << "Confirm password: ";
        cin >> passwordconfirm;
        cout << "Deposit Amount: ";
        cin >> deposit;

        int m=0;
        int k=0;
        while (file >> user >> pass >> deposit)
        {
            m++;
            if (username!=user)
                k++;
        }
        if (m==k && password==passwordconfirm)
            uservalid=true;
        else if (m!=k)
            cout << "There is already a user with this username." << endl;
        else
            cout << "The passwords given do not match." << endl;
    }
    newuser << username << " " << password << " " << deposit << endl;
    file.close();
    newuser.close();
}
