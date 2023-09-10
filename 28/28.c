#include<sched.h>
#include<stdio.h>

int main()
{
	int maxpr,minpr;

	maxpr = sched_get_priority_max(SCHED_RR);
	minpr = sched_get_priority_min(SCHED_RR);

	printf("Max  priority of RR scheduling is : %d\n",maxpr);
	printf("Min priority of RR scheduling is : %d\n",minpr);

	return 0;
}
