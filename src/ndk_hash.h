#ifndef NDK_HASH_H
#define NDK_HASH_H

// TODO : add more hashes

#include <ngx_core.h>
#include <ngx_md5.h>
#include <ngx_sha1.h>


#define NDK_MURMUR2   // NOTE : for now, always include


typedef void (*ndk_hash_pt) (char *p, char *data, size_t len);


#ifdef NDK_MD5
void    ndk_md5_hash            (char *p, char *data, size_t len);
void    ndk_md5_lower_hash      (char *p, char *data, size_t len);
#endif

#ifdef NDK_MURMUR2
#define MURMURHASH2_DIGEST_LENGTH   4
void    ndk_murmur2_hash        (char *p, char *data, size_t len);
void    ndk_murmur2_lower_hash  (char *p, char *data, size_t len);
#endif

#ifdef NDK_SHA1
void    ndk_sha1_hash           (char *p, char *data, size_t len);
void    ndk_sha1_lower_hash     (char *p, char *data, size_t len);
#endif

#endif /* NDK_HASH_H */

