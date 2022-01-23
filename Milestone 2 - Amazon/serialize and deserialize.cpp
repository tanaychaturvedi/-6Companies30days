#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
};

class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        if(!root) return {-1};
        
        queue<Node*> q;
        q.push(root);
        vector<int> arr;
        
        // str += to_string(root->val);
        arr.push_back(root->data);
        
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            
            if(node->left)
            {
                // str += to_string(root->left->val);
                arr.push_back(node->left->data);
                q.push(node->left);
            }
            else arr.push_back(-1);
            
            if(node->right)
            {
                // str += to_string(root->right->val);
                arr.push_back(node->right->data);
                q.push(node->right);
            }
            else arr.push_back(-1);
        }
        
        // for(auto &val : arr) cout<<val<<" ";
        
        
        return arr;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &arr)
    {
       
      if(arr.size()==0 || arr[0] == -1) return nullptr;
       
      queue<Node*> q;
      Node *root = new Node(arr[0]);
      q.push(root);
      int idx = 1;
       
      while(!q.empty() and idx < arr.size())
      {
          auto node = q.front();
          q.pop();
           
          node->left = arr[idx]==-1 ? nullptr : new Node(arr[idx]); idx++;
          node->right = arr[idx]==-1 ? nullptr : new Node(arr[idx]); idx++;
           
          if(node->left) q.push(node->left);
          if(node->right) q.push(node->right);
      }
       
       return root;
    }

};