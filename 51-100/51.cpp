class Solution {
public:
    const static int N=50;
    vector<vector<string>> vvs;
    bool visited[N];
    bool vis_LURD[N*2];
    bool vis_RULD[N*2];
    int lines[N];
    int n;
    inline bool& fVis_LURD(int x,int y){
        return vis_LURD[N+x+y];
    }
    inline bool& fVis_RULD(int x,int y){
        return vis_RULD[N+x-y];
    }
    void answerGenerator(){
        vector<string> v;
        for(int i=0;i<n;i++){
            string s="";
            s.append(n,'.');
            s[lines[i]]='Q';
            v.push_back(s);
        }
        vvs.push_back(v);
    }
    void dfs(int step){
        if(step==n){
            answerGenerator();
            return;
        }
        for(int i=0;i<n;i++){
            if(visited[i]||fVis_LURD(step,i)||fVis_RULD(step,i))continue;
            fVis_LURD(step,i)=fVis_RULD(step,i)=visited[i]=true;
            lines[step]=i;
            dfs(step+1);
            fVis_LURD(step,i)=fVis_RULD(step,i)=visited[i]=false;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        this->n=n;
        memset(visited,false,sizeof(visited));
        memset(vis_LURD,false,sizeof(vis_LURD));
        memset(vis_RULD,false,sizeof(vis_RULD));
        dfs(0);
        return vvs;
    }
};
