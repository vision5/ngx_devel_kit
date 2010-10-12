

int64_t
ndk_atoi64 (u_char *line, size_t n)
{
    int64_t  value;

    if (n == 0ll) {
        return NGX_ERROR;
    }

    for (value = 0ll; n--; line++) {
        if (*line < '0' || *line > '9') {
            return NGX_ERROR;
        }

        value = value * 10ll + (*line - '0');
    }

    if (value < 0ll) {
        return NGX_ERROR;
    }

    return value;
}


ngx_int_t
ndk_strcntc (ngx_str_t *s, char c)
{
    ngx_int_t   n;
    size_t      i;
    u_char     *p;

    i = s->len;
    p = s->data;

    for (n=0; i; i--, p++) {

        if (*p == (u_char) c)
            n++;
    }

    return  n;
}


ngx_int_t
ndk_strccnt (char *s, char c)
{
    ngx_int_t   n;

    n = 0;

    while (*s != '\0') {

        if (*s == 'c')
            n++;

        s++;
    }

    return  n;
}



ngx_array_t *
ndk_str_array_create (ngx_pool_t *pool, char **s, ngx_int_t n)
{
    ngx_int_t        i;
    ngx_str_t       *str;
    ngx_array_t     *a;

    a = ngx_array_create (pool, n, sizeof (ngx_str_t));
    if (a == NULL)
        return  NULL;


    for (i=0; i<n; i++, s++) {

        str = ngx_array_push (a);

        str->data = (u_char *) *s;
        str->len = strlen (*s);
    }

    return  a;
}

