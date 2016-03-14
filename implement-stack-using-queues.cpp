#include <iostream>
#include <queue>

using namespace std;

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop();
    }

    // Get the top element.
    int top() {
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }

private:
    queue<int> q;
};

int main()
{
    Stack mystack;
    mystack.push(1);
    mystack.push(2);
    mystack.push(3);

    cout << mystack.empty() << endl;
    cout << mystack.top() << endl;
    mystack.pop();
    cout << mystack.top() << endl;
    mystack.pop();
    cout << mystack.top() << endl;
    mystack.pop();

    cout << mystack.empty() << endl;

    return 0;
}

