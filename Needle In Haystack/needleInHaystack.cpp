// loop heystack -> check characters -> if match found -> return first element index ? index out of bound

#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
        int strStr(string haystack, string needle) {
            for(int i = 0;i < haystack.size();i++){
                // cout<<"HAYSTACK elem: "<<haystack[i]<<endl;
                int j = 0;
                for(int k = i;k < haystack.size();k++){
                    if(haystack[k] == needle[j]) j += 1;

                    else break;

                    if(j == needle.size()) return i;
                }
            }
            return -1;
        }
};


int main(){
    Solution sol;
    string haystack = "leetcode";
    string needle = "eet";
    cout<<"OUTPUT: "<<sol.strStr(haystack, needle);
    return 0;
}