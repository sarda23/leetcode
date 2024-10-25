class Solution {
public:
    vector<string> res;
    int m, n;  // m-rows n -cols

    // node struct for trie
    struct node{
        bool end_of_word;
        string word;
        node* children[26];
    };

    // naya node banane ke lia trie ka  -- get TRIE Node
    node* getNode(){
        node* newNode = new node();
        newNode->end_of_word = false; // abhi toh naya naya node hai

        newNode->word = ""; // abhi pata nahi - naya node hai
        // children abhi toh nahi pata - toh children ko null se initilize kardete hai
        for(int i =0;i<26;++i){
            newNode->children[i] = NULL;
        }

        return newNode;
    }
    // trie node me insert karna 
    void insert(node* root,string &word){
        node* crawl = root;

        // check for each character of word
        for(int i=0;i<word.length();++i){
            char ch = word[i];

            if(crawl->children[ch-'a'] == NULL){
                crawl->children[ch-'a'] = getNode(); // child bana dia
            }

            crawl = crawl->children[ch-'a'];
        }
        crawl->end_of_word = true;
        crawl->word = word;   
    }

    // left right down up jane ke lia 
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};

    void findTrieWords(vector<vector<char>> &board,int i,int j,node* root){
        if(i<0 || i>=m || j<0 || j>=n){
            return;
        }

        if(board[i][j] == '$' || root->children[board[i][j]-'a'] == NULL){
            return;
        }

        root = root->children[board[i][j] - 'a'];

        if(root->end_of_word == true){
            res.push_back(root->word);
            root->end_of_word = false; // q ki aage bhi word ho sakhta hai islia - q ki already yaha tak ka word res me push kar chuke hai - islia mark karo false tak ki aage ja sake
        }

        char temp = board[i][j];
        board[i][j] = '$'; // marking visited

        // left right up down
        for(vector<int> &dir:directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            findTrieWords(board,new_i,new_j,root);
        } 

        board[i][j] = temp; // marking unvisited
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size(); // rows
        n = board[0].size(); // cols

        // create root
        node* root = getNode(); // trie node ( root ) bana lia
        
        // insert words in trie
        for(string &word :words){
            insert(root,word);
        }

        // traverse in the board - only one times - and find all the words in trie if present
        for(int i =0;i<m;++i){
            for(int j=0;j<n;++j){
                char ch = board[i][j];

                if(root->children[ch-'a'] != NULL){
                    findTrieWords(board,i,j,root);
                }
            }
        }
        return res;
    }
};