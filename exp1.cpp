#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

string infixToPostfix(string infix)
{
    stack<char> s;
    string postfix = "";

    for (char ch : infix)
    {
        if (isalnum(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }

            if (!s.empty())
                s.pop();
        }
        else
        {
            while (!s.empty() &&
                   precedence(s.top()) >= precedence(ch))
            {
                postfix += s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main()
{
    int N;
    cout << "Enter stack size: ";
    cin >> N;

    stack<int> st;

    cout << "\nPUSH operations:\n";

    for (int i = 0; i < N; i++)
    {
        int value;
        cout << "Enter value: ";
        cin >> value;

        if (st.size() == N)
            cout << "Stack Overflow\n";
        else
            st.push(value);
    }

    cout << "\nPOP operation: ";

    if (st.empty())
        cout << "Stack Underflow\n";
    else
    {
        cout << st.top() << " popped\n";
        st.pop();
    }

    cout << "\nFinal contents of stack:\n";

    if (st.empty())
        cout << "Stack is empty\n";
    else
    {
        stack<int> temp = st;

        while (!temp.empty())
        {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }

    string infix;

    cout << "\nEnter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}