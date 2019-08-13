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
	Object(int ID, int priority); // Create object with ID and priority
	Object(); // Create empty object

	virtual ~Object();

	bool operator< (const Object) const; // Overload < to compare on priority
	bool operator> (const Object) const; // Overload > to compare on priority
	bool operator== (const Object) const; // Overload == to compare on ID

	int getID() const; // Get object ID
	int getPriority() const; // Get object priority
	void setPriority(int newPriority); // Set object priority
};

// Overload stream insertion for object. Prints formatted ID and priority.
std::ostream & operator<< (std::ostream &out, const Object obj);

#endif /* OBJECT_H_ */
