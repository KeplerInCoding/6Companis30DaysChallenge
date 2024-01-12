//easy

class Solution {
public:

    void fill(vector<vector<int>>&img, vector<vector<int>>&ans, int i, int j){
        int num=img[i][j];
        int deno=1;
        //up
        if(i>0){
            num+=img[i-1][j]; deno++;
            //up-left
            if(j>0){
                num+=img[i-1][j-1]; deno++;
            }
            //up-right
            if(j<img[0].size()-1){
                num+=img[i-1][j+1]; deno++;
            }
            
        }
        //down
        if(i<img.size()-1){
            num+=img[i+1][j]; deno++;
            //down-left
            if(j>0){
                num+=img[i+1][j-1]; deno++;
            }
            //down-right
            if(j<img[0].size()-1){
                num+=img[i+1][j+1]; deno++;
            }

        }
        //left
        if(j>0){
            num+=img[i][j-1]; deno++;
        }
        //right
        if(j<img[0].size()-1){
            num+=img[i][j+1]; deno++;
        }
        ans[i][j]=num/deno;
        
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector <vector <int>> ans(img.size(), vector <int> (img[0].size()));
        for(int i=0; i<img.size(); i++){
            for(int j=0; j<img[0].size(); j++){
                fill(img, ans, i, j);
            }
        }
        return ans;
    }
};