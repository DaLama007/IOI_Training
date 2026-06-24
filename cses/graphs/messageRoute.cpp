#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
  int n,m; cin >> n >> m;
  vector<vector<int>> adj(n+1);
  vector<int> dist(n+1, INT_MAX);
  vector<int> parent(n+1);

  for (int i = 0; i < m; i++) {
    int f, s; cin >> f >> s;
    adj[f].push_back(s);
    adj[s].push_back(f);
  }
  dist[1] = 0;
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for(int var : adj[node]) {
      if(dist[var] == INT_MAX){
        parent[var]=node;
        dist[var]=dist[node]+1;
        q.push(var);
      }
    }
  }

  if(dist[n]== INT_MAX) cout << "IMPOSSIBLE" << "\n";
  else {
    vector<int> route;
    for (int cur = n; cur !=1; cur = parent[cur])route.push_back(cur);
    route.push_back(1);
    reverse(route.begin(), route.end());
    //lets print
    int minDis = dist[n];
    cout<<minDis+1<<"\n";
    for(int comp: route) {
      cout << comp << " ";
    }
  }

  return 0;
}
