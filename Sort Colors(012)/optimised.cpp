#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int mid = 0;
        int right = nums.size()-1;
        while(mid <= right){
            if(nums[mid] == 0){
                int temp = nums[mid];
                nums[mid] = nums[left];
                nums[left] = temp;
                mid++;
                left++;
            }
            else if(nums[mid] == 1) mid++;

            else {
                int t = nums[right];
                nums[right] = nums[mid];
                nums[mid] = t;
                right--;
            }
        }
        for(auto it: nums){
            cout<<it<<" ";
        }
        cout<<endl;
    }
};


int main(){
    Solution sol;
    // vector<int> nums = {2,0,1};
    vector<int> nums = {2,0,2,1,1,0};
    sol.sortColors(nums);
    return 0;
}