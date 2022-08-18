#include "../../include/utils.h"

int totalFruit(vector<int>& fruits) {
    int len = fruits.size();
    int i = 0, j = 0;
    int res = 0;
    unordered_set<int> set;
    for (; j < fruits.size(); ++j) {
        if (set.find(fruits[j]) == set.end()) {
            if (set.size() < 2) {
                res = max(j - i + 1, res);
                set.insert(fruits[j]);
            } else if (set.size() >= 2){
                set.clear();
                i = j - 1;
                int val = fruits[i];
                while (fruits[--i] == val);
                set.clear();
                set.insert(fruits[j]);
                set.insert(fruits[++i]);
            }
        } else {
            res = max(j - i + 1, res);
        }
    }
    return res;
}

int totalFruit2(vector<int>& fruits) {
    int len = fruits.size();
    int a = fruits[0], b = fruits[0];
    int i = 0, j = 0;
    int res = 0;
    for (; j < fruits.size(); ++j) {
        if (a == b) {
            if (fruits[j] == a) {
                res = max(j - i + 1, res);
            } else if (fruits[j] != a) {
                b = fruits[j];
                res = max(j - i + 1, res);
            }   
        } else if (a != b && (a == fruits[j] || b == fruits[j])) {
            res = max(j - i + 1, res);
        } else {
            i = j - 1;
            b = fruits[j], a = fruits[i];
            while (fruits[--i] == a);
            i++;
        }
    }
    return res;
}

int main() {
    // vector<int> fruits = {3,3,3,1,4};
    vector<int> fruits = {0,1,2,2};
    cout << totalFruit2(fruits) << endl;
    return 0;
}