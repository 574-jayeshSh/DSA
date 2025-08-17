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
    int minVal(TreeNode* root) {
        TreeNode* curr = root;
        while (curr && curr->left != NULL) {
            curr = curr->left;
        }
        return curr->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        
       if(root->val == key){
           if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
           }

           if(root->left != NULL && root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
           }

           if(root->left == NULL && root->right != NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
           }
           if(root->left != NULL && root->right != NULL){
                root->val = minVal(root->right);
                root->right = deleteNode(root->right,root->val);
                return root;
           }
       }
       else{
            if(key < root->val){
                root->left = deleteNode(root->left,key);
                return root;
            }
            else{
                root->right = deleteNode(root->right,key);
                return root;
            }
       }
       return NULL;
    }
};