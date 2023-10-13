class Solution{
    public:
    void raasta(vector<vector<int>> m, int n, vector<string>& ans, string s, int x, int y){
        if(x==n-1 && y==n-1){
            ans.push_back(s);
            return;
        }
        m[x][y]=0;
        if(x<n-1 && m[x+1][y]==1){
            s+='D';
            raasta(m,n,ans,s,x+1,y);
            s.pop_back();
        }
        if(y>0 && m[x][y-1]==1){
            s+='L';
            raasta(m,n,ans,s,x,y-1);
            s.pop_back();
        }
        if(y<n-1 && m[x][y+1]==1){
            s+='R';
            raasta(m,n,ans,s,x,y+1);
            s.pop_back();
        }
        if(x>0 && m[x-1][y]==1){
            s+='U';
            raasta(m,n,ans,s,x-1,y);
            s.pop_back();
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[0][0]==0) return {};
        vector<string> ans;
        raasta(m,m.size(),ans,"",0,0);
        return ans;
        
    }
};
