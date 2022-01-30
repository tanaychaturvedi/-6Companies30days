class Solution {
    
    int recur(Node *root)
    {
        if(!root)
            return 0;
            
        int val = 0;
        
        val += recur(root->left);
        val += recur(root->right);
        
        int temp = val;
        val += root->data;
        
        root->data = temp;
            
        return val;
    }
    
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        recur(node);
    }
};