#include<iostream>
#include"constituency.h"
#include<fstream>
using namespace std;
int choice;

constituency::constituency()
{
	head = NULL;
	tail = NULL;
}


void constituency::menu1()
{
char key = 'Y';
do
{

	cout << "1 to register national assemble constituency\n";
	cout << "2 to list all constituencies\n";
	cout << "3 to update/Delete constituency\n";
	cout << "4 to register political party\n";
	cout << "5 to register candidate\n";
	cout << "6 to register voter\n";
	cout << "7 to cast a winner\n";
	cout << "8 to Exit Election Commision Login\n";
	cout << "Enter Your choice : ";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		char choicec;
		string con_name;
		string con_id;
		string con_symbol;
		do
		{
			cout << "Enter name of constituency i-e NA-1, Peshawar - 1 : ";
			cin >> con_name;

			cout << "Enter ID of constituency  : ";
			cin >> con_id;
			cout << "Enter Symbol of constituency  : ";
			cin >> con_symbol;

			register_constituency(con_name, con_id, con_symbol);
			cout << "do you want to add another constituency y/n \n";
			cin >> choicec;
		} while (choicec == 'y' || choicec == 'Y');

		break;
	}
	case 2:
	{
		display_constituency();
	}
	break;
	case 3:
	{
		char key;
		cout << "Press u for update\n";
		cout << "Press d for delete\n";
		cout << "Your Choice : ";
		cin >> key;
		if (key == 'U' || key == 'u')
		{
			update_constituency();
		}

		else if (key == 'D' || key == 'd')
		{
			delete_constituency();
		}

		else
		{
			cout << "Invalid input\n";
		}


	}
	break;

	case 4:
	{
			string con_name;
			cout << "Enter name of constitution for which political party is for : ";
			cin >> con_name;
			bool check = namecheck(con_name);
			if (check == true)
			{
				cout << "Registeration of Political Party Done Successfully\n";
			}
			else
			{
				cout << "No Constitution exsist with this name\n";
			}
	}
	break;
	
	case 5:
	{
		char key;
		cout << "Press P for Political Party\n";
		cout << "Press I for Independent candidate\n";
		cout << "Your Choice : ";
		cin >> key;
		if (key == 'P' || key == 'p')
		{
			char choicec;
			string con_name;
			string con_id;
			string con_symbol;
			string uname, pass;
			do
			{
				cout << "Enter name of  Party : ";
				cin >> con_name;
				cout << "Enter ID of constituency  : ";
				cin >> con_id;
				cout << "Enter Symbol of constituency  : ";
				cin >> con_symbol;
				cout << "Enter username : ";
				cin >> uname;
				cout << "Enter password : ";
				cin >> pass;
				register_candidate(con_name, con_id, con_symbol,uname,pass);
				cout << "do you want to add another political parties y/n \n";
				cin >> choicec;
			} while (choicec == 'y' || choicec == 'Y');

		}

		else if (key == 'i' || key == 'I')
		{
			char choicec;
			string con_name;
			string con_id;
			string con_symbol;
			string uname, pass;
			string cnic;

			do
			{
				cout << "Enter name of  Party : ";
				cin >> con_name;
				cout << "Enter ID of constituency  : ";
				cin >> con_id;
				cout << "Enter Symbol of constituency  : ";
				cin >> con_symbol;
				cout << "Enter CNIC : ";
				cin >> cnic;
				register_indcandidate(con_name, con_id, con_symbol, cnic);
				cout << "do you want to add another political parties y/n \n";
				cin >> choicec;
			}while (choicec == 'y' || choicec == 'Y');

		}

		else
		{
			cout << "Invalid input\n";
		}


	}
	break;
	case 6:
		register_voter();
		break;
	case 7:
		cast_cons();
		break;
	case 8:
		key = 'Q';
		break;

	default:
		cout << "Inavlid input\n";
		break;
	}
} while (key != 'Q');
}
void constituency::register_constituency(string con_name,string con_id,string con_symbol)
{
	fstream file;
	file.open("constituency.txt", ios::app);
	constituency_node* temp = new constituency_node;
	temp->name = con_name;
	temp->id = con_id;
	temp->symbol = con_symbol;
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
	file.close();
}
void constituency::display_constituency()
{
	constituency_node* temp;
	temp = head;
	cout << "All register constituency are\n";
	while (temp != NULL)
	{
		cout <<"Name : "<< temp->name << " | ID : "<<temp->id<<" | Symbol : "<<temp->symbol << endl;
		temp = temp->next;
	}
	cout << endl;
}


void constituency::delete_constituency()
{
	constituency_node* temp;

	string id1;
	temp = head;
	bool check = false;
	cout << "Enter the ID of constituency to be deleted : ";
	cin >> id1;

	if (head == NULL)
		return;

	if (temp->id == id1) {

		head = temp->next;
		free(temp);
		cout << "Deletion Done\n";
		return;
	}

	for (; temp != NULL && temp->id != id1; )
		temp = temp->next;

	if (temp == NULL || temp->next == NULL)
	{
		cout << "No Constituency with this id exist\n";
		return;
    }
	constituency_node* del = temp->next->next;

	free(temp->next); 
	temp->next = del;
	
	cout << "Deletion Done\n";	
}


void constituency::update_constituency()
{
	constituency_node* temp;
	constituency_node* del;

	string id1;
	temp = head;
	bool check = false;
	cout << "Enter the ID of constituency to be updated : ";
	cin >> id1;
	while (temp != NULL)
	{
		if (temp->id == id1)
		{
			check = true;
			cout << "Enter updated Name : ";
			cin >> temp->name;
			cout << "Enter updated ID : ";
			cin >> temp->id;
			cout << "Enter updated Symbol : ";
			cin >> temp->symbol;
			cout << "Name Updated Successfully\n";
			break;
		}
		temp = temp->next;
	}
	if (check == false)
	{
		cout << "No such constituency exist\n";
	}

}

bool constituency::namecheck(string name)
{
	constituency_node* temp;
	constituency_node* del;

	string id1;
	temp = head;
	bool check = false;
	while (temp != NULL)
	{
		if (temp->name == name)
		{
			check = true;
			register_political_party(temp->name,temp->id,temp->symbol);
			return check;
		}
		temp = temp->next;
	}
	return check;

}

void constituency::cast_cons()
{
	constituency_node* temp;
	constituency_node* temp2;

	temp = head;
	temp2 = head;
	int arr[20];
	for (int i = 0; i < 20; i++)
	{
		arr[i] = 0;
	}
	int a = 0;
	string b;
	int index = 0;
	string c;
	string name[20];
	while (temp2 != NULL)
	{
		a = 0;
		while (temp != NULL)
		{
			if (temp2->symbol == temp->symbol)
			{
				a++;
				b = temp->name;
				c = temp->symbol;
			}
			temp = temp->next;
		}
		arr[index] = a;
		name[index] = c;
		index++;
		temp2 = temp2->next;
	}
	int max = 0;
	int t;
	for (int i = 0; i < index; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			t = i;
		}
	}
	cout << "Winner is " << name[t] << "with votes" << max << endl;
}