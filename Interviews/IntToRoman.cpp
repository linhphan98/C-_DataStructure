#include <iostream>
#include <map>
#include <string.h>
#include <list>
using namespace std;

class Solution {
private: 
    map<int, char> romanNum; 
    string answer; 
    list<int> keys;
    list<int>::iterator it;
public:
    void inputNum(){
        romanNum[1] = 'I';
        romanNum[5] = 'V';
        romanNum[10] = 'X';
        romanNum[50] = 'L';
        romanNum[100] = 'C';
        romanNum[500] = 'D';
        romanNum[1000] = 'M';
        for(auto x : romanNum){
            keys.push_back(x.first);
        }
    }

    string intToRoman(int num) {
        switch(num){
            case 4:
                answer +=  "IV";
                return answer;
            case 9:
                answer +=  "IX";
                return answer;
            case 40:
                answer +=  "XL";
                return answer;
            case 90:
                answer +=  "XC";
                return answer;
            case 500:
                answer +=  "CD";
                return answer;
            case 900:
                answer +=  "CM";
                return answer;
        }

        it = keys.begin();
        while(num > *it){
            it++;
        }
        if(*it == num){
            answer += romanNum[num];
            return answer;
        }
        it--;
        answer += romanNum[*it];
        string temp = intToRoman(num - *it);
        return answer;
    }
};

int main(void){
    Solution obj;
    obj.inputNum();
    string output = obj.intToRoman(29);
    cout << output << endl;
    return 0;
}