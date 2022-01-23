pair<int,int> sum(Node *root,int x)
{
    if(!root) return {0,0};
    
    auto l = sum(root->left,x);
    auto r = sum(root->right,x);
    
    int tot = root->data + l.first + r.first;
    int freq = l.second + r.second + (tot == x);
    
    return {tot,freq};
}

int countSubtreesWithSumX(Node* root, int X)
{
    auto ans = sum(root,X);
    return ans.second;
}