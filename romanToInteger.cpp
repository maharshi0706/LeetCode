// XIV
// III -> 
// if s[i] greater than total -> total+s[i]
// else if s[i] less than total ->  total - 1
#include <unordered_map>
#include <iostream> 

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanNumerals;

        romanNumerals['I'] = 1;
        romanNumerals['V'] = 5;
        romanNumerals['X'] = 10;
        romanNumerals['L'] = 50;
        romanNumerals['C'] = 100;
        romanNumerals['D'] = 500;
        romanNumerals['M'] = 1000;

        int total = 0;
        int temp = romanNumerals[s[s.length()]];
        for(int i = s.length() - 1; i >= 0; i--){
            // cout << "TOTAL: " << total << endl;
            // cout << "temp: " << temp << endl;
            // cout << "S[i]: " << s[i] << " | Value: " << romanNumerals[s[i]] << endl;
            if(romanNumerals.find(s[i]) != romanNumerals.end() && romanNumerals[s[i]] >= temp) {
                total += romanNumerals[s[i]];
            }
            else if(romanNumerals[s[i]] < temp){ 
                total -= romanNumerals[s[i]];
            }
            temp = romanNumerals[s[i]];
        }
        return total;
    }
};

int main() {
    Solution sol;
    string roman = "MCMXCIV";
    int result = sol.romanToInt(roman);
    cout << "Integer value: " << result << endl;
    return 0;
}