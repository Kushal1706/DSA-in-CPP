class Solution {

  public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        // Your code goes here
        sort(arr,arr+n);
        int ans=0;
        
        for(int i=0;i<n-2;i++){
            int left=i+1,right=n-1;
            while(left<right){
                int s=arr[i]+arr[left]+arr[right];
                if(s<sum){
                   ans=ans+(right-left);
                   left++;
                }   
                else if(s==sum || s>sum){
                   right--;
                }
            }
        }
        return ans;
    }
};