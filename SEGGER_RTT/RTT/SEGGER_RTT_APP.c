#include "SEGGER_RTT_APP.h"

static void rtt_log(unsigned char TerminalId,const char * sFormat, ...);
static void rtt_warning(unsigned char TerminalId,const char * sFormat, ...);
static void rtt_error(unsigned char TerminalId,const char * sFormat, ...);

RTT_INFO_T rtt_info = 
{
    rtt_log,
    rtt_warning,
    rtt_error,
};

/**
  * @brief  SEGGER_RTT 初始化函数
  * @retval none
  * @note 使用 SEGGER_RTT 前必须调用此初始化函数
  */
void rtt_init(void)
{
    /* 配置通道0，上行配置*/
	SEGGER_RTT_ConfigUpBuffer(0, "RTTUP", NULL, 0, SEGGER_RTT_MODE_NO_BLOCK_SKIP);
	
	/* 配置通道0，下行配置*/	
	SEGGER_RTT_ConfigDownBuffer(0, "RTTDOWN", NULL, 0, SEGGER_RTT_MODE_NO_BLOCK_SKIP);
}

/**
  * @brief  从 SEGGER RTT buffer 0 中接收一个字符
  * @retval 接收到的字符
  */
int rtt_get_char(void)
{
    int ch;
    
    if (SEGGER_RTT_HasKey())
    {
        ch = SEGGER_RTT_GetKey();
    }
 
    return ch;
}


/**
  * @brief  打印函数
  * @param  TerminalId: 要输出的终端号，（1-10）
  * @param  s: 指向要输出的字符
  */
void rtt_printf(unsigned char TerminalId,const char * sFormat, ...)
{
    SEGGER_RTT_SetTerminal(TerminalId);
    SEGGER_RTT_WriteString(0,RTT_CTRL_RESET"");
    SEGGER_RTT_printf(0, sFormat);
}

/**
  * @brief  日志信息
  * @param  TerminalId: 要输出的终端号，（1-10）
  * @param  s: 指向要输出的字符
  */
static void rtt_log(unsigned char TerminalId,const char * sFormat, ...)
{
    SEGGER_RTT_SetTerminal(TerminalId);
    SEGGER_RTT_WriteString(0,RTT_CTRL_BG_BRIGHT_GREEN RTT_CTRL_TEXT_BLACK"RTT_LOG: ");
    SEGGER_RTT_WriteString(0,RTT_CTRL_RESET"");
    SEGGER_RTT_printf(0, sFormat);
}

/**
  * @brief  警告信息
  * @param  TerminalId: 要输出的终端号，（1-10）
  * @param  s: 指向要输出的字符
  */
static void rtt_warning(unsigned char TerminalId,const char * sFormat, ...)
{
    SEGGER_RTT_SetTerminal(TerminalId);
    SEGGER_RTT_WriteString(0,RTT_CTRL_BG_BRIGHT_YELLOW RTT_CTRL_TEXT_BLACK"RTT_WARNING: ");
    SEGGER_RTT_WriteString(0,RTT_CTRL_RESET"");
    SEGGER_RTT_printf(0, sFormat);
}

/**
  * @brief  错误信息
  * @param  TerminalId: 要输出的终端号，（1-10）
  * @param  s: 指向要输出的字符
  */
static void rtt_error(unsigned char TerminalId,const char * sFormat, ...)
{
    SEGGER_RTT_SetTerminal(TerminalId);
    SEGGER_RTT_WriteString(0,RTT_CTRL_BG_BRIGHT_RED RTT_CTRL_TEXT_BLACK"RTT_ERROR: ");
    SEGGER_RTT_WriteString(0,RTT_CTRL_RESET"");
    SEGGER_RTT_printf(0, sFormat);
}







