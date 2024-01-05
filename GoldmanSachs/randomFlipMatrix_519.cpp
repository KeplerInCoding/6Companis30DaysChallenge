//medium

class Solution {
public:
    Solution(int m, int n) {
        rows=m;
        cols=n;
        total=m*n;
    }
    
    vector<int> flip() {
        vector<int>v;
        if(ones.size()==total){
            return v;
        }
        int num=rand()%total;
        while(ones.count(num)) num= (num+1)%total;
        ones.insert(num);
        v.push_back(num/cols);
        v.push_back(num%cols);
        return v;
    }
    
    void reset() {
        ones = {};
    }
    private:
    unordered_set<int> ones;
    int rows;
    int cols;
    int total;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */