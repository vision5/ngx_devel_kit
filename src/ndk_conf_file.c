

/* NOTE : you will find other conf_set functions in the following files :
 *
 * complex_value.c
 * encoding.c
 * path.c
 *
 */


char *
ndk_conf_set_true_slot (ngx_conf_t *cf, ngx_command_t *cmd, void *conf)
{
    char  *p = conf;

    ngx_flag_t       *fp;
    ngx_conf_post_t  *post;

    fp = (ngx_flag_t*) (p + cmd->offset);

    if (*fp != NGX_CONF_UNSET) {
        return  "is duplicate";
    }
 
    *fp = 1;

    if (cmd->post) {
        post = cmd->post;
        return  post->post_handler (cf, post, fp);
    }

    return  NGX_CONF_OK;
}



char *
ndk_conf_set_false_slot (ngx_conf_t *cf, ngx_command_t *cmd, void *conf)
{
    char  *p = conf;

    ngx_flag_t       *fp;
    ngx_conf_post_t  *post;

    fp = (ngx_flag_t*) (p + cmd->offset);

    if (*fp != NGX_CONF_UNSET) {
        return  "is duplicate";
    }
 
    *fp = 0;

    if (cmd->post) {
        post = cmd->post;
        return  post->post_handler (cf, post, fp);
    }

    return  NGX_CONF_OK;
}




char *
ndk_conf_set_ptr_slot (ngx_conf_t *cf, ngx_command_t *cmd, void *conf)
{
    char  *p = conf;

    void  **ptr;

    ptr = (void**) (p + cmd->offset);

    if (*ptr != NGX_CONF_UNSET_PTR) {
        return  "is duplicate";
    }
 
    *ptr = cmd->post;

    return  NGX_CONF_OK;
}



char *
ndk_conf_set_null_slot (ngx_conf_t *cf, ngx_command_t *cmd, void *conf)
{
    char  *p = conf;

    void            **pp;
    ngx_conf_post_t  *post;

    pp = (void **) (p + cmd->offset);

    if (*pp != NGX_CONF_UNSET_PTR) {
        return  "is duplicate";
    }
 
    *pp = NULL;

    if (cmd->post) {
        post = cmd->post;
        return  post->post_handler (cf, post, pp);
    }

    return  NGX_CONF_OK;
}


char *
ndk_conf_set_num64_slot (ngx_conf_t *cf, ngx_command_t *cmd, void *conf)
{
    char  *p = conf;

    int64_t          *np;
    ngx_str_t        *value;
    ngx_conf_post_t  *post;


    np = (int64_t *) (p + cmd->offset);

    if (*np != NGX_CONF_UNSET) {
        return "is duplicate";
    }

    value = cf->args->elts;
    *np = ndk_atoi64 (value[1].data, value[1].len);
    if (*np == NGX_ERROR) {
        return "invalid number";
    }

    if (cmd->post) {
        post = cmd->post;
        return post->post_handler(cf, post, np);
    }

    return NGX_CONF_OK;
}


char *
ndk_conf_set_str_array_multi_slot (ngx_conf_t *cf, ngx_command_t *cmd, void *conf)
{
    char  *p = conf;

    ngx_str_t         *value, *s;
    ngx_array_t      **a;
    ngx_conf_post_t   *post;
    ngx_uint_t         i;
    
    a = (ngx_array_t **) (p + cmd->offset);

    if (*a == NGX_CONF_UNSET_PTR) {
        *a = ngx_array_create(cf->pool, 4, sizeof(ngx_str_t));
        if (*a == NULL) {
            return NGX_CONF_ERROR;
        }
    }

    s = NULL;

    for (i=cf->args->nelts-1; i; i--) {

        s = ngx_array_push(*a);
        if (s == NULL) {
            return NGX_CONF_ERROR;
        }

        value = cf->args->elts;

        *s = value[i];
    }

    if (cmd->post) {
        post = cmd->post;
        return  post->post_handler(cf, post, s);
    }

    return NGX_CONF_OK;
}



char *
ndk_conf_set_keyval1_slot (ngx_conf_t *cf, ngx_command_t *cmd, void *conf)
{
    char  *p = conf;
    
    ngx_str_t           *value;
    ngx_keyval_t        *kv;
    ngx_conf_post_t     *post;

    kv = (ngx_keyval_t *) (p + cmd->offset);

    if (kv->key.data)
        return  "is duplicate";

    value = cf->args->elts;

    kv->key = value[1];
    kv->value = value[2];

    if (cmd->post) {
        post = cmd->post;
        return  post->post_handler (cf, post, kv);
    }

    return  NGX_CONF_OK;
}



char *
ndk_conf_set_num_flag_slot (ngx_conf_t *cf, ngx_command_t *cmd, void *conf)
{
    char  *p = conf;

    ngx_int_t        *np;
    ngx_str_t        *value;
    ngx_conf_post_t  *post;

    np = (ngx_int_t *) (p + cmd->offset);

    if (*np != NGX_CONF_UNSET) {
        return  "is duplicate";
    }

    value = cf->args->elts;

    if (ngx_strcasecmp (value[1].data, (u_char *) "on") == 0) {
        *np = NDK_CONF_SET_TRUE;

    } else if (ngx_strcasecmp (value[1].data, (u_char *) "off") == 0) {
        *np = NDK_CONF_SET_FALSE;

    } else {
        *np = ngx_atoi (value[1].data, value[1].len);
        if (*np == NGX_ERROR) {
            return  "invalid number and not 'on'/'off'";
        }
    }

    if (cmd->post) {
        post = cmd->post;
        return  post->post_handler (cf, post, np);
    }

    return  NGX_CONF_OK;
}



char *
ndk_conf_set_sec_flag_slot (ngx_conf_t *cf, ngx_command_t *cmd, void *conf)
{
    char  *p = conf;

    time_t              *tp;
    ngx_str_t           *value;
    ngx_conf_post_t     *post;

    tp = (time_t *) (p + cmd->offset);

    if (*tp != NGX_CONF_UNSET) {
        return  "is duplicate";
    }

    value = cf->args->elts;

    if (ngx_strcasecmp (value[1].data, (u_char *) "on") == 0) {
        *tp = NDK_CONF_SET_TRUE;

    } else if (ngx_strcasecmp (value[1].data, (u_char *) "off") == 0) {
        *tp = NDK_CONF_SET_FALSE;

    } else {
        *tp = ngx_parse_time (&value[1], 1);
        if (*tp == NGX_ERROR) {
            return  "has an invalid time and not 'on'/'off'";
        }
    }

    if (cmd->post) {
        post = cmd->post;
        return  post->post_handler (cf, post, tp);
    }

    return  NGX_CONF_OK;
}


