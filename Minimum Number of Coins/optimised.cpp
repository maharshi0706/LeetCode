#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    int numOfCoins(int V, vector<int> currencyValues){
        vector<int> Currencies;
        int totalCoins = 0;
        for(int i = currencyValues.size()-1;i >= 0 ;i--){
            while(V >= currencyValues[i]){
                V = V - currencyValues[i];
                totalCoins += 1;
                Currencies.push_back(currencyValues[i]);
            }
        }
        if(V != 0) return -1;
        // for(auto coin: Currencies){
        //     cout<<coin<<" ";
        // }
        // cout<<endl;
        return totalCoins;
    }
};


int main(){
    Solution sol;
    cout<<sol.numOfCoins(3, {2,5})<<endl;
    return 0;
}