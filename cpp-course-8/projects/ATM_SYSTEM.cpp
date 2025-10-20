#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
const string ClientsFileName = "Clients.txt";

void Login();

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;


};

sClient Client;

void ShowATMMainMenue(sClient client);

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{

    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;

}

vector <sClient> SaveCleintsDataToFile(string FileName, vector <sClient> vClients)
{

    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite

    string DataLine;

    if (MyFile.is_open())
    {

        for (sClient C : vClients)
        {

            if (C.MarkForDelete == false)
            {
                //we only write records that are not marked for delete.  
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;

            }

        }

        MyFile.close();

    }

    return vClients;

}

vector<string> SplitString(string S1, string Delim)
{

    vector<string> vString;

    short pos = 0;
    string sWord; // define a string variable  

    // use find() function to get the position of the delimiters  
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word   
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
    }

    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }

    return vString;

}

sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{

    sClient Client;
    vector<string> vClientData;

    vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);//cast string to double


    return Client;

}

vector <sClient> LoadCleintsDataFromFile(string FileName)
{

    vector <sClient> vClients;

    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode

    if (MyFile.is_open())
    {

        string Line;
        sClient Client;

        while (getline(MyFile, Line))
        {

            Client = ConvertLinetoRecord(Line);

            vClients.push_back(Client);
        }

        MyFile.close();

    }

    return vClients;

}

sClient readAccountNumberAndPinCode() {
    sClient client;
    cout << "Enter Account Number : ";
    getline(cin >> ws, client.AccountNumber);
    cout << "Enter Pin Code : ";
    getline(cin, client.PinCode);
    return client;
}

bool checkIfClientExist(sClient& client) {
    vector <sClient> sClients = LoadCleintsDataFromFile(ClientsFileName);
    for(sClient& C : sClients) {
        if(C.AccountNumber == client.AccountNumber && C.PinCode == client.PinCode) {
            client = C;
            return true;
        }
    }
    return false;
}

enum enATMMainMenueOptions { eQuickWithdraw = 1, eNormalWithdraw = 2, eDeposit = 3, eCheckBalance = 4, eLogout = 5 };

enum enATMQuickWithdrawMenueOptions {
    eTweny = 1,
    eFivty = 2,
    eOneHundred = 3,
    eTwoHundreds = 4,
    eFourHundreds = 5,
    eSixHundreds = 6,
    eHeightHundreds = 7,
    eOneThousand = 8,
    eExit = 9
};

void GoBackToATMMainMenue(sClient Client)
{
    cout << "\n\nPress any key to go back to ATM Main Menue...";
    cin.ignore();
    cin.get();
    ShowATMMainMenue(Client);

}

