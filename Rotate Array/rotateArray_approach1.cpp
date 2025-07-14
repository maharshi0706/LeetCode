// while k-- > 0
//      for i=n till 0
//          temp = arr[i]
//          //arr[0] = arr[i]
//          arr[i] = arr[i-1]
//          if i=0
//              arr[i] = temp

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            while((k--) > 0){
                int temp = nums[nums.size()-1];
                for(int i = nums.size()-1;i > 0;i--){
                    nums[i] = nums[i-1];
                    if ((i-1) == 0) {
                        nums[i-1] = temp;
                    }
                }
            }
            for(auto j: nums) {
                cout<<j<<" ";
            }
            
        }
};

int main(){
    Solution S;
    // vector<int> nums = {1,2,3,4,5,6,7};
    vector<int> nums = {-1,-100,3,99};
    int k = 2;
    S.rotate(nums, k);
    return 0;
}