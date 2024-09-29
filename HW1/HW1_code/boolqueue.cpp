#include "boolqueue.h"
#include <stdexcept>

BoolQueue::BoolQueue():frontNode(nullptr), rearNode(nullptr), size(0) {}

BoolQueue::~BoolQueue() {
    while(!isEmpty()) {
        dequeue();
    }
}

void BoolQueue::enqueue(bool item){
    Node*newNode = new Node(item);
    if(rearNode == nullptr)
    {
        frontNode = newNode;
        rearNode = newNode;
    }
    else
    {
        rearNode->next = newNode;
        rearNode = newNode;
    }
    size++;
}

bool BoolQueue::dequeue(){
    if(isEmpty()) {
        throw std::out_of_range("Queue is empty, cannot dequeue.");
    }

    Node*tempNode = frontNode;
    bool poppedData = frontNode->data;
    frontNode = frontNode->next;
    delete tempNode;
    size--;

    if(frontNode == nullptr)        //하나ㅏ만 있었을 때 dequeue를 하면 isEmpty가 됌 그래서 머리와 꼬리 모두 nullptr 해줌.
    {
        frontNode = nullptr;
        rearNode = nullptr;
    }
    return poppedData;
}

bool BoolQueue::front() const{
    if(isEmpty()) {
        throw std::out_of_range("Queue is empty, cannot front.");
    }
    bool frontData = frontNode->data;
    return frontData;
}

bool BoolQueue::isEmpty() const{
    if(size < 1)
            return 1;
        else
            return 0;
}

int BoolQueue::getSize() const{
    return size;
}
