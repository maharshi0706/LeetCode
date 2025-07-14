#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int jump(vector<int>& nums) {
    if (nums.size() == 1) return 0;

    int furthestIndex = 0;
    
    int count = 0;
    for(int i = 0;i < nums.size();i = furthestIndex){
        cout<<"I: "<<i<<" nums[i]: "<<nums[i]<<endl;

        if(nums[i]+i >= nums.size()-1)  {
            count += 1;
            break;
        }

        if(nums[i] == 1) {
            count += 1;
            furthestIndex++;
            continue;
        }
        
        int max = nums[i+1];
        furthestIndex = i+1;
        for(int j = i+2;j <= nums[i]+i; j++){
            cout<<"   j: "<<j<<" nums[j]: "<<nums[j]<<" Max: "<<max<<endl;


            if(nums[j] >= max) {
                max = nums[j];
                furthestIndex = j;
                cout<<"         IN IF fIndex: "<<furthestIndex<<endl;
            }
        }
        count += 1;
        cout<<"Count: "<<count<<" furthestIndex: "<<furthestIndex<<endl;
    }
    return count;
  }
};

int main(){
  Solution sol;
  vector<int> nums = {2,1,1,1,1};
//   vector<int> nums = {2,3,1,1,4};
//   vector<int> nums = {2,1};
  cout<<sol.jump(nums)<<endl;
  return 0;
}