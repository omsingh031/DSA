class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        // Find maximum value to optimize boolean array size
        int max_val = 0;
        for (int v : nums) {
            max_val = max(max_val, v);
        }

        int u = 1;
        while (u <= max_val) {
            u <<= 1;
        }

        vector<bool> one(u, false);
        vector<bool> two(u, false);
        vector<bool> three(u, false);

        // Stage 1: Build reachability for 1-element and 2-element XORs
        for (int v : nums) {
            one[v] = true;
            for (int x = 0; x < u; ++x) {
                if (one[x]) {
                    two[x ^ v] = true;
                }
            }
        }

        // Stage 2: Build reachability for 3-element XORs
        for (int v : nums) {
            for (int x = 0; x < u; ++x) {
                if (two[x]) {
                    three[x ^ v] = true;
                }
            }
        }

        // Stage 3: Count unique 3-element XOR sums
        int ans = 0;
        for (int x = 0; x < u; ++x) {
            if (three[x]) {
                ans++;
            }
        }

        return ans;
    }
};