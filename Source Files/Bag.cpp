#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;

DoublyLinkedList::DoublyLinkedList(){
    this->head = nullptr;
    this->tail = nullptr;
}

void DoublyLinkedList::add_to_first_position(TElem element)
{
    DoublyLinkedElement* new_element = new DoublyLinkedElement();
    new_element->element = element;
    new_element->frequency = 0;
    //the first element doesn't have an element before it, so:
    new_element->previous_element = nullptr;
    new_element->next_element = this->head;
    if(this->head == nullptr)
    {
        this->head = new_element;
        this->tail = new_element;
        this->head->frequency=1;
        this->tail->frequency=1;
    }
    else
    {
        DoublyLinkedElement* current_element;
        current_element = this->head;
        while (current_element != nullptr && current_element->element != element)
            current_element = current_element->next_element;
        if(current_element != nullptr)
        {
            current_element->frequency++;
            return;
        }
        this->head->next_element = this->head;
        this->head = new_element;
        this->head->frequency = 1;
    }
}
//Complexity: Theta(1)

bool DoublyLinkedList::delete_element(TElem element)
{
    DoublyLinkedElement* current_element;
    current_element = this->head;
    while(current_element!= nullptr && current_element->element!=element)
        current_element = current_element->next_element;
    if(current_element != nullptr) {
        if (current_element->frequency > 1)
        {
            current_element->frequency--;
            return true;
        }
        if (current_element == this->head) {
            if (current_element == this->tail) {
                this->head = nullptr;
                this->tail = nullptr;
            } else {
                this->head = this->head->next_element;
                this->head->previous_element = nullptr;
            }
        }
        else
        {
            if (current_element == this->tail) {
                this->tail = this->tail->previous_element;
                this->tail->next_element = nullptr;
            }
            else{
                current_element->next_element->previous_element = current_element->previous_element;
                current_element->previous_element->next_element = current_element->next_element;
            }
        }
        return true;
    }
    return false;
}
//Complexity: O(n)

void DoublyLinkedList::insert_on_position(int position, TElem element)
{
    if(position < 0)
        return;
    else if (position==0)
    {
        add_to_first_position(element);
        return;
    }
    else{
        int index;
        DoublyLinkedElement* current_element;
        current_element = this->head;
        index = 0;
        while (current_element != nullptr && index < position - 1)
        {
            current_element = current_element->next_element;
            index++;
        }
        if(current_element == nullptr)
            return;
        else if (current_element == this->tail) add_to_last_position(element);
        else
        {
            DoublyLinkedElement* new_element = new DoublyLinkedElement();
            new_element->element = element;
            new_element->previous_element = current_element;
            new_element->next_element = current_element->next_element;
            current_element->next_element->previous_element = new_element;
            current_element->next_element = new_element;
        }
    }
}

void DoublyLinkedList::add_to_last_position(TElem element)
{
    DoublyLinkedElement *current_element;
    current_element = this->head;
    while (current_element != nullptr && current_element->element != element)
        current_element = current_element->next_element;
    if (current_element != nullptr) {
        current_element->frequency++;
        return;
    }
    DoublyLinkedElement* new_element = new DoublyLinkedElement();
    new_element->previous_element = this->tail;
    new_element->element = element;
    new_element->frequency= 1;
    new_element->next_element = nullptr;
    if (this->head == nullptr) {
        this->head = new_element;
        this->tail = new_element;
    } else {
        this->tail->next_element = new_element;
        this->tail = new_element;
    }
}
//Complexity: O(n)

DoublyLinkedList::~DoublyLinkedList(){;}

Bag::Bag() {
	this->elements = new DoublyLinkedList();
	this->current_element = this->elements->head;
}

void Bag::add(TElem elem) {
	this->elements->add_to_last_position(elem);
}


bool Bag::remove(TElem elem) {
	return this->elements->delete_element(elem);
}


bool Bag::search(TElem elem) {
	while(this->current_element != nullptr && this->current_element->element !=elem)
        this->current_element = this->current_element->next_element;
	if(this->current_element == nullptr)
	    return false;
	return true;
}
//Complexity: O(n)

int Bag::nrOccurrences(TElem elem){
    while (this->current_element != nullptr && this->current_element->element != elem)
        this->current_element = this->current_element->next_element;
	if(this->current_element == nullptr)
	    return 0;
    return this->current_element->frequency;
}
//Complexity: O(n)


int Bag::size() const {
	int size = 0,frequency;
	DoublyLinkedElement* current_element;
	current_element = this->elements->head;
	while(current_element != nullptr) {
        frequency = current_element->frequency;
	    size+=frequency;
        current_element = current_element->next_element;
    }
	return size;
}
//Complexity: Theta(n)


bool Bag::isEmpty() const {
	if(this->elements->head == nullptr && this->elements->tail == nullptr)
        return true;
	return false;
}
//Complexity: O(1)

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}
//Complexity: O(1)


Bag::~Bag() {
	delete this->elements;
}
//Complexity: O(1)
