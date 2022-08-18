#include "../../include/utils.h"

class MyQueue {
public:
    MyQueue() {

    }
    
    void push(int x) {
        stk1.push(x);
    }
    
    int pop() {
        doWhenEmpty();
        int val = stk2.top();
        stk2.pop();
        return val;
    }
    
    int peek() {
        doWhenEmpty();
        return stk2.top();
    }
    
    bool empty() {
        doWhenEmpty();
        return stk2.empty();
    }

    void doWhenEmpty() {
        if (stk2.empty()) {
            while (!stk1.empty()) {
                int val = stk1.top();
                stk1.pop();
                stk2.push(val);
            }
        }
    }

private:
    stack<int> stk1;  // 作为输入栈
    stack<int> stk2;  // 作为输出栈
};
