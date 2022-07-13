#include<iostream>
#include"candidate.h"
using namespace std;

struct voter_node
{
	string cnic;
	string uname;
	string pass;
	voter_node* next;
};

//bool won = false;
//string winname = "";

class voter:public candidate
{
private:
	voter_node* head, * tail;

public:
	void login_voter(string a,string b);
	void show_candidates();
	void cast_vote();
	void sortbyid();
	void sortbyname();
	void register_voter();

};