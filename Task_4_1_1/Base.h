#ifndef BASE_H
#define BASE_H
#include <string>
#include <vector>
using namespace std;

class Base {
	protected:
		string name = "default_name";
		Base* head;
		vector<Base*> children;  
	public:
		Base(Base* head, string name);
		~Base();
		void set_name(string name);
		string get_name();
		void print_hierarchy();
		void change_head(Base* new_head);
		Base* get_head();
};
#endif
