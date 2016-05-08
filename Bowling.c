#include <stdio.h>
int main(void)
{
	int frame, pin1, pin2, pin3, score, trial, strike;
	_Bool spare = 0, Double = 0;
	frame = 1, score = 0, trial = 1, strike = 0;
	while (frame < 10)
	{
		if (trial == 1)
			{
				printf("%d번째 프레임 %d 번째 처리 핀 수 : ", frame, trial);
			    scanf("%d", &pin1);
		      	if (strike)
					{
						score += (pin1 * (1 + strike));
						if (pin1 == 10)
   							{
								strike += 1;
								Double = 1;
								frame = frame + 1;
							}
						else 
							{
								if (Double)
								Double = 0;
		     		   			trial += 1;
							}
					}
					
				else if (spare)
						{
							if (pin1 == 10)
								{
									strike += 1;
									frame += 1;
								}
							else trial = 2;
						 	score += (pin1 * 2);
					 		spare = 0;
						}
				 	else if (pin1 == 10)
							{
								strike += 1;
						 		score += pin1;
								frame = frame + 1;
							}
					  	else 
							{
								score += pin1;
					 	   		trial = 2;
							} 
			}			
		else if (strike)
			{
				printf("%d번째 프레임 %d 번째 처리 핀 수 : ", frame, trial);
			 	scanf("%d", &pin2);
			 	if ((pin1 + pin2) == 10)
			 		{
						score += (pin2 * (1 + strike));
				 		spare = 1;
					}
			 	else score += (pin2 * 2);
			 	frame = frame + 1;
			 	trial = 1;
			 	strike = 0;
			}
			else 
				{
					printf("%d번째 프레임 %d 번째 처리 핀 수 : ", frame, trial);
					scanf("%d", &pin2);
				 	if ((pin1 + pin2) == 10)
					 spare = 1;
				 	score += pin2;
				 	frame = frame + 1;
				 	trial = 1;
				}
		printf("**** 현재까지 점수 : %d\n", score);
		if (strike > 1)
		   {
   			if (Double)
				;
			else strike -= 1;
			
		   }
		if (strike == 3)
			strike = 2;		
	}
	while (trial < 4)
	{
		if (trial == 1)
			{	
				printf("%d번째 프레임 %d 번째 처리 핀 수 : ", frame, trial);
				scanf("%d", &pin1);
				if (strike)
					{
						score += (pin1 * (1 + strike));
						{
							if (strike > 1)
							strike -= 1;
						}
						trial = 2;
					}
			else if (spare)
				{
					score += (pin1 * 2);
					trial = 2;
				}
				else 
					{
						score += pin1;
						trial = 2;
					}
			}
		else if (trial == 2)
				{
					printf("%d번째 프레임 %d 번째 처리 핀 수 : ", frame, trial);
					scanf("%d", &pin2);
					if (strike)
						{
							score += (pin2 * (1 + strike));
							if (pin1 + pin2 >= 10)
							trial = 3;
							else trial = 4;
						}
			else if (pin1 + pin2 >= 10)
					{
						score += pin2;
						trial = 3;
					}
				else 
					{
						score += pin2;
						trial = 4;
					}
				}
				else
					{	
						printf("%d번째 프레임 %d 번째 처리 핀 수 : ", frame, trial);
						scanf("%d", &pin3);
						score += pin3;
						trial = 4;
					}		
	
		if (trial < 4)
			printf("**** 현재까지 점수 : %d\n", score);
	}		
	printf("**** 최종 점수 : %d\n", score);
	return 0;
}
