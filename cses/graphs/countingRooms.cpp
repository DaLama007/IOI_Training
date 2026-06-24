#include <bits/stdc++.h>
using namespace std;

void flood(int row, int col,vector<string> &map, vector<vector<bool>> &visited){
  if(row>=map.size() || col>=map[0].size() || 
      row<0 || col<0 ||visited[row][col] || map[row][col] == '#') return;
  visited[row][col] = true;
  flood(row+1, col, map, visited);
  flood(row-1, col, map, visited);
  flood(row, col+1, map, visited);
  flood(row, col-1, map, visited);
}
int main (int argc, char *argv[]) {
  int n, m ; cin >> n >> m;
  vector<string> map(n);
  vector<vector<bool>> visited(n, vector<bool>(m));
  for (int  i = 0; i < n; i++) {
    cin >> map[i];
  }

  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if(map[i][j] != '#' && visited[i][j] == false) {
        flood(i,j, map, visited);
        sum+=1;
      }
    }
  }

  cout << sum <<"\n";
  return 0;
}
