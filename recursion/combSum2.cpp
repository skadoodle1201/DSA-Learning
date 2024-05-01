class Solution {
   public:
    vector<vector<int>>ans;
    void solve(vector<int>c , int target, int sum, vector<int>&v, int i){
        if(i == c.size()){
            return;
        }
        if(sum == target){
            ans.push_back(v);
            return;
        }

        if(sum+c[i] <= target){
            v.push_back(c[i]);
            solve(c,target,sum+a[i],v,i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>v;
        solve(candidates,target,0,v,0)
        return ans;
    }
};

class Solution {
   public:
    vector<vector<int>> ans;
    void solve(vector<int> a, vector<int>& v, int s) {
        if(s == a.size()){
            ans.push_back(v);
            return;
        }

        for(int i =s; i<a.size();i++){
            if(i!=s and a[i] == a[i-1]) continue;
            
            v.push_back(a[i]);
            solve(a,v,i+1);
            v.pop_back();

            solve(a, v, i + 1);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        sort(nums.begin(),nums.end());
        solve(nums, v, 0) return ans;
    }
};

class Solution {
   public:
    vector<vector<int>> ans;
    void solve(vector<int> a, vector<int>& v, int s) {

        if (s == a.size()) {
            return;
        }

        for (int i = s; i < a.size(); i++) {
            if (i != s and a[i] == a[i - 1]) continue;

            swap(a[i],a[s]);
            ans.push_back(v);
            solve(a, v, i + 1);
            swap(a[i], a[s]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> v;
        sort(nums.begin(), nums.end());
        solve(nums, v, 0) return ans;
    }
};

class Solution {
   public:
    vector<vector<string>> ans;
    bool isPalindrome(string& x) {
        int i = 0, j = x.size() - 1;
        while (i < j) {
            if (x[i++] != x[j--]) {
                return false;
            }
        }
        return true;
    }
    void solve(string& s, vector<string>& v, int si) {
        // base case
        if (si == s.size()) {
            ans.push_back(v);
            return;
        }

        // recursive case
        for (int i = si; i < s.size(); i++) {
            string x = s.substr(si, i - si + 1);
            if (isPalindrome(x)) {
                v.push_back(x);
                solve(s, v, i + 1);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> v;
        solve(s, v, 0);
        return ans;
    }
};