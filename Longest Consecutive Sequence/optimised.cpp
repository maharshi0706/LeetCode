#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> nums) {
        unordered_set<int> values(nums.begin(), nums.end());
        
        int count = 0;
        for(int num: values) {
            if(values.find(num-1) == values.end()){
                int currNum = num;
                int currCount = 1;
                while(values.find(currNum+1) != values.end()) {
                    currCount++;
                    currNum++;
                }
                count = max(count, currCount);
            }
        }
        return count;
    }
};


int main(){
    Solution sol;
    int output = sol.longestConsecutive({100,4,200,1,3,2});
    cout<<output<<endl;
    return 0;
}