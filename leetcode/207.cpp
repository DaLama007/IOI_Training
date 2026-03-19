class Solution {
  public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      vector<int> indegree(numCourses, 0);
      vector<vector<int>> nodes(numCourses);
      queue<int> noid;

      for (int i = 0; i < prerequisites.size(); i++) {
        int first = prerequisites[i][0];
        int second = prerequisites[i][1];
        indegree[first]+=1; 
      }
      for (int i = 0; i < prerequisites.size(); i++) {
        int first = prerequisites[i][0];
        int second = prerequisites[i][1];
        nodes[second].push_back(first);
      }

      for (int i = 0; i < numCourses; i++) {
        if (indegree[i]==0) {
          noid.push(i);
        }
      }

        while (!noid.empty()) {
          int node = noid.front();
          noid.pop();
          for(auto var : nodes[node]) {
            indegree[var]-=1;
            if (indegree[var]==0) {
              noid.push(var);
            }
          }
      }
      for (int i = 0; i < numCourses; i++) {
        if (indegree[i]!=0) {
          return false;
        }
      }
      return true;


      //first idea:
      /*
      for (int i = 0; i < prerequisites.size(); i++) {
        int first = prerequisites[i][0];
        int second = prerequisites[i][1];
        nodes[first].push_back(second);
      }

      queue<int> q;
      q.push(0);
      visited[0] = true;
      while (!q.empty()) {
        int n = q.front();
        q.pop();
        for(auto var : nodes[n]) {
          if (!visited[var]) {
            count++;
            q.push(var);
            visited[var] = true;
          }
          else{
            return false;
          }
        }
      }
      return true;*/
    }
};
