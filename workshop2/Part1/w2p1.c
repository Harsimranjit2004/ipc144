
/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
Full Name  :Harsimranjit singh
Student ID#:155452220
Email      :hsingh956@myseneca.ca
Section    :NNN

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const double TAX = 0.13;
    
    float s, m, l;
    int num;
    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%f", &s);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%f", &m);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%f", &l);
    printf("\nShirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2f\n", s);
    printf("MEDIUM : $%.2f\n", m);
    printf("LARGE  : $%.2f\n\n", l);
    printf("Patty's shirt size is \'S\'\n");
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &num);
    float subtotal, tax, total;
    subtotal = s * num;
    tax = (subtotal * TAX) + 0.0016;
    total = tax + subtotal;
    printf("\nPatty's shopping cart...\n");
    printf("Contains : %d shirts\n", num);
    printf("Sub-total: $%.4f\n", subtotal);
    printf("Taxes    : $%8.4f\n", tax);
    printf("Total    : $%.4f\n", total);

    return 0;
}
