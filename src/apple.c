#include <stdio.h>

int n;
int k;
int A[100000];

int p (int x) {
  int sum = 0;
  for (int i = 0; i < n; i++){      //i番目の人のりんごの個数をxで割った切り上げ値の合計
    if (A[i] % x == 0) sum += A[i] / x;   
    else sum += A[i] / x + 1;
  }
  return sum <= k;    //x個までバッグに入れられる時、入力値は題意を満足するか
}


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;    //出力の最小値-1
  ub = 1000000001;    //出力の最大値+1

  while (ub - lb > 1) {
    int m = (ub + lb) / 2;
    if (p(m)) ub = m;
    else lb = m;
  }

  printf("answer is %d\n", ub);

  return 0;
}
