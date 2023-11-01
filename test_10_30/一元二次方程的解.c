# define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, c, m, x1 = 0, x2 = 0;
	scanf("%lf%lf%lf", &a, &b, &c);
	m = sqrt(b * b - 4 * a * c);
	if (a != 0 && m > 0)
	{
		x1 = (-b + m) / 2 * a;
		x2 = (-b - m) / 2 * a;
		printf("x1 = %.3f x2 = %.3f", x1, x2);
	}
	else if (m == 0)
		printf("x1 = x2 = %.3f", x1);
	else
		printf("нч╫Б\n");
	return 0;
}