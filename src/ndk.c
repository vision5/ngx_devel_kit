 
/*
 * 2010 (C) Marcus Clyne
 */

#include    <ndk.h>

#include    <ndk_config.c>


ngx_http_module_t     ngx_http_devel_kit_module_ctx = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
ngx_module_t          ngx_http_devel_kit_module = {

    NGX_MODULE_V1,
    &ngx_http_devel_kit_module_ctx,         // module context
    ngx_http_devel_kit_commands,            // module directives
    NGX_HTTP_MODULE,                        // module type
    NULL,                                   // init master
    NULL,                                   // init module
    NULL,                                   // init process
    NULL,                                   // init thread
    NULL,                                   // exit thread
    NULL,                                   // exit process
    NULL,                                   // exit master
    NGX_MODULE_V1_PADDING
};

