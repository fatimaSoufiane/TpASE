#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include "init_ctx.h" 

static struct ctx_s* currentctx = NULL;

int init_ctx(struct ctx_s * pctx, int stack_size, func_t f , void * args){

	
     pctx->stack = (unsigned char*) malloc (stack_size);
     if (pctx->stack == NULL) return 0;		

     if(!stack_size)
	     return 0;
   
     pctx->ebp = &pctx->stack[stack_size - 4];
     pctx->esp = pctx->ebp;
     pctx->f=f;
     pctx->arg =args;
     pctx->status = CTX_READY;
     pctx->magic = CTX_MAGIC;

     return 1;

}


void switch_to_ctx(struct ctx_s* newctx)
{
	assert(newctx->magic == CTX_MAGIC);
	assert(newctx->status != CTX_TERMINATED);
	
	if(currentctx != NULL)
	{
		asm("movl %%esp, %0" :"=r"(currentctx->esp));
		asm("movl %%ebp, %0" :"=r"(currentctx->ebp));	
	}
	
	currentctx = newctx;
	
	asm("movl %0, %%ebp" ::"r"(currentctx->ebp));
	asm("movl %0, %%esp" ::"r"(currentctx->esp));
		
	if(currentctx->status == CTX_READY)
	{
		currentctx->status = CTX_ACTIVATED;
		currentctx->f(currentctx->arg);
		currentctx->status = CTX_TERMINATED;
		exit(0);
	}
	
	return ;
}





















