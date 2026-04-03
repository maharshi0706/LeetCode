#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
public:
    int getNumOfPermutations(int n){
        if(n == 0 || n == 1) return 1;

        return n * getNumOfPermutations(n-1);
    }

    void getPermutations(int numOfPermutations, vector<int> nums, vector<vector<int>>& output){
        if(numOfPermutations == 0) return;

        output.push_back(nums);
        
        int n = nums.size()-1;
        for(int i = n-1;i >= 0;i--){
            if(nums[i] < nums[i+1]){
                for(int j = n;j > i;j--){
                    if(nums[j] > nums[i]){
                        int temp = nums[j];
                        nums[j] = nums[i];
                        nums[i] = temp;
                        break;
                    }
                }
                std::reverse(nums.begin() + i + 1, nums.end());
                break;
            }
        }

        getPermutations(numOfPermutations-1, nums, output);
    }

    vector<vector<int>> permute(vector<int>& nums){
        vector<vector<int>> output;
        
        int numOfPermutations = getNumOfPermutations((int)nums.size()); 
        getPermutations(numOfPermutations, nums, output);

        return output;
    }
};


int main(){
    Solution sol;
    vector<int> nums = {1,2,3};
    vector<vector<int>> output = sol.permute(nums);
    
    for(auto num: output){
        for(auto it: num){
            cout<<it<<" ";
        }
        cout<<endl;
    }

    return 0;
}