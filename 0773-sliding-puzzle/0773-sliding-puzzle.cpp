class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        for(int i = 0;i<2;i++){
            for(int j=0;j<3;j++){
                start += to_string(board[i][j]);
            }
        }

        string target = "123450"; 

        queue<string> q;
        q.push(start);

        unordered_map<int, vector<int>> mp;
        // 0 kon kon si position se swap ho sakhta hai
        mp[0] = {1,3};
        mp[1] = {0,2,4};
        mp[2] = {1,5};
        mp[3] = {0,4};
        mp[4] = {1,3,5};
        mp[5] = {2,4};

        unordered_set<string> visited;
        visited.insert(start);

        int level = 0; // shortest steps needed 

        while(!q.empty()){
            int n = q.size();
            // iss level me jitne element hai sabko process karna hai
            while(n--){
                string curr = q.front();
                q.pop();

                if(curr == target){
                    return level;
                }

                int index_of_zero = curr.find('0'); // finding index of 0
                for(int swap_idx :mp[index_of_zero]){
                    string new_state = curr;
                    swap(new_state[index_of_zero], new_state[swap_idx]);
                    if(visited.find(new_state) == visited.end()){
                        visited.insert(new_state);
                        q.push(new_state);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};