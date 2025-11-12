#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution{
    public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();

        int maxCount = 0;
        unordered_set<int> numCount;
        for(auto it: nums) numCount.insert(it);

    
        for(int num: numCount){ // LOOP THROUGH SET, NOT VECTOR -> TO AVOID DUPLICATES
            if(!numCount.count(num-1)) {
                int currElement = num;
                int currCount = 0;
                while(numCount.count(currElement)){
                    currElement += 1;
                    currCount += 1;   
                }
                maxCount = max(maxCount, currCount);
            }
        }
        return maxCount;
    }
};


int main(){
    Solution sol;
    vector<int> nums = {1,0,1,2};
    // vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    // vector<int> nums = {100,4,200,1,3,2};
    cout<<sol.longestConsecutive(nums)<<endl;
    return 0;
}