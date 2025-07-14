#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> storeValues;
        while(n != 1){
            if(storeValues.count(n) == 1) return false;

            if(n < 10){
                int m = n*n;
                storeValues[n] = m;
                n = m;
            }
            else{
                int sum = 0;
                int temp = n;
                while(temp != 0){
                    int remainder = temp % 10;
                    sum += (remainder * remainder);
                    temp /= 10;
                }
                storeValues[n] = sum;
                n = sum;
            }
        }
        return true;
    }
};


int main(){
    Solution sol;
    int n = 2;
    cout<<sol.isHappy(n)<<endl;
    return 0;
}