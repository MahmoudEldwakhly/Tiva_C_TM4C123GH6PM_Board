/*
 * main.c
 *
 *  Created on: Oct 7, 2024
 *      Author: ahmed
 */


#include <stdio.h>

#define val 3
#define ahmed(...) printf(__VA_ARGS__)
#define embedded_learner(a,...) printf(__VA_ARGS__,a)

void main()
{
	ahmed("value=%d\n", val);
	embedded_learner(val, "value=%d\n");
}
