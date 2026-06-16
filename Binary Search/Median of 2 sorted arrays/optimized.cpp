#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        int pointer = 0;
        int i = 0, j = 0;

        int m = nums1.size(), n = nums2.size();
        int k = m + n;

        int idx2 = k / 2;
        int idx1 = idx2 - 1;

        int idx1Element = -1, idx2Element = -1;
        while(i != m && j != n) {
            if(nums1[i] < nums2[j]){
                if (pointer == idx1) idx1Element = nums1[i];
                if (pointer == idx2) idx2Element = nums1[i];
                pointer++;
                i++;
            }
            else{
                if (pointer == idx1) idx1Element = nums2[j];
                if (pointer == idx2) idx2Element = nums2[j];
                pointer++;
                j++;
                
            }
            
        }
        while(i < m) {
            if (pointer == idx1) idx1Element = nums1[i];
            if (pointer == idx2) idx2Element = nums1[i];
            pointer++;
            i++;
            
        }
        
        while(j < n) {
            if (pointer == idx1) idx1Element = nums2[j];
            if (pointer == idx2) idx2Element = nums2[j];
            pointer++;
            j++;
        }

        if (k % 2 == 0){
            return (double) ((double)(idx1Element + idx2Element)) / 2.0;
        }
        else return idx2Element;
    }
};

int main(){
    Solution sol;
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};
    cout<<sol.findMedianSortedArrays(nums1, nums2)<<endl;
    return 0;
}