#include <vector>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int uniqueIndex = 0;
        for(int i = 1;i < nums.size();++i){
            if(nums[i] != nums[uniqueIndex]){
                ++uniqueIndex; // Increment unique element count
                nums[uniqueIndex] = nums[i]; // Override duplicate with unique element 
                // nums.erase(nums.begin() + (++i));
            }
        }
        return uniqueIndex + 1;
    }
};