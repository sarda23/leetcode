//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
        void ComputeLps(string &pat, vector<int> &LPS,int m){
            int len = 0; // length of previous longest prefix & suffix
            // which are equal
            
            LPS[0] = 0;
            
            int i = 1;
            
            while(i<m){
                if(pat[i] == pat[len]){
                    len++;
                    LPS[i] = len;
                    i++;
                }
                else{
                    if(len != 0){
                        len = LPS[len-1];
                    } else{
                        LPS[i] = 0;
                        i++;
                    }
                }
            }
        } 
            
        vector <int> search(string pat, string txt)
        {
            //code here
            int n = txt.length();
            int m = pat.length();
            
            vector<int>result;
            
            // create an LPS array to store the length of longest
            // proper prefix which is also a suffix
            // lps[i] = the longest proper prefix of pat[0..i] 
            // which is also a suffix of pat[0..i].
            
            vector<int> LPS(m,0);
            ComputeLps(pat,LPS,m);
            
            // apply KMP algo
            
            int i = 0;
            int j = 0;
            while(i < n){
                if(txt[i] == pat[j]){
                    i++;
                    j++;
                }
                
                if (j==m){
                    result.push_back(i-m+1); // 1 based indexing
                    j = LPS[j-1]; 
                }else if(i<n && txt[i] != pat[j]){
                    if(j!=0){
                        j=LPS[j-1];
                    } else{
                        i++;
                    }
                }
            }
            return result;
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends