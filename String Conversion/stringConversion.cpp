#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(s.length() < numRows || numRows == 1) return s;
        
        vector<string> outputStr(numRows);
        int numOfColumns = numRows - 2;
        int i = 0;
        int count = 0;
        int diagCount = numOfColumns;
        while(i < s.length()){
            if( i % (numRows+numOfColumns) == 0) {
                count = 0;
                diagCount = numOfColumns;
            }

            if(count < numRows){
                outputStr[count] += s[i];
                count += 1;
            }
            else {
                outputStr[diagCount] += s[i];
                diagCount -= 1;
            }
            
            i++;
        }
        string finalOutput = "";
        for(auto str: outputStr){
            finalOutput += str;
        }
        return finalOutput;
    }
};

int main(){
    Solution sol;
    string s = "ABCD";
    // string s = "PAYPALISHIRING";
    int numRows = 3;
    cout<<sol.convert(s, numRows)<<endl;
    return 0;
}



// string output = "";
// int columns = numRows - 2;
// for(int i = 0;i < s.length();i++){
//     if(s[i] == '_') continue;

//     // output += s[i];
//     int skip = 0;
//     int idx = i;
//     numRows = numRows - 1;
//     if(numRows >= 0 && columns >= 0) skip = (numRows + columns);
    

//     cout<<"ROWS: "<<numRows<<" COLUMNS: "<<columns<<" Current letter: "<<s[i]<<" SKIP: "<<skip<<endl;

//     while(true){
//         cout<<"idx+skip: "<<idx+skip<<endl;
//         if((idx) < s.length()){
//             cout<<"     letter added: "<<s[idx]<<endl;
//             output += s[idx];
//             s[idx] = '_';
//             // if((idx+skip+1 < s.length()) && (s[idx+skip+1] == '_') && (s[idx+skip+2] != '_')){
//                 //     output+=s[idx+skip+2];
//                 // }
//                 idx += skip+1;
//             }
//             else {
//                 idx = i;
//                 break;
//             }
//         }
//         cout<<"Current output: "<<output<<endl;
//         columns -= 1;
//         // numRows -= 1;
        
//     }
// output.erase(std::remove(output.begin(), output.end(), '_'), output.end());
// return output;