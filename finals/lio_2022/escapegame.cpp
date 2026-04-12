#include <bits/stdc++.h>
using namespace std;

int query(vector<int> rooms){
  return find(rooms.begin(), rooms.end(),5);
}
int dfs(int parent, int node,vector<vector<int>>& adj, vector<int>& sub, vector<bool>& currNodes){
  sub[node] = 1;
  for(int var : adj[node]) {
    if(var == parent) continue;
    if(!currNodes[var]) continue;
    dfs(node, var, adj, sub, currNodes);
    sub[node] += sub[var];
  }
  return sub[node];
}
int buildComp(int parent, int node, vector<vector<int>>& adj, vector<int>& comp, vector<bool>& currNodes){
  if(currNodes[node]) comp.push_back(node);
  for(int var : adj[node]) {
    if(var == parent) continue;
    if(!currNodes[var]) continue;
    buildComp(node,var, adj, comp, currNodes);
  }
  return 0;
}
int guess(int N, vector<int> u, vector<int> v) {
  vector<vector<int>> adj(N+1);
  vector<int> sub(N+1);
  vector<bool> currNodes(N+1,true);
  int root = 1;
  for (int i = 0; i < N-1; i++) {
    adj[u[i]].push_back(v[i]);
    adj[v[i]].push_back(u[i]);
  }
  int currSize = N;
  while (currSize>1) {
    dfs(-1, root, adj, sub, currNodes);
    int size= 0;
    int idx = -1;
    for (int i = 0; i <= N; i++) {
      int lsize = sub[i];
      if (size<lsize && lsize<= currSize/2 && currNodes[i]) {
        size = lsize;
        idx = i;
      }
    }
    currSize = size;

    //now we built, check  the comp and set to false all nodes not in the comp
    vector<int> comp;
    buildComp(-1, idx, adj, comp, currNodes);
    if(guess(comp){
        for (int i = 0; i < currNodes.size(); i++) {
        currNodes[i] = false;
        }
        for(auto var : comp) {
        currNodes[var] = true;
        }

        }
        else{
        for(auto var : comp) {
        currNodes[var] = false;
        }
        }
        root = comp[0];


        }
        return 0;
