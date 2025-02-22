/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    public:
        TreeNode* solve(string& traversal, int n, int& i, int depth) {
            if (i >= n) {
                return NULL;
            }
            int j = i;
            while (j < n && traversal[j] == '-') {
                j++;
            }
            int dash = j - i;
            if (depth != dash) {
                return NULL;
            }
            i += dash;
            int value = 0;
            while (i < n && isdigit(traversal[i])) {
                value = value * 10 + (traversal[i] - '0');
                i++;
            }
    
            TreeNode* root = new TreeNode(value);
    
            root->left = solve(traversal, n, i, depth + 1);
            root->right = solve(traversal, n, i, depth + 1);
            return root;
        }
        TreeNode* recoverFromPreorder(string traversal) {
            int n = traversal.length();
            int i = 0;
            TreeNode* ans = solve(traversal, n, i, 0);
            return ans;
        }
    };