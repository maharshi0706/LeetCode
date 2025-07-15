#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowestPrice = prices[0];
        int maxProfit = 0;
        for(int i = 1;i < prices.size();i++){
            if(prices[i] < lowestPrice) lowestPrice = prices[i];

            maxProfit = max(maxProfit, (prices[i]-lowestPrice));
        }
        return maxProfit;
    }
};


int main(){
    Solution sol;
    vector<int> prices = {7,6,4,3,1};
    // vector<int> prices = {7,1,5,3,6,4};
    int output = sol.maxProfit(prices);
    cout<<output<<endl;
    return 0;
}