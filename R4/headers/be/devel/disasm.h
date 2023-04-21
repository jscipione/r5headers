#ifndef _DISASM_H
#define _DISASM_H

#if __INTEL__

#define DISASM_FLAG_OP_SIZE_16			1
#define DISASM_FLAG_ADDR_SIZE_16		2
#define DISASM_FLAG_INTEL_STYLE			4
#define DISASM_FLAG_RELATIVE_ADDRESSES	8

status_t disasm(uchar *in, uint32 insize, char *out, uint32 outsize,
				uint32 eip, uint32 flags,
				status_t (*lookup)(void *cookie, uint32 eip, uint32 *sym_addr,
						char *sym_name, int max_name_len, int is_lower),
				void *cookie);

#endif /* INTEL */

#endif /* _DISASM_H */
