class Solution {
public:
    bool valid(vector<int>& have, vector<int>& needed){
        for(int i=0;i<256;i++){
            if(have[i]<needed[i]){
                return false;
            }
        }
        return true;
    }
    
    string minWindow(string s, string t) {
        int n=s.size(), m=t.size();
        if(n<m)
        return "";

        vector<int> have(256);
        vector<int> needed(256);

        for(int i=0;i<m;i++){
            needed[t[i]]++;
        }
        int res=INT_MAX, low=0, start=-1;
    
        for(int high=0;high<s.length();high++){
            have[s[high]]++;
            while(valid(have,needed)){
                int len=high-low+1;
                if(res>len){
                    res=len;
                    start=low;
                }
                have[s[low]]--;
                low++;
            }
        }
        return (res >= INT_MAX )? "" : s.substr(start,res);
    }
};