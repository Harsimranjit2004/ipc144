/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
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

float ownfmod(double num1, double num2)
{
    int div = num1 / num2;
    float res;
    res = num1 - (div)*num2;
    return res;
}
float roundfff(float num)
{
    int n;
    float mul;
    mul = num * 10;
    n = (int)mul;
    int o;
    o = n % 10;
    n = n / 10;
    int res;
    if (o > 5)
    {
        res = n + 1;
    }
    else if (o == 0)
    {
        res = n;
    }

    else
    {
        res = n - 1;
    }

    return res;
}
float myFloor(float num)
{
    int n;
    n = num * 100;
    n = (int)n;
    double res;
    res = n / 100.00;
    return res;
}
int printCoins(double balances)
{

    float tonnie;
    double balance = balances;
    tonnie = (int)(balance / 2.00);
    double left_balance;
    left_balance = ownfmod(balance, 2.00);
    printf("Toonies  %.0f %9.4f\n", tonnie, left_balance);
    balance = left_balance;

    float loonie;
    loonie = (int)(balance / 1.00);
    left_balance = ownfmod(balance, 1.00);
    printf("Loonies  %3.0f %9.4f\n", loonie, left_balance);
    balance = left_balance;

    float quarter;
    quarter = (int)(balance / 0.25);
    left_balance = ownfmod(balance, 0.25);
    printf("Quarters %3.0f %9.4f\n", quarter, left_balance);
    balance = left_balance;

    float dimes;
    dimes = (int)(balance / 0.10);
    left_balance = ownfmod(balance, 0.10);
    printf("Dimes    %3.0f %9.4f\n", dimes, left_balance);
    balance = left_balance;

    float nickles;
    nickles = (int)(balance / 0.05);
    left_balance = ownfmod(balance, 0.05);
    printf("Nickels  %3.0f %9.4f\n", nickles, left_balance);
    balance = left_balance;

    float pennies;
    pennies = (int)(balance / 0.01);
    left_balance = ownfmod(balance, 0.01);
    printf("Pennies  %3.0f %9.4f\n\n", pennies, left_balance);
    balance = left_balance;
    return 0;
}
int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S', salSize = 'M', tomSize = 'L';
    float s, m, l;
    int Pnum, Tnum, Snum;
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
    printf("LARGE  : $%.2f\n", l);
    printf("\nPatty's shirt size is \'%c\'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &Pnum);
    printf("\nTommy's shirt size is \'%c\'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &Tnum);
    printf("\nSally's shirt size is \'%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &Snum);
    float p_subtotal, p_tax, p_total;
    p_subtotal = (s * Pnum);
    p_tax = (p_subtotal * TAX);
    p_total = (p_tax + p_subtotal);
    p_subtotal = roundfff(p_subtotal * 100) / 100;
    p_tax = roundfff(p_tax * 100) / 100;
    p_total = roundfff(p_total * 100) / 100;

    float s_subtotal, s_tax, s_total;
    s_subtotal = m * Snum;
    s_tax = s_subtotal * TAX;
    s_total = (s_tax + s_subtotal);
    s_subtotal = roundfff(s_subtotal * 100) / 100;
    s_tax = roundfff(s_tax * 100) / 100;
    s_total = roundfff(s_total * 100) / 100;

    float t_subtotal, t_tax, t_total;
    t_subtotal = Tnum * l;
    t_tax = t_subtotal * TAX;
    t_total = t_subtotal + t_tax;
    
    t_subtotal = roundfff(t_subtotal * 100) / 100;
    t_tax = roundfff(t_tax * 100) / 100;
    t_total = roundfff(t_total * 100) / 100;

    printf("\nCustomer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    S    %5.2lf %3d %9.4f %9.4f %9.4f\n", s, Pnum, p_subtotal, p_tax, p_total);
    printf("Sally    M    %5.2lf %3d %9.4f %9.4f %9.4f\n", m, Snum, s_subtotal, s_tax, s_total);
    printf("Tommy    L    %5.2lf %3d %9.4f %9.4f %9.4f\n", l, Tnum, t_subtotal, t_tax, t_total);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    double total_sub, total_tax, end_total;
    total_sub = p_subtotal + t_subtotal + s_subtotal;
    total_tax = p_tax + t_tax + s_tax;
    end_total = p_total + t_total + s_total;
    printf("%33.4lf %9.4lf %9.4lf\n\n", total_sub, total_tax, end_total);
    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("              %.4f\n",total_sub);
    printCoins(myFloor(total_sub));

    float avg = total_sub / (Pnum + Tnum + Snum);
    printf("Average cost/shirt: $%.4f\n\n", avg);

    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("              %.4f\n",end_total);
    printCoins(myFloor(end_total));
    float avgg = end_total / (Pnum + Tnum + Snum);
    printf("Average cost/shirt: $%.4f\n\n", avgg);
    return 0;
}
