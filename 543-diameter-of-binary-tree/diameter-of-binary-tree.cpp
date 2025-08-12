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
    pair<int,int>diameter(TreeNode* root){
        if(root == NULL){
            pair<int,int>p = make_pair(0,0);
            return p;
        }
        pair<int,int>leftSide = diameter(root->left);
        pair<int,int>rightSide = diameter(root->right);

        int left = leftSide.first;
        int right = rightSide.first;
        int val = leftSide.second  + rightSide.second ;

        pair<int,int>ans;
        ans.first = max(left , max (right,val));
        ans.second = max(leftSide.second , rightSide.second) + 1;
        return ans;


    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        return diameter(root).first;
    }
};