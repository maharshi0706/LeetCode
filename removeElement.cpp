class Solution {
#include <vector>
public:
    int removeElement(vector<int>& nums, int val) {
        // int n = static_cast<int>(nums.size() - 1);
        if(nums.empty()){
            return 0;
        }
        else if(nums.size()==1 && nums[0] !=val){
            return 1;
        }
        else{
            int j = nums.size()-1;
            int temp;
            int k = 0;
            int count = 0;
            int ifCount = 0;
            for(int i = 0;i <= j; i++){
                if (nums[i] == val){
                    ifCount += 1;
                    while(j>i){
                        if(nums[j] != val){
                            temp = nums[i];
                            nums[i] = nums[j];
                            nums[j] = temp;
                            // j = ;
                            break;
                        }
                        j -= 1; 
                    }
                }
                else{
                    count += 1;
                }
            }
            if (count != 0 && ifCount == 0){
                return count;
            }
            else{
                return j;
            }
        }
    }
};