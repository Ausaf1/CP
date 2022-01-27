class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }

        isTerminal = false;
    }
};

class Trie {
public:
    struct trie{
       vector<trie*>children{vector<trie*>(26,NULL)};
       bool iseow=false;
    }*Root,*curr;
    
    Trie() {
        Root=new trie();
    }
    
    void insert(string word) {
        curr=Root;
        
        for(auto &c:word){
            if(!curr->children[c-'a'])
               curr->children[c-'a']=new trie();
            curr=curr->children[c-'a'];
        }
        curr->iseow=true;
    }
    
    bool search(string word) {
         curr=Root;
        
        for(auto &c:word){
            if(!curr->children[c-'a'])
                return false;
            curr=curr->children[c-'a'];
        }
        return (curr->iseow);
    }
    
    bool startsWith(string prefix) {
        curr=Root;
        for(auto &c:prefix){
            if(!curr->children[c-'a'])
                return false;
            curr=curr->children[c-'a'];
        }        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */