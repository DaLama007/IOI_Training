class Solution {
  public:
    int orangesRotting(vector<vector<int>>& grid) {
      queue<pair<int,int>> rot;
      int freshCount =0;
      for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
          
          if(grid[i][j] == 1){
            freshCount++;
          }
          else if(grid[i][j] == 2){
            rot.push({i,j});
          }
        }
      }
      if (freshCount!=0 && rot.size()==0) {
        return -1;
      }
      if (rot.size()==0) {
        return 0;
      }
      int min =-1;
      while (!rot.empty()) {
        int s = rot.size();
        for (int r = 0; r < s; r++) {
          pair<int,int> fruit = rot.front();
          rot.pop();
          grid[fruit.first][fruit.second] = 2;
          int cr = fruit.first;
          int cc = fruit.second;int fruits[4][2] = {
            {cr, cc+1},
            {cr, cc-1},
            {cr-1, cc},
            {cr+1, cc}
          };
          for (int i = 0; i < 4; i++) {
            int row = fruits[i][0];
            int col = fruits[i][1];

            if (row<grid.size() && row>-1 && col<grid[0].size() && col>-1) {

              if (grid[row][col]==1) {
                rot.push({row,col});
                grid[row][col]=2;
              }
            }
          }
        }
        min++;
      }
      int count = 0;
      for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
          if(grid[i][j] == 1){
            count++;
          }
        }
      }
      if (count==0) {
        return min;
      }
      else{
        return -1;
      }

    }
};
