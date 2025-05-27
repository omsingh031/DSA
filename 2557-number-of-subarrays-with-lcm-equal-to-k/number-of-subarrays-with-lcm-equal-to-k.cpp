class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int lcm = nums[i];
            if (lcm == k) count++;
            for (int j = i + 1; j < n; ++j) {
                lcm = lcm / __gcd(lcm, nums[j]) * nums[j];
                if (lcm > k) break;
                if (lcm == k) count++;
            }
        }
        return count;
    }
};
