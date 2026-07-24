class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        int maxending = nums[0];
        int minending = nums[0];

        for (int i = 1; i < n; i++) {
            int v1 = nums[i];
            int v2 = maxending * nums[i];
            int v3 = minending * nums[i];

            // Update minending and maxending for current position
            minending = min(v1, min(v2, v3));
            maxending = max(v1, max(v2, v3));

            // Track the global maximum product
            res = max(res, maxending);
        }

        return res;
    }
};