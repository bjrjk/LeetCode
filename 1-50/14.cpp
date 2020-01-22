class Solution {
public:
    bool checkPosition(vector<string>& strs,int pos){
        for(int i=1;i<strs.size();i++)
            if(strs[0][pos]!=strs[i][pos])return false;
        return true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)return "";
        int minLen=strs[0].size();
        for(int i=1;i<strs.size();i++)
            minLen=min(minLen,(int)strs[i].size());
        int prefixLen=0;
        for(int i=0;i<minLen;i++){
            if(checkPosition(strs,i))prefixLen++;
            else break;
        }
        return strs[0].substr(0,prefixLen);
    }
};
