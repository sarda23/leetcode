class BrowserHistory {
public:
    // using 2 stacks

    stack<string> past;
    stack<string> future;
    string curr;

    BrowserHistory(string homepage) {
        curr = homepage;
    }
    
    void visit(string url) {
        past.push(curr);
        curr = url;
        // q ki hm visit kie hai toh ab se naya future banega - toh islia future wale stack ko clear kar denge - ya toh for loop use kar lo delete karne ke lia ya toh naya stack assign kar lo - woh clear ho jayega
        future = stack<string>(); 
    }
    
    string back(int steps) {
        while(steps>0 && !past.empty()){
            future.push(curr);
            curr = past.top();
            past.pop();
            steps--;
        }

        return curr;
    }
    
    string forward(int steps) {
        while(steps>0 && !future.empty()){
            past.push(curr);
            curr = future.top();
            future.pop();
            steps--;
        }

        return curr;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */