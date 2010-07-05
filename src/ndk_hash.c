#include "ndk_hash.h"

// openssl hashes

#define     NDK_OPENSSL_HASH(type,ctxt_type,upper)          \
    u_char              md [ctxt_type ## _DIGEST_LENGTH];        \
    ngx_uint_t          i;                                  \
    ctxt_type ##_CTX    c;                                  \
                                                            \
    type ## _Init (&c);                                     \
    type ## _Update (&c, data, len);                        \
    type ## _Final (md, &c);                                \
                                                            \
    for (i=0; i<ctxt_type ## _DIGEST_LENGTH; i++) {              \
        p += sprintf (p, (upper ? "%02X" : "%02x"), md[i]); \
    }


// TODO : check to see if can do consistent printing using "%08X" or in single go

#ifdef NDK_MD5

void
ndk_md5_hash (char *p, char *data, size_t len)
{
    NDK_OPENSSL_HASH (MD5, MD5, 1);
}

void
ndk_md5_lower_hash (char *p, char *data, size_t len)
{
    NDK_OPENSSL_HASH (MD5, MD5, 0);
}

#endif
#ifdef NDK_SHA1

void
ndk_sha1_hash (char *p, char *data, size_t len)
{
    NDK_OPENSSL_HASH (SHA1, SHA, 1);
}

void
ndk_sha1_lower_hash (char *p, char *data, size_t len)
{
    NDK_OPENSSL_HASH (SHA1, SHA, 0);
}

#endif



// non-openssl hashes

#ifdef NDK_MURMUR2

#include    "hash/murmurhash2.c"

void
ndk_murmur2_hash (char *p, char *data, size_t len)
{
    uint32_t    hash;

    hash = MurmurHash2 (data, len, 47);

    sprintf (p, "%08X", hash);
}

void
ndk_murmur2_lower_hash (char *p, char *data, size_t len)
{
    uint32_t    hash;

    hash = MurmurHash2 (data, len, 47);

    sprintf (p, "%08x", hash);
}

#endif
