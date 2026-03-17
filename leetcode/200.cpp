class Solution {
public:
    bool checkCase(vector<vector<int>>& grid, vector<vector<bool>>& visited,int row,int col){

      if(row<grid.size() && row>=0 && col<grid[0].size() && col>=0){
        if(grid[row][col] == '1' && visited[row][col]==false){
           return true;
        }
      }
      return false;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int count = 0;
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
            if(visited[i][j]==false && grid[i][j]=='1'){
              queue<pair<int,int>> q;
              visited[i][j] = true;
              q.push({i,j});

              while (!q.empty()) {
                pair<int,int> curr = q.front();
                q.pop();
                int row = curr.first;
                int col = curr.second;
                if(checkCase(grid,visited,row+1,col)){
                  q.push({row+1,col});
                  visited[row+1][col] = true;
                }
                if(checkCase(grid,visited,row-1,col)){
                  q.push({row-1,col});
                  visited[row-1][col] = true;
                }
                if(checkCase(grid,visited,row,col-1)){
                  q.push({row,col-1});
                  visited[row][col-1] = true;
                }
                if(checkCase(grid,visited,row,col+1)){
                  q.push({row,col+1});
                  visited[row][col+1] = true;
                }
              }
              count++;
            }
          }
        }
        return count;
    }
};
