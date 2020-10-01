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
int LoginCheck (string user, string pass);
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
        guestAccount();
        break;
    case 2:
        administrator();
        break;
    default:
        cout << "Invalid Input TRY AGAIN with 1 or 2 " << endl;
        goto S;
    }
    return 0;

}
string user;
string pass;

int LoginCheck (string user, string pass)
{
    ifstream file;
    string username, password;
    int n=0;
    file.open("users.txt");
    if (file.is_open())
    {
        while (!file.eof())
        {
            file >> username >> password;
            n++;
            if (user==username && pass==password)
                return n;
        }
    }
    else
    {
        cout << "file not open" << endl;
    }

}
//normalUser Function
void guestAccount()
{
    int loginattempts=0;
    ifstream userfile;
    userfile.open("users.txt");
    string userset, passset;
    if (!userfile.is_open())
    {
        cout << "file not found" << endl;
    }
    else
    {

            while (LoginCheck(user, pass)==0)
            {
                loginattempts++;
                cout << "Username: ";
                cin >> user;
                cout << "Password: ";
                cin >> pass;
                if (LoginCheck(user, pass)!=0)
                    cout << "Welcome " << user << "." << endl;
                else if (loginattempts==3)
                {
                    cout << "Maximum login attempts exceeded." << endl;
                    break;
                }
                else
                {
                    cout << "Invalid username/password combination" << endl;
                }
            }
            userfile.close();


}
}

//Administrator Function
void administrator()
{
    //variables definition
    string adminUsername;
    int adminPassword;
    S:
        cout << "\n----------------------------------------------" << endl;
        cout << "Welcome to Administrator's Portal: " << endl;
        cout << "----------------------------------------------" << endl;
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

     S:
        cout << "\n-----------------------------------" << endl;
        cout << "WELCOME ADMIN!.." << endl;
        cout << "-----------------------------------" << endl;
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
        cout << endl;
        cout << "------------------------------------------------" << endl;
        cout << endl;
        goto S;

    case 2:
        Register();
        cout << "Successfully Registered!... THANK YOU!.." << endl;
        cout << "-----------------------------------------------" << endl;
        cout << endl;
        goto S;
    case 3:
        cout << "Awesome!.." << endl;
        goto S;
    case 4:
        cout << "\nTHANK YOU FOR BANKING WITH US!.." << endl;
        cout << "------------------------------------------------" << endl;
        cout << endl;
        break;

    default:
        cout << "Invalid Choice PLEASE TRY AGAIN!.." << endl;
        cout << endl;
        goto S;

    }
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
