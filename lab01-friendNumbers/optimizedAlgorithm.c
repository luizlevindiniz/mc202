/**
 * Checks if two numbers are friends.
 * m and n are friends if the sum of all divisors of m equals n and vice-versa.
 *
 * Authors: Luiz Felipe Diniz and Victor Ferrari
 * Last Modified: 06/08/2023
 */

#include <stdio.h>
#include <math.h>

/**
 * Calculates the sum of all divisors of "num".
 * Optimized approach:
 *   check if all numbers between 2 and sqrt(num) are divisors.
 *   if a number is a divisor, its quotient also is
 *   therefore, we only need to check up to sqrt(num).
 */

int sumAllDivisors(int num)
{
    int sum = 1;
    // int remainder=0;
    // int quotient=0;
    int sqRoot = sqrt(num);

    for (int i = 2; i < sqRoot; i++)
    {
        // quotient=num/i;
        // remainder=num%i;

        // If it's a divisor, add to the overall sum.
        if ((num % i) == 0)
        {
            sum += i + (num / i);
        }
    }

    // If the number is a perfect square, sqRoot = (num / sqRoot), so
    // it should be added only once

    if ((num % sqRoot) == 0)
    {
        //(quotient==i)?(sum+=i):(sum+=i+quotient);
        // perfect square numbers results in quotient==divisor (sum redundancy)
        sum += sqRoot;
    }

    return sum;
}

int main()
{
    int n, m;
    int nSum, mSum;

    printf("Reading n and m: ");
    scanf("%d %d[^\n]", &n, &m);

    // Strange base case, unsure why.
    if (n == 1 && m == 1)
    {
        printf("%d e %d nao sao amigos\n", n, m);
        return 0;
    }

    nSum = sumAllDivisors(n);
    mSum = sumAllDivisors(m);

    (nSum == m && mSum == n) ? printf("%d e %d sao amigos\n", n, m) : printf("%d e %d nao sao amigos\n", n, m);

    return 0;
}
