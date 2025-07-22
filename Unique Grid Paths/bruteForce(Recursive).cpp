#include <iostream>
using namespace std;

class Solution {
public:
    int countTotalPaths(int i, int j, int m, int n){
        if(i == m-1 && j == n-1) return 1;
        else if(i >= m|| j >= n) return 0;
        else return countTotalPaths(i+1,j,m,n)+countTotalPaths(i,j+1,m,n);
    }

    int uniquePaths(int m, int n) {
        return countTotalPaths(0,0,m,n);
    }
};


int main(){
    Solution sol;
    int output = sol.uniquePaths(3,7);
    cout<<output<<endl;
    return 0;
}