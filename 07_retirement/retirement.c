#include <stdio.h>
#include <stdlib.h>

struct _retire_info
{
    int months;
    double contribution;
    double rate_of_return;
};
typedef struct _retire_info retire_info;

void    retirement (int startAge, //in months
                    double initial, //initial saving in dollars
                    retire_info working, //info about working
                    retire_info retired) //info about being retired


