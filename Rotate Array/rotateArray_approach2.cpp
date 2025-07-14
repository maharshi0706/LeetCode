#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            if(nums.size()<k){
                while((k--) > 0){
                    int temp = nums[nums.size()-1];
                    for(int i = nums.size()-1;i > 0;i--){
                        nums[i] = nums[i-1];
                        if ((i-1) == 0) {
                            nums[i-1] = temp;
                        }
                    }
                }  
            }
            else{
                std::reverse(nums.begin(), nums.end());
                std::reverse(nums.begin(), (nums.begin()+k));
                std::reverse((nums.begin()+k), nums.end());
            }

            for(auto j: nums) {
                cout<<j<<" ";
            }
        }
};

int main(){
    Solution S;
    vector<int> nums = {1,2,3,4,5,6,7};
    // vector<int> nums = {-1,-100,3,99};
    int k = 3;
    S.rotate(nums, k);
    return 0;
}