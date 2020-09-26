#include <iostream>
using namespace std;

int main(void){
    int input;
    int answer = 0;
    do{
        cin >> input;
        answer += input;
    }while(input != -1);
    cout << answer+1 << endl;
    return 0;
}