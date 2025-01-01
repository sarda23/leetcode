class Solution {
public:
    int maxScore(string s) {
        // 1 one
        int n = s.length();
        int result = INT_MIN;

        int zeros = 0;
        int ones = 0;

        for(int i=0;i<=n-2;i++){
            if(s[i] == '1'){
                ones++;
            }
            else{
                zeros++;
            }

            result = max(result,zeros-ones);
        }
        if(s[n-1] == '1') 
            ones++;
        return result + ones;

        // 2 pass solution
        // int n = s.length();
        // int result = INT_MIN;

        // int total_one = count(begin(s),end(s),'1');//1st pass

        // int zeros = 0;
        // int ones = 0;

        // // right_ones = total_one - ones;

        // for(int i=0;i<=n-2;i++){
        //     if(s[i] == '1'){
        //         ones++;
        //     }
        //     else{
        //         zeros++;
        //     }

        //     int right_ones = total_one - ones;

        //     result = max(result , zeros+right_ones);
        // }
        // return result;

        // int n = s.length();

        // int result = INT_MIN;

        // for(int i=0;i<=n-2;i++){

        //     // 0 to i  -  0's count
        //     int zero_count = 0;
        //     for(int j=0;j<=i;j++){
        //         if(s[j] == '0')  zero_count++;
        //     }

        //     int one_count = 0;
        //     for(int j = i+1;j<n;j++){
        //         if(s[j] == '1')  one_count++;
        //     }

        //     result = max(result, zero_count+one_count);
        // }

        // return result;
    }
};