#include <linux/export.h>
#include "fnv.h"

u32 fnv_32_buf(void *buf, size_t len)
{
	u32 hval = ((u32)0x811c9dc5);

	unsigned char *bp = (unsigned char *)buf; /* start of buffer */
	unsigned char *be = bp + len; /* beyond end of buffer */

	/*
     * FNV-1 hash each octet in the buffer
     */
	while (bp < be) {
		hval += (hval << 1) + (hval << 4) + (hval << 7) + (hval << 8) +
			(hval << 24);

		/* xor the bottom with the current octet */
		hval ^= (u32)*bp++;
	}

	/* return our new hash value */
	return hval;
}
// EXPORT_SYMBOL(fnv_32_buf);
