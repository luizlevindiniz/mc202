/**
 * A new calendar system was adopted. Now, for every
 * 12 hours of sunlight, the day change, no matter
 * how long does it take.
 *
 * Input: date, followed by sunrise time and sunset time
 * example
 *
 *  01/01/1970 	09:05:31 	17:01:59
 *  02/01/1970 	09:05:23 	17:03:03
 *  03/01/1970 	09:05:11 	17:04:10

 * Output: the new date considering that our new calendar
    system was adopted at the first input's date.

    (considering the example above)
    01/01/1970 - initial date
    02/01/1970 - is now the real date (expected output)

    Why? Because at 01/01/1970 the sun rose at 09:05:31
    and set at 17:01:59, that gives us a delta of
    (7 hours, 56 minutes and 28 seconds). But we need
    12 hours os sunlight to a day change.

 * Authors: Luiz Felipe Diniz
 * Last Modified: 30/08/2023
 */

#include <stdio.h>

struct Date
{
    int day;
    int month;
    int year;
};

struct Time
{
    int hour;
    int minute;
    int second;
};

// function to check if a certain year is a leap year
int checkLeapYear(int year)
{
    // 0 is not leap | 1 is leap
    int leap = 0;

    if (year % 4 == 0 && (year % 400 == 0 || year % 100 != 0))
    {
        leap = 1;
    }

    return leap;
}

// calculate the time difference (in seconds) between a sunset Time and a sunrise Time
// long int pointer is a pointer to update totalDiff in main function
void calculateTimeDiff(struct Time sunrise, struct Time sunset, long int *diff)
{

    int sunriseSeconds = sunrise.hour * 3600 + sunrise.minute * 60 + sunrise.second;
    int sunsetSeconds = sunset.hour * 3600 + sunset.minute * 60 + sunset.second;
    int delta = sunsetSeconds - sunriseSeconds;

    // the if below is necessary, since our input Time is 24 hour pattern
    // example: if the sun rise at day 1 - 8:00:00, but set at 01:00:00, 01:00:00 is
    // 17 hours apart from 8:00:00, and we are already at day 2.
    if (delta < 0)
    {
        delta += 24 * 3600;
    }

    (*diff) += delta;
}

// given initial date (dd/mm/yyyy) and a number of days, calculate the final Date
// adding up days to inital date
void calculateFinalDate(struct Date *initialDate, int daysToFinalDate)
{
    int daysInEachMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (checkLeapYear((*initialDate).year))
    {
        daysInEachMonth[1] = 29;
    };

    for (int i = daysToFinalDate; i > 0; i--)
    {
        (*initialDate).day += 1;

        // daysInEachMonth[something - 1]. -1 is just do adjust the month to
        // vector's index (0 - 11 instead of 1 - 12 months)
        if ((*initialDate).day > daysInEachMonth[(*initialDate).month - 1])
        {
            (*initialDate).day = 1;
            (*initialDate).month += 1;
        };

        if ((*initialDate).month > 12)
        {
            (*initialDate).month = 1;
            (*initialDate).year += 1;

            // check if the new year is leap year
            if (checkLeapYear((*initialDate).year))
            {
                daysInEachMonth[1] = 29;
            }
            else
            {
                daysInEachMonth[1] = 28;
            };
        };
    };
}

// we have 4 different possible scenarios:
// first: the sun rose but not set - in this case, every hour is a sunlight hour
// second: the sun not rose and not set - 24h of daylight
// third: the sun not rose but set - end of continuous daylight cycle
// fourth: the sun rose and set - normal delta to calculate sunlight hours

// *Obs: for the first and third case, we "faked" a sunset or a sunrise, only to
// shift the sunset or sunrise hours to a commom point. At the first case, we
// are considering that the sun has set at 23:59:59 of the same day, and at the
// third case we consider that the sun has risen at 00:00:01 of the next day.
void possibleScenarios(struct Time sunrise, struct Time sunset, long int *diff, int *sunsetPointer)
{
    // first
    if (sunrise.hour != 99 && sunset.hour == 99)
    {

        (*sunsetPointer) = 0; // hasSunSet = false
        sunset.hour = 23;
        sunset.minute = 59;
        sunset.second = 59;
        calculateTimeDiff(sunrise, sunset, diff);
    }
    // second
    else if (sunrise.hour == 99 && sunset.hour == 99 && (*sunsetPointer) == 0)
    {
        (*diff) += 3600 * 24;
    }
    // third
    else if (sunrise.hour == 99 && sunset.hour != 99 && (*sunsetPointer) == 0)
    {

        sunrise.hour = 0;
        sunrise.minute = 0;
        sunrise.second = 1;
        (*diff) += 3600 * 24;
        calculateTimeDiff(sunrise, sunset, diff);
        (*sunsetPointer) = 1; // hasSunSet = true
    }
    // fourth
    else
    {
        calculateTimeDiff(sunrise, sunset, diff);
    }
}

int main()
{
    struct Date date;
    struct Time sunrise;
    struct Time sunset;

    long int totalDiff = 0;
    long int *diffPointer = &(totalDiff); // totalDiff pointer, used in the funcions above
    int daysToFinalDate;
    int hasSunSet = 1;                 // bool to check if the sun has set in a given day
    int *sunSetPointer = &(hasSunSet); // hasSunSet pointer, used in the functions above

    // a standalone scanf only to store the initial date (dd/mm/yyyy)
    // (as mentioned, initial date is the date from the first user's input)
    scanf("%d/%d/%d%d:%d:%d%d:%d:%d[^\n]", &date.day, &date.month, &date.year, &sunrise.hour,
          &sunrise.minute, &sunrise.second, &sunset.hour, &sunset.minute, &sunset.second);

    possibleScenarios(sunrise, sunset, diffPointer, sunSetPointer);

    // the input is always structure as dd/mm/yyyy hh:mm:ss hh:mm:ss
    // we are concerned only with sunrise and sunset hours now, that gives us
    // 6 conversion for scanf. Scanf function returns the number of successful
    // conversions.
    while (scanf("%*d/%*d/%*d%d:%d:%d%d:%d:%d[^\n]", &sunrise.hour,
                 &sunrise.minute, &sunrise.second, &sunset.hour, &sunset.minute, &sunset.second) == 6)
    {
        possibleScenarios(sunrise, sunset, diffPointer, sunSetPointer);
    }

    daysToFinalDate = (totalDiff) / (3600 * 12); // 12 hour day

    // for performance, we are using the same date (struct Date type)
    // to store the final date, instead of creating a new one.
    calculateFinalDate(&date, daysToFinalDate);

    printf("%d/%d/%d\n", date.day, date.month, date.year);

    return 0;
}