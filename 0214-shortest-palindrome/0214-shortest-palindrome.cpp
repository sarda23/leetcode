class Solution {
public:
    // function to compute the lps ( longest proper prefix which is also
    // suffix ) array
    void ComputeLps(string& pat, vector<int>& lps) {
        int m = pat.length();
        int len = 0;

        lps[0] = 0; // there is no proper suffix and prefix of pattern[0..0]

        int i = 1;
        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1]; // can also write len = len -1;
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    string shortestPalindrome(string s) {
        // If we have a string s and its reverse, we want to find the longest prefix in the string s that matches a suffix in reverse string rev. To do this, we concatenate s and its reverse using a separator (e.g., s#reverse_s). Next, we calculate the Longest Prefix Suffix (LPS) array for this concatenated string. The LPS array will help us determine the length of the longest prefix and suffix that are the same, which in turn helps identify the portion of the original string that is preventing it from being a palindrome.
        string rev = s;
        reverse(begin(rev),end(rev));

        string temp = s + "-" + rev;

        vector<int> lps(temp.length(),0);
        ComputeLps(temp,lps);

        int longestLpsLength = lps[temp.length() - 1]; // temp.back()

        string culprit = rev.substr(0,s.length() -longestLpsLength);

        return culprit + s;
    }
};