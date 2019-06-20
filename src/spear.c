#include <stdio.h>

int n;
int k;
int A[100000];

int p (int x) {
  int sum = 0;
  if (x == 0) return 0;
  for (int i = 0; i < n; i++){      //長さxの棒がsum本だけ作れる
    sum += A[i] / x;
  }
  return sum < k;    //p(x)を非減少単調数列とする(作れるなら0,作れないなら1を返す)
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = -1;    //出力の最小値-1
  ub = 1000000001;    //出力の最大値+1

  while (ub - lb > 1) {
    int m = (ub + lb) / 2;
    if (p(m)) ub = m;
    else lb = m;
  }

  printf("answer is %d\n", ub-1);


  return 0;
}
