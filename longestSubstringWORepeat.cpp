#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> str;
        int left = 0;
        int right = 0;
        int currCount = 0;
        int maxSubstringCount = 0;
        while(right < s.length()){
            cout<<"CURR VAL: "<<s[right]<<endl;
            if(str.count(s[right]) == 0)  str.insert(s[right]);
            else if(str.count(s[right]) == 1){
                cout<<" IN IF"<<endl;
                while(left <= right){
                    str.erase(s[left]);
                    cout<<"     IN WHILE"<<endl;
                    if(s[left] == s[right]) {
                        cout<<"         IN IF WHILE IF"<<endl;
                        left++;
                        break;
                    }
                    left++;
                }
            }
            str.insert(s[right]);
            // currCount = right-left+1;
            cout<<"Left pos: "<<left<<" CURRCOUNT: "<<right-left+1<<endl;
            maxSubstringCount = max(maxSubstringCount, right-left+1);
            right++;
            cout<<"Right pos: "<<right<<endl;
        }
        return maxSubstringCount;
    }
};

int main(){
    Solution sol;
    string s = "bbbbb";
    // string s = "pwwkew";
    // string s = "dvdf";
    cout<<sol.lengthOfLongestSubstring(s)<<endl;
    return 0;
}
// while(left <= right && right < s.length()){
    //     if(subStr.count(s[right]) == 0){
//         subStr.insert(s[right]);
//         right++;
//     }
//     else{
    
//     }
// }

// unordered_set<char> subStr;
// int left = 0;
// int right = 0;
// int maxSubstringCount = 0;
// for(right = 0;right < s.length();right++){
//     cout<<"\nRIGHT: "<<right<<endl;
//     cout<<"element : "<<s[right]<<endl;
//     // if duplicate value NOT PRESENT
//     if(subStr.count(s[right]) == 0) {
//         subStr.insert(s[right]);
//         cout<<"added: "<<endl;
//     }
//     else{
//         // auto it = subStr.find(s[right]);
//         // if(it != subStr.end()) subStr.erase(it);
//         // subStr.clear();
        
//     }
//     cout<<"CURR SIZE: "<<subStr.size()<<endl;
//     maxSubstringCount = max(static_cast<size_t>(maxSubstringCount), subStr.size());
//     cout<<"MAX COUNT: "<<maxSubstringCount<<endl;
// }
// return maxSubstringCount;