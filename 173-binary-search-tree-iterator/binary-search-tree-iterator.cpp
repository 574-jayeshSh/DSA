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
class BSTIterator {
private:
    stack<TreeNode*> st;

    // Helper: push all left children
    void pushLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushLeft(root); // Initialize with leftmost path
    }

    // Return next smallest element
    int next() {
        TreeNode* node = st.top();
        st.pop();
        int val = node->val;

        // If node has right child, push its left path
        if (node->right) {
            pushLeft(node->right);
        }

        return val;
    }

    // Return whether we still have elements
    bool hasNext() {
        return !st.empty();
    }
};
