#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        for(int i = 1; i < barcodes.size(); i++){
            if(barcodes[i-1] == barcodes[i]){
                int count = 1;
                while(barcodes[(i + count)%barcodes.size()] == barcodes[i - 1]){
                    count++;
                }
                int temp = barcodes[i];
                barcodes[i] = barcodes[(i + count)%barcodes.size()];
                barcodes[(i + count)%barcodes.size()] = temp;
                if(i+count >= barcodes.size()) i = (i+count)%barcodes.size();
            }
        }
        return barcodes;
    }
};

int main(void){
    vector<int> barcodes;
    barcodes.push_back(2);
    barcodes.push_back(1);
    barcodes.push_back(1);



    Solution obj; 
    vector<int> answer = obj.rearrangeBarcodes(barcodes);

    for(int i = 0; i < barcodes.size(); i++){
        cout << answer[i] << " ";
    }
    return 0;
}