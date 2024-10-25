class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // sort first
        sort(begin(folder),end(folder));
        vector<string> result;

        result.push_back(folder[0]); // sort kar chuke hai toh first wale ka koi parent nahi hoga - so it can never be a sub folder

        for(int i=1;i<folder.size();++i){
            // curr folder ko aap dekh rahe ho and yeh find karne ki koshish kar rahe ho ki jo last folder tha woh as it is present hai kya curr folder me and agar woh index 0 se start nahi ho raha toh matlab woh result me hoga
            string currFolder = folder[i];
            string lastFolder = result.back();
            lastFolder += '/';

            if(currFolder.find(lastFolder) != 0){
                result.push_back(currFolder);
            }
        }
        return result;

        // approach brute force

        // unordered_set<string> st(begin(folder),end(folder));
        // vector<string> result;

        // for(string &curr_folder : folder){
        //     bool isSubFolder = false;
        //     string temp = curr_folder;
        //     while(!curr_folder.empty()){
        //         size_t pos_of_last_slash = curr_folder.find_last_of('/');

        //         curr_folder = curr_folder.substr(0,pos_of_last_slash);

        //         if(st.find(curr_folder) != st.end()){
        //             // it means curr_folder is a sub folder
        //             isSubFolder = true;
        //             break;
        //         }
        //     }

        //     if(!isSubFolder){
        //         result.push_back(temp);
        //     }
        // }

        // return result;
    }
};