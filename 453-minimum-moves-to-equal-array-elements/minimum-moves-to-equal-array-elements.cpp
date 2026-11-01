class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum=0;
        int min_el=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
            min_el=min(min_el,nums[i]);
        }
        return sum-(n*min_el);
        
    }
};