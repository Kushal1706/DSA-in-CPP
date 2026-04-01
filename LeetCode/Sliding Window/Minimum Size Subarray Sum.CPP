class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low=0 ,res=INT_MAX,sum=0;
        for(int high=0;high<nums.size();high++){
            sum+=nums[high];
            while(sum >= target){
                int len=high-low+1;
                res=min(len,res);
                sum-=nums[low];
                low++;
            }
        }
        return (res==INT_MAX)? 0 : res;
    }
};