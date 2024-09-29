#ifndef BOOLSTACK_H
#define BOOLSTACK_H


class BoolStack
{
private:
    struct Node {
        bool data;
        Node*next;
        Node(bool item):data(item),next(nullptr) {}
    };

    Node* topNode;
    int size;

public:
    BoolStack();
    ~BoolStack();

    void push(bool item);   //항목 삽입
    bool pop();             //항목 제거 및 반환
    bool top() const;       //최상단 항목 반환
    bool isEmpty() const;   //스택이 비었는지
    int getSize() const;    //스택 크기 반환
};

#endif // BOOLSTACK_H
