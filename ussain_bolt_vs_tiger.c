#include<stdio.h>

int main()
{
	int t, finish, distancetoBolt, tigerAcceleration, boltSpeed, tiger_dist;
	float time;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		tiger_dist = 0;
		scanf("%d %d %d %d", &finish, &distancetoBolt, &tigerAcceleration, &boltSpeed);
		time = finish / boltSpeed;		
		tiger_dist = 0.5 * tigerAcceleration * time *time;
		if(tiger_dist < finish + distancetoBolt)
			printf("Bolt\n");
		else
			printf("Tiger\n");
	}
	return 0;
}
