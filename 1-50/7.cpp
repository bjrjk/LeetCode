class Solution {
public:
    int reverse(int x) {
        bool flag=false;
        long long y=0,xx=x;
        if(x<0){
            flag=true;
            xx=-xx;
        }
        while(xx){
            y*=10;
            y+=xx%10;
            xx/=10;
        }
        if(flag)y=-y;
        if(y<(1<<31)||y>~(1<<31))return 0;
        else return (int)y;
    }
};
