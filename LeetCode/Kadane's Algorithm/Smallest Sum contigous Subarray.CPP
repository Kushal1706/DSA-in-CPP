class Solution {
  public:
    int smallestSumSubarray(vector<int>& a) {
        // Code here
        int bestMin=a[0],ans=a[0];
        
        for(int i=1;i<a.size();i++){
            int v1=bestMin+a[i];
            int v2=a[i];
            bestMin=min(v1,v2);
            ans=min(ans,bestMin);
        }
        return ans;
    }
};