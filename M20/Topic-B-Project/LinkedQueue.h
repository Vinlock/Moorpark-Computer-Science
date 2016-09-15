//
//  Queue.h
//  Topic B Project
//
//  Created by Dak Washbrook on 9/13/16.
//

#ifndef Queue_h
#define Queue_h

#pragma once

#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include <exception>
#include <stdexcept>
#include "PrecondViolatedExcept.h"

/**
 * Queue template class
 * FIFO - First In First Out
 */
template<typename T>
class LinkedQueue {
private:
    /**
     * Essentially the head pointer.
     *
     * @var std::shared_ptr<Node<T>>    frontPtr
     */
    std::shared_ptr<Node<T>> frontPtr;
    
    /**
     * Essentially the tail pointer.
     *
     * @var std::shared_ptr<Node<T>>    backPtr
     */
    std::shared_ptr<Node<T>> backPtr;
    
public:
    /**
     * Queue constructor
     */
	LinkedQueue() { }
    
    /**
     * Queue copy constructor.
     *
     * @param   const Queue&    queue
     */
	LinkedQueue(const LinkedQueue& queue) {
        this->frontPtr = this->backPtr = nullptr;
        *this = queue;
    }
    
    /**
     * Queue assignment operator.
     *
     * @param   const Queue<T>& queue
     * @return  *Queue|this
     */
	LinkedQueue<T>& operator = (const LinkedQueue<T>& queue)
    {
        std::shared_ptr<Node<T>> originChainPtr = queue.frontPtr;
        if (originChainPtr == nullptr) {
            this->frontPtr = nullptr;
            this->backPtr = nullptr;
        }
        else {
            while (originChainPtr != nullptr) {
                T nextItem = originChainPtr->getItem();
                this->enqueue(nextItem);
                originChainPtr = originChainPtr->getNext();
            }
        }
        
        return *this;
    }
    
    /**
     * Queue destructor
     */
    ~LinkedQueue() {
		backPtr.reset();
		frontPtr.reset();
    }
    
    /**
     * Displays the entire queue. This also expends the queue.
     */
    void displayQueue() {
        try {
            while (this->frontPtr != nullptr) {
                std::cout << this->peekFront() << std::endl;
                this->dequeue();
            }
        } catch (PrecondViolatedExcept& e) {
            std::cout << e.what() << std::endl;
        }
    }
    
    /**
     * Checks if the queue is empty.
     *
     * @return  bool
     */
    bool isEmpty() const {
        return this->frontPtr == nullptr;
    }
    
    /**
     * Adds an item to the queue.
     *
     * @param   const T&    newEntry
     * @return  bool
     */
    bool enqueue(const T& newEntry) {
        auto newNodePtr = std::make_shared<Node<T>>(newEntry);
        
        if (this->isEmpty()) {
            this->frontPtr = newNodePtr;
        }
        else {
            this->backPtr->setNext(newNodePtr);
        }
        
        this->backPtr = newNodePtr;
        return true;
    }
    
    /**
     * Removes the item/node at the front of the queue.
     *
     * @return  bool
     */
    bool dequeue() {
        bool result = false;
        if (!this->isEmpty()) {
            auto nodeToDeletePtr = this->frontPtr;
            if (this->frontPtr == this->backPtr) {
                this->frontPtr.reset();
                this->backPtr.reset();
            }
            else {
                this->frontPtr = this->frontPtr->getNext();
            }
            
            nodeToDeletePtr->setNext(nullptr);
            
            result = true;
        }
        return result;
    }
    
    /**
     * Returns a copy of the item at the front of the queue.
     *
     * @return T
     */
    T peekFront() const throw(PrecondViolatedExcept) {
        if (!isEmpty()) {
            return this->frontPtr->getItem();
        }
        else {
            throw(PrecondViolatedExcept("peekFront() - The Queue is Empty."));
        }
    }
};

/**
 * Overloading of the '<<' operator to allow queue to be used in <iostream>
 *
 * @return std::ostream&    stream
 */
template<typename T>
std::ostream& operator << (std::ostream& stream, LinkedQueue<T>& queue)
{
    queue.displayQueue();
    
    return stream;
}

#endif /* Queue_h */
