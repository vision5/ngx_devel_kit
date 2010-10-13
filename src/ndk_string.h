

#define     ndk_str_init(ns,s)              {(ns).data = (u_char*) s; (ns).len = sizeof (s) - 1;}
#define     ndk_strp_init(ns,s)             {(ns)->data = (u_char*) s; (ns)->len = sizeof (s) - 1;}

#define     ndk_zero(p,sz)                  memset (p,'\0',sz)
#define     ndk_zerop(p)                    ndk_zero (p,sizeof(*p))
#define     ndk_zeropn(p,n)                 ndk_zero (p,sizeof(*p)*(n))
#define     ndk_zerov(v)                    ndk_zero (&v,sizeof(v))

#if 1
// TODO : set ndk_hex_dump for older versions of Nginx
#define     ndk_hex_dump                    ngx_hex_dump        
#endif


int64_t         ndk_atoi64                  (u_char *line, size_t n);

ngx_int_t       ndk_strcntc                 (ngx_str_t *s, char c);
ngx_int_t       ndk_strccnt                 (char *s, char c);
ngx_array_t *   ndk_str_array_create        (ngx_pool_t *pool, char **s, ngx_int_t n);


static inline void
ndk_strtoupper (u_char *p, size_t len)
{
    u_char *e = p + len;
    for ( ; p<e; p++) {
        *p = ngx_toupper(*p);
    }    
}

