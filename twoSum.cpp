#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> output(2);
        int left = 0;
        int currentSum = 0;
        int right = numbers.size()-1;
        while (left < right){
            currentSum = numbers[left]+numbers[right];
            if(currentSum == target){
                output[0] = left+1;
                output[1] = right+1;
                break;
            }
            if(currentSum < target) left++;

            if(currentSum > target) right--;
        }
        return output;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {-1,0};
    int target = -1;
    vector<int> output = sol.twoSum(nums, target);
    for(auto i: output){
        cout<<i<<endl;
    }
    return 0;
}