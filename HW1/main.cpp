#include <iostream>
#include "boolstack.h"
#include "boolqueue.h"

using namespace std;

int main() {
    BoolStack testStack;
    BoolQueue testQueue;
    int choice1, choice2, input;

    while (true) {
        cout << "1. 스택 테스트\n";
        cout << "2. 큐 테스트\n";
        cout << "0. 프로그램 종료\n";  // 종료 옵션 추가
        cout << "테스트할 번호를 선택해주세요: ";
        cin >> choice2;

        if (choice2 == 0) {
            cout << "프로그램을 종료합니다.\n";
            break;  // 프로그램 종료
        }

        if (choice2 == 1) {
            cout << "\n1. push\n";
            cout << "2. pop\n";
            cout << "3. top 출력\n";
            cout << "4. 스택이 비었는지 확인\n";
            cout << "5. 스택 크기 확인\n";
            cout << "원하는 기능을 번호로 선택해주세요: ";
            cin >> choice1;

            switch (choice1) {
            case 1:
                cout << "push할 숫자를 입력하세요 (0=false, 그 외=true): ";
                cin >> input;
                testStack.push(input != 0);
                break;

            case 2:
                if (testStack.isEmpty())
                    cout << "스택이 비어 있습니다.\n";
                else
                    cout << "pop된 값: " << testStack.pop() << endl;
                break;

            case 3:
                if (testStack.isEmpty())
                    cout << "스택이 비어 있습니다.\n";
                else
                    cout << "최상단 값: " << testStack.top() << endl;
                break;

            case 4:
                cout << (testStack.isEmpty() ? "스택이 비어 있습니다.\n" : "스택에 값이 있습니다.\n");
                break;

            case 5:
                cout << "스택 크기: " << testStack.getSize() << endl;
                break;

            default:
                cout << "유효하지 않은 선택입니다.\n";
            }
        } else if (choice2 == 2) {
            cout << "\n1. enqueue\n";
            cout << "2. dequeue\n";
            cout << "3. front 출력\n";
            cout << "4. 큐가 비었는지 확인\n";
            cout << "5. 큐 크기 확인\n";
            cout << "원하는 기능을 번호로 선택해주세요: ";
            cin >> choice1;

            switch (choice1) {
            case 1:
                cout << "enqueue할 숫자를 입력하세요 (0=false, 그 외=true): ";
                cin >> input;
                testQueue.enqueue(input != 0);
                break;

            case 2:
                if (testQueue.isEmpty())
                    cout << "큐가 비어 있습니다.\n";
                else
                    cout << "dequeue된 값: " << testQueue.dequeue() << endl;
                break;

            case 3:
                if (testQueue.isEmpty())
                    cout << "큐가 비어 있습니다.\n";
                else
                    cout << "가장 앞의 값: " << testQueue.front() << endl;
                break;

            case 4:
                cout << (testQueue.isEmpty() ? "큐가 비어 있습니다.\n" : "큐에 값이 있습니다.\n");
                break;

            case 5:
                cout << "큐 크기: " << testQueue.getSize() << endl;
                break;

            default:
                cout << "유효하지 않은 선택입니다.\n";
            }
        } else {
            cout << "유효하지 않은 테스트 유형입니다.\n";
        }
    }

    return 0;
}
