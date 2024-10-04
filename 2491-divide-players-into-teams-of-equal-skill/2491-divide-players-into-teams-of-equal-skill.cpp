class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();

        vector<int> vec(1001,0);
        int sum = 0;
        for(int &s:skill){
            sum+=s;
            vec[s]++;
        }

        int teams = n/2;

        if(sum%teams!=0){
            return -1;
        }

        int target = sum/teams;
        long long chem = 0;

        for(int i=0;i<n;++i){
            int curr_skill = skill[i];
            int rem_skill = target - curr_skill;

            if(vec[rem_skill] <= 0){
                return -1;
            }

            chem += (long long)curr_skill * (long long)rem_skill;
            vec[rem_skill]--;
        }

        return chem/2;
        
        // int n = skill.size();

        // sort(begin(skill),end(skill));

        // int i = 0;
        // int j = n -1;
        // int s = skill[i] + skill[j];

        // long long chem = 0;

        // while(i<j){
        //     int curr_skill = skill[i] + skill[j];

        //     if(curr_skill != s){
        //         return -1;
        //     }

        //     chem += (long long)(skill[i])*(long long)(skill[j]);
        //     i++;
        //     j--;
        // }
        // return chem;
    }
};