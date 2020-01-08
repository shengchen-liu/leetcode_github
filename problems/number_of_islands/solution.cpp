/**

**/

class Solution {
public:
    bool inBound(int row, int col, int n_rows, int n_cols){
        return row >=0 && row < n_rows && col >= 0 && col < n_cols;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int n_rows = grid.size();  //4
        int n_cols = grid[0].size();  //5
        
        vector<vector<bool>> visited(n_rows, vector<bool>(n_cols, false));
        
        // top, bottom, left, right
        vector<int> x_dir {0, 0, -1, 1};
        vector<int> y_dir {-1, 1, 0, 0};
        
        int count  = 0;
        
        for (int row = 0; row < n_rows; row++){
             for (int col = 0; col < n_cols; col++){
                 // has the node been visited?
                 if (visited[row][col]) continue;
                 visited[row][col] = true;
                 if(grid[row][col] == '0') continue;  // is it land?
                 count++;
                 queue<int> q_x;
                 queue<int> q_y;

                 q_x.push(col);
                 q_y.push(row);
                 
                 while (!q_x.empty()){
                     int x = q_x.front();
                     int y = q_y.front();
                     q_x.pop();
                     q_y.pop();
                     //find adjacent nodes
                     for (int i = 0; i < 4; i++){
                        int new_row = y + y_dir[i];
                        int new_col = x + x_dir[i];

                        // is adj inBound?
                        if (!inBound(new_row, new_col, n_rows, n_cols)) continue;

                        // is adj node visited?
                        if (visited[new_row][new_col]) continue;
                        visited[new_row][new_col] = true;
                         
                        // is it land?
                        if (grid[new_row][new_col] == '0') continue;

                        //push into the queue
                         q_x.push(new_col);
                         q_y.push(new_row);
                     }
                  }

                 

             }
        }
        return count;
                        
    }

};