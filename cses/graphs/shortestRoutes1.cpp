#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
  int n, m; cin >> n >> m;
  vector<vector<tuple<int,int,int>>> adj(n+1);
  vector<bool> visited(n+1);
  vector<int> dist(n+1);

  for (int i = 0; i < m; i++) {
    int a,b,cost; cin >> a >> b >> cost;
    adj[a].push_back(make_tuple(cost, b, i));
  }

  vector<int> result;

  priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;

  for(tuple<int,int,int> ed: adj[1]) {
    pq.push(ed);
  }
  visited[1] = true;

  while (!pq.empty()) {
    auto [cost, b, i] = pq.top();
    pq.pop();
    if(!visited[b]){
      visited[b] = true;
      dist[]
      for(tuple<int,int,int> var : adj[b]) {
        pq.push(var);
      }
    }
  }

  for(int var: dist) {
    cout << var << " ";
  }

  return 0;
}
