#include <iostream>
using namespace std;

int calculate(int step, int num){
    if(num == 0) return step;
    if(num%2 == 0){
        step++;
        return calculate(step, num/2);
    }
    step++;
    return calculate(step, num-1);
}

class Solution {
public:
    int numberOfSteps (int num) {
        return calculate(0,num);
    }
};

int main(void){
    Solution obj;
    int answer = obj.numberOfSteps(123);
    cout << answer;
    return 0;
}