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
    void createMapping(vector<int>& inorder,map<int,int>&nodeToindex , int n){
        for(int i = 0; i<n ; i++){
            nodeToindex[inorder[i]] = i;
        }
    }

    TreeNode* solve(vector<int>& in, vector<int>& pre, int &index ,map<int,int>&nodeToindex ,
    int stInd , int endInd){
        if(index >= in.size() || stInd > endInd) return NULL;

        int el = pre[index++];
        TreeNode* root = new TreeNode(el);
        int pos = nodeToindex[el];
        
        root->left = solve(in ,pre,index,nodeToindex,stInd,pos-1);
        root->right = solve(in ,pre,index,nodeToindex,pos+1,endInd);
        

        return root;
        
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = in.size();

        int preOrderIndex = 0;
        map<int,int>nodeToindex;
        createMapping(in , nodeToindex , n);
        return solve(in,pre,preOrderIndex ,nodeToindex, 0 , n-1);
    }
};