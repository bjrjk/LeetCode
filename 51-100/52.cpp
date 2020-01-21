class Solution {
public:
    const static int N=50;
    bool visited[N];
    bool vis_LURD[N*2];
    bool vis_RULD[N*2];
    int lines[N];
    int tot=0;
    int n;
    inline bool& fVis_LURD(int x,int y){
        return vis_LURD[N+x+y];
    }
    inline bool& fVis_RULD(int x,int y){
        return vis_RULD[N+x-y];
    }
    void dfs(int step){
        if(step==n){
            tot++;
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
    int totalNQueens(int n) {
        this->n=n;
        memset(visited,false,sizeof(visited));
        memset(vis_LURD,false,sizeof(vis_LURD));
        memset(vis_RULD,false,sizeof(vis_RULD));
        dfs(0);
        return tot;
    }
};
