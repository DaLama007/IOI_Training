class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max=0;

        for (int i = 0; i < grid.size(); i++) {
          for (int j = 0; j < grid[0].size(); j++) {
            if(grid[i][j]==1){
              int local =1;
              queue<int> qR;
              queue<int> qC;
              qR.push(i);
              qC.push(j);

              grid[i][j] = 0;
              while (!qR.empty()) {
                int row = qR.front();
                int col = qC.front();

                qR.pop();
                qC.pop();

                int cols[]={col,col,col+1,col-1};
                int rows[]={row+1,row-1,row,row};

                for(int o=0;o<4;o++){
                  int cc = cols[o];
                  int cr = rows[o];
                  if(cr>-1 && cr<grid.size() && cc>-1 && cc<grid[0].size()){

                    if(grid[cr][cc]==1){
                      local++;
                      grid[cr][cc] = 0;
                      qR.push(cr);
                      qC.push(cc);
                    }
                  }
                }
              }
              if(max<local){
                max=local;
              }
            }
          }
        }
        return max;
    }
};
