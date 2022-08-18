#include "../../include/utils.h"

bool canConstruct(string ransomNote, string magazine) {
    vector<int> vec(26);
    for (char ch: magazine) {
        vec[ch - 'a']++;
    }
    for (char ch: ransomNote) {
        vec[ch - 'a']--;
    }
    for (int i: vec) {
        if (i < 0) return false;
    }
    return true;
}