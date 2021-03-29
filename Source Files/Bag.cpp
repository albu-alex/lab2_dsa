#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;
void DoublyLinkedList::add_to_first_position(DoublyLinkedElement **head, TElem element)
{
    DoublyLinkedElement* new_element = new DoublyLinkedElement();
    new_element->element = element;
    //the first element doesn't have an element before it, so:
    new_element->previous_element = nullptr;
    new_element->next_element = (*head);
    if((*head) != nullptr)
        (*head)->previous_element = new_element;
    (*head) = new_element;
}

void DoublyLinkedList::insert_after_position(DoublyLinkedElement *previous, TElem element)
{
    if (previous == nullptr) return;
    DoublyLinkedElement* new_element = new DoublyLinkedElement();
    new_element->element = element;
    new_element->next_element = previous->next_element;
    previous->next_element = new_element;
    new_element->previous_element = previous;
    if(new_element->next_element != nullptr)
        new_element->next_element->previous_element = new_element;
}

void DoublyLinkedList::add_to_last_position(DoublyLinkedElement **head, TElem element)
{
    DoublyLinkedElement* new_element = new DoublyLinkedElement();
    DoublyLinkedElement* previous = *head;
    new_element->element = element;
    new_element->next_element = nullptr;
    if(*head == nullptr)
    {
        new_element->previous_element = nullptr;
        *head = new_element;
    }
}

DoublyLinkedList::DoublyLinkedList() = default;

DoublyLinkedList::~DoublyLinkedList(){;}

Bag::Bag() {
	this->elements = new DoublyLinkedList;
}

void Bag::add(TElem elem) {
	//TODO - Implementation
}


bool Bag::remove(TElem elem) {
	//TODO - Implementation
	return false; 
}


bool Bag::search(TElem elem) const {
	//TODO - Implementation
	return false; 
}

int Bag::nrOccurrences(TElem elem) const {
	//TODO - Implementation
	return 0; 
}


int Bag::size() const {
	//TODO - Implementation
	return 0;
}


bool Bag::isEmpty() const {
	//TODO - Implementation
	return 0;
}

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}


Bag::~Bag() {
	delete this->elements;
}

