#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        int m = nums2.size();
        if(n > m) return findMedianSortedArrays(nums2, nums1);

        int low = 0, high = n;
        int numOfLeftElements = (n + m + 1) / 2;

        while(low <= high){

            int mid1 = low + (high - low) / 2;
            int mid2 = numOfLeftElements - mid1;
            
            int r1 = (mid1 < n) ? nums1[mid1] : INT_MAX; 
            int r2 = (mid2 < m) ? nums2[mid2] : INT_MAX;

            int l1 = (mid1 - 1 >= 0) ? nums1[mid1 - 1] : INT_MIN;
            int l2 = (mid2 - 1 >= 0) ? nums2[mid2 - 1] : INT_MIN;

            if(l1 <= r2 && l2 <= r1){
                if ((n + m) % 2 == 0) {
                    return ((double)max(l1, l2) + (double)min(r1, r2)) / 2.0;
                }
                return (double)max(l1, l2);
            }

            else if(l2 > r1) {
                low = mid1 + 1;
            }
            else high = mid1 - 1;
        }
        return 0;
    }
};

int main(){
    Solution sol;
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};
    cout<<sol.findMedianSortedArrays(nums1, nums2)<<endl;
    return 0;
}