class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        // Prefix sum matrix
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = mat[i - 1][j - 1]
                             + prefix[i - 1][j]
                             + prefix[i][j - 1]
                             - prefix[i - 1][j - 1];
            }
        }

        auto canForm = [&](int len) {
            for (int i = 0; i + len <= m; i++) {
                for (int j = 0; j + len <= n; j++) {
                    int sum = prefix[i + len][j + len]
                            - prefix[i][j + len]
                            - prefix[i + len][j]
                            + prefix[i][j];
                    if (sum <= threshold)
                        return true;
                }
            }
            return false;
        };

        int low = 0, high = min(m, n), ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canForm(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
