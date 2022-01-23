void connect(Node *root)
    {
       if(!root) return ;
        
        queue<Node *> q;
        q.push(root);
        root->nextRight = NULL;
        
        while(!q.empty())
        {
            int sz = q.size();
            // vector<Node *> arr;
            
            for(int i=0;i<sz;i++)
            {
                auto node = q.front(); q.pop();
                if(i != sz-1) node->nextRight = q.front();
                else node->nextRight = NULL;
                // arr.push_back(node);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            // for(int i=0;i<arr.size()-1;i++) arr[i]->next = arr[i+1];
            // arr.back()->next = NULL;
        }
        
        
        // return root;
    }  