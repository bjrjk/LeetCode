class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen=1;
        string ans=s.substr(0,1);
        for(int center=0;center<s.size();center++){
            for(int shift=1;center-shift>=0&&center+shift<s.size();shift++){
                if(s[center-shift]!=s[center+shift])break;
                if(2*shift+1>maxLen){
                    maxLen=2*shift+1;
                    ans=s.substr(center-shift,maxLen);
                }
            }
            for(int shift=1;center-shift+1>=0&&center+shift<s.size();shift++){
                if(s[center-shift+1]!=s[center+shift])break;
                if(2*shift>maxLen){
                    maxLen=2*shift;
                    ans=s.substr(center-shift+1,maxLen);
                }
            }
        }
        return ans;
    }
};
