#include <iostream>
using namespace std;

class Solution {
public:
    int traversal(int i, int j, int m, int n){
        if(i >= m || j >= n) return 0; // FIRST BASE CASE -> FAILURE
        else if (i == m-1 && j == n-1) return 1; // SECOND BASE CASE -> SUCCESS 
        else return traversal(i+1, j, m, n) + traversal(i, j+1, m, n); // RECURSION UNTIL REACH GOAL
    }
    int uniquePaths(int m, int n) {
        int totalPaths = traversal(0, 0, m, n);
        return totalPaths;
    }
};

int main(){
    Solution sol;
    cout<<sol.uniquePaths(3,7)<<endl;
    return 0;
}