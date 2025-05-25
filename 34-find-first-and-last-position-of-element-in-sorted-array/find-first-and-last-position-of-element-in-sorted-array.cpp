class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findIndex(nums, target, true);
        int last = findIndex(nums, target, false);
        return {first, last};
    }
    int findIndex(vector<int>& nums, int target, bool findFirst) {
        int left = 0, right = nums.size() - 1, index = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                index = mid;
                if (findFirst)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return index;
    }
};
