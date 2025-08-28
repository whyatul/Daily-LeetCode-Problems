class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        const int n = grid.size();
        for (int i = 0; i < n; ++i) {
            int x = i, y = 0;
            vector<int> diag;
            while (x < n && y < n) diag.push_back(grid[x++][y++]);
            sort(diag.begin(), diag.end());
            x = i, y = 0;
            for (int k = diag.size() - 1; k >= 0; --k) grid[x++][y++] = diag[k];
        }
        for (int j = 1; j < n; ++j) {
            int x = 0, y = j;
            vector<int> diag;
            while (x < n && y < n) diag.push_back(grid[x++][y++]);
            sort(diag.begin(), diag.end());
            x = 0, y = j;
            for (int k = 0; k < diag.size(); ++k) grid[x++][y++] = diag[k];
        }
        return grid;
    }
};