/*
    My Solution (lowestCommonAncestor_mysolution) is using a
    vector to record the path to reach the two target nodes,
    but that's not nesessary at all.

    The public answer lowestCommonAncestor is simpler and faster.
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<bool> findNodes(TreeNode *root, TreeNode* target, vector<bool> visited) {

        // Not Found
        if(root == NULL)
            return vector<bool>();

        // Found
        if(root == target) {
            return visited;
        }

        // Find Left Child
        vector<bool> left_v= visited;
        left_v.push_back(false);
        left_v = findNodes(root -> left, target, left_v);

        // Find Right Child
        vector<bool> right_v= visited;
        right_v.push_back(true);
        right_v = findNodes(root -> right, target, right_v);

        // Return Answer, could be NULL for the both.
        if(left_v.size()>right_v.size())
            return left_v;
        return right_v;
    }

    TreeNode* lowestCommonAncestor_mysolution(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<bool> path1 = findNodes(root, p, vector<bool>());
        vector<bool> path2 = findNodes(root, q, vector<bool>());

        TreeNode *answer = root;
        for(int i = 0; i < min(path1.size(), path2.size()); i++) {
            if(path1[i] == path2[i]) {
                if(path1[i])
                    answer = answer -> right;
                else
                    answer = answer -> left;
            } else
                break;
        }
        return answer;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return NULL;
        }
        if(root==p || root==q)
            return root;
        TreeNode* l,*r;
        l = lowestCommonAncestor(root->left,p,q);
        r= lowestCommonAncestor(root->right,p,q);
        if(l && r)
            return root;
        if(l)
            return l;
        if(r)
            return r;
        return NULL;
    }
};