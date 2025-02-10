/*
 * main.c
 *
 *  Created on: Oct 6, 2024
 *      Author: ahmed
 */


#include "stdio.h"
int main()
{
	int x =5;
	float y = 2.0;
	if(x/y == 2)
	{
		printf("int/float >>> int \n");
	}
	else if (x/y == 2.5)
	{
		printf("int/float >>> float \n");
	}
}
