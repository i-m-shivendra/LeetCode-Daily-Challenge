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

    int diameter = 0;
    
    int calculateHeight(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int leftHeight = calculateHeight(root->left);
        int rightHeight = calculateHeight(root->right);

        diameter = max(diameter, leftHeight+ rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        calculateHeight(root);

        return diameter;
    }
};