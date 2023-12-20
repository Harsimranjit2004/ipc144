#include <stdio.h>
int main()
{
    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");

    while (1)
    {
        char loop_type;
        int iteration;
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &loop_type, &iteration);

        if (loop_type == 'D')
        {
            if (iteration >= 3 && iteration <= 20)
            {
                printf("DO-WHILE: ");
                int i = 0;
                do
                {
                    printf("D");
                    i++;
                } while (i < iteration);

                printf("\n\n");
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            }
        }
        else if (loop_type == 'W')
        {
            if (iteration >= 3 && iteration <= 20)
            {
                printf("WHILE   : ");
                int i = 0;
                do
                {
                    printf("W");
                    i++;
                } while (i < iteration);

                printf("\n\n");
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            }
        }
        else if (loop_type == 'F')
        {
            if (iteration >= 3 && iteration <= 20)
            {
                printf("FOR     : ");
                int i = 0;
                do
                {
                    printf("F");
                    i++;
                } while (i < iteration);

                printf("\n\n");
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            }
        }
        else if (loop_type == 'Q' && iteration != 0)
        {
            printf("ERROR: To quit, the number of iterations should be 0!\n\n");
        }
        else if (loop_type == 'Q' && iteration == 0)
        {
            break;
        }

        else
        {

            printf("ERROR: Invalid entered value(s)!\n\n");
        }
    }
    printf("\n");
    printf("+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");
    printf("\n");

        return 0;
}
