#include <stdio.h>
#include <stdlib.h>

struct _retire_info
{
    int months;
    double contribution;
    double rate_of_return;
};
typedef struct _retire_info retire_info;

void    print_balance(int age, double balance)
{
    printf("Age %3d month %2d you have $%.2lf\n", age/12, age%12, balance);
}

double calcBalance(double currentBallance, retire_info info)
{
    double increase = currentBallance * info.rate_of_return;
    double newBalance = currentBallance + increase + info.contribution;
    return (newBalance);
}

double  getBalance(int age, double balance, retire_info info)
{
    while (info.months)
    {
        print_balance(age, balance);
        balance = calcBalance(balance, info);
        age++;
        info.months--;
    }
    return (balance);
}

void    retirement (int startAge, //in months
                    double initial, //initial saving in dollars
                    retire_info working, //info about working
                    retire_info retired) //info about being retired
{
    int retirementAge = startAge + working.months;
    double balanceAtRetirement = getBalance(startAge, initial, working);
    getBalance(retirementAge, balanceAtRetirement, retired);
}

int main(void) {
    int startAge = 327; //in months
    double initial = 21345.0; //in dollars
    retire_info working;
    retire_info retired;

    working.months = 489;
    working.contribution = 1000;
    working.rate_of_return = 0.045/12; //per month

    retired.months = 384;
    retired.contribution = -4000;
    retired.rate_of_return = 0.01/12; //per month

    retirement(startAge, initial, working, retired);

    return EXIT_SUCCESS;
}
