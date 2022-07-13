#include<iostream>
using namespace std;

struct candidate_node
{
	string name;
	string symbol;
	string count;
	string cnic;
	string id;
	string uname;
	string pass;
	candidate_node* next;
};


class candidate{
private:
	candidate_node* head1, * tail1;
public:
	void sortid();
	void sortname();
	void display_can();
	void register_candidate();
	void register_indcandidate(string con_name,string con_id,string con_symbol,string cnic);
	void register_candidate(string con_name, string con_id, string con_symbol, string uname,string pass);


};