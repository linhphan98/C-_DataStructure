#include <iostream>
#include <vector>
#include <map>
#include <string.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
        map<char, int> table;
        for(int i = 0; i < board.size(); i++){
            for(int x = 0; x < board[i].size(); x++){
                if(table[board[i][x]] != 0){
                    table[board[i][x]]++;
                }else {
                    table[board[i][x]] = 1;
                }
            }
        }
        
        int count = word.length();
        while(word.length() != 0){
            if(table[word[0]] != 0){
                count--;
                table[word[0]]--;
            }
            word = word.substr(1, word.length());
        }
        if(count == 0){
            return true;
        }else{
            return false;
        }
    }
};

int main(void){
    vector<vector<char> > board; 
    for(int i = 0; i < 3; i++){
        vector<char> temp;
        switch(i){
            case 0:
                temp.push_back('A');
                temp.push_back('B');
                temp.push_back('C');
                temp.push_back('E');
                board.push_back(temp);
            break;
            case 1:
                temp.push_back('S');
                temp.push_back('F');
                temp.push_back('C');
                temp.push_back('S');
                board.push_back(temp);
            break;
            case 2:
                temp.push_back('A');
                temp.push_back('D');
                temp.push_back('E');
                temp.push_back('E');
                board.push_back(temp);
            break;
        }
    }

    Solution obj; 
    bool ans = obj.exist(board, "ABCB");
    cout << ans << endl;

    return 0;
}