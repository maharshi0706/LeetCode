#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        vector<int> nums3;
        int m = nums1.size();
        int n = nums2.size();
        int k = m + n;

        int i = 0, j = 0;
        while(i != m && j != n) {
            if(nums1[i] < nums2[j]) nums3.push_back(nums1[i++]);

            else nums3.push_back(nums2[j++]);
        }
        while(i < m) nums3.push_back(nums1[i++]);

        while(j < n) nums3.push_back(nums2[j++]);

        if (k % 2 == 0){
            return (double) ((double)(nums3[k / 2]) + (double)(nums3[k / 2 - 1])) / 2.0;
        }
        else return nums3[k / 2];
        
    }
};

int main(){
    Solution sol;
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};
    cout<<sol.findMedianSortedArrays(nums1, nums2)<<endl;
    return 0;
}