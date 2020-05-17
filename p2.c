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

double area_of_rectangle(struct rectangle R)
{
	double a = sq(R.x1-R.x2) + sq(R.y1-R.y2);
	double b = sq(R.x2-R.x3) + sq(R.y2-R.y3);
	return sqrt(a*b);
}

double smallest_rectangle(struct rectangle R[], int n)
{
	
}

int main()
{
	int n;
	struct rectangle R[5];
	printf("Enter the number of rectangles : ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		printf("Enter the x co-ordinates of the rectangle in clockwise order of vertices : ");
		scanf("%lf %lf %lf %lf", &R[i].x1, &R[i].x2, &R[i].x3, &R[i].x4);
		printf("Enter the y co-ordinates of the rectangle in clockwise order of vertices : ");
		scanf("%lf %lf %lf %lf", &R[i].y1, &R[i].y2, &R[i].y3, &R[i].y4);
	}
	
	printf("The area of the smallest bounding rectangle containing all the rectangles is %4.2lf", smallest_rectangle(R, n));
	return 0;	
}
