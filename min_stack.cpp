#include <stack>
#include <iostream>

class MinStack {
private:
    std::stack<int> minStack;
    std::stack<int> stack;
public:
    MinStack() {

    }

    void push(int val) {
        stack.push(val);
        if (!minStack.size() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        auto top = stack.top();

        stack.pop();

        if (top == minStack.top()) {
            minStack.pop();
        }
    }

    int top() {
        return stack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    std::cout << "minStack->getMin(): " << minStack->getMin() << std::endl; // - 3
    minStack->pop();
    std::cout << "minStack->top(): " << minStack->top() << std::endl;    // return 0
    std::cout << "minStack->getMin(): " << minStack->getMin() << std::endl; // return -2
}
