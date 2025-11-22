#include <iostream>
using namespace std;

class Solution{
public:

    string expansion(int left, int right,const string &s){
        // EXPAND IF SIMILAR CHARACTER
        while(left >= 0 && right < s.size() && s[left] == s[right]){ 
            left--;
            right++;
            
            // REDUNDANT PALINDROME CHECK AS MAIN WHILE LOOP ENSURES PALINDROME
            
            // int tempLeft = left;
            // int tempRight = right;
            // while(tempLeft < tempRight){
            //     if(s[tempLeft++] != s[tempRight--]) break;
            // }
        }
        return s.substr(left+1, right - left - 1); // left offset, length
    }
    
    string longestPalindrome(string s) {
        string mainLongestSubstr = "";
        for(int mid = 0;mid < s.size();mid++){
            // Expand for odd lengths
            string oddStr = expansion(mid,mid,s);
            // Expand for even lengths
            string evenStr = expansion(mid,mid+1,s);
            mainLongestSubstr = oddStr.size() > mainLongestSubstr.size() ? oddStr : mainLongestSubstr;
            mainLongestSubstr = mainLongestSubstr.size() > evenStr.size() ? mainLongestSubstr : evenStr;
        }
        return mainLongestSubstr;
    }
};


int main(){
    Solution sol;
    cout<<sol.longestPalindrome("babad")<<endl;
    return 0;
}