#include "../../include/utils.h"


// 逆波兰表达式求值
// 输入：tokens = ["4","13","5","/","+"]
// 输出：6
// 解释：该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
int evalRPN(vector<string>& tokens) {
    stack<int> stk;
    for (string str: tokens) {
        if (str == "+") {
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();
            stk.push(b + a);
        } else if (str == "-") {
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();
            stk.push(b - a);
        } else if (str == "*") {
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();
            stk.push(b * a);
        } else if (str == "/") {
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();
            stk.push(b / a);
        } else {
            stk.push(atoi(str.c_str()));
        }
    }
    return stk.top();
}