#include "Base.h"
#include <iostream>
using namespace std;

Base::Base(Base* head, string name) {
	this->head = head;
	this->name = name;
	if (head != nullptr)
		head->children.push_back(this);
}

void Base::set_name(string name) {
	this->name = name;
}

string Base::get_name() {
	return name;
}

void Base::print_hierarchy() {
	if (children.size() != 0)
		cout << endl << name << "  ";
	for (int i = 0; i < children.size(); i++) {
		if (i < children.size() - 1)
			cout << children[i]->get_name() << "  ";
		else
			cout << children[i]->get_name();
	}
	for (int j = 0; j < children.size(); j++)
		children[j]->print_hierarchy();
}

void Base::change_head(Base* new_head) {
	if (head != nullptr && new_head != nullptr) {
		for (int i = 0; i < head->children.size(); i++) {
			if (head->children[i] == this)
				head->children.erase(head->children.begin() + i);
		}
		new_head->children.emplace_back(this);
		head = new_head;
	}
}

Base* Base::get_head() {
	return head;
}

Base::~Base() {
	for (int i = 0; i < children.size(); i++) {
		delete children[i];
	}
}