/**
 * Checks if the rabbit can escape from the fox through a hole.
 * rabbit can escape if there is a hole feasible to reach before the fox.
 * fox velocity is 2x rabbit's velocity
 * all coordinates/distances are given in meters
 * gcc -Wall -Wextra -O3 -std=c17 -pedantic (compilation params)
 *
 * Authors: Luiz Felipe Diniz and Victor Ferrari
 * Last Modified: 17/08/2023
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * Plenty of structs, just to keep the code
 * a little bit cleaner.
 *
 * x and y are the initial coordinates
 * xDistanceToHole and yDistanceToHole is the difference between
 * the hole initial coordinates and rabbit/fox ones.
 */
struct Rabbit
{

    double x;
    double y;
    double velocity;
    double xDistanceToHole;
    double yDistanceToHole;
    double totalDistanceToHole;
    bool hasEscaped;
};

struct Fox
{

    double x;
    double y;
    double velocity;
    double xDistanceToHole;
    double yDistanceToHole;
    double totalDistanceToHole;
};

struct Hole
{

    double x;
    double y;
};

int main()
{

    /**
     * the main idea is to calculate the real distance of each animal
     * from hole (using pythagorean theorem) and calculate the time
     * which each animal is taking to reach it
     */
    struct Rabbit rabbit;
    struct Fox fox;
    struct Hole hole;

    /**
     * we are concerned only with the first feasible escape, that's why
     * I'm declaring 2 variables (escapeX and escapeY) to keep track of it
     */
    int totalHoles;
    double escapeX = 0.000;
    double escapeY = 0.000;
    double rabbitTime = 0.0;
    double foxTime = 0.0;

    // arbitrary velocities in meters per second
    rabbit.hasEscaped = false;
    fox.velocity = 2.000;
    rabbit.velocity = 1.000;

    // test inputs (avaible at sqtpm professor's website)
    scanf("%d %lf %lf %lf %lf", &totalHoles, &rabbit.x, &rabbit.y, &fox.x, &fox.y);

    for (int i = 1; (i <= totalHoles); i++)
    {
        /**
         * in this chunk of code I'm calculating the time, using the
         * absolute value of delta(hole coordinates and animal coordinates).
         * Double data type was chosen here to reach the desire precision
         * (professor's coordinates inputs follows the pattern: xyz.abcdef)
         * where each letter is a number ranging from 0 to 9
         */
        scanf("%lf %lf", &hole.x, &hole.y);

        fox.xDistanceToHole = (fabs(hole.x - fox.x));
        fox.yDistanceToHole = (fabs(hole.y - fox.y));
        fox.totalDistanceToHole = sqrt((pow(fox.xDistanceToHole, 2)) + (pow(fox.yDistanceToHole, 2)));

        rabbit.xDistanceToHole = (fabs(hole.x - rabbit.x));
        rabbit.yDistanceToHole = (fabs(hole.y - rabbit.y));
        rabbit.totalDistanceToHole = sqrt((pow(rabbit.xDistanceToHole, 2)) + (pow(rabbit.yDistanceToHole, 2)));

        foxTime = (fox.totalDistanceToHole / fox.velocity);
        rabbitTime = (rabbit.totalDistanceToHole / rabbit.velocity);

        if ((rabbitTime < foxTime) && (!rabbit.hasEscaped))
        {
            /**
             * saving the first feasible rabbit escape.
             * unfortunately, the loop can't be broken here
             * because we have to read all the inputs from
             * professor's tests.
             */
            escapeX = hole.x;
            escapeY = hole.y;
            rabbit.hasEscaped = true;
        }
    }

    // output after the loop has finished
    if (rabbit.hasEscaped == true)
    {

        printf("O coelho pode escapar pelo buraco (%.3lf,%.3lf).\n", escapeX, escapeY);
    }
    else
    {

        printf("O coelho nao pode escapar.\n");
    }

    return 0;
}
