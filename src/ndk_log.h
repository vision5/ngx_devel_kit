

// TODO : multiple versions for different compilers (e.g. args...) including versions that create functions that map over ngx_log_core

#define     ndk_log_alert(...)      ngx_log_error (NGX_LOG_ALERT, __VA_ARGS__)
#define     ndk_log_crit(...)       ngx_log_error (NGX_LOG_CRIT, __VA_ARGS__)
#define     ndk_log_emerg(...)      ngx_log_error (NGX_LOG_EMERG, __VA_ARGS__)
#define     ndk_log_err(...)        ngx_log_error (NGX_LOG_ERR, __VA_ARGS__)
#define     ndk_log_info(...)       ngx_log_error (NGX_LOG_INFO, __VA_ARGS__)
#define     ndk_log_notice(...)     ngx_log_error (NGX_LOG_NOTICE, __VA_ARGS__)
#define     ndk_log_stderr(...)     ngx_log_error (NGX_LOG_STDERR, __VA_ARGS__)
#define     ndk_log_warn(...)       ngx_log_error (NGX_LOG_WARN, __VA_ARGS__)

