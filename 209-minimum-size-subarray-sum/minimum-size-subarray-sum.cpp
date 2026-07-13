class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int low=0,high=0,len=0;
        int sum=0;
        int res=INT_MAX;
        while(high<n){
            sum+=nums[high];        //hiring employees
            while(sum>=target){  //firing employees
                 len=high-low+1;
                 res=min(res,len);
                 sum-=nums[low];
                 low++;
            }
            high++  ;             //increasing the hiring if the current team is not able to do the work
        }
        return res==INT_MAX?0:res;
    }
};