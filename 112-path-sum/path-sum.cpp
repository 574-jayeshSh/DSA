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
    bool solve(TreeNode* root ,int &sum , int k ){
        if(root == NULL) return false;
        sum += root->val;
        if(root->left == NULL && root->right ==NULL){
            if(sum != k) {
            sum -= root->val;
            return false;
            }
            return true;
        }
        
        bool leftans = solve(root->left , sum , k);
        bool rightans = solve(root->right , sum , k);
        
        sum -= root->val;
       
        return leftans || rightans;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;

        return solve(root,sum,targetSum);
    }
};