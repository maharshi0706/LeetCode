#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;


class Solution{
public:
    int maxSubarray(vector<int> nums){
        unordered_map<int, int> prefixSumValues;
        int maxCount = 0;
        int sum = 0;
        for(int i = 0;i < nums.size();i++){
            sum += nums[i];
            if(sum == 0) maxCount = i + 1;
            else{
                if(prefixSumValues.find(sum) != prefixSumValues.end()){
                    maxCount = max(maxCount, i - prefixSumValues[sum]);
                }
                else prefixSumValues[sum] = i;
            }
        }
        return maxCount;
    }
};


int main(){
    Solution sol;
    int output = sol.maxSubarray({6, -2, 2, -8, 1, 7, 4, -10});
    cout<<output<<endl;
    return 0;
}