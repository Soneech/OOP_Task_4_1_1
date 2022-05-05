#include "Application.h"
#include "Base.h"
#include "Object.h"
#include <iostream>
using namespace std;

Application::Application(Base* head) : Base(head, "child") { }

void Application::build_tree_objects() {
	string head_name, name_parent, name_child;

	cin >> head_name;
	set_name(head_name);

	Base* curr_parent = this;
	Base* curr_child = this;

	cin >> name_parent >> name_child;
	while (name_parent != name_child) {
		if (name_parent != curr_parent->get_name())
			curr_parent = curr_child;
		curr_child = new Object(curr_parent, name_child);
		cin >> name_parent >> name_child;
	}
}

int Application::execute() {
	cout << get_name();
	print_hierarchy();
	return 0;
}