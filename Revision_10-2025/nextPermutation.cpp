#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
    public:
    void nextPermutation(vector<int>& nums){
        bool found = false;
        for(int i = nums.size()-1;i > 0;i--){
            if(nums[i-1] < nums[i]){ // Base Condition -> Find smaller element on left than current
                int pivot = i-1;
                for(int j = nums.size()-1;j >= i;j--){ // Find rightmost element > pivot in suffix(right of pivot)
                    if(nums[j] > nums[pivot]){
                        swap(nums[j], nums[pivot]);
                        break;
                    }
                }
                reverse(nums.begin()+i, nums.end());
                found = true;
                break;
            }
        }
        if(!found)  reverse(nums.begin(), nums.end());

        for(auto it: nums) cout<<it<<" ";
        cout<<endl;
    }
};


int main(){
    vector<int> nums = {1,3,2};
    Solution sol;
    sol.nextPermutation(nums);
    return 0;
}