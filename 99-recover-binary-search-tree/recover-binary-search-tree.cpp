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
    void inorder(TreeNode* root , vector<int>&in){
        if(root == NULL) return;

        inorder(root->left , in);
        in.push_back(root->val);
        inorder(root->right, in);
    }

    void correctBSTUtil(TreeNode* root, vector<int> &inorder, int &index){
        if(root == nullptr) return;
        
        // Recursively fill the left subtree
        correctBSTUtil(root->left, inorder, index);
    
        // Replace the current node's data with 
        // the correct value from the sorted array
        root->val = inorder[index];
        index++;
        
        // Recursively fill the right subtree
        correctBSTUtil(root->right, inorder, index);
    }
    void recoverTree(TreeNode* root) {
        vector<int>in;
        inorder(root , in);
        sort(in.begin() , in.end());

        int index = 0;
        correctBSTUtil(root, in, index);
    }
};