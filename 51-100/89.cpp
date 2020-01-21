class Solution {
public:
    vector<vector<int>> vvi;
    void init(){
        vector<int> v0,v1;
        v0.push_back(0);
        v1.push_back(0);
        v1.push_back(1);
        vvi.push_back(v0);
        vvi.push_back(v1);
    }
    vector<int> grayCode(int n) {
        init();
        for(int i=2;i<=n;i++){
            vector<int> vi;
            vector<int>& vp=vvi[i-1];
            for(int k=0;k<vp.size();k++)vi.push_back(vp[k]);
            for(int k=vp.size()-1;k>=0;k--)vi.push_back(vp[k]|(1<<(i-1)));
            vvi.push_back(vi);
        }
        return vvi[n];
    }
};
