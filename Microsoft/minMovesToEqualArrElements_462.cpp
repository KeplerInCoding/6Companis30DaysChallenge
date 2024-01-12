//medium

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        //median
        int n=nums.size();
        int median=nums[n/2];
        int ans=0;
        for(int i=0; i<n; i++){
            ans+=abs(median-nums[i]);
        }
        return ans;
    }
};