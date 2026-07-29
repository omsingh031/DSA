class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int x:nums){
            sum+=x;
        }
        int right;
        int left=0;
        if(left==sum-nums[0]){
            return 0;
        }
        for(int i=1;i<n;i++){
            left+=nums[i-1];
            right=sum-nums[i]-left;
            if(left==right){
                return i;
            }
        }
        return -1;

        
       
    }
};