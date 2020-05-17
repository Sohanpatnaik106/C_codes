#include<stdio.h>
#include<math.h>
#define MAX 15

struct point {
	double x;
	double y;
};

double triangleArea(struct point *polygonPoints, int i, int j, int k) {
	double x1, x2, x3, y1, y2, y3;
	x1 = polygonPoints[i].x;
	x2 = polygonPoints[j].x;
	x3 = polygonPoints[k].x;
	y1 = polygonPoints[i].y;
	y2 = polygonPoints[j].y;
	y3 = polygonPoints[k].y;

	double a, b, c;
	a = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
	b = sqrt(pow(x2-x3, 2) + pow(y2-y3, 2));
	c = sqrt(pow(x3-x1, 2) + pow(y3-y1, 2));

	double s = (a+b+c)/2;

	return sqrt(s*(s-a)*(s-b)*(s-c));

}

double polygonArea(struct point *polygonPoints, int noOfVertices) {
	double polygonArea = 0;
	for(int i = 1; i <= noOfVertices-2; i++) {
		polygonArea = polygonArea + triangleArea(polygonPoints, 0, i, i+1);
	}

	return polygonArea;
}

int main() {
	struct point polygonPoints[MAX];
	
	int noOfVertices;
	printf("Enter the number of vertices of the polygon : ");
	scanf("%d", &noOfVertices);
	
	printf("Enter the co-ordinates of %d vertices in clockwise order (x, y) : \n", noOfVertices);
	for(int i = 0; i < noOfVertices; i++) {
		printf("Co-ordinate of vertex %d : ", i);
		scanf("%lf %lf", &polygonPoints[i].x, &polygonPoints[i].y);
	}

	double areaOfPolygon;
	areaOfPolygon = polygonArea(polygonPoints, noOfVertices);

	printf("The convex polygon area is : %lf\n", areaOfPolygon);
	return 0;
}