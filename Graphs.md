# Graphs Cheat Sheet

## BFS Traversal
![image](https://github.com/user-attachments/assets/1eb8e9d5-2e81-40d3-a8fa-e0671f2ada98)
```c++

// visited array is needed only for undirected graph because if graph is unidirectional then no need to check if element was already visited
// 0 has no neighbors(DNE), 1's neighbors are 2 and 6 and so on.
    vector<vector<int>> adj = {{}, {2,6}, {1,3,4}, {2}, {2,5}, {4,8}, {1,7,9}, {6,8}, {5,7}, {6}};
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

## BFS Traversal
![image](https://github.com/user-attachments/assets/852d0cde-bd5b-436a-b08f-ec63ae0c618b)
```c++

   // vector<vector<int>> adj = {{}, {2,6}, {1,3,4}, {2}, {2,5}, {4,8}, {1,7,9}, {6,8}, {5,7}, {6}};
    vector<vector<int>> adj = {{}, {2,3}, {1,5,6}, {1,4,7}, {3,8}, {2}, {2}, {2}, {3,8}, {4,7}};
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
