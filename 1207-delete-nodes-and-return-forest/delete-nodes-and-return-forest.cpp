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
    TreeNode* helper(TreeNode* root, unordered_set<int> st, vector<TreeNode*>& ans){
        if(root == NULL) return NULL;

        root->left = helper(root->left , st , ans);
        root->right = helper(root->right , st , ans);

        if(st.find(root->val) != st.end()){
            if(root->left){
                ans.push_back(root->left);
            }
            if(root->right){
                ans.push_back(root->right);
            }
            return NULL;
        }
        else{
            return root;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;

        unordered_set<int> st;
        for(int &nums : to_delete){
            st.insert(nums);
        }

        helper(root , st, result);
        if(st.find(root->val) == st.end()){
            result.push_back(root);
        }
        return result;

    }
};