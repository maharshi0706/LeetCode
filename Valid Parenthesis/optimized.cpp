#include <stack>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution{
public:
    bool isValid(string s) {
        stack<char> parenthesis;
        unordered_map<char, char> parenthesisStore = {
            {'}', '{'},
            {']', '['},
            {')', '('},
        };

        for(int i = 0;i < s.size();i++){
            auto it = parenthesisStore.find(s[i]);
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                parenthesis.push(s[i]);
            }
            else{
                char check = it->second;
                if(parenthesis.empty()) return false;

                if(parenthesis.top() == check) parenthesis.pop();
                
                else return false;
            }
        }

        if (parenthesis.empty()) return true;
        else return false;
    }
};


int main(){
    Solution sol;
    cout<<sol.isValid("([)")<<endl;
    return 0;
}