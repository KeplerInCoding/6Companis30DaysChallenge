//hard
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int maxi;

    pair<vector <int>, int> checkBT(TreeNode* root){
        vector <int>v;
        if(!root) return {v,0};
        
        if(!root->left && !root->right){
            maxi = max(maxi, root->val);
            v.push_back(root->val);
            return {v, root->val};
        }

        pair <vector<int>, int> p1 = checkBT(root->left);
        pair <vector<int>, int> p2 = checkBT(root->right);
        cout<<"ROOT : "<<root->val <<endl;
        if(p1.second==INT_MAX || p2.second==INT_MAX){
            cout<<"error : not BST childs"<<endl;
            return {v, INT_MAX};
        }

        vector <int> v1 = p1.first;
        vector <int> v2 = p2.first;
        if(v1.size() && v1[v1.size()-1]>=root->val){
            maxi = max(maxi, max(p1.second, p2.second));
            cout<<"error in left   maxi: "<<maxi<<endl;
            return {v, INT_MAX};
        }
        if(v2.size() && v2[0]<=root->val){
            maxi = max(maxi, max(p1.second, p2.second));
            cout<<"error in right   maxi : "<<maxi<<endl;
            return {v, INT_MAX};
        }
        if(v1.size())v.push_back(v1[0]);
        v.push_back(root->val);
        if(v2.size())v.push_back(v2[v2.size()-1]);
        int sum = p1.second + p2.second + root->val;
        maxi = max(maxi, sum);
        cout<<"BST    sum : "<<sum<<endl;
        return {v, sum};

    }



    int maxSumBST(TreeNode* root) {
        maxi=0;
        checkBT(root);
        return maxi;
    }
};