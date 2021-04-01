#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
    this->current_element = bag.elements->head;
    this->current_frequency = 1;
}


void BagIterator::first() {
    this->current_element = this->bag.elements->head;
    this->current_frequency = 1;
}


void BagIterator::next() {
	if(!this->valid())
	    throw exception();
	if(this->current_frequency < this->current_element->frequency)
	    this->current_frequency++;
	else
    {
	    this->current_frequency=1;
	    this->current_element = this->current_element->next_element;
    }
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
