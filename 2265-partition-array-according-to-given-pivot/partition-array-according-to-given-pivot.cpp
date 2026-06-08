class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        int lessCount = 0;
        int equalCount = 0;

        for(int num : nums) {
            if(num < pivot) lessCount++;
            else if(num == pivot) equalCount++;
        }

        vector<int> ans(nums.size());

        int lessIdx = 0;
        int equalIdx = lessCount;
        int greaterIdx = lessCount + equalCount;

        for(int num : nums) {

            if(num < pivot)
                ans[lessIdx++] = num;

            else if(num == pivot)
                ans[equalIdx++] = num;

            else
                ans[greaterIdx++] = num;
        }

        return ans;
    }
};