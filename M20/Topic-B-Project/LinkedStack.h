//
//  Stack.h
//  Topic B Project
//
//  Created by Dak Washbrook on 9/13/16.
//

#ifndef Stack_h
#define Stack_h

#pragma once

#include "Node.h"
#include "PrecondViolatedExcept.h"
#include <memory>
#include <string>

/**
 * Stack template class
 * LIFO - Last In First Out
 */
template<typename T>
class LinkedStack {
    
private:
    /**
     * Essentially the head pointer.
     * 
     * @var std::shared_ptr<Node<T>>
     */
    std::shared_ptr<Node<T>> topPtr;
    
public:
    /**
     * Stack default constructor.
     */
	LinkedStack() { }
    
    /**
     * Stack copy constructor
     *
     * @param   const Stack<T>&     stack
     */
	LinkedStack(const LinkedStack<T>& stack) {
        this->topPtr = nullptr;
        *this = stack;
    }
    
    /**
     * Assignment operator.
     *
     * @param   const Stack<T>&     stack
     */
	LinkedStack<T>& operator = (const LinkedStack<T>& stack)
    {
        std::shared_ptr<Node<T>> origChainPtr = stack.topPtr;
        if (origChainPtr == nullptr) {
            this->topPtr = nullptr;
        }
        else {
            this->topPtr = std::make_shared<Node<T>>();
            this->topPtr->setItem(origChainPtr->getItem());
            
            std::shared_ptr<Node<T>> newChainPtr = this->topPtr;
            
            origChainPtr = origChainPtr->getNext();
            
            while (origChainPtr != nullptr) {
                T nextItem = origChainPtr->getItem();
                
                std::shared_ptr<Node<T>> newNodePtr = std::make_shared<Node<T>>(nextItem);
                
                newChainPtr->setNext(newNodePtr);
                
                newChainPtr = newChainPtr->getNext();
                
                origChainPtr = origChainPtr->getNext();
            }
            newChainPtr->setNext(nullptr);
        }
        
        return *this;
    }
    
    /**
     * Stack destructor
     */
    ~LinkedStack() {
		this->topPtr.reset();
    }
    
    /**
     * Checks to see if the stack is empty.
     *
     * @return  bool
     */
    bool isEmpty() {
        return this->topPtr == nullptr;
    }
    
    /**
     * Pushes a new item to the top of the stack.
     *
     * @param   const T&    newEntry
     * @return  bool
     */
    bool push(const T& newEntry) {
        std::shared_ptr<Node<T>> newNodePtr = std::make_shared<Node<T>>(newEntry, this->topPtr);
        this->topPtr = newNodePtr;
        newNodePtr = nullptr;
        return true;
    }
    
    /**
     * Pop off/expend the top of the stack.
     *
     * @return  bool
     */
    bool pop() {
        bool result = false;
        if (!this->isEmpty()) {
            std::shared_ptr<Node<T>> nodeToDeletePtr = this->topPtr;
            this->topPtr = this->topPtr->getNext();
            
            nodeToDeletePtr->setNext(nullptr);
            nodeToDeletePtr.reset();
            
            result = true;
        }
        return result;
    }
    
    /**
     * Returns a copy of the item at the top of the stack.
     *
     * @return  T
     */
    T peek() {
        return this->topPtr->getItem();
    }
    
    /**
     * Displays the entire stack. This also expends the stack.
     */
    void displayStack() {
        try {
            while (this->topPtr != nullptr) {
                std::cout << " " << this->peek();
                this->pop();
            }
            std::cout << std::endl << std::endl;
        } catch (PrecondViolatedExcept& e) {
            std::cout << e.what() << std::endl;
        }
    }
    
};

/**
 * Overloading of the '<<' operator to allow stack to be used in <iostream>
 *
 * @return std::ostream&    stream
 */
template<typename T>
std::ostream& operator << (std::ostream& stream, LinkedStack<T>& stack)
{
    stack.displayStack();
    
    return stream;
}

#endif /* Stack_h */
