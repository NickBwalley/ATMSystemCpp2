#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//function prototype
void guestAccount();
void adminsAccount();
void adminsFunct();
void guestFunct();
void registerNewClient();
void depositClientFunds();
void changeAdminsPassword();
void exit();
/**********************************/
//guest userLoginCheck
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

//adminsLoginCheck
string user2;
string pass2;

int LoginCheck2 (string user2, string pass2)
{
    ifstream file;
    string username, password;
    int n=0;
    file.open("admin.txt");
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
        adminsAccount();
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
        cout << "\n-----------------------------------" << endl;
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
                if (LoginCheck(user, pass)!=0){
                    cout << "\nWelcome " << user << "!.." << endl;
                    guestFunct();
                }
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

//function administrator account
void adminsAccount()
{
    int loginattempts=0;
    ifstream userfile;
    userfile.open("admin.txt");
    string userset, passset;
    if (!userfile.is_open())
    {
        cout << "file not found" << endl;
    }
    else
    {
        cout << "\n--------------------------------------------" << endl;
        cout << " WELCOME TO THE ADMINISTRATOR'S ACCOUNT!.." << endl;
        cout << "Press 1 to login as an ADMIN!.." << endl;
        int option;
        cin >> option;
        if (option==1)
        {
            while (LoginCheck2(user2, pass2)==0)
            {
                loginattempts++;
                cout << "Enter Admins Username: ";
                cin >> user;
                cout << "Enter Admins Password: ";
                cin >> pass;
                if (LoginCheck2(user2, pass2)!=0)
                {
                    cout << "\nWelcome " << user << "!.." << endl;
                    adminsFunct();
                }
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


        }


    }
}

//adminsFunct implementation
void adminsFunct()
{
    int option;
    A:
        cout << "\n1. Register New Client" << endl;
        cout << "2. Deposit Client Funds" << endl;
        cout << "3. Change my Password" << endl;
        cout << "4. Exit" << endl;
        cout << "\n Choose option to proceed: " << endl;
        cin >> option;
    switch(option)
    {
    case 1:
        registerNewClient();
        break;
    case 2:
        //depositClientFunds();
        break;
    case 3:
        changeAdminsPassword();
        break;
    case 4:
        exit();
    default:
        cout << "\nInvalid Input PLEASE TRY AGAIN!.." << endl;
        goto A;
    }

}
void registerNewClient()
{
    Register();
    cout << "\n\nUser Successfully Registered!.." << endl;
    cout << "--------------------------------------------" << endl;
    adminsFunct();
}
void changeAdminsPassword()
{
    string strSearch; //string to search
    string strReplace; //string to replace
    cout << "\n--------------------------------" << endl;
    cout << "ADMINS PASSWORD RESET!.." << endl;;
    cout << "Enter Admin's Username: " << endl;;
    cin >> strSearch;
    cout << "Enter New Admin's Password: " << endl;
    cin >> strReplace;
    ifstream filein("admin.txt"); //File to read from
    ofstream fileout("temp.txt"); //Temporary file
     if(!filein || !fileout) //if both files are not available
	{
        cout << "Error opening files!" << endl;
        exit(1);
    }
    string strTemp;
    bool found = false;
    while(filein >> strTemp) // it will check line from admin to strTemp string
    {
        if(strTemp == strSearch) // if your word found then replace
        {
            strTemp = strReplace;
            //found = true
        }
        strTemp += "\n";
        fileout << strTemp; //output everything to fileout (admin.txt)
    }


}
/**********************GUEST ACCOUNT *******************************/
//guestFunct implementation
void guestFunct()
{
    int option;
    cout << "\n1. Check Balance" << endl;
    cout << "2. Withdraw Cash" << endl;
    cout << "3. Change my Password" << endl;
    cout << "\n Choose option to proceed: " << endl;
    cin >> option;

}
void exit()
{
    cout << "\n\nTHANK YOU FOR BANKING WITH US!.." << endl;
    exit(0);
}
