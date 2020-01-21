class Solution {
public:
    vector<int> candidateArr;
    vector<int> process;
    vector<vector<int>> vvi;
    int target;
    set<vector<int>> uos;
    void vviInsert(){
        vector<int> vi = process;
        sort(vi.begin(),vi.end());
        if(!uos.count(vi)){
            vvi.push_back(process);
            uos.insert(vi);
        }
    }
    void dfs(int curPos,int left){
        if(left==0){
            vviInsert();
            return;
        }
        if(left<0||curPos>=candidateArr.size())return;
        for(int i=0;i<=1;i++){
            for(int k=0;k<i;k++)process.push_back(candidateArr[curPos]);
            dfs(curPos+1,left-i*candidateArr[curPos]);
            for(int k=0;k<i;k++)process.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        candidateArr = candidates;
        sort(candidateArr.begin(),candidateArr.end(),greater<int>());
        this->target=target;
        dfs(0,target);
        return vvi;
    }
};
