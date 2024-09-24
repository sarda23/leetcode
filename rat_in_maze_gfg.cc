//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // T:C - rat can go in 3 direction ( he can't go in the direction from where it came from)
    //total num of cells = n^2 
    //O(3^n^2)
    // space complexity - depth of recursion tree
    // max can be worst case - in the path to reach the destination - it can visit every element - O(n^2)
    
    vector<string> result;
    
    bool isSafe(int i ,int j ,int n){
        return i>=0 && i<n && j>=0 && j<n;
    }
    
    void solve(int i,int j,int &n,vector<vector<int>> &mat,string &path){
        
        if(!isSafe(i,j,n) || mat[i][j] == 0){
            return;
        }
        
        if(i == n-1 && j ==n-1){
            result.push_back(path);
            return;
        }
        
        mat[i][j] = 0;
        
        // D, R, L, U
        path.push_back('D');
        solve(i+1,j,n,mat,path);
        path.pop_back();
        
        path.push_back('R');
        solve(i,j+1,n,mat,path);
        path.pop_back();
        
        path.push_back('L');
        solve(i,j-1,n,mat,path);
        path.pop_back();
        
        path.push_back('U');
        solve(i-1,j,n,mat,path);
        path.pop_back();
        
        
        mat[i][j] = 1;
    }
    
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        string path = "";
        int n = mat[0].size();
        
        solve(0,0,n,mat,path);
        
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
