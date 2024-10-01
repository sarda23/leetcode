class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if(k == 1){
            return 'a';
        }

        int n = operations.size();
        long long len = 1; // starting length
        long long new_k = -1;
        int operation_type = -1;

        for(int i=0;i<n;++i){
            len *= 2;  // a aa aaaa  .. 

            if(len >= k){
                operation_type = operations[i];
                new_k = k - len/2;
                break;
            }
        }

        char ch = kthCharacter(new_k,operations);

        if(operation_type == 0){
            return ch;
        }
        
        return ch == 'z'? 'a': ch+1;
    }
};