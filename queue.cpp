//code for static implementation of a queue data structure in C++
#include <iostream> 
using namespace std;
bool isoverflow() {
    return (rear == size - 1);
}
bool isunderflow() {
    return (front== -1);
}
void enqueue(int value) {
    if (isoverflow()) {
        cout << "Queue Overflow" << endl;
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
    cout << "Inserted " << value << endl;
}
void dequeue() {
    if (isunderflow()) {
        cout << "Queue Underflow" << endl;
        return;
    }
    cout << "Deleted " << queue[front] << endl;
    front++;
    if (front > rear) {
        front = rear = -1; // Reset the queue when it becomes empty
    }
}

void peek() {
    if (isunderflow()) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Front element is: " << queue[front] << endl;
}

void traverse() {
    if (isunderflow()) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue elements are: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, value;
    while (true) {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Traverse" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                traverse();
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
