#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
    this->current_element = bag.elements->head;
}


void BagIterator::first() {
    this->current_element = this->bag.elements->head;
}


void BagIterator::next() {
	if(!this->valid())
	    throw exception();
	else
	    this->current_element = this->current_element->next_element;
}


bool BagIterator::valid() const {
	if (this->current_element == nullptr)
	    return false;
	return true;
}


TElem BagIterator::getCurrent() const
{
	if(this->valid())
	    return this->current_element->element;
	else
	    throw exception();
}
