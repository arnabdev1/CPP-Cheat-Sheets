# Binary Trees Cheat Sheet

## Binary Tree Node Declaration
```c++
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
```

## Recursive Depth-First Search (DFS)
```c++
// Preorder: Root → Left → Right
void preorder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
// Inorder: Left → Root → Right
void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
// Postorder: Left → Right → Root
void postorder(TreeNode* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}
```


## Iterative DFS (Preorder using stack)
```c++
void iterativeDFS(TreeNode* root) {
    if (root == nullptr) return;

    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        TreeNode* node = s.top();
        s.pop();
        cout << node->val << " ";

        if (node->right) s.push(node->right); // Right pushed first so left is processed first
        if (node->left) s.push(node->left);
    }
}
```

## Iterative BFS (Level order using QUEUE)
```c++
#include <queue>

void bfs(TreeNode* root) {
    if (root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << " ";

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

```

## DFS Binary tree max depth(root to leaf)
```c++
// recursive
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
// iterative
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        stack<pair<TreeNode*,int>> s;
        s.push({root,1});
        int maxx = 1;
        while(!s.empty()){
            pair<TreeNode*,int> curr = s.top();
            s.pop();
            TreeNode* node = curr.first;
            int depth = curr.second;
            maxx = max(depth,maxx);
            if(node->right){
                s.push({node->right,depth+1});
            }
            if(node->left){
                s.push({node->left, depth+1});
            }
            
        }
        return maxx;
    }
```





## DFS check if binary trees are same
```c++
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q) return true;
        if(p&&q && p->val == q->val){
            return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
        }else{
            return false;
        }
    }
```


## BFS Level order traversal saved in an array
```c++
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        vector<vector<int>> v;        
        if(!root) return v;

        q.push({root,0});
        while(!q.empty()){
            TreeNode* temp = q.front().first;
            int level = q.front().second;
            // if that level exists pushback element or push back vector
            if(v.size()<=level){
                v.push_back({temp->val});
            }else{
                v[level].push_back(temp->val);
            }
            // cout << temp->val << endl;
            q.pop();
            if(temp->left) q.push({temp->left, level+1});
            if(temp->right) q.push({temp->right,level+1});
        }
        return v;
    }
```
