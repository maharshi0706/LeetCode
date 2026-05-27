#include <iostream>
using namespace std;

class Solution{
public:
    // Returns 1 if ans == mid
    //  Returns 2 if ans < mid -> potential answer to right of mid - eliminate left
    // Returns 0 if ans > mid -> potential answer to left of mid - eliminate right
    int findRoot(int mid, int n, int m){
        long long ans = 1;
        for(int i = 0;i < n;i++) {
            ans *= mid;
            if(ans > m) return 0;
        }
        if(ans == m) return 1;
        
        return 2;
    }

    int binarySearch(int low, int high, int n, int m){
        // Base condition
        if(low > high) return -1;

        int mid = (low + high) / 2;
        // If mid is M
        if(findRoot(mid, n, m) == 1) return mid;
        
        else if(findRoot(mid, n, m) == 0) return binarySearch(low, mid - 1, n ,m);
        
        else return binarySearch(mid + 1, high, n, m);
    }

    int NthRoot(int N, int M) {
       return binarySearch(1, M, N, M);
    }
};

int main(){
    Solution sol;
    cout<<sol.NthRoot(3, 69)<<endl;
    return 0;
}