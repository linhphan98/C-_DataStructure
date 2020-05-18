#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

class Solution {
public:
    int toBin(string a){
        int aNum = 0;
        for(int i = 0; i < a.length(); i++){
            if(a[i] == '1'){
                aNum += pow(2, a.length() - 1 - i);
            }
        }
        return aNum;
    }
    string addBinary(string a, string b) {
        string answer = "";
        int aNum = 0;
        int bNum = 0;
        if(a[0] == '0' || b[0] == '0') return answer;
        if(a.length() < 1 or a.length() >= pow(10,4)) return answer;
        if(b.length() < 1 or b.length() >= pow(10,4)) return answer;

        aNum = toBin(a);
        bNum = toBin(b);
        int count = 7;
        int sum = aNum + bNum;
        while(sum != 0 || count > -1){
            if(pow(2,count) <= sum) {
                sum -= pow(2,count);
                answer += "1";
            }else{
                answer += "0";
            }
            count--;    
        }
        answer = answer.substr(answer.find("1"), answer.length());
        return answer;
    }
};

int main(void){
    Solution obj;
    string answer = obj.addBinary("1010", "1011");
    cout << answer << endl;
    return 0;
}