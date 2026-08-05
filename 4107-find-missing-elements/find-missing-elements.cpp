class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        
        // 1. Sort the array so the numbers are in order
        sort(nums.begin(), nums.end());
        
        // 2. Loop through the array bounds safely (stop before the last element)
        for (int i = 0; i < nums.size() - 1; i++) {
            
            // 3. If there is a gap between the current number and the next one,
            // grab all the numbers in that gap.
            for (int missing = nums[i] + 1; missing < nums[i + 1]; missing++) {
                ans.push_back(missing);
            }
        }
        
        return ans;
    }
};