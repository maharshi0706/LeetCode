#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int totalDirections = m + n - 2; // (m-1) + (n-1) total directions to be taken
        int chooseDirection = m - 1;
        double res = 1;
        
        // 8c2 -> 7*8 / 2*1
        for(int i = 1; i <= chooseDirection;i++){
            res = res * (totalDirections - chooseDirection + i) / i;    
        }
        return (int)res;
    }
};

int main(){
    Solution sol;
    cout<<sol.uniquePaths(3,7)<<endl;
    return 0;
}