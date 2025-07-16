#include <bits/stdc++.h>
using namespace std;
/*
   idenya adalah hanya ada 3 kemungkinan pada setiap angka/operation
   1. ketika matchstick ditempatnya dilepas 1
   2. ketika matchstick ditempatnya ditambah 1
   3. ketika matchstick ditempatnya dipindah 1

   ini bisa kita manual cari sendiri tanpa perlu algonya, kemudian kita 
   list di array atau vector yang nyimpan
   di code ini, ad untuk kasus 2, mn itu kasus 1, rv untuk kasus 3

   kemudian kita bisa melakukan rekursi dan mencatat berapa banyak matchstick 
   yg sudah dibuang dan ditambah
   kalau untuk dipindah akan dianggap sebagai ditambah dan dikurang
*/

vector<int> ad[13], mn[13], rv[13]; // 10 itu +, 11 itu -, 12 itu =
int op[5];
bool fn = 0;

void solve(int id, int a, int b) {
    printf("id: %d, a: %d, b: %d\n", id, a, b);
  if(id == 5) {
    if(a != 1 || b != 1) return;
    if(op[1] == 10 && op[0] + op[2] == op[4]) {
      fn = 1;
      for(int i=0;i<5;i++) {
        if(op[i] == 10) cout<<'+';
        else if(op[i] == 11) cout<<'-';
        else if(op[i] == 12) cout<<'=';
        //else cout<<op[i];
        printf("op[%d]: %d\n", i, op[i]);
      }
      cout<<"\n";
    } else if(op[1] == 11 && op[0] - op[2] == op[4]) {
      fn = 1;
      for(int i=0;i<5;i++) {
        if(op[i] == 10) cout<<'+';
        else if(op[i] == 11) cout<<'-';
        else if(op[i] == 12) cout<<'=';
        //else cout<<op[i];
        printf("op[%d]: %d\n", i, op[i]);
      }
      cout<<"\n";
    }
    return;
  } else if(id == 3) solve(id + 1, a, b);
  else {
    if(a == 0) {
      int num = op[id];
      for(auto p : ad[num]) {
        op[id] = p;
        solve(id + 1, a + 1, b);
        if(fn) return;
        op[id] = num;
      }
    }
    if(b == 0) {
      int num = op[id];
      for(auto p : mn[num]) {
        op[id] = p;
        solve(id + 1, a, b + 1);
        if(fn) return;
        op[id] = num;
      }
    }
    if(a == 0 && b == 0){
      int num = op[id];
      for(auto p : rv[num]) {
        op[id] = p;
        solve(id + 1, a + 1, b + 1);
        if(fn) return;
        op[id] = num;
      }
    }
    solve(id + 1, a, b);
  }
}

int main() {
  ad[11].push_back(10);
  ad[0].push_back(8);
  ad[6].push_back(8);
  ad[9].push_back(8);
  ad[5].push_back(6);
  ad[5].push_back(9);
  ad[3].push_back(9);
  ad[1].push_back(7);
  
  for(int i=0;i<13;i++) {
    for(auto p : ad[i]) mn[p].push_back(i);
  }
  
  rv[0].push_back(9), rv[9].push_back(0);
  rv[0].push_back(6), rv[6].push_back(0);
  rv[6].push_back(9), rv[9].push_back(6);
  rv[2].push_back(3), rv[3].push_back(2);
  rv[3].push_back(5), rv[5].push_back(3);
  
  string S;
  cin>>S;
  
  op[0] = S[0] - '0';
  if(S[1] == '+') op[1] = 10;
  else op[1] = 11;
  op[2] = S[2] - '0';
  op[3] = 12;
  op[4] = S[4] - '0';
  
  solve(0, 0, 0);
  if(!fn) cout<<"-1\n";
  return 0;
}
