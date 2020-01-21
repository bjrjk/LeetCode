class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        long long y=0,xx=x,xxx=x;
        while(xx){
            y*=10;
            y+=xx%10;
            xx/=10;
        }
        return y==xxx;
    }
};
