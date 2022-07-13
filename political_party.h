#include<iostream>
using namespace std;
struct political_party
{
	int count;
	string symbol;
	string uname;
	string name;
	string pass;
	string id;
	political_party* next;
};

class political
{
private:
	political_party* head, * tail;
public:
	void acceptreject();
	void login_poltical(string a, string b);
	political();
	void register_political_party(string name,string id,string sym);
	
};