#include "../../include/utils.h"


bool isAnagram(string s, string t) {
    vector<int> vec(26);
    for (char ch: s) {
        vec[ch - 'a']++;
    }
    for (char ch: t) {
        vec[ch - 'a']--;
    }
    for (int i: vec) {
        if (i != 0) return false;
    }
    return true;
}