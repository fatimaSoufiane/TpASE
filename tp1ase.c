#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <setjmp.h>
#include <assert.h>

#define CTX_MAGIC 0xDEADEEF

typedef int (func_t)(int);
typedef struct ctx_s{
	void* esp;
	void* ebp;
	unsigned int magic;
}ctx_s;

ctx_s * pctx;



int try(ctx_s *pctx, func_t *f, int arg)
{
	pctx->magic = CTX_MAGIC;
	asm("mov %%rsp, %0\n" : "=r"(pctx->esp));
	asm("mov %%rbp, %0\n" : "=r"(pctx->ebp));
		
	return  f(arg);
}

int throw(ctx_s *pctx, int r)
{

	assert(pctx->magic == CTX_MAGIC);
	static int res =0 ;
	res =r;
	asm("mov %0, %%rsp" :: "r"(pctx->esp));
	asm("mov %0, %%rbp" :: "r"(pctx->ebp));
        
	return res;
	
}

int f(int v){

	if(v>0)
		return f(v-1);
	else
		throw(pctx,8);	
	
}	



int main(int argc, int** argv)
{
		
	int  res;
	pctx = (ctx_s*)malloc(sizeof(ctx_s));
	
	res = try(pctx, f, 3);
	printf("res = %d\n",res);
	
}
