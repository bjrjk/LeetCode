class Solution {
public:
    void nextStep(bool& down, int& pos, int numRows){
        if(numRows==1)return;
        if(pos==numRows-1||pos==0)down=!down;
        if(down)pos++;
        else pos--;
    }
    string convert(string s, int numRows) {
        vector<char> v[1005];
        bool down=false;
        int pos=0;
        for(int i=0;i<s.size();i++){
            v[pos].push_back(s[i]);
            nextStep(down,pos,numRows);
        }
        string result="";
        for(int i=0;i<numRows;i++){
            for(int j=0;j<v[i].size();j++){
                result+=v[i][j];
            }
        }
        return result;
    }
};
