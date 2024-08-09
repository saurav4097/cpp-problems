//if we stuck in a problem of a multi case   in 2D
#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the longest common subsequence
int commonChild(string str1, string str2) {
    int n1 = str1.length();
    int n2 = str2.length();

    // Create a 2D DP table to store lengths of longest common subsequence
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // The value in dp[n1][n2] will be the length of the longest common subsequence
    return dp[n1][n2];
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    int result = commonChild(str1, str2);
    cout << result << endl;

    return 0;
}
