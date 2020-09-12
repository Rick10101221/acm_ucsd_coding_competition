#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;


int main() {
    int numEmails, approvedSchools;
    unordered_set<string> set;
    vector<string> res;
    
    cin >> numEmails >> approvedSchools;
    if (!numEmails || !approvedSchools) return 0;
    
    for (int i = 0; i < stoi(approvedSchools); i++) {
        string temp;
        cin >> temp;        
        set.insert(temp);
    }
    for (int i = 0; i < stoi(numEmails); i++) {
        string currentEmail;
        cin >> currentEmail;
        unsigned int j = 1, k = 0;
        while (j > 0 && j < currentEmail.length() && currentEmail[j - 1] != '@') {
            j++;
        }
        k = j;
        while (k < currentEmail.length() && currentEmail[k - 1] != '.') {
            k++;
        }
        string element = currentEmail.substr(j, k - j - 1);
        if (set.find(element) == set.end() || currentEmail[k] != 'e') {
            res.push_back(currentEmail);
        }   
    }
    for (auto c : res) {
        cout << c << endl;
    }
    return 0;
}
