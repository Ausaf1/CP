class FreqStack {
public:
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> group;
    int max_freq = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        max_freq = max(max_freq,freq[val]);
        group[freq[val]].push(val);
    }
    
    int pop() {
        int top_max = group[max_freq].top();
        group[max_freq].pop();
        freq[top_max]--;
        if(group[max_freq].size() == 0)
            max_freq--;
        return top_max;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */