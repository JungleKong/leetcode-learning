#include "../../include/utils.h"

string replaceSpace(string s) {
    string res;
    for (char ch: s) {
        if (ch == ' ') {
            res += "%20";
        } else {
            res += ch;
        }
    }
    return res;
}