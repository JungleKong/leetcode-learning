#include "../../include/utils.h"

// 使用一个队列实现
class MyStack {
public:
    MyStack() {

    }
    
    void push(int x) {
        que.push(x);
    }
    
    int pop() {
        int res = 0;
        int size = que.size();
        while (size > 1) {
            res = que.front();
            que.push(res);
            que.pop();
            size--;
        }
        res = que.front();
        que.pop();
        return res;
    }
    
    int top() {
        int res = 0;
        int size = que.size();
        while (size > 0) {
            res = que.front();
            que.push(res);
            que.pop();
            size--;
        }
        return res;
    }
    
    bool empty() {
        return que.empty();
    }
private:
    queue<int> que;
};


// 也可以使用两个栈,另一个做缓存之用