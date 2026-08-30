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
        unordered_map<int, int> numsCount;

        int count = 0;
        // Step 1 -> Store element, count in map
        for(int num: nums){
            numsCount[num]++;
        }

        // Step 2 -> Traverse Map to update min heap 
        // PQ of type structure -> storing element and count || Compare also struct with function operator
        priority_queue<elementCount, vector<elementCount>, Compare> minPQ;

        // Logic: Push all elements and pop until K elements remain 
        for(auto it = numsCount.begin(); it != numsCount.end();it++){
            minPQ.push({it->first, it->second});

            if (minPQ.size() > k) minPQ.pop();
        }

        // Step 3 -> Transfer heap elements to vector
        vector<int> output;
        output.reserve(k);
        while(!minPQ.empty()){
            output.push_back(minPQ.top().element);
            minPQ.pop();
        }
        return output;
    }
};


int main(){
    Solution sol;
    vector<int> nums = {1,2,1,2,1,2,3,1,3,2};
    vector<int> output = sol.topKFrequent(nums, 2);

    for(auto num: output){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}