#include <iostream>
using namespace std;

#define MAX 10

class Queue {
    int arr[MAX];
    int front;
    int rear;

public:
    Queue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    void push(int x) {
        if (isFull()) {
            cout << "\nQueue is Full";
            return;
        }

        if (front == -1) {   // first insertion
            front = 0;
        }

        rear++;
        arr[rear] = x;
    }

    void pop() {
        if (isEmpty()) {
            cout << "\nQueue is Empty";
            return;
        }

        front++;
    }

    void printQueue() {
        if (isEmpty()) {
            cout << "\nQueue is Empty";
            return;
        }

        cout << "\nQueue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " | ";
        }
    }
};

int main() {
    Queue q1;

    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(40);

    cout << "\n--------Queue Elements After Pushing--------------";
    q1.printQueue();

    cout << "\n--------Queue Elements After Popping--------------";
    q1.pop();
    q1.pop();
    q1.printQueue();

    return 0;
}

