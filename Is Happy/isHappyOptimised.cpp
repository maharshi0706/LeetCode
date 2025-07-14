    #include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> storeValues;
        while(n != 1){
            if(storeValues.count(n) == 1) return false;

            storeValues.insert(n);
            int sum = 0;
            while(n != 0){
                int remainder = n % 10;
                sum += (remainder * remainder);
                n /= 10;
            }
            n = sum;
        }
        return true;
    }
};


int main(){
    Solution sol;
    int n = 19;
    cout<<sol.isHappy(n)<<endl;
    return 0;
}