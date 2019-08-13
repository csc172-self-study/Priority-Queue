/*
 * Object.h
 *
 *  Created on: Jul 15, 2019
 *      Author: alex
 */

#ifndef OBJECT_H_
#define OBJECT_H_

class Object {
private:
	int priority;
	int ObjectID;
public:
	Object(int, int);

	virtual ~Object();

	bool operator< (const Object) const;
	bool operator> (const Object) const;
	bool operator== (const Object) const;

	int getID();
};

#endif /* OBJECT_H_ */
