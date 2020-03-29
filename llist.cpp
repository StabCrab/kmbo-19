#include <cstdlib>
#include "llist.h"

LList::LList()
{
    _size = 0;
    head = nullptr;
}


LList::Node::Node()
{
    this->next = next;
    this->value = value;
}
LList::Node::~Node()
{
    this->setNext(nullptr);
    delete this->next;
}

LList::Node *LList::Node::getNext() {
    return this->next;
}

void LList::Node::setValue(int new_value)
{
    this->value = new_value;
}

void LList::Node::setNext(LList::Node *node)
{
    this->next = node;
}

int LList::Node::getValue() {
    return this->value;
}

void LList::push_back(int value)
{
    Node *temp = new Node;
    temp->setValue(value);
    temp->setNext(nullptr);
    this->_size++;
    if (this->_size == 1)
    {
        first_node = temp;
        head = temp;
        first_node->setNext(nullptr);
    }
    else
    {
        head->setNext(temp);
        head = temp;
    }
}
void LList::push_front(int value)
{
    Node *temp = new Node;
    temp->setValue(value);
    this->_size++;
    if (this->_size == 1)
    {
        first_node = temp;
        head = temp;
        first_node->setNext(nullptr);
    }
    else
    {
        temp->setNext(first_node);
        first_node = temp;
    }
}

void LList::pop_front()
{
    if (this->size() > 0)
    {
        Node* newFirst = first_node->getNext();
        delete first_node;
        first_node = newFirst;
        this->_size--;
    }
}
void LList::pop_back()
{
    Node* newHead = head->getNext();
    delete head;
    head = newHead;
    this->_size--;
}
void LList::reverse()
{
    Node *nextNode = new Node;
    Node *currentNode = new Node;
    Node *previousNode= new Node;
    previousNode = first_node;
    currentNode = first_node->getNext();
    nextNode = currentNode->getNext();
    first_node->setNext(nullptr);
    currentNode->setNext(previousNode);
    head = first_node;
    while (nextNode->getNext() != nullptr)
    {
        previousNode = currentNode;
        currentNode = nextNode;
        nextNode = nextNode->getNext();
        currentNode->setNext(previousNode);
    }
    previousNode = currentNode;
    currentNode = nextNode;
    nextNode = nextNode->getNext();
    currentNode->setNext(previousNode);
    first_node = currentNode;
}

LList::~LList()
{
    for (int i = 0; i < this->size(); i++)
    {
        this->pop_front();
    }
}
LList::Node LList::getHead() const {
    return *head;
}

int LList::operator[](size_t idx) const {
    Node* node = this->first_node;
    for(int i = 0; i < idx; i++)
    {
        node = node->getNext();
    }
    return node->getValue();
}

size_t LList::size() const {
    return _size;
}

void LList::insert_at(size_t idx, int val)
{
    if (this->_size == 0 || idx == 0)
    {
        push_front(val);
        exit;
    }
    if(idx == this->_size - 1)
    {
        push_back(val);
        exit;
    }
    Node* currentNode = first_node;
    Node* newNode = new Node;
    Node* newNodeNext = new Node;
    newNode->setValue(val);
    for (int i = 0; i < idx - 1; i++)
    {
        currentNode = currentNode->getNext();
    }
    newNodeNext = currentNode->getNext();
    currentNode->setNext(newNode);
    newNode->setNext(newNodeNext);
    this->_size++;
}
void LList::erase_at(size_t idx)
{
    Node* currentNode = first_node;
    for (int i = 0; i < idx - 1; i++)
    {
        currentNode = currentNode->getNext();
    }
    Node* erasedNode = currentNode->getNext();
    currentNode->setNext(erasedNode->getNext());
    delete erasedNode;
    this->_size--;

}

LList::Node LList::operator[](size_t idx)
{
    Node* node = this->first_node;
    for(int i = 0; i < idx; i++)
    {
        node = node->getNext();
    }
    return *node;
}

