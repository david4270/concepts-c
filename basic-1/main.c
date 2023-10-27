// Just simple calculation and input and output
#include <stdio.h>
#include <time.h>

double addi(double a, double b){
    double f = a + b;
    return f;
}

double subt(double a, double b){
    double f = a - b;
    return f;
}

double mulp(double a, double b){
    double f = a * b;
    return f;
}

double divs(double a, double b){
    double f = a / b;
    return f;
}

int main(){
    /****  Simple Calculator ******/
    double a,b,f;
    int mode;
    printf("Calculator\n Which calculation do you want to do?\n 1: add, 2: sub, 3: mul, 4: div \n >>");
    scanf("%d",&mode);
    printf("What is your first number? : ");
    scanf("%lf", &a);
    printf("What is your second number? : ");
    scanf("%lf", &b);

    switch(mode){
        case 1: 
            f = addi(a,b);
            break;
        case 2:
            f = subt(a,b);
            break;
        case 3:
            f = mulp(a,b);
            break;
        case 4:
            if(b == 0){
                printf("Cannot calculate division\n");
            }
            else{
                f = divs(a,b);
            }
            break;
        default: break;
    }

    printf("The result is %.2lf\n\n", f);

    /********* Age calculation *********/

    printf("Let's figure out your age \n");
    
    int year, month, day;
    time_t sec_1970_now, day_1970_now, today_year;
    sec_1970_now = time(NULL);
    day_1970_now = sec_1970_now / (24*3600);
    today_year = 1970 + day_1970_now/365;


    printf("Which year did you born?: ");
    scanf("%d", &year);
    printf("Which month did you born?: ");
    scanf("%d", &month);
    printf("Which day did you born?: ");
    scanf("%d", &day);
    printf("Your birthday is %d/%d/%d \n", month,day,year);

    printf("Days since Jan 1, 1970: %ld\n", day_1970_now);
    printf("This year is %d\n", today_year);
    printf("You are %d years old\n", today_year - year);

    return 0;
}

// printf -> used to print string
// \n -> next line
// %lf -> long float
// %.2lf -> 2 decimal places
// %6.1lf -> 6 places, 1 decimal places
// %d -> integers
// %4d -> 4 places
// %c -> charcter

// scanf -> used to scan characters/double/float/integer
// scanf("%d %d %lf",a,b,c) -> scan integer a, integer b, and double c (a b c)
