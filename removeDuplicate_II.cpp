#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if(nums.empty()) return 0;

            if(nums.size()==1) return 1;

            int position = 2;
            for(int i = 2;i < nums.size();i++){
                if(nums[i] != nums[position-2]){
                    nums[position++] = nums[i];
                }
                else continue;
            }
            return position;
        }
    };


int main(){
    Solution sol;
    // vector<int> nums = {};
    vector<int> nums = {0,0,1,1,1,1,2,3,3};
    // vector<int> nums = {1,1,1,2,2,3};
    cout<<"RESULT: "<<sol.removeDuplicates(nums)<<endl;
    return 0;
}