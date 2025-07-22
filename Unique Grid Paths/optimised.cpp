#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m + n - 2;
        int r = m - 1;
        double res = 1;
        for(int i = 1;i <= r;i++){
            res = res * (N - r + i) / i;
        }
        return (int)res;
    }
};


int main(){
    Solution sol;
    int output = sol.uniquePaths(3,7);
    cout<<output<<endl;
    return 0;
}