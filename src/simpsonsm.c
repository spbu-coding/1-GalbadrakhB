#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Pi 3.1416

int n, i;
double x, x1, a, b, h, h1, incompSum = 0, incompsum1 = 0;

double f(double x) {
    return sin(x);
}

double Simpsons_rule(double a, double b) {
    h = (b - a) / n;
    for (i = 1; i < n; i++) {
        x = a + i * h;
        if (i % 2 == 0) {
            incompSum = incompSum + (2 * f(x));
        }
        else {
            incompSum = incompSum + (4 * f(x));
        }
    }
    return h / 3.0 * (f(a) + incompSum + f(b));
}

double Rectangle_method(double a, double b) {
    h = (b - a) / n;
    for (i = 1; i < n; i++) {
        x = a + i * h;
        incompsum1 = incompsum1 + f(x + h / 2);
    }
    return h * incompsum1;
}

int read_integral() {
    if (printf("Please enter the left border of the integral\na = ") < 0) {
        printf("Cannot write to stdout\n");
        return 0;
    }
    scanf_s("%lf", &a);
    if (a < 0) {
        printf("The left border of the integral must be greater than or equal to 0\n");
        return 0;
    }
    if (a > Pi) {
        printf("The left border of the integral must be lesser than Pi\n");
        return 0;
    }
    if (printf("Please enter the right border of the integral\nb = ") < 0) {
        printf("Cannot write to stdout");
        return 0;
    }
    scanf_s("%lf", &b);
    if (b < 0) {
        printf("The right border of the integral must be greater than 0\n");
        return 0;
    }
    if (a > Pi) {
        printf("The right border of the integral must be lesser than or equal to Pi\n");
        return 0;
    }
    if (a > b) {
        printf("The left border of the integral cannot be greater than the right border\n");
        return 0;
    }
    if (printf("Please enter the number of integral segments\nn = ") < 0) {
        printf("Cannot write to stdout\n");
        return 0;
    }
    scanf_s("%d", &n);
    if (n <= 0) {
        printf("The number of segments can only be a positive number\n");
        return 0;
    }
    if (n % 2 == 0) {}
    else {
        printf("The number of segments must be an even number\n");
    }
    return 1;
}

    int main()
    {
        
        if (read_integral()) {
            printf("The integral is (using the Rectangular integration) = %lf\n", Rectangle_method(a, b));
            printf("The integral is (using the Simpsons rule) = %lf\n", Simpsons_rule(a, b));
        }
    return 0;
}
  



