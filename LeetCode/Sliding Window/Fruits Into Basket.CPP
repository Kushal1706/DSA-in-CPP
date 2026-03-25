class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low=0,res=INT_MIN;
        unordered_map<int,int> freq;

        for(int high=0;high<fruits.size();high++){
            freq[fruits[high]]++;
            while(freq.size() > 2){
                freq[fruits[low]]--;
                if(freq[fruits[low]]==0){
                    freq.erase(fruits[low]);
                }
                low++;
            }
            if(freq.size() <= 2){
                int len=high-low+1;
                res=max(res,len);
            }
        }
        return res;
    }
};