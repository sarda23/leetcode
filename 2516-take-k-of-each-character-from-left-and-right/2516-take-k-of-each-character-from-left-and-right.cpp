class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();

        int count_a = 0;
        int count_b = 0;
        int count_c = 0;

        for(char &ch : s){
            if(ch == 'a')
                count_a++;
            if(ch == 'b')
                count_b++;
            if(ch == 'c')
                count_c++;
        }

        if(count_a < k || count_b < k || count_c < k){
            return -1; // not possible to delete k characters
        }

        int i = 0;
        int j = 0;
        int not_deleted_window_size = 0;

        while(j<n){
            if(s[j] == 'a'){ // delete na karne wali window
                count_a--;
            }else if(s[j] == 'b'){ // delete na karne wali window
                count_b--;
            }else { // delete na karne wali window
                count_c--;
            }

            // if deletion count of any character becomes less than k, then shrink the window and bring them back

            while(i<=j && (count_a<k || count_b<k || count_c<k)){
                if(s[i] == 'a'){
                    count_a++;
                }
                else if(s[i] == 'b'){
                    count_b++;
                }
                else {
                    count_c++;
                }
                i++;
            }
            not_deleted_window_size = max(not_deleted_window_size, j-i+1);
            j++;
        }

        return n - not_deleted_window_size;
    }
};