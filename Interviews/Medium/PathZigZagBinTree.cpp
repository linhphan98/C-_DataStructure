#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> pathInZigZagTree(int label){
    vector<int> answer; 
    if(label == 1){
        return {1};
    }
    if(label >= 1 and label <= 1000000){
        vector<int> array;
        array.push_back(1);
        int level = 1;
        int i = 1;
        int count = 1;

        while(i < label){
            if((level-1) % 2 == 0){
                for(int x = i + pow(2,level); x > i; x--){
                    if(x == label){
                        break;
                    }
                    array.push_back(x);
                    count++;
                }
                i += pow(2,level);
            }else if((level-1) % 2 != 0){
                for(int x = 1; x <= pow(2,level); x++){
                    if((i + x) == label){
                        break;
                    }
                    array.push_back(i + x);
                    count++;
                }
                i += pow(2,level);
            }
            level++;
        }
        answer.push_back(label);
        while(count > 0){
            if(count%2 == 0){
                count = (count - 2)/2;
                answer.insert(answer.begin(), array[count]);
            }else if(count%2 != 0){
                count = (count - 1)/2;
                answer.insert(answer.begin(), array[count]);
            }
        }
    }
    return answer;
}

int main(void){
    vector<int> answer = pathInZigZagTree(2);
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
    return 0;
}