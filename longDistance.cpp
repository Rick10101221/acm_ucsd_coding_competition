#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    unordered_map<int, int> dp;
    dp[0] = 0;
    int numberOfTestCases;
    cin >> numberOfTestCases;
    for (int i = 0; i < numberOfTestCases; i++) {
        int rows;
        cin >> rows;
        if (rows > 0 && dp[rows - 1]) {
            if (rows % 2) {
                cout << dp[rows - 1] + 4 << endl;
            } else {
                cout << dp[rows - 1] + 2 << endl;
            }
        } else {
            int j = 0, total = 0;
            while (j != rows) {
                if (j % 2 == 0) {
                    total += 4;
                } else {
                    total += 2;
                }
                j++;
            }
            dp[rows] = total;
            cout << total << endl;
        }
    }
    return 0;
}
