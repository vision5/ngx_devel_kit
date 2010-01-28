 
/*
 * 2010 (C) Marcus Clyne
*/


#ifndef NDK_H
#define NDK_H


#include    <ngx_config.h>
#include    <ngx_core.h>
#include    <ngx_http.h>

#include    <spl_devel.h>


#if !(NDK_DEVEL)
#if !(NDK)
#error At least one module requires the Nginx Development Kit to be compiled with \
the source (add --with-module=/path/to/devel/kit/src to configure command)
#endif
#else
#ifndef NDK_ALL
#define NDK_ALL 1
#endif
#endif


#include    <ndk_config.h>

#endif
