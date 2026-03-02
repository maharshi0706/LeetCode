#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

class Solution{
public:
    void subsetSum(vector<int> input, vector<int> output, vector<int>& sumOfSubsets){
        // base case -> if input : empty -> print output || Calculate sum of current Subset
        if(input.size() == 0){
            // Calculate sum
            int sum = 0;
            for(auto idx: output){
                // cout<<idx<<" ";
                sum += idx;
            }
            // cout<<endl;
            sumOfSubsets.push_back(sum); // Store in vector
            return;
        }

        // int firstElement = input[0];
        output.push_back(input[0]);
        subsetSum(vector<int> (input.begin()+1, input.end()), output, sumOfSubsets);
        subsetSum(vector<int> (input.begin()+1, input.end()), vector<int> (output.begin(), output.end()-1), sumOfSubsets);
    }
};


int main(){
    Solution sol;
    vector<int> sums = {};
    vector<int> input = {1,2,3};
    // std::sort(input.begin(), input.end(), std::greater<int>()); // Sorting INPUT in descending order gives sum in increasing order
    sol.subsetSum(input,{}, sums);
    std::sort(sums.begin(), sums.end());
    for(auto it: sums){
        cout<<it<<endl;
    }
    return 0;
}