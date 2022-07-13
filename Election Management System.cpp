// Election Management System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"constituency.h"
using namespace std;
int main()
{
	constituency c1;
	int choice1;
	while (1)
	{
		cout << "enter 1 to login as election commision\n";
		cout << "enter 2 to login as poltical party\n";
		cout << "enter 3 to login as voter\n";
		cout << "enter 4 to exit\n";
		cin >> choice1;
		switch (choice1)
		{
		case 1:
		{
			c1.menu1();
			break;
		}
		case 2:
		{
			string uname;
			string pass;
			cout << "Enter user name : ";
			cin >> uname;
			cout << "Enter Password : ";
			cin >> pass;
			c1.login_poltical(uname, pass);
			break;
		}
		case 3:
		{
			string uname;
			string pass;
			cout << "Enter user name : ";
			cin >> uname;
			cout << "Enter Password : ";
			cin >> pass;
			c1.login_voter(uname, pass);
			break;
		}
		case 4:
		{
			exit(1);
			break;
		}
		default:
			cout << "Invalid Input\n";
			break;
		}
	}
}
