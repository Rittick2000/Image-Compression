void bonusToManager(int v , vector<bool>& bonus , vector<int>& parent){
    while(bonus[parent[v]] != true && parent[v] != 0){
        v = parent[v];
    }
    bonus[v] = true;
}
int main() {
    int N ,k;
    cin>>N>>k;
    vector<int> par(N+1);
    for(int i = 0 ; i < N ; i++){
        cin>>par[i+1];
    }
    vector<bool> bonus(N+1,false);
    int v;
    for(int i = 0 ;i < k ; i++){
        cin>>v;
        bonusToManager(v,bonus,par);
    }
    for(int i = 1 ; i <= N ; i++){
        if(bonus[i] == false){
            cout<<i<<" ";
        }
    }
    return 0;
}