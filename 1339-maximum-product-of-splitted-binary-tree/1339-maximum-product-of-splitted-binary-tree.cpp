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
    int maxProduct(TreeNode* root) {
        const int MOD = 1e9 + 7;
        long long maxProd =0;
        long long totalSum = calculateSum(root);
        findMaxProduct(root, totalSum, maxProd);
        return maxProd % MOD;
    }

private:
    long long calculateSum(TreeNode*node){
        if(!node) return 0;
        return node ->val + calculateSum(node->left)+calculateSum(node->right);
    }
    long long findMaxProduct(TreeNode* node, long long totalSum, long long& maxProd) {
        if (!node) return 0;
        long long leftSum = findMaxProduct(node->left, totalSum, maxProd);
        long long rightSum = findMaxProduct(node->right, totalSum, maxProd);
        long long currSum = node->val + leftSum + rightSum;
        long long product = currSum * (totalSum - currSum);
        maxProd = max(maxProd, product);
        
        return currSum;
    }
};