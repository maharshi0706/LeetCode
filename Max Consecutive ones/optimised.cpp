#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.empty()) return 0;

        int maxSize = 0;
        int size = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] == 1){
                size += 1;
                maxSize = max(maxSize, size);
            }
            else size = 0;
        }

        return maxSize;
    }
};


int main(){
    Solution sol;
    vector<int> nums = {1,0,1,1,0,1};
    int maxOnes = sol.findMaxConsecutiveOnes(nums);
    cout<<maxOnes<<endl;
    return 0;
}