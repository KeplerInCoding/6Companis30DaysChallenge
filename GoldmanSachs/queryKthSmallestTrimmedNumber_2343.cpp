//medium

    class Solution {
        public:
        vector<int> smallestTrimmedNumbers(vector<string>& nums,vector<vector<int>>& queries) {
            vector<int> ans;
            for (const vector<int>& query : queries)
            ans.push_back(getKSmallestIndex(nums, query[0], query[1]));
            return ans;
        }

        private:
        int getKSmallestIndex(const vector<string>& nums, int k, int trim) {
            const int startIndex = nums[0].length() - trim;
            vector<pair<string, int>> trimmed;  // (num, index)

            for (int i = 0; i < nums.size(); ++i) {
            const string& num = nums[i];
            trimmed.push_back({num.substr(startIndex), i});
            }

            ranges::sort(trimmed);
            return trimmed[k - 1].second;
        }
};


// class Solution {
// public:

//     long long getMax(vector <long long> &nums){
//         long long m = LLONG_MIN;
//         for(int i = 0; i < nums.size(); i++) m = max(m, nums[i]);
//         return m;
//     }

//     void countingSort(vector <long long> &nums, int pos, vector<vector<int>> &q, vector <int> &ans, unordered_map <int, vector <int>> &trim, unordered_map <long long, int> &mp){
//         vector <int> count(10, 0);
//         int n = nums.size();
//         vector <long long> sorted(n);
//         for(int i = 0; i < n; i++){
//             long long p = pow(10, pos - 1);
//             int index = (nums[i] / p) % 10;
//             count[index]++;
//             cout << "count: " << index << endl;
//         }
//         for(int i = 1; i < 10; i++) count[i] += count[i - 1];
//         for(int i = n - 1; i >= 0; i--){
//             long long p = pow(10, pos - 1);
//             int index = (nums[i] / p) % 10;
//             cout << "p : " << p << "  index : " << index << "  count : " << count[index] << "  nums[i]: " << nums[i] << endl;
//             sorted[--count[index]] = nums[i];

//         }
//         for(int i = 0; i < n; i++){
//             nums[i] = sorted[i];

//             cout << "nums: " << nums[i] << endl;
//         }
//         auto it = trim.find(pos);
//         if(it == trim.end()) return;
//         for(int i = 0; i < trim[pos].size(); i++){
//             int index = trim[pos][i];
//             int small = nums[q[index][0] - 1];
//             ans[index] = mp[small];
//             cout << "ans : " << small << endl;
//             cout << "index : " << mp[small] << endl;
//         }
//     }

//     vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
//         vector <int> ans(queries.size(), -1);
//         unordered_map <int, vector <int>> trim;
//         vector <long long> NUMS;  // Change to long long
//         unordered_map <long long, int> mp;  // Change to long long
//         for(int i = 0; i < nums.size(); i++){
//             NUMS.push_back(stoll(nums[i]));  // Change stoi to stoll
//             mp[NUMS[i]] = i;
//         }
//         for(int i = 0; i < queries.size(); i++){
//             trim[queries[i][1]].push_back(i);
//         }
//         long long digits = getMax(NUMS);  // Change to long long
//         cout << "digits: " << digits << endl;
//         int i = 1;
//         while(digits){
//             countingSort(NUMS, i, queries, ans, trim, mp);
//             digits /= 10;
//             i++;
//         }
//         return ans;
//     }
// };
