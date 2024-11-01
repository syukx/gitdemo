#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <time.h>
int randomNo(int n)
{
    srand(time(NULL));
    return rand() % n;
}
void player(char ch, char player[])
{
    switch (ch)
    {
    case 0:
        printf("\n%s CHOSE ROCK....", player);
        break;
    case 1:
        printf("\n%s CHOSE PAPER....", player);
        break;
    case 2:
        printf("\n%s CHOSE SCISSORS....", player);
        break;
    default:
        printf("\nINVALID INPUT!!!");
        exit(0);
        break;
    }
}
char actions(int user, int random)
{

    if (user == random)
        return 'd';
    else if (user == 0 && random == 1)
        return 'r';
    else if (user == 1 && random == 0)
        return 'u';
    else if (user == 0 && random == 2)
        return 'u';
    else if (user == 2 && random == 0)
        return 'r';
    else if (user == 1 && random == 2)
        return 'r';
    else if (user == 2 && random == 1)
        return 'u';
}

// int result(char res)
// {
//     if (res == 'r')
//         return 0;
//     else
//         return 1;
// }
int main()
{
    char n[100], p1[100], p2[] = "PLAYER2";
    int ch, cu = 0, cr = 0, round;
    printf("\n~~~~~GAME RULES:~~~~~\n0.ROCK\n1.PAPER\n2.SCISSORS\n");
    printf("\nHOW MANY ROUNDS?");
    scanf("%d", &round);
    getchar();
    printf("\nENTER YOUR NAME:");
    gets(n);
    strcpy(p1, n);
    for (int i = 0; i < round; i++)
    {
        printf("\n\nENTER YOUR CHOICE:");

        scanf("%d", &ch);
        player(ch, p1);
        int random = randomNo(3);

        player(random, p2);
        if (actions(ch, random) == 'd')
            printf("\nDRAW THIS ROUND.");

        else if (actions(ch, random) == 'r')
        {
            printf("\n%s WON THIS ROUND.", p2);
            cr++;
        }
        else
        {
            printf("\n%s WON THIS ROUND.", p1);
            cu++;
        }
    }
    printf("\n\n~~~~~~SCORES~~~~~~\n\n");
    printf("%s:%d", p1, cu);
    printf("\n%s:%d\n", p2, cr);
    printf("~~~~~~~~~~~~~~~~~~\n");
    if (cu > cr)
        printf("\nOVERALL WIN:%s", p1);
    else if (cr > cu)
        printf("\nOVERALL WIN:%s", p2);
    else
        printf("\nDRAW");

    return 0;
}