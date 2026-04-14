#include "bits/stdc++.h"
using namespace std;
struct Edge{
  int p;
  int n;
  int l;
};

//compare object with function for prio queue
struct EdgeCompare{
  bool operator() (const Edge& e1, const Edge& e2) const{
    return e1.l>e2.l;
  }
};
int main (int argc, char *argv[]) {
  int N, M , Q;
  cin>> N >> M >> Q;

  vector<vector<Edge>> nodes(N+1);
  for (int i = 0; i < M; i++) {
    int n1, n2, li;
    cin>> n1 >> n2 >> li;

    nodes[n1].push_back({n1,n2,li});
    nodes[n2].push_back({n2,n1,li});
  }
  vector<pair<int,int>> interest;
  for (int i = 0; i < Q; i++) {
    int s, t;
    cin>>s>>t;
    interest.push_back({s,t});
  }
  vector<bool> visited(N+1, false);
  priority_queue<Edge, vector<Edge>, EdgeCompare> pq;
  vector<vector<Edge>> ng(N+1);
  for(Edge var : nodes[1]) {
    var.p = 1;
    pq.push(var);
  }
  while (!pq.empty()) {
    Edge top = pq.top();
    pq.pop();
    if(visited[top.n]) continue;
    ng[top.p].push_back(top);
    ng[top.n].push_back({top.n, top.p, top.l});
    for(Edge var : nodes[top.n]) {
      var.p = top.n;
      pq.push(var);

    }
    visited[top.n] = true;
  }
  for (int i = 0; i < Q; i++) {
    pair<int,int> station = interest[i];
    queue<pair<int,int>> q;
    vector<bool> visited2(N+1, false);
    q.push({0, station.first});
    visited2[station.first] = true;
    bool found = false;
    while (!q.empty()) {
      pair<int,int> f = q.front();
      q.pop();
      for(Edge var : ng[f.second]) {
        if(visited2[var.n])continue;
        int dist = max(f.first,var.l);
        if (var.n == station.second) {
          cout<<dist<<"\n";
          found = true;
          break;
        }
        q.push({dist, var.n});
        visited2[var.n] = true;
      }
      if(found) break;
    }
  }

  return 0;
}
