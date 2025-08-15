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

    TreeNode* solve(vector<int>& in, vector<int>& post, int &index ,map<int,int>&nodeToindex ,
    int stInd , int endInd){
        if(index < 0 || stInd > endInd) return NULL;

        int el = post[index--];
        TreeNode* root = new TreeNode(el);
        int pos = nodeToindex[el];
        root->right = solve(in ,post,index,nodeToindex,pos+1,endInd);
        root->left = solve(in ,post,index,nodeToindex,stInd,pos-1);
        

        return root;
        
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n = in.size();

        int postOrderIndex = n-1;
        map<int,int>nodeToindex;
        createMapping(in , nodeToindex , n);
        return solve(in,post,postOrderIndex ,nodeToindex, 0 , n-1);
    }
};