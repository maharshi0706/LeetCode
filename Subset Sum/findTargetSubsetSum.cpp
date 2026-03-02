#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    // Use index instead of output vector for comparison and tracking
    bool findTargetSubsetSum(vector<int>& input, int index, int target, int currentSum){
        // Base case
        if(input.size() == index){
            // Check for target in current subset sum
            return currentSum == target;
        }
        
        // include -> add element to currentsum
        bool include = findTargetSubsetSum(input, index + 1, target, currentSum+input[index]);
        
        // exclude -> DO NOT add element to currentsum
        bool exclude = findTargetSubsetSum(input, index + 1, target, currentSum);
        
        return include || exclude;
    }
};

int main(){
    Solution sol;
    int target = 5;
    vector<int> input = {1,2,3};
    cout<<sol.findTargetSubsetSum(input, 0, 5, 0)<<endl;
    return 0;
}