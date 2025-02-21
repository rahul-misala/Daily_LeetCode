//Leetcode Link : https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/?envType=daily-question&envId=2025-02-21


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
class FindElements {
    public:
        unordered_set<int> st;
        void solveUsingDFS(TreeNode* root,int x){
            if(root == NULL){
                return;
            }
            root->val = x;
            st.insert(x);
            solveUsingDFS(root->left,2*x+1);
            solveUsingDFS(root->right,2*x+2);
        }
        FindElements(TreeNode* root) {
            st.clear();
            solveUsingDFS(root,0);
        }
        
        bool find(int target) {
            int ans = st.count(target);
            return ans;
        }
    };
    
    /**
     * Your FindElements object will be instantiated and called as such:
     * FindElements* obj = new FindElements(root);
     * bool param_1 = obj->find(target);
     */     