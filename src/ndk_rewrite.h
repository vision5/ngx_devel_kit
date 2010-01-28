

// TODO : should remove this when not needed



// used for plugging into the rewrite module (taken from the rewrite module)

typedef struct {
    ngx_array_t  *codes;        /* uintptr_t */
    ngx_uint_t    stack_size;
    ngx_flag_t    log;
    ngx_flag_t    uninitialized_variable_warn;
} ngx_http_rewrite_loc_conf_t;


extern  ngx_module_t  ngx_http_rewrite_module;

char *      ngx_http_rewrite_value      (ngx_conf_t *cf, ngx_http_rewrite_loc_conf_t *lcf,
                                            ngx_str_t *value);
ngx_int_t   ngx_http_rewrite_var        (ngx_http_request_t *r, 
                                            ngx_http_variable_value_t *v, uintptr_t data);

