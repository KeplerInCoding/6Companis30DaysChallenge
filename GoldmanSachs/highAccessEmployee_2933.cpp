//medium

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {

        unordered_map <string, vector<int>> mp;
        vector <string> v;
        for(int i=0; i<access_times.size(); i++){
            int m = stoi(access_times[i][1]); 
            // cout<<m<<endl;
            int time = (m%100)+((m/100)*60);
            mp[access_times[i][0]].push_back(time);
        }
        for (auto i = mp.begin(); i != mp.end(); i++) {
            sort(i->second.begin(), i->second.end());
        }
        
        for (auto i = mp.begin(); i != mp.end(); i++) {
            vector <int> vec = i->second;
            // cout<<i->first<<" : "<<endl;
            if(vec.size()<3) continue;
            for(int k=1 ; k<vec.size()-1; k++){
                if(vec[k+1]-vec[k-1]<60){
                    v.push_back(i->first); break;
                }
            }
        }

        return v;
    }
};