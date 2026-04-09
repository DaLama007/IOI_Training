#include <bits/stdc++.h>
using namespace std;

struct Road{
  int node;
  int type;
  int length;
};

int main (int argc, char *argv[]) {
  int n,r,p;
  cin>>n>>r>>p;
  vector<vector<Road>> nodes(n+1);

  //set priority with its sorting
  auto cmp = [](const Road &a, const Road &b) {
    if (a.type != b.type) return a.type > b.type; // rural first
    return a.length > b.length; // smaller length first
  };
  priority_queue<Road, vector<Road>, decltype(cmp)> prioQ(cmp);
  set<int> connected;
  for (int i = 0; i < r; i++) {
    int u,v,l;
    cin>>u>>v>>l;
    nodes[u].push_back({v, 0, l});
    nodes[v].push_back({u, 0, l});
  }
  for (int i = 0; i < p; i++) {
    int u,v,l;
    cin>>u>>v>>l;
    nodes[u].push_back({v, 1, l});
    nodes[v].push_back({u, 1, l});
  }

  //lets start by adding the first node
  int sum = 0;
  int permits = 0;
  connected.insert(1);
  //and all its edges to prio queue
  for(Road ro: nodes[1]) {
    prioQ.push(ro);
  }
  //nnw we loop, steps are:
  // 1. get best edge
  // 2. select that node
  // 3. push all its edges
  while (connected.size()<n) {

    while (!prioQ.empty() && connected.contains(prioQ.top().node)) {
      prioQ.pop();
    }
    if(prioQ.empty()) break;
    Road road = prioQ.top();
    prioQ.pop();
    if(road.type == 1) permits++;
    sum += road.length;
    connected.insert(road.node);
    for(Road ro: nodes[road.node]) {
      if (!connected.contains(ro.node)) {
        prioQ.push(ro);
      }
    }
  }
  cout<< permits <<" "<< sum <<"\n";
  return 0;
}
