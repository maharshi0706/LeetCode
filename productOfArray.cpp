#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> preProduct(nums.size()) ;//= [1] * nums.size();
        vector<int> postProduct(nums.size()); //= [1] * nums.size();
        vector<int> answer(nums.size()); // = [1] * nums.size();
        int preVal = 1;
        int postVal = 1;
        preProduct[0] = 1;
        postProduct[nums.size()-1] = 1;
        for(int i = 1; i < nums.size();i++){
            preVal *= nums[i-1];
            // cout<<"PRE VAL: "<<preVal<<endl;
            preProduct[i] = preVal;
        }
        for(int i = nums.size()-2;i >= 0;i--){
            postVal *= nums[i+1];
            postProduct[i] = postVal;
        }
        for(int i = 0;i < nums.size();i++){
            answer[i] = preProduct[i] * postProduct[i];
        }
        // for (const auto& num : preProduct) {
        // cout << "PRE: " << num << " ";
        // }   
        // cout<<endl;
        // for (const auto& num : postProduct) {
        // cout << "POST: " << num << " ";
        // }   
        return answer;
    }
};


int main(){
    // vector<int> nums = {1,2,3,4};
    vector<int> nums = {-1,1,0,-3,3};
    Solution sol;
    vector<int> output = sol.productExceptSelf(nums);
    for (const auto& num : output) {
        cout << num << " ";
    }
    return 0;
}