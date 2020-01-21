class Solution {
public:
    vector<int> candidateArr;
    vector<int> process;
    vector<vector<int>> vvi;
    int target;
    void dfs(int curPos,int left){
        if(left==0){
            vvi.push_back(process);
            return;
        }
        if(left<0||curPos>=candidateArr.size())return;
        for(int i=0;i<=left/candidateArr[curPos];i++){
            for(int k=0;k<i;k++)process.push_back(candidateArr[curPos]);
            dfs(curPos+1,left-i*candidateArr[curPos]);
            for(int k=0;k<i;k++)process.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        candidateArr = candidates;
        sort(candidateArr.begin(),candidateArr.end(),greater<int>());
        this->target=target;
        dfs(0,target);
        return vvi;
    }
};
