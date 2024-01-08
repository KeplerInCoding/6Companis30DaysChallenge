//medium trie incomplete

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        unordered_set <string> t;
        int div;
        string s;
        for(int i=0; i<n; i++){
            div=0;
            s="";
            for(int j = i; j<n; j++){
                // cout<<"num : "<<nums[j]<<endl;
                string c = s+','+to_string(nums[j]);
                for(int m=0; m<c.size(); m++){
                    cout<<c[m];
                }
                if(nums[j]%p==0){
                    div++;
                    cout<<"  div : "<<div;
                } 
                if(div<=k){
                    s=c;
                    if(t.count(c)){
                        continue;
                    }
                    t.insert(c);
                    cout<<"  yess"<<endl;
                }
                else{
                    cout<<endl;
                    break;
                }

                
            }
            cout<<endl<<"next :"<<endl;
        }
        return t.size();

    }
};

//TLE