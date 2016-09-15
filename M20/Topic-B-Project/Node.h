//
//  Node.h
//  Topic B Project
//
//  Created by Dak Washbrook on 9/13/16.
//

#ifndef Node_h
#define Node_h

#include <memory>

/**
 * Node template class
 */
template<typename T>
class Node {
private :
    /**
     * Item held in the node.
     *
     * @var T   item
     */
    T item;
    
    /**
     * Pointer to the next node.
     *
     * @var std::shared_ptr<Node<T>>    next
     */
    std::shared_ptr<Node<T>> next;
    
public:
    /**
     * Node default constructor.
     */
    Node() { }
    
    /**
     * Node item constructor.
     *
     * @param   const T&    item
     */
    Node(const T& item) : item(item) { }
    
    /**
     * Node item and next pointer constructor.
     *
     * @param   const T&                    item
     * @param   std::shared_ptr<Node<T>>    nextNodePtr
     */
    Node(const T& item, std::shared_ptr<Node<T>> nextNodePtr) : item(item), next(nextNodePtr) { }
    
    /**
     * Set/overwrite the item in the node.
     *
     * @param   const T&    item
     */
    void setItem(const T& item) {
        this->item = item;
    }
    
    /**
     * Set the next node pointer.
     *
     * @param   std::shared_ptr<Node<T>>    nextNodePtr
     */
    void setNext(std::shared_ptr<Node<T>> nextNodePtr) {
        this->next = nextNodePtr;
    }
    
    /**
     * Get the item from the node.
     *
     * @return  T
     */
    T getItem() const {
        return this->item;
    }
    
    /**
     * Get the next node.
     *
     * @return  std::shared_ptr<Node<T>>
     */
    std::shared_ptr<Node<T>> getNext() const {
        return this->next;
    }
};

#endif /* Node_h */
