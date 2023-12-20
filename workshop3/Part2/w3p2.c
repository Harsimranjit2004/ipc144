/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
Full Name  :Harsimranjit singh
Student ID#:155452220
Email      :hsingh956
Section    :NNN

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

char toLowercase(char ch) // this function helps to convert the uppercase letters to the lowercase letters
{
    if (ch >= 'A' && ch <= 'Z') // check if letter are capital
    {
        ch = ch + ('a' - 'A'); // use ascii value
    }
    return ch;
}
int main(void)
{

    const double GRAMS_IN_LBS = 453.5924;

    // this variables is for product specification
    char coffee1type, coffee2type, coffee3type;
    int coffee1bag, coffee2bag, coffee3bag;
    char cream1, cream2, cream3;

    // variables for customer
    char c_type, c_cream;
    int c_servings;

    // coffee product information
    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");
    printf("Enter the coffee product information being sold today...\n\n");

    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf("%c", &coffee1type);
    printf("Bag weight (g): ");
    scanf("%d", &coffee1bag);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream1);

    printf("\nCOFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffee2type);
    printf("Bag weight (g): ");
    scanf("%d", &coffee2bag);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream2);

    printf("\nCOFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffee3type);
    printf("Bag weight (g): ");
    scanf("%d", &coffee3bag);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream3);

    printf("\n");
    printf("---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |%4d   |%4d    |%4d   |%5d |%7.3f |%4d   |\n", coffee1type == 'l' || coffee1type == 'L', coffee1type == 'm' || coffee1type == 'M', coffee1type == 'r' || coffee1type == 'R', coffee1bag, (coffee1bag * 1 / GRAMS_IN_LBS), cream1 == 'y' || cream1 == 'Y');
    printf(" 2 |%4d   |%4d    |%4d   |%5d |%7.3f |%4d   |\n", coffee2type == 'l' || coffee2type == 'L', coffee2type == 'm' || coffee2type == 'M', coffee2type == 'r' || coffee2type == 'R', coffee2bag, (coffee2bag * 1 / GRAMS_IN_LBS), cream2 == 'y' || cream2 == 'Y');
    printf(" 3 |%4d   |%4d    |%4d   |%5d |%7.3f |%4d   |\n\n", coffee3type == 'l' || coffee3type == 'L', coffee3type == 'm' || coffee3type == 'M', coffee3type == 'r' || coffee3type == 'R', coffee3bag, (coffee3bag * 1 / GRAMS_IN_LBS), cream3 == 'y' || cream3 == 'Y');

    // customer coffee preference
    printf("Enter how you like your coffee...\n\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &c_type);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &c_cream);
    printf("Typical number of daily servings: ");
    scanf("%d", &c_servings);
    printf("\nThe below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|%8d         |%7d      |%4d   |\n", (((int)toLowercase(c_type)) == (int)toLowercase(coffee1type)), (c_servings >= 1 && c_servings <= 4), ((int)toLowercase(c_cream) == (int)toLowercase(cream1)));
    printf(" 2|%8d         |%7d      |%4d   |\n", (((int)toLowercase(c_type)) == (int)toLowercase(coffee2type)), (c_servings >= 5 && c_servings <= 9), ((int)toLowercase(c_cream) == (int)toLowercase(cream2)));
    printf(" 3|%8d         |%7d      |%4d   |\n\n", (((int)toLowercase(c_type)) == (int)toLowercase(coffee3type)), c_servings >= 10, ((int)toLowercase(c_cream) == (int)toLowercase(cream3)));

    printf("Enter how you like your coffee...\n\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &c_type);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &c_cream);
    printf("Typical number of daily servings: ");
    scanf("%d", &c_servings);
    printf("\nThe below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|%8d         |%7d      |%4d   |\n", (((int)toLowercase(c_type)) == (int)toLowercase(coffee1type)), (c_servings >= 1 && c_servings <= 4), ((int)toLowercase(c_cream) == (int)toLowercase(cream1)));
    printf(" 2|%8d         |%7d      |%4d   |\n", (((int)toLowercase(c_type)) == (int)toLowercase(coffee2type)), (c_servings >= 5 && c_servings <= 9), ((int)toLowercase(c_cream) == (int)toLowercase(cream2)));
    printf(" 3|%8d         |%7d      |%4d   |\n\n", (((int)toLowercase(c_type)) == (int)toLowercase(coffee3type)), c_servings >= 10, ((int)toLowercase(c_cream) == (int)toLowercase(cream3)));

    printf("Hope you found a product that suits your likes!\n\n");

    return 0;
}
