#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;


struct elementCount{
    int element;
    int count;
};

class Solution{
public:
    struct Compare {
        bool operator()(elementCount c1, elementCount c2) {
            return c1.count > c2.count;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> output;
        unordered_map<int, int> numsCount;

        int count = 0;
        // Step 1 -> Store element, count in map
        for(int i = 0;i < nums.size();i++){
            // Check if element exists in map
            auto it = numsCount.find(nums[i]);
            // If exists -> update count
            if(it != numsCount.end()) numsCount[nums[i]] += 1;

            // Else append element with count 1
            else {
                numsCount[nums[i]] = 1;
                count++;
            }
        }

        // Step 2 -> Traverse Map to update min heap
        struct elementCount eCount;
        
        // PQ of type structure -> storing element and count || Compare also struct with function operator
        priority_queue<elementCount, vector<elementCount>, Compare> minPQ;

        // Logic: Push till k elements in PQ and then compare count for k+1 till end to pop and push 
        auto it = numsCount.begin();
        while(it != numsCount.end() && k--){
            eCount.element = it->first;
            eCount.count = it->second;
            minPQ.push(eCount);
            it++;
        }

        while(it != numsCount.end()){
            eCount.element = it->first;
            eCount.count = it->second;
            if(eCount.count > minPQ.top().count){
                minPQ.pop();
                minPQ.push(eCount);
            }
            it++;
        }

        // Step 3 -> Transfer heap elements to vector
        while(!minPQ.empty()){
            output.push_back(minPQ.top().element);
            minPQ.pop();
        }
        return output;
    }
};


int main(){
    Solution sol;
    vector<int> nums = {1};
    vector<int> output = sol.topKFrequent(nums, 1);

    for(auto num: output){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}