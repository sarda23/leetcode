//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void InsertAtBottom(stack<int> &s,int element){
        // base case
        if(s.empty()){
            s.push(element);
            return;
        }
        
        int top = s.top();
        s.pop();
        InsertAtBottom(s,element);
        s.push(top);
    }
    
    void Reverse(stack<int> &s){
        if(s.empty()){
            return;
        }
        
        int top = s.top();
        s.pop();
        
        Reverse(s);
        InsertAtBottom(s,top);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends