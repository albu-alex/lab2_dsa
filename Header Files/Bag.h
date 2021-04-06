#pragma once
//DO NOT INCLUDE BAGITERATOR


//DO NOT CHANGE THIS PART
#define NULL_TELEM -111111;
typedef int TElem;
class DoublyLinkedElement
{
    public:
    TElem element;
    int frequency=0;
    DoublyLinkedElement* next_element;
    DoublyLinkedElement* previous_element;
};
class DoublyLinkedList
{
    public:
        int size;
        DoublyLinkedElement* head;
        DoublyLinkedElement* tail;
        DoublyLinkedList();
        ~DoublyLinkedList();
        //void add_to_first_position(DoublyLinkedElement** head, TElem element);
        void add_to_first_position(TElem element);
        void insert_on_position(int position, TElem element);
        void add_to_last_position(TElem element);
        bool delete_element(TElem element);
};
class BagIterator; 
class Bag {
    //DO NOT CHANGE THIS PART
    friend class BagIterator;

private:
    DoublyLinkedList* elements;
public:
	//constructor
	Bag();

	//adds an element to the bag
	void add(TElem e);

	//removes one occurrence of an element from a bag
	//returns true if an element was removed, false otherwise (if e was not part of the bag)
	bool remove(TElem e);

	//checks if an element appearch is the bag
	bool search(TElem e) const;

	//returns the number of occurrences for an element in the bag
	int nrOccurrences(TElem e) const;

	//returns the number of elements from the bag
	int size() const;

	//returns an iterator for this bag
	BagIterator iterator();

	//checks if the bag is empty
	bool isEmpty() const;

	//destructor
	~Bag();
};