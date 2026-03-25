class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low=0, res=INT_MIN;
        unordered_map<char,int> freq;

        for(int high=0;high<s.length();high++){
            freq[s[high]]++;
            while(freq[s[high]] > 1){
                freq[s[low]]--;
                if(freq[s[low]]==0){
                    freq.erase(freq[s[low]]);
                }
                low++;
            }
            int len=high-low+1;
            res=max(res,len);
        }
        return (res == INT_MIN)? 0 : res;
    }
};