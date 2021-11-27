// File name:
// Author:
// userid:
// Email:
// Class: CS2201 @ Vanderbilt U.
// Assignment Number:
// Description:
// Honor statement:
// Last Changed:

#include "DblQueue.h"


#include <string>
#include <fstream>
#include <iostream>


// Class Constructor

DblQueue::DblQueue() : head(nullptr), length(0), tail(nullptr) {
}

// Copy Constructor
// pre:  Class object, aQueue, exists
// post: Object is initialized to be a copy of the parameter
DblQueue::DblQueue(const DblQueue &aQueue) : head(nullptr), length(aQueue.length), tail(nullptr) {

    if (aQueue.head != nullptr) {
        //first node
        head = new Node;
        head->val = aQueue.head->val;
        head->next = nullptr;

        //rest of dna
        node x = head;
        for (node n = aQueue.head->next;
             n != nullptr; n = n->next) {
            x->next = new Node;
            x = x->next;
            x->val = n->val;
            x->next = tail;
        }

    }
}

// Class Destructor
// Destroys a queue
// pre:  Class object exists
// post: Class object does not exist

DblQueue::~DblQueue() {
    while (head != nullptr) {
        dequeue();
    }
}


// Assignment operator
// Assigns a queue to another
// pre: both class objects exist
// post: this class object gets assigned a copy of the parameter class object
const DblQueue &DblQueue::operator=(const DblQueue &rhs) {
    if (this != &rhs) {
        DblQueue tmp(rhs);
        std::swap(head, tmp.head);
        std::swap(tail, tmp.tail);
    }
    return *this;
}

// isEmpty
// Checks if the queue is empty
// pre:  A queue exists.
// post: Returns true if it IS empty, false if NOT empty.
bool DblQueue::isEmpty() const {
    return length == 0;
}

// enqueue
// enqueues an item to back of the queue.
// pre:  DblQueue exists and item is passed.
// post: adds the given item to the end of the queue.
void DblQueue::enqueue(const Itemtype &item) {
    Node *n = new Node;
    n->val = item;
    if (isEmpty()) {
        tail = n;
        tail->next = nullptr;
        head = tail;
        head->next = nullptr;

    } else {
        tail->next = n;
        tail = n;
        tail->next = nullptr;
    }
    length++;
}

// dequeue
// dequeues the front item off the queue
// pre:  DblQueue exists.
// post: Removes item on front of the queue. If the queue
//       was already empty, throws an std::underflow_error exception.
void DblQueue::dequeue() {
    if (length != 0) {
        if (length == 1) {
            node x = head;
            head = nullptr;
            delete x;
            length--;
            tail = nullptr;
        } else {
            node y = head;
            node x = head;
            y = y->next;
            x->next = nullptr;
            head = y;
            length--;
        }
    } else {
        throw std::underflow_error("The queue is empty");
    }
}

// front
// Returns the front item of the queue without dequeueing it.
// pre:  DblQueue exists.
// post: Returns item at front of queue.  If the queue is empty,
//       throws an std::underflow_error exception.

Itemtype DblQueue::front() const {
    if (isEmpty()) {
        throw std::underflow_error("The queue is empty");
    }
    return head->val;
}

// size
// Returns the number of items on the queue.
size_t DblQueue::size() const {
    return this->length;
};

