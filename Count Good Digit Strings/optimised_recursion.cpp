#include <iostream>
using namespace std;

class Solution{
public:
    long long power(long long base, long long exp, long long MOD){
        // Base case
        if (exp == 0) return 1;

        long long half = power(base, exp / 2, MOD);
        long long result = (half * half) % MOD;

        if(exp % 2 == 1){
            result = (result * base) % MOD;
        }
        return result;
    }

    int countGoodNumbers(long long n){
        const long long MOD = 1e9 + 7;
        long long even = (n+1)/2;
        long long odd = (n)/2;

        return (power(5,even,MOD) * power(4,odd,MOD)) % MOD;
    }
};
// class Solution{
// public:
//     int countGoodNumbers(long long n){
//         const long long MOD = 1e9 + 7;
//         // Base case -> if n = 0, stop
//         if(n == 0) return 1;

//         if(n % 2 == 0){ // Prime -> 4 options
//             return (4*countGoodNumbers(n-1)) % MOD;
//         }
//         else return (5*countGoodNumbers(n-1)) % MOD; // Even -> 5 options
//         // return n;
//     }
// };

int main(){
    Solution sol;
    long long n = 4; 
    cout<<sol.countGoodNumbers(n)<<endl;
    return 0;
}