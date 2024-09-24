// TRIE solution
// 1. insert in trie
// 2. search common prefix - convert the arr2 num to string so that digit can be searched easily 

struct TrieNode{
    TrieNode* children[10]; // 10 digits - array of pointer
};

class Solution {
public:

    TrieNode* getTrieNode(){
        TrieNode* node = new TrieNode();
        for(int i=0;i<10;++i){
            node->children[i] = nullptr;
        }
        return node;
    }

    void insert(int num, TrieNode* root){
        TrieNode* crawl = root;
        string numStr = to_string(num);

        for(char ch:numStr){ // O(num of digits)
            int idx = ch - '0';
            if(!crawl->children[idx]){
                crawl->children[idx] = getTrieNode();
            }

            crawl = crawl->children[idx];
        }
    }

    // returns the length of the longest prefix
    int searchTrie(int num,TrieNode* root){
        TrieNode* crawl = root;
        string numStr = to_string(num);
        int length = 0;

        for(char ch:numStr){
            int idx = ch -'0';
            if(crawl->children[idx]){
                length++;
                crawl = crawl->children[idx];
            }
            else{
                break;
            }
        }
        return length;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root = getTrieNode(); // TRIE

        for(int num:arr1){
            insert(num,root);
        }

        int result = 0;
        for(int num:arr2){
            result = max(result,searchTrie(num,root));
        }

        return result;
    }
};

// // Brute force
// class Solution {
// public:
//     int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
//         // saare prefix nikal ke set me dal do
//         unordered_set<int> st;//O(total num of prefixes of numbers in arr1)

//         for(int v1: arr1){
//             // already set me present hoga toh
//             // prefix can repeat islia
//             while(!st.count(v1) && v1 >0){
//                 st.insert(v1);

//                 v1/=10;
//             }
//         }

//         int result = 0; // longest common prefix

//         for(int num:arr2){
//             while(!st.count(num) && num >0){
//                 num /=10;
//             }

//             if(num > 0){ // matlab set me mila hai num
//             // to find num of digits in a num 
//             // log10(num) + 1
//             // this might not be a int so need to do static_cast to int
//                 result = max(result,static_cast<int>(log10(num)) + 1);
//             }
//         }

//         return result;
//     }
// };