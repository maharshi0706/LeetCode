#include <iostream>
#include <unordered_set>
using namespace std;

class Solution{
public:
    int lengthOfLongestSubstring(string s){
        unordered_set<int> charVisited;
        int left = 0;
        int right = 0;
        int maxCount = 0;
        while(right < s.length()){
            if(charVisited.find(s[right]) == charVisited.end()){
                charVisited.insert(s[right]);
                maxCount = max(maxCount, right-left+1);
                right++;
            }
            else{
                charVisited.erase(s[left]);
                left++;
            }
        }
        return maxCount;
    }    
};

int main(){
    Solution sol;
    int len = sol.lengthOfLongestSubstring("abcabcbb");
    cout<<len<<endl;
    return 0;
}