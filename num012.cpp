// Finding pth root of a number using Newton's formula
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

double x[20];

// General function form
// p denotes power and N denotes the number whose pth root is to be calculated
double f(int x, int p, int N)
{
    return pow(x, p) - N;
}

bool errorCheck(double x1, double x2)
{
    if(abs(x2 - x1) < 0.0001)
        return true;
    else
        return false;
}

int main()
{
    int p, N;
    scanf("%d %d", &p, &N);
    int x0 = 0;
    int x1 = 0;

    // To find interval in which root lies
    while(f(x0,p,N)*f(x1,p,N) > 0){
        x0 = x1;
        x1++;
    }

    x[0] = x0;
    x[1] = x1;

    int index = 0;
    for(int i = 0; i < 15; ++i){
        x[i+1] = ( (p - 1) * pow(x[i], p) + N) / (p * pow(x[i], p - 1));
        index++;
        if(errorCheck(x[i], x[i-1]))
            break;
    }

    // Uncomment to view iteration table
    /*for(int i = 0; i < 10; ++i)
      printf("%.4lf\n", x[i]);*/
    printf("Found root at x = %.4lf\n", x[index]);
    return 0;
}
