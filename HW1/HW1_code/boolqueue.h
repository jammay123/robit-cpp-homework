#ifndef BOOLQUEUE_H
#define BOOLQUEUE_H


class BoolQueue
{
private:
    struct Node {
        bool data;
        Node* next;
        Node(bool item) : data(item), next(nullptr) {}
    };
    Node* frontNode;
    Node* rearNode;
    int size;

public:
    BoolQueue();
    ~BoolQueue();

    void enqueue(bool item);    //항목 삽입
    bool dequeue();             //항목 제거 및 반환
    bool front() const;         //가장 앞 항목 반환
    bool isEmpty() const;       //큐가 비었는지
    int getSize() const;        //큐의 크기 반환
};

#endif // BOOLQUEUE_H
