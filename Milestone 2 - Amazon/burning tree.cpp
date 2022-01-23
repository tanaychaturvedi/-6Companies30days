class Solution {
    
    Node* f(Node *root,map<Node*,Node*> &par,int target)
    {
        queue<Node*> q;
        q.push(root);
        Node *tar = nullptr;
        par[root] = nullptr;
        
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            if(node->data == target) 
            {
                tar = node;
            }
            
            if(node->left)
            {
                par[node->left] = node;
                q.push(node->left);
            }
            
            if(node->right)
            {
                par[node->right] = node;
                q.push(node->right);
            }
        }
        
        
        return tar;
    }
    
    
  public:
    int minTime(Node* root, int target) 
    {
        map<Node*,Node *> par;
        auto tar = f(root,par,target);
        
        int t = -1;
        queue<Node*> q;
        q.push(tar);
        map<Node*,bool> vis;
        vis[tar] = true;
        
        while(!q.empty())
        {
            t++;
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                auto curr = q.front();
                q.pop();
                vis[curr] = true;
                if(curr->left and !vis[curr->left])
                {
                    q.push(curr->left);
                }
                if(curr->right and !vis[curr->right])
                {
                    q.push(curr->right);
                }
                if(par[curr] and !vis[par[curr]])
                {
                    q.push(par[curr]);
                }
            }
        }
        
        
        return t;
    }
};