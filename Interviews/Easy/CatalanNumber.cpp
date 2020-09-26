#include <iostream>

using namespace std;
int catalan(int value){
    if(value <= 1) return 1;
    int result = 0;
    for(int i = 0; i < value; i++){
        result += catalan(i)*catalan(value - i - 1);
    }
    return result;
}

int main(void){
    for(int i = 1; i <= 10; i++){
        cout << catalan(i) << " ";
    }
    cout << endl;
    return 0;
}