#include <iostream>
using namespace std;
#define N 5
int stack[N];
int top = -1;
void push(int value)
{
    if (top == N - 1)
    {
        cout << "Stack Overflow!" << endl;
    }
    else
    {
        top++;
        stack[top] = value;
        cout << value << " pushed into stack." << endl;
    }
}
void pop()
{
    if (top == -1)
    {
        cout << "Stack Underflow!" << endl;
    }
    else
    {
        cout << stack[top] << " popped from stack." << endl;
        top--;
    }
}
void display()
{
    if (top == -1)
    {
        cout << "Stack is empty." << endl;
    }
    else
    {
        cout << "Final contents of stack: ";
        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    pop();
    push(50);
    display();
    return 0;
}