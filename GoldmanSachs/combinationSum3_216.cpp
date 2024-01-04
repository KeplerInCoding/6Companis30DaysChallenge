//medium

class Solution {
public:

    void Sum(int k, int sum, vector <vector<int>> &ans, vector <int> &v, int index){
        if(k<0 || sum<0) return;
        if(!sum && !k) {
            ans.push_back(v);
            return;
        }
        for(int i=index; i<=9-k+1; i++){
            v.push_back(i);
            Sum(k-1, sum-i, ans, v, i+1);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector <vector <int>> ans;
        if(n<=1) return ans;
        vector <int> v;
        Sum(k, n, ans, v, 1);
        return ans;
    }
};