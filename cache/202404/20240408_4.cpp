#include<bits/stdc++.h>
//using ll = long long;
using namespace std;

const int N = 10 + 10;

int cpot[N + 1], num[N + 1];


struct TupNode{
    int r, c, d;
};

struct TSMatrix{
    int rows, cols, nums;
    TupNode tup[N] = {};
};

void Trans(TSMatrix M){
	int temp[N + 1][N + 1] = {};
	for(int i = 0; i < M.rows; i++){
		for(int j = 0; j < M.cols; j++){
			for(int k = 0; k < M.nums; k++){
				if(i == M.tup[k].r && j == M.tup[k].c){
					temp[i][j] = M.tup[k].d;
				}
			}
		}
	}
	
	for(int i = 0; i < M.rows; i++){
		for(int j = 0; j < M.cols; j++){
			cout << temp[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void FastTranspose(TSMatrix M, TSMatrix &T){
    T.rows = M.cols, T.cols = M.rows, T.nums = M.nums;
    int cnt = 3;
    
    if(T.nums){
        for(int i = 0; i < M.nums; ++i) num[M.tup[i].c]++;

        for(int col = 1; col < M.nums; ++col) cpot[col] = cpot[col - 1] + num[col - 1];
		
		for(int i = 0; i < M.nums - 1; ++i) cout << cpot[i] << ' ';
		
		cout << '\n' << '\n';
		
        for(int i = 0; i < M.nums; ++i){
        	if(i == 3){
        		for(int j = 0; j < T.nums; ++j){
        			cout << T.tup[j].r << " " << T.tup[j].c << " " << T.tup[j].d << '\n';
    			}
			}
            int col = M.tup[i].c;
            T.tup[cpot[col]].r = M.tup[i].c;
            T.tup[cpot[col]].c = M.tup[i].r;
            T.tup[cpot[col]].d = M.tup[i].d;
            cpot[col]++;
        }
    }
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    TSMatrix M, T;
    cin >> M.rows >> M.cols >> M.nums;

    for(int i = 0; i < M.nums; ++i){
        cin >> M.tup[i].r >> M.tup[i].c >> M.tup[i].d;
    }
    
    Trans(M);

    FastTranspose(M, T);

//    for(int i = 0; i < T.nums; ++i){
//        cout << T.tup[i].r << " " << T.tup[i].c << " " << T.tup[i].d << '\n';
//    }
    
    cout << '\n';
    
    Trans(T);
    
    return 0;
}