#include <stdio.h>
#include <math.h>

int sumAllDivisors(int num){
int sum=1;
int remainder=0;
int quotient=0;
int sqRoot = sqrt(num);

for(int i=2;i<=sqRoot;i++){
    quotient=num/i;
    remainder=num%i;
    if(remainder==0){
        (quotient==i)?(sum+=i):(sum+=i+quotient);
        //perfect square numbers results in quotient==divisor (sum redundancy)
    }
}
return sum;
}

int main() {
int n,m;
int nSum,mSum;

printf("Reading n and m: ");
scanf("%d %d[^\n]",&n,&m);

nSum=sumAllDivisors(n);
mSum=sumAllDivisors(m);

if(n==1 && m==1){
    printf("%d e %d nao sao amigos\n",n,m);
}else{
    (nSum==m && mSum==n)?printf("%d e %d sao amigos\n",n,m):printf("%d e %d nao sao amigos\n",n,m);
}
return 0;
}
