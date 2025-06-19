#include <iostream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string output = "";
        int left = s.length();
        int right = s.length();
        for(int i = s.length();i >= 0; i--){
            cout<<"CURRENT LETTER IN LOOP: "<<s[i]<<endl;
            if (s[i] != ' '){
                left = i;
                cout<<"IN if L: "<<s[left]<<endl;
            }

            if(s[i] == ' ' || left == 0){               
                if(left < right){
                    cout<<" IN if->else R: "<<s[right]<<"POS: "<<right<<endl;
                    int temp = left;
                    if (s[left] == ' ') temp = left+1;
                    else temp = left;
                    // append word into string
                    while(temp < right){
                        cout<<"     LETTER: "<<s[temp]<<endl;
                        output += s[temp++];
                    }
                    if(right > left) output += ' ';
                    cout<<" word: "<<output<<output.length()<<endl;
                }
                right = i;
                cout<<" IN if->else R: "<<s[right]<<"POS: "<<right<<endl;
            }
            
        }
        if(output[output.length()-1] == ' ') output = output.erase(output.length()-1);
        return output;
    }
};

int main(){
    Solution sol;
    string str = "  ";
    // string str = "  hello world  ";
    // string str = "the sky is blue";
    string output = sol.reverseWords(str);
    cout<<str.length()<<output<<output.length();
    return 0;
}