# Graphs Cheat Sheet

## BFS Traversal
![image](https://github.com/user-attachments/assets/1eb8e9d5-2e81-40d3-a8fa-e0671f2ada98)
```c++

// visited array is needed only for undirected graph because if graph is unidirectional then no need to check if element was already visited
// 0 has no neighbors(DNE), 1's neighbors are 2 and 6 and so on.

    vector<vector<int>> adj = {{}, {2,6}, {1,3,4}, {2}, {2,5}, {4,8}, {1,7,9}, {6,8}, {5,7}, {6}};
   // 1 2 6 3 4 7 9 5 8 

    int start = 1;
    vector<int> bfsOfGraph(int start, vector<vector<int>> &adj) {
        int V = adj.size();
        // boolean list to mark all the vertices as not visited.
        vector<bool> vis(V, false);

        // initially we mark first vertex as visited(true).
        vis[start] = true;

        vector<int> res;

        // creating a queue for BFS and pushing first vertex in queue.
        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            // adding front element in output list and popping it from queue.
            int t = q.front();
            res.push_back(t);
            q.pop();

            // traversing over all the connected components of front element.
            for (int v : adj[t]) {
                // if they aren't visited, we mark them visited and add to queue.
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        // returning the output list.
        return res;
    }
    

```

## DFS Traversal
![image](https://github.com/user-attachments/assets/852d0cde-bd5b-436a-b08f-ec63ae0c618b)
```c++

   // vector<vector<int>> adj = {{}, {2,6}, {1,3,4}, {2}, {2,5}, {4,8}, {1,7,9}, {6,8}, {5,7}, {6}};
   // 1 2 3 4 5 8 7 6 9 

    vector<vector<int>> adj = {{}, {2,3}, {1,5,6}, {1,4,7}, {3,8}, {2}, {2}, {2}, {3,8}, {4,7}};
   // 1 2 5 6 3 4 8 7 

    int n = adj.size();
    vector<bool> vis(n,false);
    int start = 1;
    vector<int> res;
    dfs(start, adj, vis, res);

    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &res){
        vis[node] = true;
        res.push_back(node);
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis, res);
            }
        }
    }    

```


## When grid is given and adjacent elements represent the next level(BFS example)
```c++
vector<vector<int>> grid = {
    {1, 0, 1},
    {1, 1, 0},
    {0, 1, 1}
};

// 1 means it qualifies as part of the graph and will be traversed if connected to another 1 in one of 4 sides
vector<pair<int,int>> bfsGrid(vector<vector<int>>& grid) {
    vector<pair<int,int>> res;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<int, int>> q; // BFS queue

    // Start BFS from (0, 0)
    q.push({0, 0});
    vis[0][0] = true;

    // Directions for traversal (right, left, down, up)
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // BFS traversal
    while (!q.empty()) {
        auto temp = q.front();
        int x = temp.first, y = temp.second;
        res.push_back(temp); // Collect the grid value at (x, y)
        q.pop();

        for (auto dir : directions) {
            int dx = dir.first, dy = dir.second;
            int nx = x + dx, ny = y + dy;

            // Check bounds and if it's a valid node (value = 1) and not visited
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1 && !vis[nx][ny]) {
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return res;
}
vector<pair<int,int>>  result = bfsGrid(grid);
```




## Finding cycle in undrected graph when edges are given(union find algorithm)
```c++
    int findParent(int a, vector<int>& par) {
        if (par[a] != a) {
            par[a] = findParent(par[a], par);  // Path compression
        }
        return par[a];
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> par(numCourses);
        vector<int> rank(numCourses, 0);
        
        // Initialize the union-find data structure
        for (int i = 0; i < numCourses; i++) {
            par[i] = i;
        }
        
        for (auto edge : prerequisites) {
            int a = edge[0];
            int b = edge[1];
            
            int rootA = findParent(a, par);
            int rootB = findParent(b, par);
            
            if (rootA == rootB) {
                return false;  // Cycle detected
            }
            
            // Union by rank
            if (rank[rootA] > rank[rootB]) {
                par[rootB] = rootA;
            } else if (rank[rootB] > rank[rootA]) {
                par[rootA] = rootB;
            } else {
                par[rootA] = rootB;
                rank[rootB]++;
            }
        }
        
        return true;  // No cycles found
    }
```



## Finding cycle in undrected graph when adjacency list is given(DFS)
```c++
bool hasCycleDFS(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (hasCycleDFS(neighbor, node, adj, visited)) return true;
        } else if (neighbor != parent) {
            return true;  // Cycle detected
        }
    }
    return false;
}

bool detectCycle(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);
    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (hasCycleDFS(i, -1, adj, visited)) return true;
        }
    }
    return false;
}
```
## Finding cycle in undrected graph when adjacency list is given(BFS)
```c++
bool hasCycleBFS(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<pair<int, int>> q; // {node, parent}
    q.push({start, -1});
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, node}); // Push neighbor with current node as parent
            } else if (neighbor != parent) {
                return true; // Cycle detected
            }
        }
    }
    return false;
}

bool detectCycle(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);

    // Create adjacency list
    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    // the above conversion code can be ignored if adjacency list is already given
    // Check for cycles in all components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (hasCycleBFS(i, adj, visited)) {
                return true;
            }
        }
    }
    return false;
}
```



## Finding cycle in **DIRECTED** graph when adjacency list is given(DFS)
```c++
    bool dfs(int node, vector<vector<int>> adj, vector<int>& vis, vector<int>& pathvis){
        vis[node] = 1;
        pathvis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it, adj, vis, pathvis) == true){
                    return true;
                }
            }else if(pathvis[it]==true){
                return true; // when both vis and path vis is true indicating 
                            //  that this node was visited twice in the same path and direction
            }
        }
        pathvis[node]=0; // resetting for other paths because this path has been traversed fully
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> adj) {
        vector<int> vis(V,0);
        vector<int> pathvis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathvis) == true){
                    return true;
                }
            }
        }
        return false;
    }

```

## Topological sort of Directed Acyclic Graphs (DFS)
```c++
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis,  stack<int>& st){
        vis[node] = true;
        for(auto it:adj[node]){
            if(vis[it]==false){
                dfs(it,adj,vis,st);
            }
        }
        st.push(node);
    }
    
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> ans, vis(n,false);
        stack<int> st;
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                dfs(i, adj, vis, st);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
```

## Topological sort of Directed Acyclic Graphs (BFS) using Kahn's algorithm
```c++
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> inDegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                inDegree[it]++;
            }
        }
        
        queue<int> q;
        
        for(int i=0;i<n;i++){
            if(inDegree[i]==0) q.push(i);
        }
        
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adj[node]){
                inDegree[it]--;
                if(inDegree[it]==0)q.push(it);
                
            }
        }
        return topo;
        
    }
```
