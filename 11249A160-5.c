#include <stdio.h>

#define MAX 25

int matrix[MAX][MAX];
int visited_cities[MAX];
int limit;
int cost = 0;

/* Function to find nearest unvisited city */
int tsp(int city)
{
    int count;
    int nearest_city = -1;
    int minimum = 999;

    for(count = 0; count < limit; count++)
    {
        if(matrix[city][count] != 0 && visited_cities[count] == 0)
        {
            if(matrix[city][count] < minimum)
            {
                minimum = matrix[city][count];
                nearest_city = count;
            }
        }
    }

    if(nearest_city != -1)
    {
        cost += minimum;
    }

    return nearest_city;
}

/* Recursive function to generate minimum cost path */
void minimum_cost(int city)
{
    int nearest_city;

    visited_cities[city] = 1;
    printf("%d ", city + 1);

    nearest_city = tsp(city);

    if(nearest_city == -1)   // If all cities visited
    {
        printf("%d", 1);     // Return to starting city
        cost += matrix[city][0];
        return;
    }

    minimum_cost(nearest_city);
}

int main()
{
    int i, j;

    printf("Enter Total Number of Cities: ");
    scanf("%d", &limit);

    if(limit > MAX)
    {
        printf("Maximum supported cities: %d\n", MAX);
        return 0;
    }

    printf("\nEnter Cost Matrix:\n");

    for(i = 0; i < limit; i++)
    {
        for(j = 0; j < limit; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
        visited_cities[i] = 0;
    }

    printf("\nEntered Cost Matrix:\n");
    for(i = 0; i < limit; i++)
    {
        for(j = 0; j < limit; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nPath: ");
    minimum_cost(0);

    printf("\nMinimum Cost: %d\n", cost);

    return 0;
}
