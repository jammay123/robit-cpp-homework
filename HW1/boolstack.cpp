#include "boolstack.h"
#include <stdexcept>

BoolStack::BoolStack():topNode(nullptr), size(0) {} //topnode, size 0으로 초기화

BoolStack::~BoolStack() {
    while(!isEmpty()) {
        pop();
    }
}

void BoolStack::push(bool item){
    Node*newNode = new Node(item);
    newNode->next = topNode;
    topNode = newNode;
    size++;
}

bool BoolStack::pop(){
    if(isEmpty()) {
        throw std::out_of_range("Stack is empty, cannot pop.");
    }

    Node* tempNode = topNode;
    bool poppedData = topNode->data;
    topNode = topNode->next;
    delete tempNode;
    size--;

    return poppedData;
}

bool BoolStack::top() const {
    if(isEmpty()) {
        throw std::out_of_range("Stack is empty, cannot pop.");
    }
    bool topData = topNode->data;
    return topData;
}

bool BoolStack::isEmpty() const {
    if(size < 1)
        return 1;
    else
        return 0;
}

int BoolStack::getSize() const {
    return size;
}


