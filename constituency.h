#pragma once
#include<iostream>
#include"political_party.h"
#include"voter.h"
using namespace std;
struct constituency_node
{
	int count;
	string symbol;
	string name;
	string id;
	constituency_node* next;
};

class constituency:public political,public voter
{
private:
	constituency_node* head, * tail;
public:
	void cast_cons();
	constituency();
	void menu1();
	void register_constituency(string con_name1,string con_id1,string sym);
	void display_constituency();
	bool namecheck(string name);
	void update_constituency();
	void delete_constituency();
	void show_results();
	

};
