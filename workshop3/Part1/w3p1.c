/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  :Harsimranjit singh
Student ID#:155452220
Email      :hsingh956
Section    :NNN

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>


int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;
    const int pid1 = 111, pid2 = 222, pid3 = 111;
    double priceof1 = 111.49, priceof2 = 222.99, priceof3 = 334.49;
    char taxed1 = 'Y', taxed2 = 'N', taxed3 = 'N';
    double avg;
    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n", pid1);
    printf("  Taxed: %c\n", taxed1);
    printf("  Price: $%.4lf\n\n", priceof1);
    printf("Product-2 (ID:%d)\n", pid2);
    printf("  Taxed: %c\n", taxed2);
    printf("  Price: $%.4lf\n\n", priceof2);
    printf("Product-3 (ID:%d)\n", pid3);
    printf("  Taxed: %c\n", taxed3);
    printf("  Price: $%.4lf\n\n", priceof3);
    avg = (priceof1 + priceof2 + priceof3) / 3;
    printf("The average of all prices is: $%0.4lf\n\n", avg);
    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n\n");
    printf("Some Data Analysis...\n");
    printf("=====================\n");
    printf("1. Is product 1 taxable? -> %d\n\n", taxed1 == 'Y');
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", (taxed2 == 'N' && taxed3 == 'N'));
    printf("3. Is product 3 less than testValue ($%.2f)? -> %d\n\n", testValue, (priceof3 < testValue));
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", (priceof3 > (priceof1 + priceof2)));
    printf("5. Is the price of product 1 equal to or more than the price difference\n   of product 3 LESS product 2? ->  %d (price difference: $%0.2lf)\n\n", priceof1 >= (priceof3 - priceof2), (priceof3 - priceof2));
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n", (priceof2 >= avg));
    printf("7. Based on product ID, product 1 is unique -> %d\n\n", (pid1 != pid2 && pid1 != pid3));
    printf("8. Based on product ID, product 2 is unique -> %d\n\n", (pid2 != pid1 && pid2 != pid3));
    printf("9. Based on product ID, product 3 is unique -> %d\n\n", (pid3 != pid1 && pid3 != pid2));

    return 0;
}
