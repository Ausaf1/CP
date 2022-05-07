class Solution {
public:
    #define ll long long int
    bool isPalindrome(ll num){
    ll t = num,rev = 0;
    while(t > 0){
        rev = rev*10 + t%10;
        t/=10;
    }
    return num == rev;
}
    int superpalindromesInRange(string left, string right) {
        ll lt = stol(left);
        ll rt = stol(right);
        int n = 0;
        for(int i = 1;i < 100000;i++){
            string s = to_string(i);
            s.append(s.rbegin(),s.rend());
            ll number = stol(s);
            number*=number;
            if(number > rt)
                break;
            if(number >= lt && isPalindrome(number))
                n++;
        }
        for(int i = 1;i < 100000;i++){
            string s = to_string(i);
            s.append(s.rbegin()+1,s.rend());
            ll number = stol(s);
            number*=number;
            if(number > rt)
                break;
            if(number >= lt && isPalindrome(number))
                n++;
        }
        return n;
    }
};