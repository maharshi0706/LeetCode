#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
        // check if solution exists
        int gasSum = accumulate(gas.begin(), gas.end(), 0);
        int costSum = accumulate(cost.begin(), cost.end(), 0);
        if(gasSum < costSum) return -1;

        int currentStartIndex = 0;
        int currentFuel = 0;
        for(int i = 0;i < gas.size(); i++){
            currentFuel = currentFuel + gas[i] - cost[i];
            cout<<"C F: "<<currentFuel<<endl;
            if (currentFuel < 0) {
                currentStartIndex = i+1;
                cout<<"     in if C F: "<<currentFuel<<" start Index: "<<currentStartIndex<<endl;
                currentFuel = 0;
            }
        }
        return currentStartIndex;
    }
};


int main(){
    Solution sol;
    vector<int> gas = {1, 2, 3, 4, 5};
    // vector<int> gas = {2,3,4};
    vector<int> cost = {3, 4, 5, 1, 2};
    // vector<int> cost = {3,4,3};
    cout<<sol.canCompleteCircuit(gas, cost)<<endl;
    return 0;
}