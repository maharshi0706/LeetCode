#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution{
    public:
    int length(vector<int> nums){
        unordered_map<int,int> prefixSum;
        int currSum = 0;
        int maxLength = 0;
        int length = 0;
        for(int i = 0;i < nums.size();i++){
            currSum += nums[i];
            auto it = prefixSum.find(currSum);
            if(currSum == 0) length = i+1;
            else if(it != prefixSum.end()){ // preFixSum FOUND
                length = i - it->second;
            }
            else prefixSum[currSum] = i;
            maxLength = max(maxLength, length);
        }
        return maxLength;
    }
};

int main(){
    Solution sol;
    // vector<int> nums = {1, 0, -5};
    // vector<int> nums = {6, -2, 2, -8, 1, 7, 4, -10};
    vector<int> nums = {9, -3, 3, -1, 6, -5};
    cout<<sol.length(nums)<<endl;
    return 0;
}