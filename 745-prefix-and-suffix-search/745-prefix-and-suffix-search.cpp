 struct node{
  
    node* arr[27] ; 
    int ind = -1;   
    
    void put(char ch,node* newNode){  
        arr[ch-'a'] = newNode ;
    }
    
    bool contains(char ch){ 
        return arr[ch-'a'] ;
    }
    
    node* getNext(char ch){ 
        return arr[ch-'a'] ;
    }
    
    void setIndex(int index){
        ind = index ;
    }
    
    int getIndex(){
        return ind ;
    }
    
};

class WordFilter {
    
    node *trie;

    
public:
    
    void insert(node *root,string s,int index){
        for(auto &ch : s){
            if(!root->contains(ch))
                root->put(ch,new node());
            root = root->getNext(ch);
            root->setIndex(index);
        }
    }
    WordFilter(vector<string>& words) {
         trie = new node() ;
        int index = 0 ;
        string s ;
        for(auto &word: words){
            s = "{" + word ;
            insert(trie,s,index) ;
            
            for(int i = word.size() - 1;i >= 0 ; i--){
                s = word[i] + s ;
                insert(trie,s,index) ;
            }
            index++ ;
        }
    }
    
    int f(string prefix, string suffix) {
        node *temp = trie;
        string match = suffix + '{' + prefix;
        for(auto &c : match){
            if(!temp || !temp->contains(c))
                return -1;
            temp = temp->getNext(c);
        }
        return temp->getIndex();
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */