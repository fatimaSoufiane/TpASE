#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include "init_ctx.h"



struct ctx_s ctx_ping;
struct ctx_s ctx_pong;


void f_ping(void* arg);
void f_pong(void* arg);

void f_ping(void* args)
{
	while(1)
	{
		printf("A\n");
		switch_to_ctx(&ctx_pong);
		printf("B\n");
		switch_to_ctx(&ctx_pong);
		printf("C\n");
		switch_to_ctx(&ctx_pong);
	}
}


void f_pong(void* args)
{
	while(1)
	{
		printf("1\n");
		switch_to_ctx(&ctx_ping);
		printf("2\n");
		switch_to_ctx(&ctx_ping);
	}
}


int main(int argc, char* argv[])
{	

	init_ctx(&ctx_ping, 16384, f_ping, NULL);
	init_ctx(&ctx_pong, 16384, f_pong, NULL);
	switch_to_ctx(&ctx_ping);

	exit(EXIT_SUCCESS);
	
	return 0;
}



