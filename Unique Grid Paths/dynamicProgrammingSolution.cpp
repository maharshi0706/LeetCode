#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:

    int countTotalPaths(int i, int j, int m, int n, vector<vector<int>> &dp){
        if(i == m-1 && j == n-1) return 1;
        if(i >= m || j >= n) return 0;
        else if (dp[i][j] != -1) return dp[i][j];
        else return dp[i][j] = countTotalPaths(i+1,j,m,n,dp)+countTotalPaths(i,j+1,m,n,dp);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return countTotalPaths(0,0,m,n,dp);
    }
};


int main(){
    Solution sol;
    int output = sol.uniquePaths(3,7);
    cout<<output<<endl;
    return 0;
}