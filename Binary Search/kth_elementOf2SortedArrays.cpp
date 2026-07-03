#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    int kthElement(vector<int> &a, vector<int>& b, int k) {
        int n = a.size();
        int m = b.size();
        if(n > m) return kthElement(b, a, k);

        int numOfLeftElements = k;
        int low = max(0, k - m), high = min(k, n);

        while(low <= high){
            int mid1 = low + (high - low) / 2;
            int mid2 = numOfLeftElements - mid1;

            int r1 = (a[mid1] >= 0) ? a[mid1] : INT_MAX;
            int r2 = (b[mid2] >= 0) ? b[mid2] : INT_MAX;
            
            int l1 = (a[mid1 - 1] >= 0) ? a[mid1 - 1] : INT_MIN;
            int l2 = (b[mid2 - 1] >= 0) ? b[mid2 - 1] : INT_MIN;

            if(l1 < r2 && l2 < r1){
                return max(l1, l2);
            }

            else if(l2 > r1) low = mid1 + 1;

            else high = mid1 - 1;
        }

        return 0;
    }
};

int main(){
    Solution sol;
    vector<int> a = {100, 112, 256, 349, 770};
    vector<int> b = {72, 86, 113, 119, 265, 445, 892};
    cout<<sol.kthElement(a, b, 7)<<endl;
    return 0;
}