#include <bits/stdc++.h>
using namespace std;

class DisjointSets{
public:
  vector<int> parent;
  vector<int> sizes;
  int components;
  int largest;
  DisjointSets(int size) : parent(size+1), sizes(size+1,1), components(size), largest(1){
    for (int i = 1; i < size; i++) parent[i] = i;
  }

  bool unite(int nodeOne, int nodeTwo){
    int parOne = find(nodeOne);
    int parTwo = find(nodeTwo);

    // in case the tow are already in a same component
    if(parOne == parTwo) return false;

    if(sizes[parOne] < sizes[parTwo]) swap(parOne, parTwo);
    sizes[parOne] += sizes[parTwo];
    parent[parTwo] = parOne;
    components--;
    if(sizes[largest]< sizes[parOne]) largest = parOne;
    return true;
  }

  int find(int node){
    if(parent[node] == node) return node;
    return find(parent[node]);
  }

  bool connected(int nodeOne, int nodeTwo){
    return find(nodeOne) == find(nodeTwo);
  }
};
int main (int argc, char *argv[]) {
  int n,m; cin >> n >> m;

  DisjointSets dsu(n);
  for (int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    dsu.unite(a,b);
   
    int maxS = dsu.sizes[dsu.largest];

    cout<<dsu.components << " " << maxS << "\n";
  }
  return 0;
}
