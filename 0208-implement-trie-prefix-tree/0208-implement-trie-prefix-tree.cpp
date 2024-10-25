class Trie {
public:
    struct trienode {
        bool endOfWord;
        trienode* children[26];
    };

    trienode* getNode(){
        trienode* newnode = new trienode();

        newnode->endOfWord = false;

        for(int i =0;i<26;++i){
            newnode->children[i] = NULL;
        }

        return newnode;
    }

    trienode* root;

    Trie() {
        root = getNode();
    }
    
    void insert(string word) {
        trienode* crawl = root;

        for(int i=0;i<word.length();++i){
            char ch = word[i];
            int idx = ch - 'a';

            if(crawl->children[idx] == NULL){
                crawl->children[idx] = getNode();
            }
            crawl = crawl->children[idx];
        }
        // by the end crawl will be pointing to e   if word is apple
        crawl->endOfWord = true;
    }
    
    bool search(string word) {
        trienode* crawl = root;

        for(int i=0;i<word.length();++i){
            char ch = word[i];
            int idx = ch - 'a';

            if(crawl->children[idx] == NULL){
                return false;
            }
            crawl = crawl->children[idx];
        }
        if(crawl != NULL && crawl->endOfWord == true){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        trienode* crawl = root;
        int i=0;
        for(;i<prefix.length();i++){
            char ch = prefix[i];
            int idx = ch - 'a';

            if(crawl->children[idx] == NULL){
                return false;
            }
            crawl = crawl->children[idx];
        }
        // agar for loop se bahar aagaye hai toh 
        if(i == prefix.length()){
            return true;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */