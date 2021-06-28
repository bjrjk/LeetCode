class Solution {
public:
    string input, pattern;
    short arr[2005][2005];
    bool isMatch(string s, string p) {
        input = s;
        pattern = p;
        memset(arr, -1, sizeof(arr));
        return dfs(0, 0);
    }
    bool dfs(int iPos, int pPos){
        if(arr[iPos][pPos] != -1) return arr[iPos][pPos];
        int inputLen = input.size(), patternLen = pattern.size();
        if(iPos == inputLen && pPos == patternLen) return arr[iPos][pPos]=true;
        if(iPos >= inputLen || pPos >= patternLen){
            if(iPos == inputLen && pPos < patternLen){
                for(int i=pPos;i<patternLen;i++){
                    if(pattern[i]!='*') return arr[iPos][pPos]=false;
                }
                return arr[iPos][pPos]=true;
            }
            return arr[iPos][pPos]=false;
        } 
        switch(pattern[pPos]){
            case '*':
                return arr[iPos][pPos]=dfs(iPos+1, pPos+1) || dfs(iPos+1, pPos) || dfs(iPos, pPos+1);
                break;
            case '?':
                return arr[iPos][pPos]=dfs(iPos+1, pPos+1);
                break;
            default:
                if(input[iPos] == pattern[pPos])
                    return arr[iPos][pPos]=dfs(iPos+1, pPos+1);
                else
                    return arr[iPos][pPos]=false;
                break;
        }
    }
};