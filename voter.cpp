#include<iostream>
#include"voter.h"
#include<fstream>
using namespace std;

void voter::login_voter(string name, string pass)
{
	voter_node* temp;
	voter_node* del;

	temp = head;
	bool check = false;
	while (temp != NULL)
	{
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
		cout << "Press 1 to sort by id\n";
		cout << "Press 2 ro sort by nmae\n";
		cout << "Enter your choice : ";
		cin >> ch;
		switch (ch)
		{
		case '1':
			sortbyid();
			break;
		case '2':
			sortbyname();
			break;
		default:
			cout << "Inavalid input\n";
			break;

		}
	}

}

void voter::register_voter()
{
	fstream file;
	file.open("voter.txt", ios::app);

	string uname;
	string pass;
	string cnic;
	voter_node* temp = new voter_node;
	cout << "Enter user name : ";
	cin >> uname;
	cout << "Enter password : ";
	cin >> pass;
	
	cout << "Enter cnic : ";
	cin >> cnic;


	temp->uname = uname;
	temp->pass = pass;
	temp->cnic = cnic;
	temp->next = NULL;
	
	if (head == NULL)
	{
		head = temp;
		tail = temp;
		file << temp->uname << " " << temp->pass << " " << temp->cnic << endl;

	}
	else
	{
		file << temp->uname << " " << temp->pass << " " << temp->cnic << endl;
		tail->next = temp;
		tail = tail->next;
	}
	return;
}

void voter::show_candidates()
{
	display_can();
}
void voter::sortbyid()
{
	sortid();
}

void voter::sortbyname()
{
	sortname();
}


