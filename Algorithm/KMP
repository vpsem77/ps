int cnt;
vector<int> res;
vector<int> failure(string& s){
    vector<int> f(s.size());
    int j = 0;
    for(int i=1;i<s.size();i++){
        while(j > 0 && s[i] != s[j]) j = f[j-1];
        if(s[i] == s[j]) f[i] = ++j;
    }
    return f;
}
// par중간에 text가 몇번 나타나는지 cnt에 저장, 그 위치는 res에 저장
string pat, text;
getline(cin,pat);
getline(cin,text);
vector<int> f = failure(text);
int j = 0;
for(int i=0;i<pat.size();i++){
    while(j > 0 && pat[i] != text[j]) j = f[j-1];
    if(pat[i] == text[j]) j++;
    if(j == text.size()){
        cnt++;
        res.push_back(i-j+2);
        j = f[j-1];
    }
}
