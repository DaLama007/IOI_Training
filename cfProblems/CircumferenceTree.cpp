#include "bits/stdc++.h"
using namespace std;

struct Node{
  vector<int> otherNodes;
  int dist;
};

int dfs(int node, vector<Node>& edges){
  queue<Node> bfs;
  for(int i = 0; i< edges.size(); i++) edges[i]. dist = -1;
  edges[node].dist = 0;
  bfs.push();
  while (!bfs.empty()) {
    Node n =  bfs.front;
    bfs.pop();

    for(int in: edges[n].otherNodes) {
      if(edges[in].dist == -1){

      edges[in].dist = 1+ n.dist;
      queue.push()

    }
  }

  return 0;
}



int find(int num, vector<Node>& edges){
  int m = 1;
  for (int i = 2; i <= num; i++) {
    if(edges[m].dist<edges[i].dist) m = i;
  }
  return m;
}

int main (int argc, char *argv[]) {
  int n; cin >> n;
  vector<Node> edges(n+1);
  queue<int> q;

  for (int i = 0; i < n-1; i++) {
    int f,s; cin >> f; cin >> s;
    edges[s].otherNodes.push_back(f);
    edges[f].otherNodes.push_back(s);
  }

  //first dfs
  dfs(edges[0], edges);
  int m = find(n, edges);
  dfs(edges[m], edges);
  int res = find(n, edges);

  cout << res*3 << "\n";

  return 0;
}
