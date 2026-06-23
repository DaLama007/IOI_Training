#include "bits/stdc++.h"
using namespace std;

int timer = 0;

void euler(int node, vector<vector<int>> &sub, vector<int> &start, vector<int> &end){
  start[node] =  timer ++;

  for (int i = 0; i < sub[node].size(); i++) {
    euler(sub[node][i], sub, start, end);
  }

  end[node] = timer;
}
int main (int argc, char *argv[]) {
  int n; cin >> n;
  vector<vector<int>> sub(n+1);
  vector<int> start(n+1);
  vector<int> end(n+1);

  for (int i = 2; i < n+1; i++) {
    int b; cin >> b;
    sub[b].push_back(i);
  }
  
  euler(1,sub, start, end);

  for (int i = 1; i < n+1; i++) {
    int result = end[i] - start[i] -1;
    cout << result << " ";
  }

  return 0;
}
