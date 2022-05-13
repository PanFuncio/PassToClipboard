#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <Windows.h> // use < > for all system and library headers
#include <winuser.h>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <complex>
#include <string>
#include <map>
#include <conio.h>
using namespace std;

// Quick tool to make your passwords come to your clipboard by writing their assosiciated keywords
void ToClip(HWND hwnd, const std::string& s)
{
    OpenClipboard(hwnd);
    EmptyClipboard();
    HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, s.size() + 1);
    if (!hg) {
        CloseClipboard();
        return;
    }
    memcpy(GlobalLock(hg), s.c_str(), s.size() + 1);
    GlobalUnlock(hg);
    SetClipboardData(CF_TEXT, hg);
    CloseClipboard();
    GlobalFree(hg);
}

int Action(string task)
{
    if (task == "LIST") // this shows all keywords
    {
        return 99;
    }
    else if (task == "EXIT")
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
class ToNum
{
public:
    map<string, string> passwords2;
    string keyword;
    string password;
    char password23;
    HWND hwnd = GetDesktopWindow();
    bool found_password = false;
    virtual void getPassword(string userInput)
    {
        map<string, string>::iterator itr = passwords2.begin();
        while (itr != passwords2.end())
        {
            if (itr->first == userInput)
            {
                cout << endl<<"Im in your clipboard!" << endl << endl << endl;
                found_password = true;
                ToClip(hwnd, itr->second);
                break;
            }
            itr++;
        }
        if (!found_password) { cout << endl << "No such keyword, try again " << endl << endl; }
    }
    virtual void InitiliazePasswordMap() // these are your passwords, add new ones as you wish
    {
        passwords2.insert({ "test1","pass1" });
        passwords2.insert({ "test2","pass2" });
        passwords2.insert({ "test3","trshr53453tht101rystr36363gfsd" });
        passwords2.insert({ "boink!234&w","333style_hero_of_my_story333" });
    }
    virtual void ListPasswords()
    {
        map<string, string>::iterator itr = passwords2.begin();
        cout << endl << "List of keywords: " << endl << endl;
        while (itr != passwords2.end())
        {
            cout << itr->first << endl;
            itr++;
        }
        cout << endl << endl << endl;
    }
    ToNum() = default;
    ~ToNum() = default;
};
string takePasswdFromUser() // makes password you enter invisible
{
    string ipt = "";
    char ipt_ch;
    while (true) {
        ipt_ch = _getch();
        if (ipt_ch < 32) {
            cout << endl;
            return ipt;
        }
        ipt.push_back(ipt_ch);
    }
}
int main()
{
    HWND hwnd = GetDesktopWindow();
    int exit = 0;
    string task;
    int task2;
    cout << "please login with your set password " << endl;
    string ActualPassword = "123"; // set this to your preferred password to get into the program
    string YourPassword = takePasswdFromUser();
    //cin >> YourPassword;
    if (YourPassword == ActualPassword)
    {
        "Login succesful welcome";
    }
    else
    {
        cout << "ouch";
        return 0;
    }
    string keyword;
    ToNum passwords;
    do
    {
        cout << "Type the password KEYWORD you want" << endl << "type LIST to get a list of passwords you can access" << endl << "type EXIT to close the program" << endl;
        passwords.InitiliazePasswordMap();
        cin >> task;

        task2 = Action(task);

        switch (task2)
        {
            case 0:
            {
                exit = 1;
                cout << "exiting..." << endl;
                break;
            }
            case 99:
            {
                passwords.ListPasswords();
                break;
            }
            case 1:
            {
                keyword = task;
                passwords.getPassword(keyword);
                break;
            }
 
        }
    } while (exit == 0);

    return 0;
}


