/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
Full Name  : Harsimranjit singh
Student ID#: 155452220
Email      : hsingh956@myseneca.ca
Section    : NNN

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#include <stdio.h>
#define MAX_PATH 70
#define MIN_PATH 5
#define MAX_LIVES 10
#define MIN_LIVES 1
struct PlayerInfo
{
    int lives;
    char symbol;
    int tresures;
    int past_position[MAX_PATH];
};
struct GameInfo
{
    int max_moves;
    int path_length;
    int bombs[MAX_PATH];
    int treasure[MAX_PATH];
};
void display_board(struct GameInfo game, struct PlayerInfo player, int past_counter)
{
       int i;
		
   
        if(past_counter !=0){
          printf("  ");
        }
        for (i = 0; i < game.path_length; i++) // 1st line
        {

            if (past_counter != 0 && past_counter == i + 1)
            {
                printf("%c", player.symbol);
		break;
            }
            else
            {
		if(past_counter !=0){

                printf(" ");
                 }
            }
        }
    

    printf("\n");
    printf("  "); 
    for (i = 0; i < game.path_length; i++) // second line

    {
        
        if (player.past_position[i] == 1)
        {
            if (game.bombs[i] == 1 && game.treasure[i] == 1)
            {
                printf("&");
            }
            else if (game.bombs[i] == 1)
            {
                printf("!");
            }
            else if (game.treasure[i] == 1)
            {
                printf("$");
            }
            else if (game.bombs[i] == 0 && game.treasure[i] == 0)
            {
                printf(".");
            }
        }
        else
        {
            printf("-");
        }
    }
    printf("\n");
     printf("  ");

    for (i = 1; i <= game.path_length; i++) // third line
    {
       
        if (i % 10 == 0)
        {
            int no = i / 10;
            printf("%d", no);
        }
        else
        {
            printf("|");
        }
    }
    printf("\n");
    printf("  ");
    for (i = 1; i <= game.path_length; i++)
    {
        int no = i % 10;
        printf("%d", no);
    }
    printf("\n");
}
void display_lives(int treasure_found, struct GameInfo game, struct PlayerInfo player)
{
    printf("+---------------------------------------------------+\n");
    printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.lives, treasure_found, game.max_moves);
    printf("+---------------------------------------------------+\n");
}
int main()
{
    // initilize the player and game
    struct PlayerInfo player = {0, ' ', 0, {0}};
    struct GameInfo game = {0, 0, {0}, {0}};
   
    // MAIN
    int treasure_found = 0;
    int past_counter = 0;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n");
    printf("\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.symbol);
    while (1)
    {
        int temp;
        printf("Set the number of lives: ");
        scanf("%d", &temp);
        if (temp <= MAX_LIVES && temp >= MIN_LIVES)
        {
            player.lives = temp;
            break;
        }
        else
        {
            printf("     Must be between 1 and 10!\n");
        }
    }
    printf("Player configuration set-up is complete\n");
    printf("\n");
    printf("GAME Configuration\n");
    printf("------------------\n");
    while (1)
    {
        int temp;
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &temp);
        if (temp >= MIN_PATH && temp <= MAX_PATH && temp % 5 == 0)
        {
            game.path_length = temp;
            break;
        }
        else
        {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
    }
    while (1)
    {
        int temp;
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &temp);
        int max_value = game.path_length * 0.75;
        if (temp >= player.lives && temp < max_value)
        {
            game.max_moves = temp;
            break;
        }
        else
        {
            printf("    Value must be between %d and %d\n", player.lives, max_value);
        }
    }
    printf("\n");
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.path_length);
    int sum = 0;
    int i = 0;
    int j = 5;
    while (sum < game.path_length)
    {

        printf("   Positions [%2d-%2d]: ", i + 1, j);
        int k;
        for (k = i; k < j; k++)
        {
            if (scanf("%d", &game.bombs[k]) != 1)
            {
                break;
            }
        }
        i += 5;
        j += 5;
        sum += 5;
    }
    printf("BOMB placement set\n");
    printf("\n");
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",game.path_length);
    sum = 0;
    i = 0;
    j = 5;
    while (sum < game.path_length)
    {

        printf("   Positions [%2d-%2d]: ", i + 1, j);
        int k;
        for (k = i; k < j; k++)
        {
            if (scanf("%d", &game.treasure[k]) != 1)
            {
                break;
            }
        }
        i += 5;
        j += 5;
        sum += 5;
    }
    printf("TREASURE placement set\n");
    printf("\n");
    printf("GAME configuration set-up is complete...\n");
    printf("\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.symbol);
    printf("   Lives      : %d\n", player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");
    printf("\n");
    printf("Game:\n");
    printf("   Path Length: %d\n",game.path_length);
    printf("   Bombs      : ");

    for (i = 0; i < game.path_length; i++)
    {
        printf("%d", game.bombs[i]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < game.path_length; i++)
    {
        printf("%d", game.treasure[i]);
    }
    printf("\n\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");
    
    while (game.max_moves > 0 && player.lives > 0)
    {

        display_board(game, player, past_counter);
        display_lives(treasure_found, game, player);

        int move;
        while (1)
        {
            printf("Next Move [1-%d]: ", game.path_length);
            scanf("%d", &move);
            if (move >= 1 && move <= game.path_length)
            {
                break;
            }
            else
            {
                printf("  Out of Range!!!\n");
            }
        }
        printf("\n");

        if (player.past_position[move - 1] == 1)
        {
            printf("===============> Dope! You've been here before!\n");
            past_counter = move;
        }
        else
        {
            past_counter = move;
            player.past_position[move - 1] = 1;
            if (game.bombs[move - 1] == 1 && game.treasure[move - 1] == 1)
            {
                printf("===============> [&] !!! BOOOOOM !!! [&]\n");
                printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
                player.lives--;
                treasure_found++;
            }
            else if (game.bombs[move - 1] == 0 && game.treasure[move - 1] == 0)
            {
                printf("===============> [.] ...Nothing found here... [.]\n");
            }

            else if (game.treasure[move - 1] == 1)
            {
                printf("===============> [$] $$$ Found Treasure! $$$ [$]\n");
                treasure_found++;
            }
            else if (game.bombs[move - 1] == 1)
            {
                printf("===============> [!] !!! BOOOOOM !!! [!]\n");

                player.lives--;
            }

            game.max_moves--;
        }

        printf("\n");
    }
   
    printf("No more LIVES remaining!\n");
    printf("\n");
    display_board(game, player, past_counter);
    display_lives(treasure_found, game, player);
    printf("\n");
    printf("##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n");
    printf("\n");
    printf("You should play again and try to beat your score!\n");
    printf("\n");
    return 0;
}
