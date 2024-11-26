class Solution {
#include <vector>
public:
    int majorityElement(vector<int>& nums) {
        int count;
        int tempVariable;
        for(int i=0;i<nums.size() -1;i++){
            int j = 1;
            while(j < nums.size()-1){
                count++;
                if(nums[i] == nums[j]) count++;

                ++j;
            }
            if(count > (nums.size()-1 / 2)) return nums[i];
        }
        return 0;
    }
};