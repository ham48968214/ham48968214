#include<iostream>
#include<fstream>
#include"political_party.h"
using namespace std;
bool won = false;
string winname = "";

political::political()
{
	head = NULL;
	tail = NULL;
}

void political::login_poltical(string name,string pass)
{
	political_party* temp;
	political_party* del;

	temp = head;
	bool check = false;
	while (temp != NULL)
	{
		cout << "Name : " << temp->uname << "  pass : " << temp->pass << endl;

		if (temp->uname == name && temp->pass == pass)
		{
			check = true;
			break;
		}
		temp = temp->next;
	}
	if (check == false)
	{
		cout << "LOGIN FAILED\n";
	}
	else
	{
		char ch;
		cout << "Press 1 to accept/reject ticket\n";
		cout << "Press 2 to check result\n";
		cin >> ch;
		switch (ch)
		{
		case '1':
			acceptreject();
			break;
		case '2':
			if (won == false)
			{
				cout << "Voting is not Done\n";
			}
			else
			{
				cout << "Voting is Done\n";
				cout << "Winner : " << winname;
			}
			break;
		default:
			cout << "Invalid input\n";
			break;

		}
	}

}


void political::register_political_party(string conname,string id,string sym)
{
	fstream file;
	file.open("political_party.txt", ios::app);

	string uname;
	string pass;
	political_party* temp = new political_party;
	cout << "Enter user name : ";
	cin >> uname;
	cout << "Enter password : ";
	cin >> pass;
	temp->uname = uname;
	temp->pass = pass;
	temp->name = conname;
	temp->symbol = sym;
	temp->id = id;
	temp->next = NULL;
	temp->count = 0;
	
	if (head == NULL)
	{
		head = temp;
		tail = temp;
		file << temp->name << " " << temp->id << " " << temp->symbol << endl;

	}
	else
	{
		file << temp->name << " " << temp->id << " " << temp->symbol << endl;
		tail->next = temp;
		tail = tail->next;

	}
	return;
}
void political::acceptreject()
{
	char key;
	political_party* temp;
	political_party* del;
	int i = 0;
	temp = head;
	bool check = false;
	while (temp != NULL)
	{
		cout << i << " " << temp->name << " | ID : " << temp->id << endl;
		temp = temp->next;
		i++;
	}
	cout << "Do you want to accept ticket (y/n) : ";
	cin >> key;
	if (key == 'y' || key == 'Y')
	{
		cout << "Accepted all tickets\n";
	}
	else
	{
		cout << "Rejected all tickets\n";
	}
}
