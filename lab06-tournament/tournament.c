#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TeamCard
{
    /* data */
    char teamName[30];
    int wins;
    int losses;
    int draws;
    int goalsScored;
    int goalsConceded;
    int matchesPlayed;
    int totalPoints;
};

int alphabeticalSort(struct TeamCard *player1, struct TeamCard *player2)
{
    return (strcmp(player1->teamName, player2->teamName));
}

int totalPointsSort(struct TeamCard *player1, struct TeamCard *player2)
{
    if (player1->totalPoints == player2->totalPoints)
    {
        return (totalWinsSort(player1, player2));
    }
    else if (player1->totalPoints > player2->totalPoints)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int totalWinsSort(struct TeamCard *player1, struct TeamCard *player2)
{
    if (player1->wins == player2->wins)
    {
        return (netGoalsSort(player1, player2));
    }
    else if (player1->wins > player2->wins)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int netGoalsSort(struct TeamCard *player1, struct TeamCard *player2)
{
    int netGoals1 = player1->goalsScored - player1->goalsConceded;
    int netGoals2 = player2->goalsScored - player2->goalsConceded;
    if (netGoals1 == netGoals2)
    {
        return (goalsScoredSort(player1, player2));
    }
    else if (netGoals1 > netGoals2)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int goalsScoredSort(struct TeamCard *player1, struct TeamCard *player2)
{
    if (player1->goalsScored == player2->goalsScored)
    {
        return (lessGamesSort(player1, player2));
    }
    else if (player1->goalsScored > player2->goalsScored)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int lessGamesSort(struct TeamCard *player1, struct TeamCard *player2)
{
    if (player1->matchesPlayed == player2->matchesPlayed)
    {
        return (alphabeticalSort(player1, player2));
    }
    else if (player1->matchesPlayed > player2->matchesPlayed)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void auxPrint(struct TeamCard *tournament, int numberOfTeams)
{
    for (int i = 0; i < numberOfTeams; i++)
    {
        /* code */
        printf("%d) %s, %dp, %dj (%d-%d-%d), %ds (%d-%d)\n", i + 1,
               tournament[i].teamName, tournament[i].totalPoints, tournament[i].matchesPlayed,
               tournament[i].wins, tournament[i].draws, tournament[i].losses,
               (tournament[i].goalsScored - tournament[i].goalsConceded), tournament[i].goalsScored, tournament[i].goalsConceded);
    }
}

int binarySearch(struct TeamCard *tournament, int start, int end, char *playerName)
{

    int m = (end + start) / 2;
    int compare = strcmp(playerName, tournament[m].teamName);

    if (compare == 0)
    {
        return m;
    }

    if (start >= end)
    {
        return 0;
    }
    else if (compare > 0)
    {
        return binarySearch(tournament, m + 1, end, playerName);
    }
    else
    {
        return binarySearch(tournament, start, m - 1, playerName);
    }
}

int main()
{

    int totalOfTournaments;
    int totalOfMatches;
    int totalOfTeams;
    char tournamentName[100];

    scanf("%d ", &totalOfTournaments);

    for (int i = 0; i < totalOfTournaments; i++)
    {
        fgets(tournamentName, 100, stdin);
        scanf("%d ", &totalOfTeams);
        struct TeamCard *Tournament = malloc(sizeof(struct TeamCard) * totalOfTeams);
        for (int j = 0; j < totalOfTeams; j++)
        {

            // scanf("%s", Tournament[j].teamName);
            scanf("%[^\n]%*c ", Tournament[j].teamName);
            Tournament[j].wins = 0;
            Tournament[j].losses = 0;
            Tournament[j].draws = 0;
            Tournament[j].goalsScored = 0;
            Tournament[j].goalsConceded = 0;
            Tournament[j].matchesPlayed = 0;
            Tournament[j].totalPoints = 0;
        }

        qsort(Tournament, totalOfTeams, sizeof(struct TeamCard), alphabeticalSort);

        scanf("%d ", &totalOfMatches);
        char team1[30];
        char team2[30];
        int score1;
        int score2;
        int team1Index;
        int team2Index;
        printf("%s", tournamentName);
        for (int z = 0; z < totalOfMatches; z++)
        {
            /* code */
            scanf("%[^#]#%d@%d#%s ", team1, &score1, &score2, team2);
            team1Index = binarySearch(Tournament, 0, totalOfTeams - 1, team1);
            team2Index = binarySearch(Tournament, 0, totalOfTeams - 1, team2);

            if (score1 == score2)
            {
                Tournament[team1Index].draws++;
                Tournament[team1Index].matchesPlayed++;
                Tournament[team1Index].goalsScored += score1;
                Tournament[team1Index].goalsConceded += score2;
                Tournament[team1Index].totalPoints += 1;

                Tournament[team2Index].draws++;
                Tournament[team2Index].matchesPlayed++;
                Tournament[team2Index].goalsScored += score2;
                Tournament[team2Index].goalsConceded += score1;
                Tournament[team2Index].totalPoints += 1;
            }
            else if (score1 > score2)
            {
                Tournament[team1Index].wins++;
                Tournament[team1Index].matchesPlayed++;
                Tournament[team1Index].goalsScored += score1;
                Tournament[team1Index].goalsConceded += score2;
                Tournament[team1Index].totalPoints += 3;

                Tournament[team2Index].losses++;
                Tournament[team2Index].matchesPlayed++;
                Tournament[team2Index].goalsScored += score2;
                Tournament[team2Index].goalsConceded += score1;
            }
            else
            {
                Tournament[team1Index].losses++;
                Tournament[team1Index].matchesPlayed++;
                Tournament[team1Index].goalsScored += score1;
                Tournament[team1Index].goalsConceded += score2;

                Tournament[team2Index].wins++;
                Tournament[team2Index].matchesPlayed++;
                Tournament[team2Index].goalsScored += score2;
                Tournament[team2Index].goalsConceded += score1;
                Tournament[team2Index].totalPoints += 3;
            }
        }
        qsort(Tournament, totalOfTeams, sizeof(struct TeamCard), totalPointsSort);
        auxPrint(Tournament, totalOfTeams);
        printf("\n");
        free(Tournament);
    }

    return 0;
}