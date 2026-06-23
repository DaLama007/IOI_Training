#include <bits/stdc++.h>
using namespace std;

int far(int node,int n, vector<vector<int>> &adj){
  vector<int> dist(n+1, -1);
  queue<int> q;
  q.push(node);
  dist[node] = 0;
  while (!q.empty()) {
    int parent = q.front();
    q.pop();
    for (int i = 0; i < adj[parent].size(); i++) {
      int child = adj[parent][i];
      if(dist[child] !=-1) continue;
      q.push(child);
      dist[child] = dist[parent]+1;
    }
  }
  
  int maxDis = dist[1];
  for (int i = 2; i < n; i++) {
    maxDis = max(maxDis, dist[i]);
  }
  return maxDis;
}
int main (int argc, char *argv[]) {
  int n; cin >> n;
  vector<vector<int>> adj(n+1);

  for (int i = 0; i < n-1; i++) {
    int f,s; cin >> f >> s;
    adj[f].push_back(s);
    adj[s].push_back(f);
  }

  for (int i = 1; i <= n; i++) {
    int res = far(i, n, adj);
    cout << res << " ";
  }
  return 0;
}
