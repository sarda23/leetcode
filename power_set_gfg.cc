//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//  same as -- just check that set can't be empty -- everything else is same https://leetcode.com/problems/subsets/
class Solution{
	public:
	    vector<string> result;
	    
	    void solve(int idx,string &s , string &curr){
	        
	        if(idx >= s.length()){
	            if(curr != ""){
	                result.push_back(curr);
	            }
	            return;
	        }
	        
	        curr.push_back(s[idx]);
	        solve(idx+1,s,curr);
	        curr.pop_back();
	        
	        solve(idx+1,s,curr);
	    }
	    
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    string curr = "";
		    solve(0,s,curr);
		    
		    sort(begin(result),end(result));
		    return result;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends