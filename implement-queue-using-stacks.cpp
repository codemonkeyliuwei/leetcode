#include <iostream>
#include <stack>

using namespace std;

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        while (!mystack.empty()) {
            tmp.push(mystack.top());
            mystack.pop();
        }
        mystack.push(x);
        while (!tmp.empty()) {
            mystack.push(tmp.top());
            tmp.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        return mystack.pop();
    }

    // Get the front element.
    int peek(void) {
        return mystack.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return mystack.empty();
    }

private:
    stack<int> mystack;
    stack<int> tmp;
};

int main(void)
{
    Queue q;

    for (int i = 0; i < 4; i++) {
        q.push(i);
    }

    while (!q.empty()) {
        cout << q.peek();
        q.pop();
    }
    
    return 0;
}

