// bottom up 
// state def : dp[i] = min character in string s from index i to index (n-1)
// so our ans is dp[0] -- so we'll start the loop from n-1 (end)
class Solution {
public:
    int minExtraChar(string s, vector<string>& dict) {
        int n = s.length();
        unordered_set<string> st(begin(dict),end(dict));

        vector<int> t(n+1,0);
        
        for(int i=n-1;i>=0;--i){
            t[i] = 1 + t[i+1]; 

            for(int j = i;j<n;++j){
                string curr = s.substr(i,j-i+1);
                if(st.count(curr)){
                    t[i] = min(t[i],t[j+1]);
                }
            }
        }

        return t[0];
    }
};


// memoization
// class Solution {
// public:
//     // O(2^n * n * n) -- need to memoize
//     // O(n * n * n) last n is for substr
//     // S.C : O(n) -- set-- num of character in dict
//     // dp array with size 51 or u can take map
//     //int t[51];

//     int solve(int i,string &s,unordered_set<string> &st,int &n,unordered_map<int,int> &mp){
//         if(i>=n){
//             return 0;
//         }
        
//         // if(t[i] != -1){
//         //     return t[i];
//         // }
        
//         if(mp.count(i)){
//             return mp[i];
//         }

//         int result = 1 + solve(i+1,s,st,n,mp); // skip the character

//         for(int j=i;j<n;++j){
//             string curr = s.substr(i,j-i+1);//length of substring from i
//             if(st.count(curr)){ // if the substr is present(valid) in the dict
//                 result = min(result,solve(j+1,s,st,n,mp));
//             }            
//         }

//         return mp[i] = result;
//     }

//     int minExtraChar(string s, vector<string>& dict) {
//         int n = s.length();
//         unordered_set<string> st(begin(dict),end(dict));
//         //memset(t,-1,sizeof(t));
//         unordered_map<int,int> mp;

//         return solve(0,s,st,n,mp);
//     }
// };