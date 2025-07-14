#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        int lengthOfLastWord(string s) {
            
            if (s.length() == 1 && s[0] != ' ') return 1;
            int count = 0;
            int loopIdx = s.size()-1;
            // char lastCharacter = s[s.length()-1];
            
            // int loopIdx = (lastCharacter == ' ') ? s.length() - 2 : s.length()-1;

            
            // while loopIdx != 0:
            //     if s[loopIdx] == ' ':
            //         loopIdx--;
            cout<<"loopIdx: "<<loopIdx<< " "<<s[loopIdx]<<endl;
            while (loopIdx > 0){
                if (s[loopIdx] == ' ') loopIdx -= 1;
                else break;
            }
            
            if (loopIdx == 0 && s[loopIdx] == ' '){
                return count;
            }
            
            cout<<"S len value: "<<s[s.size()]<<endl;
            cout<<"LOOP IDX value: "<<s[loopIdx]<<endl;
            
            for(int i = loopIdx; i>= 0; i--){
                cout<<"CHAR: "<<s[i]<<endl;
                if (s[i] == ' '){ break;}
                count += 1;
            }
            
            return count;
        }
};

int main(){
    Solution soln;
    string check = "Hello world";
    // string check = "   fly me   to   the moon      ";
    int result = soln.lengthOfLastWord(check);
    cout<<"OUTPUT: " << result << endl;
}