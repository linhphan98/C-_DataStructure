// Input: [[1],[2],[3],[]]
// Output: true
// Explanation:  
// We start in room 0, and pick up key 1.
// We then go to room 1, and pick up key 2.
// We then go to room 2, and pick up key 3.
// We then go to room 3.  Since we were able to go to every room, we return true.
// Input: [[1,3],[3,0,1],[2],[0]]
// Output: false
// Explanation: We can't enter the room with number 2.
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        if(rooms.size() < 1 or rooms.size() > 1000) return false;
        map<int, int> keys;
        for(int i = 0; i < rooms[0].size(); i++){
            keys[rooms[0][i]] = 1;
        }
        map<int,int>::iterator it;
        for(it = keys.begin(); it!=keys.end(); it++){
            if(rooms[it -> first].size() == 0) continue;
            for(int i = 0; i < rooms[it -> first].size(); i++){
                if(keys[rooms[it -> first][i]] == 0) {
                    keys[rooms[it -> first][i]] = 1;
                }
            }     
        }
        for(int i = 1; i < rooms.size(); i++){
            if(keys[i]==0) return false;
        }
        return true;
    }
};