#include <bits/stdc++.h>
using namespace std;

  int getFar(bool getSize, int node, vector<vector<int>> &adj, vector<int> &dist){
  queue<int> q;
  q.push(node);

  fill(dist.begin(), dist.end(), -1);
  dist[node] = 0;
  while(!q.empty()){
    int n = q.front();
    q.pop();
    for (int i = 0; i < adj[n].size(); i++) {
      if(dist[adj[n][i]] != -1) continue;
      q.push(adj[n][i]);
      dist[adj[n][i]] = dist[n]+1;
    }
  }
  int md = node;
  for (int i = 1; i < dist.size(); i++) {
     if(dist[md]<dist[i]) md = i;
  }
  if (getSize) {
    return dist[md];
  }
  return md;
}

int main (int argc, char *argv[]) {
  int n; cin >> n;
  vector<vector<int>> adj(n+1);
  vector<int> dist(n+1);

  for (int i = 0; i < n-1; i++) {
    int f, s; cin >> f >> s;
    adj[f].push_back(s);
    adj[s].push_back(f);
  }

  int n1 = getFar(false, 1, adj, dist);

  int dia= getFar(true, n1, adj, dist);

  cout << dia << "\n";
  return 0;
}
