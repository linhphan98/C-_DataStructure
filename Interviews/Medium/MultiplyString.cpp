#include <iostream>
#include <map>
#include <string.h>
#include <list>
using namespace std;

class Solution {
private: 
    map<char, int> table;
public:
    void inputTable(){
        for(int i = 0; i < 10; i++){
            table['0' + i] = i;
        }
    }

    string multiply(string num1, string num2) {
        int int1 = 0;
        int int2 = 0;
        while(num1.length() != 0 || num2.length() != 0){
            if(num1.length() == 0){
                int2 = (int2*10) + (num2[0] - '0');
                num2 = num2.substr(1, num2.length()); 
            }else if(num2.length() == 0){
                int1 = (int1*10) + (num1[0] - '0');
                num1 = num1.substr(1,num1.length());
            }else{
                int1 = (int1*10) + (num1[0] - '0');
                int2 = (int2*10) + (num2[0] - '0');
                num1 = num1.substr(1,num1.length());
                num2 = num2.substr(1, num2.length()); 
            }
        }
        
        int multiply = int1*int2;
        list<string> li;
        while(multiply != 0){
            string s(1,(multiply%10) + '0');
            li.push_back(s);
            multiply /= 10;
        }
        string answer;
        while(li.size() != 0){
            answer += li.front();
            li.pop_front();
        }
        return answer;
    }
};

int main(void){
    Solution obj;
    obj.inputTable();
    string answer = obj.multiply("123", "456");
    cout << answer << endl;
    return 0;
}
