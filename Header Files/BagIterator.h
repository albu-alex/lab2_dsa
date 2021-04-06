#include "Bag.h"

class BagIterator
{
	//DO NOT CHANGE THIS PART
	friend class Bag;
	
private:
	const Bag& bag;
	DoublyLinkedElement* current_element;
	int current_frequency;
	//TODO  - Representation

	BagIterator(Bag& c);
public:
	void first();
	void next();
	TElem getCurrent() const;
	bool valid() const;
    TElem remove();
};
