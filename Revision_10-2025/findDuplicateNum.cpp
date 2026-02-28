#include <vector>
#include <iostream>
using namespace std;

class Solution{
    public:
    int findDuplicate(vector<int>& nums){
        int slow = 0;
        int fast = 0;
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        fast = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};


int main(){
    Solution sol;
    vector<int> nums = {3,3,3,3,3};
    // vector<int> nums = {3,1,3,4,2};
    // vector<int> nums = {1,3,4,2,2};
    cout<<sol.findDuplicate(nums)<<endl;
    return 0;
}

