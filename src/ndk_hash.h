

// TODO : add more hashes

#if (NGX_OPENSSL_MD5)
#include    <md5.h>
#include    <sha.h>

#ifndef NDK_MD5
#define NDK_MD5
#endif

#ifndef NDK_SHA1
#define NDK_SHA1
#endif

#else
#warning  using the MD5, SHA1... hash functions currently requires the OpenSSL module to be enabled \
(e.g. --with-http-ssl-module) - those functions requiring this have not been enabled
#endif

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

#ifdef NDK_SAH1
void    ndk_sha1_hash           (char *p, char *data, size_t len);
void    ndk_sha1_lower_hash     (char *p, char *data, size_t len);
#endif
