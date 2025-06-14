#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goalpost = nums.size()-1;
        for(int i = nums.size()-1;i >= 0;i--){
            if((i+nums[i]) >= goalpost) goalpost = i;

            cout<<"GP: "<<goalpost<<endl;
            
        }
        if(goalpost == 0) return true;
        else return false;
    }
    // bool canJump(vector<int>& nums) {
    //     if(nums.size() == 1) return true;
    //     cout<<"SIZE: "<<nums.size()<<" -1 size: "<<nums.size()-1<<endl;
    //     int furthest = nums[0];
    //     for(int i = 0;i < nums.size()-1;i++){
    //         cout<<"FUR BEFORE: "<<furthest<<endl;
    //         if (nums[i] != 0) furthest = max(furthest, i + nums[i]);
    //         else continue;
    //         cout<<"FUR AFTER: "<<furthest<<endl;
    //         if (furthest >= nums.size()-1){
    //             return true;
    //         }
    //     }
    //     return false;
    // }
};

int main(){
    Solution sol;
    // vector<int> nums = {2,3,1,1,4};
    // vector<int> nums = {0,2,3};
    vector<int> nums = {3,0,8,2,0,0,1};
    cout<<sol.canJump(nums)<<endl;
    return 0;
}