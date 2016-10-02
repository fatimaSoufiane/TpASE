#ifndef INIT_CTX
#define INIT_CTX
#define CTX_MAGIC 0xDEADEED

typedef void (func_t) (void*);

enum stat_c{
 	CTX_READY,
	CTX_TERMINATED,
	CTX_ACTIVATED,

};


struct ctx_s
{	
	void* ebp;
	void* esp;	
	unsigned int magic;
	func_t *f;
	void* arg;
	enum stat_c status;
	unsigned char* stack;
};

int init_ctx(struct ctx_s * pctx, int stack_size, func_t f , void * args);
void switch_to_ctx(struct ctx_s* newctx);

#endif
