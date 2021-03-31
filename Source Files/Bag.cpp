#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;

DoublyLinkedList::DoublyLinkedList(){
    this->head = nullptr;
    this->tail = nullptr;
}

//void DoublyLinkedList::add_to_first_position(DoublyLinkedElement **head, TElem element)
//{
//    DoublyLinkedElement* new_element = new DoublyLinkedElement();
//    new_element->element = element;
//    //the first element doesn't have an element before it, so:
//    new_element->previous_element = nullptr;
//    new_element->next_element = (*head);
//    if((*head) != nullptr)
//        (*head)->previous_element = new_element;
//    (*head) = new_element;
//}

bool DoublyLinkedList::delete_element(TElem element)
{
    DoublyLinkedElement* current_element;
    current_element = this->head;
    while(current_element!= nullptr && current_element->element!=element)
        current_element = current_element->next_element;
    //DoublyLinkedElement* deleted_element = current_element;
    if(current_element != nullptr) {
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

void DoublyLinkedList::insert_on_position(int position, TElem element)
{
    if(position < 0)
        return;
    else if (position==0)
    {
        //not_yet_implemented
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
    DoublyLinkedElement* new_element = new DoublyLinkedElement();
    new_element->previous_element = this->tail;
    new_element->element = element;
    new_element->next_element = nullptr;
    if(this->head == nullptr)
    {
        this->head = new_element;
        this->tail = new_element;
    }
    else
    {
        this->tail->next_element = new_element;
        this->tail = new_element;
    }
}

DoublyLinkedList::~DoublyLinkedList(){;}

Bag::Bag() {
	this->elements = new DoublyLinkedList();
}

void Bag::add(TElem elem) {
	this->elements->add_to_last_position(elem);
}


bool Bag::remove(TElem elem) {
	return this->elements->delete_element(elem);
}


bool Bag::search(TElem elem) const {
	DoublyLinkedElement* current_element;
	current_element = this->elements->head;
	while(current_element != nullptr && current_element->element !=elem)
	    current_element = current_element->next_element;
	if(current_element == nullptr)
	    return false;
	return true;
}
//Complexity: O(n)

int Bag::nrOccurrences(TElem elem) const {
	//TODO - Implementation
	return 0; 
}


int Bag::size() const {
	int size = 0;
	DoublyLinkedElement* current_element;
	current_element = this->elements->head;
	while(current_element != nullptr) {
        size++;
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

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}


Bag::~Bag() {
	delete this->elements;
}

