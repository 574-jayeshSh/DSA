class Solution {
public:
    vector<vector<int>> ans;

    void levelOrderTraversal(TreeNode* root) {
        if (!root) return; // Handle empty tree

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL); // Level separator

        vector<int> level;

        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if (temp == NULL) {
                ans.push_back(level);
                level.clear();
                if (!q.empty()) {
                    q.push(NULL); // Add another separator for the next level
                }
            } 
            else {
                level.push_back(temp->val);

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        levelOrderTraversal(root);
        return ans;
    }
};
