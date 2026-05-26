#include <iostream>
using namespace std;

class Solution{
public:
    long long binarySearch(int low, int high, int x, long long ans){
        if(low > high) return ans;

        long long mid = (low + high) / 2;
        if(mid * mid <= x) return binarySearch(mid + 1, high, x, mid);

        return binarySearch(low, mid - 1, x, ans);
    }

    int mySqrt(int x){
        long long ans = 1;
        ans = binarySearch(0, x, x, ans);
        return ans;
    }
};

int main(){
    Solution sol;
    cout<<sol.mySqrt(2)<<endl;
    return 0;
}