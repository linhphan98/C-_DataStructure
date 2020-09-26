#include <iostream>
#include <map>
#include <string.h>
#include <math.h>
using namespace std;

class Solution {
public:
    int kthGrammar(int N, int K) {
        if(N > 30) return 0;
        if(K > pow(2, (N-1))) return 0;
        map<char, string> table;
        table['0'] = "01";
        table['1'] = "10";

        string value = "0";
        int row = 0;
        while(row < N-1){
            string temp = value;
            
            if(row == 0) {
                value.clear();
                value += table[temp[row]];
            }else{
                int half = value.length()/2;
                string first = temp.substr(0,half);
                string second = temp.substr(half, temp.length());
                
                value += (second+first);
            }
            
            row++;
        }
        return value[K-1] - '0';
    }
};  
int main(void){
    Solution obj; 
    int answer = obj.kthGrammar(30,12);
    cout << answer;
    return 0;
}