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
    bool solve(TreeNode* rt,long lt,long rht)
    {
        if(rt==NULL)
            return true;
       if(rt->val>=rht||rt->val<=lt)
           return false;
       //int temp1=lt;
       long temp2=min(rht,(long)rt->val);
       long temp3=max(lt,(long)rt->val);
       if(solve(rt->left,lt,temp2)&&solve(rt->right,temp3,rht))
           return true;
       else
           return false;
    }
    bool isValidBST(TreeNode* root) 
    {
        long l=INT_MIN-(long)6;
        long r=INT_MAX+(long)6;
        return solve(root,l,r);
    }
};