 
/*
 * 2010 (C) Marcus Clyne
*/


#ifndef NDK_H
#define NDK_H


#include    <ngx_config.h>
#include    <ngx_core.h>
#include    <ngx_http.h>


#define     ndk_version     2013
#define     NDK_VERSION     "0.2.13"


#if !(NDK)
#error At least one module requires the Nginx Development Kit to be compiled with \
the source (add --with-module=/path/to/devel/kit/src to configure command)
#endif

#include    <ndk_config.h>
#include    <ndk_includes.h>

#endif
