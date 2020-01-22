// https://blog.csdn.net/leonard1853/article/details/84166474
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int iPos,jPos;
        for(iPos=nums.size()-2;iPos>=0&&nums[iPos]>=nums[iPos+1];iPos--);
        if(iPos==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(jPos=nums.size()-1;jPos>iPos&&nums[iPos]>=nums[jPos];jPos--);
        swap(nums[iPos],nums[jPos]);
        reverse(nums.begin()+iPos+1,nums.end());
    }
};
