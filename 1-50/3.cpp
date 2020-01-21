class Solution {
public:
    bool visited[128];
    int maxNum=0;
    int lengthOfLongestSubstring(string s) {
        for(int i=0;i<s.length();i++){
            int curNum=0;
            memset(visited,false,sizeof(visited));
            for(int j=i;j<s.length();j++){
                if(!visited[s[j]]){
                    visited[s[j]]=true;
                    curNum++;
                    maxNum=max(maxNum,curNum);
                }
                else break;
            }
        }
        return maxNum;
    }
};
