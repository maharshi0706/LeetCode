#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n; // since n value will change during recursion -> store in diff variable
        double ans = 1.0;
        if(nn<0) nn = -1 * nn; // convert negative power to positive
        while(nn){
            if(nn % 2){
                ans = ans * x;
                nn = nn - 1;
            }
            else{
                x = x * x;
                nn = nn / 2;    
            }
        }
        if(n < 0) ans = (double) (1.0) / (double) (ans);

        return ans;
    }
};

int main(){
    Solution sol;
    double x = 2.0;
    int n = 10;
    double answer = sol.myPow(x, n);
    cout<<answer<<endl;
    return 0;
}