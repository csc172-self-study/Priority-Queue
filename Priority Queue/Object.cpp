/*
 * Object.cpp
 *
 *  Created on: Jul 15, 2019
 *      Author: alex
 */

#include "Object.h"
#include <iostream>
#include <stddef.h>

Object::Object(int ObjID, int prior) {
	ObjectID = ObjID;
	priority = prior;
}

Object::Object() {
	ObjectID = NULL;
	priority = NULL;
}

Object::~Object() {}

bool Object::operator< (const Object obj) const {
	return priority < obj.priority;
}

bool Object::operator> (const Object obj) const {
	return priority > obj.priority;
}

bool Object::operator== (const Object obj) const {
	return ObjectID == obj.ObjectID;
}

int Object::getID() const {
	return ObjectID;
}

int Object::getPriority() const {
	return priority;
}

void Object::setPriority(int newPriority) {
	priority = newPriority;
}

std::ostream & operator<< (std::ostream &out, const Object obj) {
	out << "ID: " << obj.getID() << ". Priority: " << obj.getPriority();
	return out;
}
