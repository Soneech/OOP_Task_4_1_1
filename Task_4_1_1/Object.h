#ifndef OBJECT_H
#define OBJECT_H
#include "Base.h"
#include <string>
using namespace std;

class Object : public Base {
public:
	Object(Base* head, string name);
};
#endif