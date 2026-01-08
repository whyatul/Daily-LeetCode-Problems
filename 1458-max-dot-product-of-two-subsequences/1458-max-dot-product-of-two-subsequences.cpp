class Solution {
public:
       int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
     
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MIN));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int product = nums1[i-1] * nums2[j-1];
                int withPrev = (dp[i-1][j-1] == INT_MIN) ? product : dp[i-1][j-1] + product;
               
                int justCurrent = product;
                
                
                int skipFirst = dp[i-1][j];
                
                
                int skipSecond = dp[i][j-1];
                
                dp[i][j] = max({withPrev, justCurrent, skipFirst, skipSecond});
            }
        }
        
        return dp[m][n];
    }
};

class SolutionOptimized {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        vector<int> prev(n + 1, INT_MIN);
        vector<int> curr(n + 1, INT_MIN);
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int product = nums1[i-1] * nums2[j-1];
                
                int withPrev = (prev[j-1] == INT_MIN) ? product : prev[j-1] + product;
                int justCurrent = product;
                int skipFirst = prev[j];
                int skipSecond = curr[j-1];
                
                curr[j] = max({withPrev, justCurrent, skipFirst, skipSecond});
            }
            swap(prev, curr);
            fill(curr.begin(), curr.end(), INT_MIN);
        }
        
        return prev[n];
    }
};