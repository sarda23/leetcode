class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();

        vector<int> max_right(n); // stores the index of max element to right

        max_right[n-1] = n-1;

        for(int i = n-2;i>=0;--i){
            int right_max_idx = max_right[i+1];
            int right_max_ele = s[right_max_idx];

            max_right[i] = (s[i] > right_max_ele) ? i : right_max_idx;
        }

        for(int i=0;i<n;++i){
            int max_right_idx = max_right[i];
            int max_right_ele = s[max_right_idx];

            if(s[i] < max_right_ele){
                swap(s[i] , s[max_right_idx]);
                return stoi(s);
            }
        }

        return num;
    }
};