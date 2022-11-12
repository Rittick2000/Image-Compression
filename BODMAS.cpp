#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll>ans[30][30];

ll calculate(ll a, char op, ll b){
    if (op=='+') return a+b;
    else if (op=='-') return a-b;
    return a*b;
}

ll precedence(char ch){
    if(ch == '+'|| ch == '-')
        return 1;
    return 2;
}

vector<ll> allAnswers(string expr, ll low, ll high){
    if(!ans[low][high].empty()) return ans[low][high];
    vector<ll> res, operatorPos;
    for(ll i=low;i<=high;++i){
        if(!isdigit(expr[i])){
            operatorPos.push_back(i);
        }
    }

    if(operatorPos.size()==0){
        res.push_back(stoi(expr.substr(low,high-low+1)));
        return res;
    }

    else if(operatorPos.size()==1){
        ll num = calculate(stoi(expr.substr(low, operatorPos[0]-low)),expr[operatorPos[0]], stoi(expr.substr(operatorPos[0]+1,high-operatorPos[0])));
        res.push_back(num);
        return res;
    }

    for(ll i:operatorPos){
        vector<ll> l = allAnswers(expr, low, i-1);
        vector<ll> r = allAnswers(expr, i+1, high);
        for (ll j:l){
            for (ll k:r){
                res.push_back(calculate(j, expr[i], k));
            }
        }
    }

    sort(res.begin(), res.end());
    res.resize(distance(res.begin(), unique(res.begin(), res.end())));
    ans[low][high]=res;
    return res;
}


ll correctAnswer(string expr){
    stack <ll> values;
    stack <char> ops;
     
    for(ll i = 0; i < expr.length(); i++){
        if(isdigit(expr[i])){
            ll val = 0;   
            while(i < expr.length() && isdigit(expr[i])){
                val = (val*10) + (expr[i]-'0');
                ++i;
            } 
            values.push(val); 
            --i;
        }
         
        else{
            while(!ops.empty() && precedence(ops.top())>= precedence(expr[i])){
                ll val2 = values.top();
                values.pop();
                ll val1 = values.top();
                values.pop();
                 
                char op = ops.top();
                ops.pop();
                 
                values.push(calculate(val1, op, val2));
            }
            ops.push(expr[i]);
        }
    }
     
    while(!ops.empty()){
        ll val2 = values.top();
        values.pop();
                 
        ll val1 = values.top();
        values.pop();
                 
        char op = ops.top();
        ops.pop();
                 
        values.push(calculate(val1, op, val2));
    }
     
    return values.top();
}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    string expr;
    cin>>expr;
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;++i){
        cin>>arr[i];
    }
    ll answer = correctAnswer(expr);
    vector<ll>v = allAnswers(expr,0,expr.size()-1);
    ll score=0;
    for(ll i=0;i<n;++i){
        if(arr[i]==answer) score+=5;
        else if(binary_search(v.begin(), v.end(), arr[i])) score+=2;
    }
    cout<<score;
    return 0;
}