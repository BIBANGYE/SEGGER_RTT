#ifndef __SEGGER_RTT_APP_
#define __SEGGER_RTT_APP_

#include "SEGGER_RTT.h"
#include <string.h>


typedef struct
{
	void (*RTT_LOG)(unsigned char TerminalId,const char * sFormat, ...); 
	void (*RTT_WARNING)(unsigned char TerminalId,const char * sFormat, ...);
	void (*RTT_ERROR)(unsigned char TerminalId,const char * sFormat, ...);
}RTT_INFO_T;

extern RTT_INFO_T rtt_info;


// SEGGER_RTT 初始化函数
void rtt_init(void);

// 从 SEGGER RTT buffer 0 中接收一个字符
int rtt_get_char(void);

// 打印函数
void rtt_printf(unsigned char TerminalId,const char * sFormat, ...);


#endif /* __SEGGER_RTT_APP_ */



