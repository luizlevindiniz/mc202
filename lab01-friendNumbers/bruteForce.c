/**
 * Checks if two numbers are friends.
 * m and n are friends if the sum of all divisors of m equals n and vice-versa.
 *
 * Authors: Luiz Felipe Diniz and Victor Ferrari
 * Last Modified: 06/08/2023
 */

#include <stdio.h>

/**
 * Calculates the sum of all divisors of "num".
 * Brute force approach: check if all numbers between 2 and "num" are divisors
 */

int sumAllDivisors(int num){
    int sum=1;
    //int remainder=0;

for(int i=2;i<num;i++){
    //remainder=num%i;
    if((num % i) == 0){
        sum+=i;
    }
}

return sum;
}


int main() {
    int n,m;
    int nSum,mSum;

    printf("Reading n and m: ");
        scanf("%d %d[^\n]",&n,&m);

    // Strange base case, unsure why.
    if(n == 1 && m == 1) {
        printf("%d e %d nao sao amigos\n", n, m);
        return 0;
    }

    nSum=sumAllDivisors(n);
    mSum=sumAllDivisors(m);

    (nSum == m && mSum == n) ? printf("%d e %d sao amigos\n",n,m) : printf("%d e %d nao sao amigos\n",n,m);

    return 0;
}
