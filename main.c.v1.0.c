#include <stdio.h>
#include <stdlib.h>
// write your code in C99 (gcc 6.2.0)

int ranksSorted[100000];
int mini_maxi[2];

/*
 *  -Function finds smallest and highest rank in ranks[] and store them in mini_maxi[2]
 *  -Arguments: set of ranks[] and the range of set
 *  -No returned values.
 */
void min_max(int ranks[], int N)
{
    int max_rank = ranks[0], min_rank = ranks[0];
    for(int i = 0; i < N; i++)
    {
        if(ranks[i] < min_rank)
            min_rank = ranks[i];
        if(ranks[i] > max_rank)
            max_rank = ranks[i];
    }
    mini_maxi[0] = min_rank;
    mini_maxi[1] = max_rank;
}

/*
 *  -Function makes an array "int ranksSorted[100000]" whose members are numbers of officers with the same ranks ordered by ranks.
 *   Needed is array of 100,000 members because a range from N.
 *  -Arguments: set of ranks[] and the range of set
 *  -No returned values.
 */
void ranksSortedArray(int ranks[], int N)
{
    min_max(ranks, N);
    int min_rank = mini_maxi[0];
    for(int i = 0; i < N; i++)
        ranksSorted[ranks[i] - min_rank]++;

    /* Just for debugging purpose */
    for(int i = 0; i < N; i++)
        printf("rankSorted[%d] =  %d\n", i, ranksSorted[i]);
}

/*
 *  -Function makes a sum of officers who are having their superiors with one rank up.
 *  -Arguments: set of ranks[] and the range of set
 *  -Returned value is 'subrankNo' - numbers of officers in 'ranks[]' who are having their superiors with one rank up.
 */
int subranksNumber(int ranks[], int N)
{
    ranksSortedArray(ranks, N);
    int subrankNo = 0, min_rank = mini_maxi[0], max_rank = mini_maxi[1];
    for(int i = max_rank; i >= min_rank + 1; i--)
    {
        /* If there is officer with rank 'i' add his one rank subordinars to the sum. */
        if(ranksSorted[i] > 0)
            subrankNo += ranksSorted[i -1];
            //printf("subrankNo =  %d\n", subrankNo);
    }
    return subrankNo;
}

/*
 *  -Required function
 *  -Arguments: set of ranks[] and the range of set
 *  -Returned value is required solution.
 */
int solution(int ranks[], int N)
{
    return subranksNumber(ranks, N);
}

int main()
{
    int ranks[9] = {3, 5, 3, 0, 4, 2, 3, 0, 1};
    printf("\nNumber of subranks (solution) = %d\n", solution(ranks, 9));
    return 0;
}
/*How many officers should salute their superiors if each salute only the officers who are one rank up?
  Given is a set of officers with their ranks as ranks[]. ranks[] have a range of 2 - 100,000, and ranks are form 0 to 1,000,000,000.
  Write a function:
                      int solution(int ranks[], int N)
*/
