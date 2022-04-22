/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* fin1(TreeNode *rt1,TreeNode *prev)
    {
     if(rt1->right==NULL)
     {
        return rt1;
     }
     return fin1(rt1->right,rt1);
    }
    TreeNode* fin(TreeNode *rt)
    {
      if(rt->left==NULL)
      {
         return rt->right;
      }
      if(rt->right==NULL)
          return rt->left;
      TreeNode *temp=rt->right;
      TreeNode *rt1=fin1(rt->left,rt);
      rt1->right=temp;
       // cout<<rt1->val<<" "<<rt->val<<"\n";
   //   rt->val=rt1->val;
      
      return rt->left;
    }
    TreeNode* solve(TreeNode* root,int key)
    {
     if(root==NULL)
         return root;
     if(root->val==key)
     {
        return fin(root);
     }
      if(root->left!=NULL&&root->left->val==key)
      {
        TreeNode *rt=fin(root->left);
        root->left=rt;
          //cout<<rt->val<<" "<<rt->right->val<<" "<<rt->left->val<<"\n";
        return root;
      }
     else
     {
         root->left=solve(root->left,key);
       //  return root;
     }
     if(root->right!=NULL&&root->right->val==key)
     {
       TreeNode *rt=fin(root->right);
      //   cout<<rt<<" ";
       root->right=rt;
       return root;
     }
     else
     {
       root->right=solve(root->right,key);
        // return root;
     }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        TreeNode *rt=root;
        if(root==NULL)
            return NULL;
        return solve(root,key);
    }
};