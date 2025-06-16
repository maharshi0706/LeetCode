#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int jump(vector<int>& nums) {
    if (nums.size() == 1) return 0;
    int currentEnd = 0;
    int nextFurthest = 0;
    int count = 0;
    for(int i = 0; i<=nums.size()-2;i++){
      nextFurthest = max(nextFurthest, i+nums[i]);
      // cout<<"Next Furthest: "<<nextFurthest<<endl;
      if(i == currentEnd){
        count += 1;
        currentEnd = nextFurthest;
      }
      // cout<<"Count: "<<count<<endl;
      // cout<<"Cuurent End: "<<currentEnd<<endl;
      if(currentEnd >= nums.size()-1) break;
    }
    return count;
  }
};

int main(){
  Solution sol;
  // vector<int> nums = {2,3,1,1,4};
  vector<int> nums = {2};
  // vector<int> nums = {2,1,1,1,1};
  cout<<sol.jump(nums)<<endl;
  return 0;
}

  //   if (nums.size() == 1) return 0;

  //   int count = 0;
  //   int farthestIndex = 0;

  //   for(int i = 0;i < nums.size();i+=farthestIndex){
  //     cout<<"I: "<<i<<" nums[i]: "<<nums[i]<<endl;
    
  //     for(int j = i+1; j <= (nums[i]+i); j++){
    
  //       cout<<"   j: "<<j<<" nums[j]: "<<nums[j]<<endl;
    
  //       if(nums[j]>nums[farthestIndex]) farthestIndex = j;
    
  //     }
  //     count += 1;
  //     cout<<"Count: "<<count<<" FarthestIndex: "<<farthestIndex<<endl;
    
  //     if (farthestIndex == nums.size()) break;
      
  //   }
  //   return count;