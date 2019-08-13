/*
 * Object.h
 *
 *  Created on: Jul 15, 2019
 *      Author: alex
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include <iostream>

class Object {
private:
	int priority;
	int ObjectID;
public:
	Object(int ID, int priority);
	Object();

	virtual ~Object();

	bool operator< (const Object) const;
	bool operator> (const Object) const;
	bool operator== (const Object) const;

	int getID() const;
	int getPriority() const;
	void setPriority(int newPriority);
};

std::ostream & operator<< (std::ostream &out, const Object obj);

#endif /* OBJECT_H_ */
