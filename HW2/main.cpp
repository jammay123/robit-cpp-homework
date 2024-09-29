#include <iostream>
#include <vector>
#include <stack>
#include <cctype>       // isdigit 함수 사용
#include <sstream>      // istringstream 사용
#include <cmath>

using namespace std;

struct CharIntConstruct
{
    int type;     // 0==number, 1==operator
    int number;
    char symbol;
};

int compare_op(char oper)
{
    if (oper == '+' || oper == '-')
        return 1;
    else if (oper == '*' || oper == '/' || oper == '%')
        return 2;
    else if (oper == '^')
        return 3;
    else                // 예외 처리
        return -1;
}

vector<CharIntConstruct> make_postfix(istream& ins)  // 값을 받아와서 후위 표기법으로 바꾸는 함수
{
    vector<CharIntConstruct> result_postfix;
    stack<char> oper_stack;
    int Lparen = 0, Rparen = 0;
    string num_buffer = "";
    char ch_temp1;  // 문자열로 받기 때문에 문자 하나하나 비교를 위한 변수

    while (ins >> ch_temp1)  // 입력 스트림에서 한 글자씩 받음
    {
        // 처음에 -가 있는 경우(음수 처리)
        if (num_buffer.empty() && ch_temp1 == '-' && result_postfix.empty())
        {
            num_buffer += '-';
            continue;
        }

        // 숫자인 경우
        if (isdigit(ch_temp1))
        {
            num_buffer += ch_temp1;
        }
        else
        {
            // number_buffer에 숫자가 있으면 처리
            if (!num_buffer.empty())
            {
                CharIntConstruct temp;
                temp.type = 0;
                temp.number = stoi(num_buffer);  // 숫자로 변환
                result_postfix.push_back(temp);
                num_buffer = "";  // 버퍼 초기화
            }

            // '(' 처리
            if (ch_temp1 == '(')
            {
                Lparen++;
                oper_stack.push('(');

                // 괄호 안에서 음수/양수 처리
                if (ins.peek() == '-')
                {
                    ins.get(ch_temp1);
                    num_buffer += '-';
                }
                else if (ins.peek() == '+')
                {
                    ins.get(ch_temp1);  // '+'는 그냥 넘김
                }
            }
            // ')' 처리
            else if (ch_temp1 == ')')
            {
                Rparen++;
                while (!oper_stack.empty() && oper_stack.top() != '(')
                {
                    CharIntConstruct temp;
                    temp.type = 1;
                    temp.symbol = oper_stack.top();
                    result_postfix.push_back(temp);
                    oper_stack.pop();
                }
                if (!oper_stack.empty() && oper_stack.top() == '(')
                {
                    oper_stack.pop();  // '(' 제거
                }
            }

            else if (ch_temp1 == '+' || ch_temp1 == '-' || ch_temp1 == '*' || ch_temp1 == '/' || ch_temp1 == '%' || ch_temp1== '^')
            {
                // 스택의 연산자와 우선순위 비교 후 pop
                while (!oper_stack.empty() && compare_op(oper_stack.top()) >= compare_op(ch_temp1))
                {
                    CharIntConstruct temp;
                    temp.type = 1;
                    temp.symbol = oper_stack.top();
                    result_postfix.push_back(temp);
                    oper_stack.pop();
                }
                oper_stack.push(ch_temp1);

                // 양수/음수 처리
                if (ins.peek() == '-')
                {
                    ins.get(ch_temp1);
                    num_buffer += '-';
                }
                else if (ins.peek() == '+')
                {
                    ins.get(ch_temp1);  // '+'는 그냥 넘김
                }
            }
            else
            {
                cout << ch_temp1 << "는 적절하지 않은 피연산자입니다.\n";
                exit(1);
            }
        }
    }


    if (!num_buffer.empty())
    {
        CharIntConstruct temp;
        temp.type = 0;
        temp.number = stoi(num_buffer);
        result_postfix.push_back(temp);
    }


    while (!oper_stack.empty())
    {
        CharIntConstruct temp;
        temp.type = 1;
        temp.symbol = oper_stack.top();
        result_postfix.push_back(temp);
        oper_stack.pop();
    }


    if (Lparen != Rparen)
    {
        cout << "올바르지 않은 괄호 연산자 사용입니다.\n";
        exit(1);
    }
    return result_postfix;
}

bool evaluate_stack(stack<int>& numbers, const char symbol)
{
    if (numbers.size() < 2)
        return false;  // 숫자가 2개보다 적으면 false

    int stack_num1 = numbers.top();
    numbers.pop();
    int stack_num2 = numbers.top();
    numbers.pop();

    int cal;
    switch (symbol)
    {
    case '+':
        cal = stack_num2 + stack_num1;
        break;
    case '-':
        cal = stack_num2 - stack_num1;
        break;
    case '*':
        cal = stack_num2 * stack_num1;
        break;
    case '/':
        cal = stack_num2 / stack_num1;
        break;
    case '%':
        cal = stack_num2 % stack_num1;
        break;
    case '^':
        cal = pow(stack_num2, stack_num1);
        break;
    default:
        return false;
    }
    numbers.push(cal);  // 계산된 수가 다음 계산 될 수 있게 다시 push
    return true;        // true
}

int evaluate_postfix(vector<CharIntConstruct> postfix)
{
    stack<int> cal_number;

    for (const auto& data : postfix)  // char, int 형 -> auto
    {
        if (data.type == 0)
        {
            cal_number.push(data.number);
        }
        else if (data.type == 1)
        {
            if (!evaluate_stack(cal_number, data.symbol))
            {
                cout << "오류" << endl;
                return -1;
            }
        }
    }

    if (cal_number.size() == 1)  // 하나만 남았을 때는 결과(계산이 다 끝남)
    {
        return cal_number.top();
    }

    cout << "계산 오류!" << endl;
    return -1;
}

int main()
{
    int result = -1;
    while (1)
    {
        string infix;
        cout << "Input Infix\n";
        getline(cin, infix, '\n');

        if (infix == "EOI")
            break;

        istringstream iss(infix);  // 스트림 형식으로 받아오기에 스트링을 스트림 형식으로 바꿔줘야함
        result = evaluate_postfix(make_postfix(iss));
        if (result != -1)
            cout << "result : " << result << endl;
    }
    return 0;
}
