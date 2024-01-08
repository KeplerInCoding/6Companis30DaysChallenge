//medium

class Solution {
public:


    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue <pair<int,int>> q;
        int row=isWater.size();
        int col=isWater[0].size();

        vector <vector<int>> ans(row, vector<int>(col,-1));

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(isWater[i][j]){
                    ans[i][j]=0;
                    q.emplace(i,j);
                }
            }
        }
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            int x,y;
            //up
            x=i-1, y=j;
            if(x>=0 && x<row && ans[x][y]==-1){
                ans[x][y]=ans[i][j]+1;
                q.emplace(x,y);
            }

            //left
            x=i, y=j-1;
            if(y>=0 && y<col && ans[x][y]==-1){
                ans[x][y]=ans[i][j]+1;
                q.emplace(x,y);
            }

            //down
            x=i+1, y=j;
            if(x>=0 && x<row && ans[x][y]==-1){
                ans[x][y]=ans[i][j]+1;
                q.emplace(x,y);
            }

            //right
            x=i, y=j+1;
            if(y>=0 && y<col && ans[x][y]==-1){
                ans[x][y]=ans[i][j]+1;
                q.emplace(x,y);
            }
            q.pop();

        }
        return ans;
    }
};