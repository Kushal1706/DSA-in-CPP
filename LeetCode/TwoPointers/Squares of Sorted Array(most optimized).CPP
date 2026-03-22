class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> neg;
        vector<int> pos;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                neg.push_back(nums[i]);
            }else{
                pos.push_back(nums[i]);
            }
        }
        if(neg.size()==0){
            for(int i=0;i<pos.size();i++){
                pos[i]=pos[i]*pos[i];
            }
            return pos;
        }
        if(pos.size()==0){
            for(int i=0;i<neg.size();i++){
                neg[i]=neg[i]*neg[i];
            }
            reverse(neg.begin(),neg.end());
            return neg;
        }
        for(int i=0;i<neg.size();i++){
            neg[i]=neg[i]*neg[i];
        }
        reverse(neg.begin(),neg.end());
        for(int i=0;i<pos.size();i++){
            pos[i]=pos[i]*pos[i];
        }
        vector<int> res;
        int i=0,j=0;
        while(i<neg.size() && j<pos.size()){
            if(neg[i]>pos[j]){
                res.push_back(pos[j++]);
            }
            else{
                res.push_back(neg[i++]);
            }
        }
        while(i<neg.size()) res.push_back(neg[i++]);
        while(j<pos.size()) res.push_back(pos[j++]);
        return res;
    }
};