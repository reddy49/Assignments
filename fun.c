#include<stdio.h>

int fun()
{
	static int num = 13;
	return num--;
}

int main()
{
	for (fun() ; fun() ; fun()) {
		printf("%d ", fun() );
	}
}

