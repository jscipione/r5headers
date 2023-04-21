/*
   This file contains the structures that GNU malloc uses to manage
   memory.  It is not intended for public consumption.

*/


/* The allocator divides the heap into blocks of fixed size; large
   requests receive one or more whole blocks, and small requests
   receive a fragment of a block.  Fragment sizes are powers of two,
   and all fragments of a block are the same size.  When all the
   fragments in a block have been freed, the block itself is freed.  */
#define INT_BIT         (CHAR_BIT * sizeof(int))
#define BLOCKLOG        (INT_BIT > 16 ? 12 : 9) 
#define BLOCKSIZE       (1 << BLOCKLOG)
#define BLOCKIFY(SIZE)  (((SIZE) + BLOCKSIZE - 1) / BLOCKSIZE)

/* Determine the amount of memory spanned by the initial heap table
   (not an absolute limit).  */
#define HEAP            (INT_BIT > 16 ? 4194304 : 65536)

/* Number of contiguous free blocks allowed to build up at the end of
   memory before they will be returned to the system.  */
#define FINAL_FREE_BLOCKS       8

/* Data structure giving per-block information.  */
typedef union
{
	/* Heap information for a busy block.  */
	struct
	{
		/* Zero for a large (multiblock) object, or positive giving the
		   logarithm to the base two of the fragment size.	*/
		int type;
		union
		{
			struct
			{
				size_t nfree;	/* Free frags in a fragmented block.	*/
				size_t first;	/* First free fragment of the block.	*/
			} frag;

			/* For a large object, in its first block, this has the number
			   of blocks in the object.	 In the other blocks, this has a
			   negative number which says how far back the first block is.	*/
			ptrdiff_t size;
		} info;
	} busy;

	/* Heap information for a free block
	   (that may be the first of a free cluster).  */
	struct
	{
		size_t size;			/* Size (in blocks) of a free cluster.	*/
		size_t next;			/* Index of next free cluster.	*/
		size_t prev;			/* Index of previous free cluster.	*/
	} free;
} malloc_info;



/* Address to block number and vice versa.  */
#define BLOCK(A)        (((char *) (A) - ms->_heapbase) / BLOCKSIZE + 1)
#define ADDRESS(B)      ((void *) (((B) - 1) * BLOCKSIZE + ms->_heapbase))


/* Doubly linked lists of free fragments.  */
struct list
{
    struct list *next;
    struct list *prev;
};


/* List of blocks allocated with `memalign' (or `valloc').  */
struct alignlist
{
    struct alignlist *next;
    void * aligned;             /* The address that memaligned returned.  */
    void * exact;               /* The address that malloc returned.  */
};



/*
   This is all the state that the malloc routines need to know about.
   A pointer to this structure is passed along with the normal arguments
   by the wrapper routines.
*/
typedef struct malloc_state {

    int  malloc_sem;  /* semaphore & lock to serialize access, must be first */
    long malloc_lock;

	/* Are you experienced?  */
	int malloc_initialized;

	/* Pointer to the base of the first block.  */
	char *_heapbase;

	/* Block information table.  Allocated with align/free (not malloc/free).  */
	malloc_info *_heapinfo;

	/* Number of info entries.  */
	size_t heapsize;

	/* Search index in the info table.  */
	size_t _heapindex;

	/* Limit of valid info table indices.  */
	size_t _heaplimit;

	/* Free lists for each fragment size.  */
	struct list _fraghead[BLOCKLOG];

	/* List of blocks allocated with `memalign' (or `valloc').  */
	struct alignlist *_aligned_blocks;

	/* Instrumentation.  */
	size_t _chunks_used;
	size_t _bytes_used;
	size_t _chunks_free;
	size_t _bytes_free;

	/* private data used by the hooks */
	void	*data;
	
} malloc_state;


/*
   This contains function pointers that are used by the underlying
   GNU malloc code.  They have to be separated from the malloc_state
   structure because someone that is linked statically would have the
   routines at a different address than someone who isn't linked
   statically and if they share the same malloc_state structure then
   problems would arise.  This is really only a problem for shared 
   malloc pools but nonetheless we must deal with it.
*/   
typedef struct malloc_funcs
{
	/* free_memory function or NULL */
	long	(*free_memory)(void *ptr, size_t size);

	/* How to really get more memory.  */
	void *(*morecore) (ptrdiff_t size, struct malloc_state *ms);

	/* Debugging hooks */
	void *(*malloc_hook)  (size_t size, malloc_state *ms, struct malloc_funcs *mf);
	void  (*free_hook)    (void *ptr,   malloc_state *ms, struct malloc_funcs *mf);
	void *(*realloc_hook) (void *ptr,   size_t size,  malloc_state *ms, struct malloc_funcs *mf);
	void *(*memalign_hook)(size_t size, size_t align, malloc_state *ms, struct malloc_funcs *mf);

	/* saved hook values, used by mcheck  */
	void *(*old_malloc_hook)  (size_t size, malloc_state *ms, struct malloc_funcs *mf);
	void  (*old_free_hook)    (void *ptr,   malloc_state *ms, struct malloc_funcs *mf);
	void *(*old_realloc_hook) (void *ptr,   size_t size,  malloc_state *ms, struct malloc_funcs *mf);
	void *(*old_memalign_hook)(size_t size, size_t align, malloc_state *ms, struct malloc_funcs *mf);

	/* a function called by mcheck() when something awful happens.  */
	void (*abortfunc) (enum mcheck_status);
	
	void (*malloc_initialize_hook) (void);
	void (*after_morecore_hook) (void);

}malloc_funcs;

/* Internal version of `free' used in `morecore' (malloc.c). Do Not Call. */
extern void  _free_internal   (void * __ptr,  malloc_state *ms, malloc_funcs *mf);
extern void *_malloc_internal (size_t __size, malloc_state *ms, malloc_funcs *mf);

/* these are the routines you write your wrappers for */
extern _IMPEXP_ROOT void *_malloc  (size_t size,  malloc_state *ms, malloc_funcs *mf);
extern _IMPEXP_ROOT void *_calloc  (size_t nmemb, size_t size,      malloc_state *ms, malloc_funcs *mf);
extern _IMPEXP_ROOT void *_realloc (void * ptr,   size_t size,      malloc_state *ms, malloc_funcs *mf);
extern _IMPEXP_ROOT void *_valloc  (size_t size,  malloc_state *ms, malloc_funcs *mf);
extern _IMPEXP_ROOT void *_memalign(size_t align, size_t size,      malloc_state *ms, malloc_funcs *mf);
extern _IMPEXP_ROOT void  _free    (void *ptr,    malloc_state *ms, malloc_funcs *mf);
extern _IMPEXP_ROOT void  _cfree   (void *ptr,    malloc_state *ms, malloc_funcs *mf);

extern _IMPEXP_ROOT int _mcheck (void (*func) (enum mcheck_status), malloc_state *ms,
					malloc_funcs *mf);
extern _IMPEXP_ROOT struct mstats _mstats (malloc_state *ms, malloc_funcs *mf);
extern _IMPEXP_ROOT void *_malloc_find_object_address (void *ptr, malloc_state *ms, malloc_funcs *mf);
