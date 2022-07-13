#include<iostream>
#include"candidate.h"
using namespace std;
int len = 0;

void candidate::register_indcandidate(string con_name, string con_id, string con_symbol, string cnic)
{
	string uname;
	string pass;
	candidate_node* temp = new candidate_node;
	cout << "Enter user name : ";
	cin >> uname;
	
	cout << "Enter cnic : ";
	cin >> cnic;

	temp->id = con_id;
	temp->name = con_name;
	temp->symbol = con_symbol;

	temp->uname = uname;
	temp->cnic = cnic;
	temp->next = NULL;

	if (head1 == NULL)
	{
		head1 = temp;
		tail1 = temp;
		len++;
	}
	else
	{
		tail1->next = temp;
		tail1 = tail1->next;
		len++;
	}
	return;

}
void candidate::register_candidate(string con_name, string con_id, string con_symbol, string uname, string pass)
{
	string cnic;
	candidate_node* temp = new candidate_node;
	cout << "Enter  name : ";
	cin >> uname;
	cout << "Enter password : ";
	cin >> pass;
	cout << "Enter cnic : ";
	cin >> cnic;

	temp->id = con_id;
	temp->name = con_name;
	temp->symbol = con_symbol;
	temp->pass = pass;
	temp->cnic = cnic;
	temp->next = NULL;

	if (head1 == NULL)
	{
		head1 = temp;
		tail1 = temp;
		len++;
	}
	else
	{
		tail1->next = temp;
		tail1 = tail1->next;
		len++;
	}
	return;

}

void candidate::display_can()
{
	candidate_node* temp;
	temp = head1;
	cout << "All register candidate are\n";
	while (temp != NULL)
	{
		cout << "Name : " << temp->uname << " | ID : " << temp->id << " | Symbol : " << temp->symbol << endl;
		temp = temp->next;
	}
	cout << endl;

}

candidate_node* swap(candidate_node* ptr1, candidate_node* ptr2)
{
	candidate_node* tmp = ptr2->next;
	ptr2->next = ptr1;
	ptr1->next = tmp;
	return ptr2;
}

void bubbleSortid(candidate_node** head, int count)
{
	candidate_node** h;
	int i, j, swapped;

	for (i = 0; i <= count; i++)
	{

		h = head;
		swapped = 0;

		for (j = 0; j < count - i - 1; j++)
		{

			candidate_node* p1 = *h;
			candidate_node* p2 = p1->next;

			if (p1->id.length() > p2->id.length())
			{

				*h = swap(p1, p2);
				swapped = 1;
			}

			h = &(*h)->next;
		}

		if (swapped == 0)
			break;
	}
	return;
}


void bubbleSortname(candidate_node** head, int count)
{
	candidate_node** h;
	int i, j, swapped;

	for (i = 0; i <= count; i++)
	{

		h = head;
		swapped = 0;

		for (j = 0; j < count - i - 1; j++)
		{

			candidate_node* p1 = *h;
			candidate_node* p2 = p1->next;

			if (p1->name.length() > p2->name.length())
			{

				*h = swap(p1, p2);
				swapped = 1;
			}

			h = &(*h)->next;
		}

		if (swapped == 0)
			break;
	}
	return;
}

void candidate::sortid()
{
	bubbleSortid(&head1, len);
}


void candidate::sortname()
{
	bubbleSortname(&head1, len);
}

