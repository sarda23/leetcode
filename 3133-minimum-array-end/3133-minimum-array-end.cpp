class Solution {
public:
    long long minEnd(int n, int x) {
        long long num = x; // starting will be from x itself
        for(int i=1;i<n;i++){

            // wish next num will be num+1
            num = (num+1) | x;

        }
        return num;
    }
};