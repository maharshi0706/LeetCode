#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> charCount;
        for(char c: magazine){
            charCount[c]++;
        }
        for(char c: ransomNote){
            if(charCount[c] == 0) return false;

            charCount[c]--;
        }
        return true;
    }
};
// class Solution {
// public:
//     bool canConstruct(string ransomNote, string magazine) {
//         unordered_map<char, int> charCount;
//         // int count;
//         for(int i = 0;i < magazine.size();i++){
//             if(charCount.count(magazine[i]) == 1) charCount[magazine[i]] += 1;

//             else charCount[magazine[i]] = 1;
//         }

//         for(int i = 0;i < ransomNote.size();i++){
//             if(charCount.count(ransomNote[i]) == 0 || charCount[ransomNote[i]] <= 0) return false;

//             else charCount[ransomNote[i]] -= 1;
//         }
//         return true;
//     }
// };


int main(){
    Solution sol;
    string s1 = "baa";
    string s2 = "aab";
    cout<<sol.canConstruct(s1,s2)<<endl;
    return 0;
}