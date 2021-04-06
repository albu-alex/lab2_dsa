#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(Bag& c): bag(c)
{
    this->current_element = bag.elements->head;
    this->current_frequency = 1;
}
//Complexity : Theta(1)


void BagIterator::first() {
    this->current_element = this->bag.elements->head;
    this->current_frequency = 1;
}
//Complexity : Theta(1)


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
//Complexity : Theta(1)


bool BagIterator::valid() const {
	if (this->current_element == nullptr)
	    return false;
	return true;
}
//Complexity : Theta(1)


TElem BagIterator::getCurrent() const
{
	if(this->valid())
	    return this->current_element->element;
	else
	    throw exception();
}
//Complexity : Theta(1)


TElem BagIterator::remove()
{
    if(!this->valid())
        throw exception();
    if(this->current_element->frequency > 1)
    {
        this->current_element->frequency--;
        this->bag.elements->size--;
        return this->current_element->element;
    }
    else if(this->current_element->frequency == 1){
        TElem element_to_be_returned = this->current_element->element;
        this->bag.elements->delete_element(this->current_element->element);
        this->current_element = this->current_element->next_element;
        return element_to_be_returned;
    }
    else{
        TElem element_to_be_returned = this->current_element->element;
        this->current_element = nullptr;
        bag.elements->tail = bag.elements->tail->previous_element;
        this->bag.elements->size--;
        return element_to_be_returned;
    }
}
//Complexity : O(n)