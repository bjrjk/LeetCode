class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)return 0;
        if(nums.size()==1)return 1;
        int head=0,tail=1;
        while(tail<nums.size()){
            if(nums[head]==nums[tail])tail++;
            else nums[++head]=nums[tail++];
        }
        return head+1;
    }
};
