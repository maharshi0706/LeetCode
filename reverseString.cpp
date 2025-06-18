#include <iostream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string output = "";
        int left = s.length();
        int right = s.length();
        for(int i = s.length()-1;i >= 0; i--){
            cout<<"CURRENT LETTER IN LOOP: "<<s[i]<<endl;
            if(s[i] == ' '){
                if(right <= left) {
                    cout<<" IN if->if R: "<<s[right]<<" L: "<<s[left]<<endl;
                    right--;
                }
                
                else{
                    cout<<" IN if->else R: "<<s[right]<<" L(before): "<<s[left]<<endl;
                    int temp = -1;
                    if (s[left] == ' ') temp = left+1;
                    else temp = left;
                    // append word into string
                    while(temp < right){
                        output += s[temp++];
                    }
                    if(right > left) output += ' ';
                    right = i;
                    cout<<" IN if->else R: "<<s[right]<<" L(after): "<<s[left]<<endl;
                    cout<<" word: "<<output<<endl;
                }
            }
            
            if (s[i] != ' '){
                left = i;
                cout<<"IN if L: "<<s[left]<<endl;
                if(left == 0 && right > 0){
                    int temp = left;
                    while(temp < right){
                        output += s[temp++];
                    }
                }
            }
        }
        return output;
    }
};

int main(){
    Solution sol;
    string str = "  hello world  ";
    // string str = "the sky is blue";
    string output = sol.reverseWords(str);
    cout<<str.length()<<output<<output.length();
    return 0;
}