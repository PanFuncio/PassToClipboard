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

using namespace std;

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
int TaskToNum(string task)
{

	//if (task == "list")  
	//{
	//	return 99;
	//}
	// copy above for quick new option, remember to add a case in switch
	if (task == "LIST") // this shows all keywords
	{
		return 99;
	}
	if (task == "EXIT")
	{
		return 0;
	}
	if (task == "test1")
	{
		return 1;
	}
	if (task == "test2")
	{
		return 2;
	}
}

int main()
{

	HWND hwnd = GetDesktopWindow();
	int exit = 0;
	string task;
	int task2;
	cout << "please login with your set password " << endl;
	string ActualPassword = "123"; // set this to your preferred password
	string YourPassword;
	cin >> YourPassword;
	if (YourPassword == ActualPassword)
	{
		"Login succesful welcome";
	}
	else
	{
		cout << "ouch";
		return 0;
	}
	string passwords[99] = { "test1", "test2" }; // add passwords you want
	int passwordsSize = *(&passwords + 1) - passwords;

	do
	{
		cout << "Type the password KEYWORD you want" << endl << "type LIST to get a list of passwords you can access" << endl <<"type EXIT to close the program" << endl;
		cin >> task;
		task2 = TaskToNum(task);
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
			cout << "Accessing passwords keywords" << endl << endl << endl;
			for (int i = 0; i < passwordsSize; i++)
			{
				if(passwords[i]!="")
				cout << passwords[i] << endl;
			}
			cout << "All the passwords I found" << endl << endl << endl;
			break;
		}
		case 1:
		{
			cout << "copying " << task << endl;
			ToClip(hwnd, "password_for_test1"); // Function that copies to clipboard, hwnd - window string - our password or  anything you want
			cout << "Im in your clipboard" << endl;
			break;
		}
		case 2:
		{
			cout << "copying " << task << endl;
			ToClip(hwnd, "password_for_test2");
			cout << "Im in your clipboard" << endl;
			break;
		}
		default:
		{
			cout << "No such keyword has been found, try again" << endl << endl << endl;
			break;
		}
		}
	} while (exit == 0);

	return 0;
}
/*
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
using namespace std;

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

int TaskToNum(string task)
{

  //if (task == "list")  
  //{
  //	return 99;
  //}
  // copy above for quick new option, remember to add a case in switch
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
  virtual void TaskToNum2(string userInput)
  {
    
    map<string, string>::iterator itr = passwords2.begin();
    while (itr != passwords2.end())
    {
      if (itr->first == userInput)
      {
        cout << "Im in your clipboard" << endl;
        cout << endl << "Password for " << itr->first << " is " << itr->second << endl << endl << endl;
        
        ToClip(hwnd, itr->second);
        break;
      }
      else
      {
        cout << "No such keyword has been found, try again" << endl << endl << endl;
        break;
        
      }
      itr++;
    }
  }
  virtual void InitiliazePasswordMap()
  {
    passwords2.insert({ "test1","pass1" });
    passwords2.insert({ "test2","pass2" });
    passwords2.insert({ "test3","trshr53453tht101rystr36363gfsd" });
  }
  virtual void ListPasswords()
  {
    map<string, string>::iterator itr = passwords2.begin();
    cout << "List of keywords: " << endl;
    while (itr != passwords2.end())
    {
      cout << itr->first << endl;
      itr++;
    }
    
  }
  ToNum() = default;
  ~ToNum() = default;
};

int main()
{

  HWND hwnd = GetDesktopWindow();
  int exit = 0;
  string task;
  int task2;
  cout << "please login with your set password " << endl;
  string ActualPassword = "123"; // set this to your preferred password
  string YourPassword;
  cin >> YourPassword;
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
  ToNum tonumer;
  
  //cin >> keyword;
  
  
  do
  {
    cout << "Type the password KEYWORD you want" << endl << "type LIST to get a list of passwords you can access" << endl << "type EXIT to close the program" << endl;
    tonumer.InitiliazePasswordMap();
    cin >> task;
    
    task2 = TaskToNum(task);
    
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
      tonumer.ListPasswords();
      break;
    }
    case 1:
    {
      keyword = task;
      tonumer.TaskToNum2(keyword);
      break;
    }
    default:
    {
      
    }
    }
  } while (exit == 0);

  return 0;
}


*/

