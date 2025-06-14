#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i = 0;i < prices.size()-1;i++){
            if((prices[i+1]-prices[i])>0) profit += (prices[i+1] - prices[i]); 
        }
        cout<<profit<<endl;
    }
};

int main(){
    Solution S;
    // vector<int> prices = {7,1,5,3,6,4};
    // vector<int> prices = {1,2,3,5,4};
    vector<int> prices = {7,6,4,3,1};
    S.maxProfit(prices);
    return 0;
}