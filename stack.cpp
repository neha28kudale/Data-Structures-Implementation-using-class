#include <iostream>
using namespace std;
#define MAX 10

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() {        
        top = -1;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX - 1);
    }

    void push(int val) {
        if (!isFull()) {
            top++;
            arr[top] = val;
        } else {
            cout << "\nStack is Full";
        }
    }

    void pop() {
        if (!isEmpty()) {
            top--;
        } else {
            cout << "\nStack is Empty";
        }
    }

    void printStack() {
        if (isEmpty()) {
            cout << "\nStack is Empty";
            return;
        }

        cout << "\nStack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " | ";
        }
    }
};

int main() {
	//STACK
    Stack s1;
	cout<<"\n--------Stack Elements After Pushing --------------";
    s1.push(5);
    s1.push(4);
    s1.push(3);
    s1.printStack();
	cout<<"\n\n--------Stack Elements After Poping --------------";
    s1.pop();
    s1.pop();
    s1.printStack();
    
    return 0;
}

