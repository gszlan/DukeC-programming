#include <stdlib.h>
#include <stdio.h>

struct _retire_info {
    int months;
    double contribution;
    double rate_of_return;
};

typedef struct _retire_info retire_info;

double calculate(int age, int months, double rate, double contribution, double savings) {

   double currentBalance = savings;
   int currentAge = age;
   for(int i = 0; i < months; i++) {
       printf("Age %3d month %2d you have $%.2lf\n", currentAge/12, currentAge % 12, currentBalance);
       currentBalance += currentBalance * rate / 12 + contribution; 
       currentAge++;
   }
   return currentBalance;
}

void retirement (int startAge,   //in months
                 double initial, //initial savings in dollars
                 retire_info working, //info about working
                 retire_info retired) //info about being retired
{
   double savingsAtRetirement = calculate(startAge, working.months, working.rate_of_return, working.contribution, initial);
   calculate(startAge + working.months, retired.months , retired.rate_of_return, retired.contribution, savingsAtRetirement);
}

int  main(void) {

    retire_info working = {489, 1000, 0.045};
    retire_info retired = {384, -4000, 0.01};
    int age = 327;
    double savings = 21345L;

    retirement(age, savings, working, retired);
    return 0;
    }

