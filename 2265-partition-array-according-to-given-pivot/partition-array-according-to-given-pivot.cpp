
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

// Notes:
// We have solved this question using the index of the beginning of the elements which fall in each individual bracket
// which is less than pivot, greater than pivot, and equal to pivot: meaning we have divided the ans vector into three parts
// for stable partitioning
// First we find the number of elements which are greater than, less than and equal to pivot element and then we decide the indexing;
// ans={_ _ _ _ _ _ _ _ _ _}
//      l       e   r
// l starts from 0, means the index where less than pivot element starts filling which consists of 4 elements
// r starts from (no.of less + no. of equal to indexing) means the index where more than pivot element starts filling which consists of 4 elements
// e starts from(no. of less than pivot elements), means the index where the elements equal to pivot starts filling which consists of 2 elements