short ReadATMMainMenueOption()
{
    cout << "Choose what do you want to do? [1 to 5]? ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}

void ShowTotalBalanceScreen()
{
    vector <sClient> sClients = LoadCleintsDataFromFile(ClientsFileName);
    
    for(sClient& C : sClients) {
        if(C.AccountNumber == Client.AccountNumber) {
            cout << "\n==============================================\n";
            cout << "\nYour Balance is : " << C.AccountBalance << endl;
            cout << "\n==============================================\n";
            break;
        }
    }
}

short ReadATMQuickWithdrawMenueOption() {
    short choice = 0;
    cout << "Choose what to withdraw from [1] to [8] OR [9] For Exit ?";
    cin >> choice;
    return choice;
}

void QuickWithdraw(double balance) {
    char res = 'n';
    cout << "\n\nAre you sure you want to perform this transaction? y/n? ";
    cin >> res;

    vector <sClient> sClients  = LoadCleintsDataFromFile(ClientsFileName);

    if(res == 'y' || res ==  'Y') {
        for(sClient& C : sClients) {
            if(C.AccountNumber == Client.AccountNumber) {
                if(C.AccountBalance >= balance) {
                    Client.AccountBalance -= balance;
                    C = Client;
                    SaveCleintsDataToFile(ClientsFileName, sClients);
                    cout << "\n\nDone Successfully, New balance is: " << Client.AccountBalance << endl;
                } else {
                    cout << "\n\nYour balance insuffussant\n";
                }
                break;
            }
        }
    } else {
        GoBackToATMMainMenue(Client);
    }
}
 
void PerfromATMQuickWithdrawMenueOption(sClient Client, enATMQuickWithdrawMenueOptions ATMQuickWithdrawMenueOption)
{
    switch (ATMQuickWithdrawMenueOption)
    {
        case enATMQuickWithdrawMenueOptions::eTweny:
        {
            QuickWithdraw(20);
            GoBackToATMMainMenue(Client);
            break;
        }

        case enATMQuickWithdrawMenueOptions::eFivty:
        {
            QuickWithdraw(50);
            GoBackToATMMainMenue(Client);
            break;
        }

        case enATMQuickWithdrawMenueOptions::eOneHundred:
        {
            QuickWithdraw(100);
            GoBackToATMMainMenue(Client);
            break;
        }

        case enATMQuickWithdrawMenueOptions::eTwoHundreds:
        {
            QuickWithdraw(200);
            GoBackToATMMainMenue(Client);
            break;
        }

        case enATMQuickWithdrawMenueOptions::eFourHundreds:
        {
            QuickWithdraw(400);
            GoBackToATMMainMenue(Client);
            break;
        }

        case enATMQuickWithdrawMenueOptions::eSixHundreds:
        {
            QuickWithdraw(600);
            GoBackToATMMainMenue(Client);
            break;
        }

        case enATMQuickWithdrawMenueOptions::eHeightHundreds:
        {
            QuickWithdraw(800);
            GoBackToATMMainMenue(Client);
            break;
        }

        case enATMQuickWithdrawMenueOptions::eOneThousand:
        {
            QuickWithdraw(1000);
            GoBackToATMMainMenue(Client);
            break;
        }

        case enATMQuickWithdrawMenueOptions::eExit:
        {
            GoBackToATMMainMenue(Client);
            break;
        }
    }

}

void ShowQuickWithDrawScreen() {
    system("clear");
    cout << "===========================================\n";
    cout << "\t\tQuick Withdraw\n";
    cout << "===========================================\n";
    cout << "\t[1] 20 \t\t[2] 50\n";
    cout << "\t[3] 100 \t[4] 200\n";
    cout << "\t[5] 400 \t[6] 600\n";
    cout << "\t[7] 800 \t[8] 1000\n";
    cout << "\t[9] Exit\n";
    cout << "===========================================\n";
    cout << "\nYour Balance is : " << Client.AccountBalance << endl;
    PerfromATMQuickWithdrawMenueOption(Client, (enATMQuickWithdrawMenueOptions)ReadATMQuickWithdrawMenueOption());
}

double readBalance() {
    double balance = 0;
    do {
        cout << "\nEnter balance 5's : " << endl;
        cin >> balance;
    }while((int)balance % 5 != 0);
    return balance;
}

void ShowNormalWithDrawScreen() {
    system("clear");
    cout << "===========================================\n";
    cout << "\t\tNormal Withdraw\n";
    cout << "===========================================\n\n";
    double balance = readBalance();
    QuickWithdraw(balance);
}

void ShowDepositScreen() {
    double balance = 0;
    system("clear");
    cout << "===========================================\n";
    cout << "\t\tDeposit Screen\n";
    cout << "===========================================\n\n";
    do {
        cout << "Enter Deposit balance (positive ( > 0 )) : ";
        cin >>  balance;
    }while(balance <= 0);
    vector <sClient> sClients = LoadCleintsDataFromFile(ClientsFileName);
    for(sClient& C : sClients) {
        if(C.AccountNumber == Client.AccountNumber) {
            Client.AccountBalance += balance;
            C = Client;
            SaveCleintsDataToFile(ClientsFileName, sClients);
        }
    }
}

void PerfromATMMenueOption(sClient Client, enATMMainMenueOptions ATMMenueOption)
{
    switch (ATMMenueOption)
    {
        case enATMMainMenueOptions::eQuickWithdraw:
        {
            system("clear");
            ShowQuickWithDrawScreen();
            GoBackToATMMainMenue(Client);
            break;
        }

        case enATMMainMenueOptions::eNormalWithdraw:
        {
            system("clear");
            ShowNormalWithDrawScreen();
            GoBackToATMMainMenue(Client);
            break;
        }

        case enATMMainMenueOptions::eDeposit:
        {
            system("clear");
            ShowDepositScreen();
            GoBackToATMMainMenue(Client);
            break;
        }

        case enATMMainMenueOptions::eCheckBalance:
        {
            system("clear");
            ShowTotalBalanceScreen();
            GoBackToATMMainMenue(Client);
            break;
        }

        case enATMMainMenueOptions::eLogout:
        {
            system("clear");
            Login();
            break;
        }
    }

}

void ShowATMMainMenue(sClient client)
{
    system("clear");
    cout << "===========================================\n";
    cout << "\t\tATM Main Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Quick Withdraw.\n";
    cout << "\t[2] Normal Withdraw.\n";
    cout << "\t[3] Deposit.\n";
    cout << "\t[4] Check Balance.\n";
    cout << "\t[5] Logout.\n";
    cout << "===========================================\n";
    PerfromATMMenueOption(client, (enATMMainMenueOptions)ReadATMMainMenueOption());
}

void Login() {
    int counter = 0;
    do {
        system("clear");
        cout << "\n=============================\n\n";
        cout << "\tLogin Screen\n";
        cout << "\n=============================\n\n";
        if(counter != 0) 
            cout << "Invalid Account Number/PinCode!\n";
        Client = readAccountNumberAndPinCode();

        if(checkIfClientExist(Client)) {
            system("clear");

            ShowATMMainMenue(Client);
            cin.ignore();
            cin.get();
        } else {
            counter++; 
        }
    }while(!checkIfClientExist(Client));
}

int main() {
    system("clear");
    Login();
    
    return 0;
}