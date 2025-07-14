#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        
        // s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
        
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        auto it = std::remove_if(s.begin(), s.end(), [](char const &c) {
            return !std::isalnum(c);
        });
        s.erase(it, s.end());
        cout<<"s: "<<s.length()<<endl;
        if (s.length() <= 1) return true;

        int left = 0;
        int right = s.length()-1;
        while(left < right){
            if (s[left] == s[right]){
                left++;
                right--;
            }
            else return false;
        }
        return true;
    }
};

int main(){
    Solution sol;
    string s = ".";
    // string s = "aa";
    // string s = "A man, a plan, a canal: Panama";
    cout<<sol.isPalindrome(s)<<endl;
    return 0;
}