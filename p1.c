#include<stdio.h>
#include<math.h>

struct rectangle 
{
	double x1, y1, x2, y2, x3, y3, x4, y4;
};

double sq(double x)
{
	return x * x;
}

int is_valid_rectangle(struct rectangle R)
{
	double a = sq(R.x1-R.x2) + sq(R.y1-R.y2);
	double b = sq(R.x2-R.x3) + sq(R.y2-R.y3);
	double c = sq(R.x3-R.x4) + sq(R.y3-R.y4);
	double d = sq(R.x4-R.x1) + sq(R.y4-R.y1);
	double e = sq(R.x1-R.x3) + sq(R.y1-R.y3);
	double f = sq(R.x2-R.x4) + sq(R.y2-R.y4);

	if((a == c) && (b == d) && (a + b == e) && (c + d == f) && ((R.y2-R.y1 == 0) || (R.y3-R.y2 == 0)))
		return 1;
	else 
		return 0; 
}

double area_of_rectangle(struct rectangle R)
{
	double a = sq(R.x1-R.x2) + sq(R.y1-R.y2);
	double b = sq(R.x2-R.x3) + sq(R.y2-R.y3);
	return sqrt(a*b);
}

int is_inside(struct rectangle R, double x, double y)
{
	if(((R.x1-x)*(R.x3-x)) < 0 && ((R.y1-y)*(R.y3-y)) < 0)
		return 1;
	else 
		return 0;
}

int main()
{
	struct rectangle R;
	printf("Enter the x co-ordinates of the rectangle in clockwise order of vertices : ");
	scanf("%lf %lf %lf %lf", &R.x1, &R.x2, &R.x3, &R.x4);
	printf("Enter the y co-ordinates of the rectangle in clockwise order of vertices : ");
	scanf("%lf %lf %lf %lf", &R.y1, &R.y2, &R.y3, &R.y4);
	
	if(is_valid_rectangle(R))
	{
		double x, y;
		printf("\nThe rectangle is an axis parallel rectangle.\n");
		printf("The area of the rectangle is %4.2lf.\n\n", area_of_rectangle(R));
		printf("Enter the x and y co-ordinates of the new point : ");
		scanf("%lf %lf", &x, &y);
		if(is_inside(R, x, y))
			printf("The point is inside the rectangle.\n");
		else
			printf("The point is not inside the rectangle.\n");

	}
	return 0;	
}
