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
    pair<bool,int>isBalancedFast(TreeNode* root){
        if(root == NULL){
            pair<bool,int>p = make_pair(true,0);
            return p;
        }
        pair<bool,int>leftSide = isBalancedFast(root->left);
        pair<bool,int>rightSide = isBalancedFast(root->right);

        int left = leftSide.first;
        int right = rightSide.first;
        int val = abs(leftSide.second  - rightSide.second) <= 1;

        pair<bool,int>ans;
        
        ans.second = max(leftSide.second , rightSide.second) + 1;
        if(left && right && val) ans.first = true;
        else ans.first = false;
        return ans;


    }
    bool isBalanced(TreeNode* root) {
        return isBalancedFast(root).first;
    }
};