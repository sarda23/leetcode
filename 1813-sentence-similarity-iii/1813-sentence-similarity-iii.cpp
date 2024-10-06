class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.length() < s2.length()){
            swap(s1,s2); // to have s1 as the longest string all the time
        }

        deque<string> d1, d2;
        stringstream ss1(s1);
        string token;
        while(ss1 >> token){
            d1.push_back(token);
        }

        stringstream ss2(s2);
        while(ss2 >> token){
            d2.push_back(token);
        }

        while(!d1.empty() && !d2.empty() && d1.front() == d2.front()){
            d1.pop_front();
            d2.pop_front();
        }
        
        while(!d1.empty() && !d2.empty() && d1.back() == d2.back()){
            d1.pop_back();
            d2.pop_back();
        }
        return d2.empty();

        // 1st method 
        // vector<string> vec1, vec2;
        // stringstream ss1(s1);
        // string token;
        // while(ss1 >> token){
        //     vec1.push_back(token);
        // }

        // stringstream ss2(s2);
        // while(ss2 >> token){
        //     vec2.push_back(token);
        // }

        // int i = 0, j = vec1.size()-1; // s1 vec1
        // int k = 0, l = vec2.size()-1; // s2 vec2

        // while(k<vec2.size() && i<vec1.size() && vec2[k] == vec1[i]){
        //     k++;
        //     i++;
        // }

        // while(l>=k && vec2[l] == vec1[j]){
        //     j--;
        //     l--;
        // }

        // return l<k;
    }
};