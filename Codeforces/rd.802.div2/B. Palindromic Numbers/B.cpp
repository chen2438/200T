#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

struct INT{
    vector<int> X;
    int r;//r余数
    bool neg;//负数
    
    bool less(INT B){//X<B.X, 两者都为正数
        if (X.size() != B.X.size()) return X.size() < B.X.size();
        for (int i = X.size() - 1; i >= 0; i -- ) {
            if(X[i] != B.X[i]) return X[i] < B.X[i];
        }
        return false;
    }
    
    void sub(INT B){  // X -= B, 支持小减大, 两者都为正数
        vector<int> C;
        int Cneg;
        if(less(B)) {Cneg=true; swap(X,B.X);}
        else Cneg=false;
        for (int i = 0, t = 0; i < X.size(); i ++ ){
            t = X[i] - t;
            if (i < B.X.size()) t -= B.X[i];
            C.push_back((t + 10) % 10);
            if (t < 0) t = 1;
            else t = 0;
        }
        while (C.size() > 1 && C.back() == 0) C.pop_back();
        X = C;
        neg = Cneg;
    }
    
    void getINT(){//输入
        X.clear();
        string a;cin>>a;
        if (a[0] == '-') {
            neg = true;
            for (int i = a.size() - 1; i >= 1; i -- ) X.push_back(a[i] - '0');
        }
        else {
            neg = false;
            for (int i = a.size() - 1; i >= 0; i -- ) X.push_back(a[i] - '0');
        }
    }
    
    void putINT(){//输出
        if(neg) cout<<'-';
        for (int i = X.size() - 1; i >= 0; i -- ) cout << X[i];
        cout<<endl;
    }
};

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		INT N,M;
		N.getINT();
		if(N.X[N.X.size()-1]==9){
			FOR(i,1,N.X.size()+1) M.X.push_back(1);
		}
		else{
			FOR(i,1,N.X.size()) M.X.push_back(9);
		}
		M.sub(N);
		M.putINT();
	}
	return 0;
}