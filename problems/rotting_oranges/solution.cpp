/**
visited? 
**/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //visited table
        int n_rows = grid.size();  //2
        int n_cols = grid[0].size(); //2
        
        vector<vector<int>> visited(n_rows, vector<int>(n_cols, false));
        
        int minute = 0;
        
        queue<int> q_x;
        queue<int> q_y;
        
        // note: count all the fresh oranges.
        int fresh = 0;
        
        for (int row = 0; row < n_rows; row++){
            for (int col = 0; col < n_cols; col++){
                // find the first rotten [0, 0]
                if (grid[row][col] == 2 ){
                    // queue
                    q_x.push(col);
                    q_y.push(row);
                    
                    visited[row][col] = true;
                }
                if (grid[row][col] == 1) fresh++;
                
            }
        }
        
        //if no fresh at all
        if (fresh == 0 ) return 0;
        
        vector<int> x_dir{0, 0, -1, 1};
        vector<int> y_dir{-1, 1, 0, 0};
        

        while (!q_x.empty()){
            ++minute;
            int size = q_x.size(); // 1
            for (int count = 0; count < size; count ++){
                int x = q_x.front();
                int y = q_y.front();
                q_x.pop();
                q_y.pop();
                // [0,0]
                // for neighbor ->q: [[[0,1], [1, 0]]
                for (int i = 0; i < 4; i++){
                    int x_new = x + x_dir[i];
                    int y_new = y + y_dir[i];

                    //inbound?
                    if (!inBound(x_new, y_new, n_rows, n_cols)) continue;

                    // visited?
                    if (visited[y_new][x_new]) continue;
                    visited[y_new][x_new] = true;

                    // [0, 1]
                    if (grid[y_new][x_new] == 0) continue; //empty
                    q_x.push(x_new);
                    q_y.push(y_new);
                    if (grid[y_new][x_new] == 1){ // fresh
                        grid[y_new][x_new] = 2; // fresh -> bad
                    } // q[[0, 1]]
                }
            }
        }
        
        minute--;
        for (int row = 0; row < n_rows; row++){
            for (int col = 0; col < n_cols; col++){
                if (grid[row][col] == 1) return -1;
            }
        }
        return minute;
    }
    
    bool inBound(int x_new, int y_new, int n_rows, int n_cols){
        return x_new >= 0 && x_new < n_cols && y_new >=0 && y_new < n_rows;
    }
};