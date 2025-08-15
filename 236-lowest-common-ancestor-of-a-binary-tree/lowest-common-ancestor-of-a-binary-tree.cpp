/**
 * Definition for a binary tree TreeNode.
 * struct TreeTreeNode {
 *     int val;
 *     TreeTreeNode *left;
 *     TreeTreeNode *right;
 *     TreeTreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lca(TreeNode*root , TreeNode* n1, TreeNode* n2){
    if(root == NULL) return NULL;
    if(root -> val == n1->val || root -> val == n2->val ) return root;

    TreeNode* left = lca(root->left, n1 , n2);
    TreeNode* right = lca(root->right, n1 , n2);

    if(left != NULL && right != NULL) return root;
    else if(left == NULL && right != NULL) return right;
    else if(left != NULL && right == NULL) return left;
    else return NULL;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return lca(root, p, q);
    }
};