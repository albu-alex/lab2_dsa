#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;

DoublyLinkedList::DoublyLinkedList(){
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}
//Complexity: Theta(1)

void DoublyLinkedList::add_to_first_position(TElem element)
{
    DoublyLinkedElement* new_element = new DoublyLinkedElement();
    new_element->element = element;
    new_element->frequency = 1;
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
        DoublyLinkedElement* current_element_head;
        DoublyLinkedElement* current_element_tail;
        current_element_head = this->head;
        current_element_tail = this->tail;
        while (current_element_head != nullptr && current_element_head->element != element && current_element_tail->element!= element && current_element_tail!=nullptr) {
            current_element_head = current_element_head->next_element;
            current_element_tail = current_element_tail->previous_element;
        }
        if(current_element_head != nullptr && current_element_head->element == element)
        {
            current_element_head->frequency++;
            return;
        }
        if(current_element_tail != nullptr && current_element_tail->element == element)
        {
            current_element_tail->frequency++;
            return;
        }
        this->head->next_element = this->head;
        this->head = new_element;
    }
}
//Function not used; Complexity: O(n)

bool DoublyLinkedList::delete_element(TElem element)
{
    DoublyLinkedElement* current_element_head;
    DoublyLinkedElement* current_element_tail;
    current_element_head = this->head;
    current_element_tail = this->tail;
    while (current_element_head != nullptr && current_element_tail != nullptr && current_element_head->element != element && current_element_tail->element!= element) {
        current_element_head = current_element_head->next_element;
        current_element_tail = current_element_tail->previous_element;
    }
    if(current_element_head != nullptr && current_element_head->element == element) {
        if (current_element_head->frequency > 1)
        {
            current_element_head->frequency--;
            this->size--;
            return true;
        }
        if (current_element_head == this->head) {
            if (current_element_head == this->tail) {
                this->head = nullptr;
                this->tail = nullptr;
            } else {
                this->head = this->head->next_element;
                this->head->previous_element = nullptr;
            }
        }
        else{
            current_element_head->next_element->previous_element = current_element_head->previous_element;
            current_element_head->previous_element->next_element = current_element_head->next_element;
        }
        this->size--;
        return true;
    }
    if(current_element_tail != nullptr && current_element_tail->element == element){
        if (current_element_tail->frequency > 1)
        {
            current_element_tail->frequency--;
            this->size--;
            return true;
        }
        if (current_element_tail == this->tail) {
            if (current_element_tail == this->head) {
                this->head = nullptr;
                this->tail = nullptr;
            } else {
                this->tail = this->tail->previous_element;
                this->tail->next_element = nullptr;
            }
        }
        else{
            current_element_tail->next_element->previous_element = current_element_tail->previous_element;
            current_element_tail->previous_element->next_element = current_element_tail->next_element;
        }
        this->size--;
        return true;
    }
    return false;
}
//Complexity: O(n); Best case : Theta(1) when element to be removed is the head or the tail ; Worst case: Theta(n)

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
        while (current_element != nullptr && index < position - 1 && current_element->element != element)
        {
            current_element = current_element->next_element;
            index++;
        }
        if(current_element == nullptr)
            return;
        if(current_element->element == element) {
            current_element->frequency++;
            return;
        }
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
//Function not used; Complexity: O(n) , Best case: Theta(n), Worst case: Theta(n)

void DoublyLinkedList::add_to_last_position(TElem element)
{
    DoublyLinkedElement* current_element_head;
    DoublyLinkedElement* current_element_tail;
    current_element_head = this->head;
    current_element_tail = this->tail;
    while (current_element_head != nullptr && current_element_tail != nullptr && current_element_head->element != element && current_element_tail->element!= element) {
        current_element_head = current_element_head->next_element;
        current_element_tail = current_element_tail->previous_element;
    }
    if(current_element_head != nullptr && current_element_head->element == element)
    {
        current_element_head->frequency++;
        this->size++;
        return;
    }
    if(current_element_tail != nullptr && current_element_tail->element == element)
    {
        current_element_tail->frequency++;
        this->size++;
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
    this->size++;
}
//Complexity: O(n); Best case: Theta(1), when element to be added is already in the list and it is the head or the tail; Worst case: Theta(n)

DoublyLinkedList::~DoublyLinkedList(){;}

Bag::Bag() {
	this->elements = new DoublyLinkedList();
}
//Complexity: Theta(1)

void Bag::add(TElem elem) {
	this->elements->add_to_last_position(elem);
}
//Complexity: O(n); Best case: Theta(1), when element to be added is already in the list and it is the head or the tail; Worst case: Theta(n)


bool Bag::remove(TElem elem) {
    return this->elements->delete_element(elem);
}
//Complexity: O(n); Best case : Theta(1) when element to be removed is the head or the tail ; Worst case: Theta(n)


bool Bag::search(TElem elem)const {
    DoublyLinkedElement* current_element_head;
    DoublyLinkedElement* current_element_tail;
    current_element_head = this->elements->head;
    current_element_tail = this->elements->tail;
    while (current_element_head != nullptr && current_element_tail != nullptr && current_element_head->element != elem && current_element_tail->element!= elem) {
        current_element_head = current_element_head->next_element;
        current_element_tail = current_element_tail->previous_element;
    }
    if(current_element_tail == nullptr && current_element_head == nullptr)
	    return false;
	return true;
}
//Complexity: O(n) ; Best case: Theta(1), when searched element is already in the list and it is the head or the tail; Worst case: Theta(n)


int Bag::nrOccurrences(TElem elem)const{
    DoublyLinkedElement* current_element_head;
    DoublyLinkedElement* current_element_tail;
    current_element_head = this->elements->head;
    current_element_tail = this->elements->tail;
    while (current_element_head != nullptr && current_element_tail != nullptr && current_element_head->element != elem && current_element_tail->element!= elem) {
        current_element_head = current_element_head->next_element;
        current_element_tail = current_element_tail->previous_element;
    }
    if(current_element_head == nullptr || current_element_tail == nullptr)
        return 0;
    if(current_element_tail->element == elem) return current_element_tail->frequency;
    if(current_element_head->element == elem) return current_element_head->frequency;
}
//Complexity: O(n) ; Best case: Theta(1),  when searched element is already in the list and it is the head or the tail; Worst case: Theta(n)


int Bag::size() const {
    return this->elements->size;
}
//Complexity: Theta(1)


bool Bag::isEmpty() const {
	if(this->elements->head == nullptr && this->elements->tail == nullptr)
        return true;
	return false;
}
//Complexity: Theta(1)


BagIterator Bag::iterator() const {
	return BagIterator(*this);
}
//Complexity: Theta(1)


Bag::~Bag() {
	delete this->elements;
}
//Complexity: Theta(1)
