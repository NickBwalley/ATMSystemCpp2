#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//function prototype
void guestAccount();
void administrator();

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
    return 0;
}

void Register()
{
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
        int m=0;
        int k=0;
        while (file >> user >> pass)
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
    newuser << username << " " << password << endl;;
    file.close();
    newuser.close();
}

int main()
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
        //administrator();
        break;
    default:
        cout << "Invalid Input TRY AGAIN with 1 or 2 " << endl;
        goto S;
    }

        cout << "1.Login \n2.Register" << endl;
        //int option;
        cin >> option;
        if (option==1)
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
        else if (option==2)
        {
            Register();
        }
    }
    int a;
    cin >> a; // this has no purpose other than stopping the program closing automatically
    return 0;
}

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
        cout << "\n--------------------------" << endl;
        cout << " WELCOME TO THE GUESTS ACCOUNT!.." << endl;
        cout << "Press 1 to login to your account!.." << endl;
        int option;
        cin >> option;
        if (option==1)
        {
            while (LoginCheck(user, pass)==0)
            {
                loginattempts++;
                cout << "Enter your Username: ";
                cin >> user;
                cout << "Enter your Password: ";
                cin >> pass;
                if (LoginCheck(user, pass)!=0)
                    cout << "\nWelcome " << user << "!.." << endl;
                else if (loginattempts==3)
                {
                    cout << "Maximum login attempts exceeded!..PLEASE TRY AGAIN LATER!..." << endl;
                    break;
                }
                else
                {
                    cout << "Invalid username/password combination" << endl;
                }
            }
            exit(0);

        }


}
}
