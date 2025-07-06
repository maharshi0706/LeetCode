#include<iostream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::istringstream iss(s);
        std::vector<std::string> words;
        std::string word;
        while (iss >> word) {
            words.push_back(word);
        }
        if(pattern.size() != words.size()) return false;

        unordered_map<char,string> characToWordMap;
        unordered_map<string, char> wordToCharMap;
        for(int i = 0;i < pattern.size();i++){
            char c = pattern[i];
            string word = words[i];
            
            if(characToWordMap.count(c) && characToWordMap[c] != word) return false;
            else characToWordMap[c] = word;
            
            if(wordToCharMap.count(word) && wordToCharMap[word] != c) return false;
            else wordToCharMap[word] = c;
        }
        return true;

        
    }
};


int main(){
    Solution sol;
    string pattern = "aaaa";
    string s = "dog cat cat";
    cout<<sol.wordPattern(pattern,s)<<endl;
    return 0;
}