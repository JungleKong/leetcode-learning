#include "../../include/utils.h"
// 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
// 请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

// 输入: s = "abcdefg", k = 2
// 输出: "cdefgab"

// 输入: s = "lrloseumgh", k = 6
// 输出: "umghlrlose"


// 先整体反转, 再局部反转
string reverseLeftWords(string s, int n) {
    reverse(s.begin(), s.end());
    reverse(s.begin(), s.begin() + s.size() - n);
    reverse(s.begin() + s.size() - n, s.end());
    return s;
}