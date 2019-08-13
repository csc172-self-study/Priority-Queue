/*
 * Object.cpp
 *
 *  Created on: Jul 15, 2019
 *      Author: alex
 */

#include "Object.h"

Object::Object(int ObjID, int prior) {
	ObjectID = ObjID;
	priority = prior;
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

int Object::getID() {
	return ObjectID;
}
