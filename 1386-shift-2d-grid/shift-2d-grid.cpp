class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;

        k = k % total;
        if (k == 0) return grid;

        vector<vector<int>> result(m, vector<int>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int flatIndex = i * n + j;
                int newFlatIndex = (flatIndex + k) % total;

                result[newFlatIndex / n][newFlatIndex % n] = grid[i][j];
            }
        }

        return result;
    }
};