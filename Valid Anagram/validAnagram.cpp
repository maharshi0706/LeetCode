#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        unordered_map<char, int> charCount;
        for(char c: s){
            charCount[c]++;
        }

        for(char c: t){
            if(charCount[c] == 0) return false;
            
            charCount[c]--;
        }
        return true;
    }
};


int main(){
    Solution sol;
    string s = "rt";
    string t = "car";
    cout<<sol.isAnagram(s,t)<<endl;
    return 0;
}