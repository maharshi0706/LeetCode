#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int traversal(int i, int j, int m, int n, vector<vector<int>>& dp){
        if(i >= m || j >= n) return 0; // FIRST BASE CASE -> FAILURE
        if (i == m-1 && j == n-1) return 1; // SECOND BASE CASE -> SUCCESS
        if (dp[i][j] != -1) return dp[i][j]; // DP CASE -> If state already traversed before, return value
        else return dp[i][j] = traversal(i+1, j, m, n, dp) + traversal(i, j+1, m, n, dp); // Store value of traversion in current state
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        int num = traversal(0, 0, m, n, dp);
        // if(m == 1 && n == 1) return num;
        // return dp[0][0];
        return num;
    }
};

int main(){
    Solution sol;
    cout<<sol.uniquePaths(3,7)<<endl;
    return 0;
}