#ifndef LLIST_H
#define LLIST_H

#include <cstddef>

// Linked list of integers

class LList
{
    // HERE WILL BE YOUR CODE
private:

    class Node
    {
    public:
        Node();
        ~Node();
        void setValue(int new_value);
        int getValue();
        Node* getNext();
        void setNext(Node *node);
    private:
        int value;
        Node* next;
    };
    size_t _size;
    Node* head;
    Node* current;
    Node* first_node;
public:
    Node getHead() const;
    LList();                         // construct new collection
    ~LList();                        // free resources
    void push_back(int val);         // add new value at the end:  [1 2 3 4] -> [1 2 3 4 5]
    void push_front(int val);        // add new value at the begin [1 2 3 4] -> [5 1 2 3 4]
    void pop_back();          // remove at the end          [1 2 3 4] -> [1 2 3]
    void pop_front();         // remove at the front        [1 2 3 4] -> [2 3 4]
    size_t size() const;             // get actual number of items [1 2 3 4] -> 4
    Node operator[](size_t idx);     // get rw access ot specific item addressing by idx
    int  operator[](size_t idx) const; //get read-only access
    void erase_at(size_t idx);       // remove item at specific position: [1 2 3 4], 2 -> [1 2 4]
    void insert_at(size_t idx, int val); // insert item at specific position: [1 2 3 4], 1, 5 -> [1 5 2 3 4]
    void reverse();                  // reverse item sequense: [1 2 3 4] -> [4 3 2 1]
};

#endif //LLIST_H
