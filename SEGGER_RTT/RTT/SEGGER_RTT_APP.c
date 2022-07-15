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
  * @brief  SEGGER_RTT ��ʼ������
  * @retval none
  * @note ʹ�� SEGGER_RTT ǰ������ô˳�ʼ������
  */
void rtt_init(void)
{
    /* ����ͨ��0����������*/
	SEGGER_RTT_ConfigUpBuffer(0, "RTTUP", NULL, 0, SEGGER_RTT_MODE_NO_BLOCK_SKIP);
	
	/* ����ͨ��0����������*/	
	SEGGER_RTT_ConfigDownBuffer(0, "RTTDOWN", NULL, 0, SEGGER_RTT_MODE_NO_BLOCK_SKIP);
}

/**
  * @brief  �� SEGGER RTT buffer 0 �н���һ���ַ�
  * @retval ���յ����ַ�
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
  * @brief  ��ӡ����
  * @param  TerminalId: Ҫ������ն˺ţ���1-10��
  * @param  s: ָ��Ҫ������ַ�
  */
void rtt_printf(unsigned char TerminalId,const char * sFormat, ...)
{
    SEGGER_RTT_SetTerminal(TerminalId);
    SEGGER_RTT_WriteString(0,RTT_CTRL_RESET"");
    SEGGER_RTT_printf(0, sFormat);
}

/**
  * @brief  ��־��Ϣ
  * @param  TerminalId: Ҫ������ն˺ţ���1-10��
  * @param  s: ָ��Ҫ������ַ�
  */
static void rtt_log(unsigned char TerminalId,const char * sFormat, ...)
{
    SEGGER_RTT_SetTerminal(TerminalId);
    SEGGER_RTT_WriteString(0,RTT_CTRL_BG_BRIGHT_GREEN RTT_CTRL_TEXT_BLACK"RTT_LOG: ");
    SEGGER_RTT_WriteString(0,RTT_CTRL_RESET"");
    SEGGER_RTT_printf(0, sFormat);
}

/**
  * @brief  ������Ϣ
  * @param  TerminalId: Ҫ������ն˺ţ���1-10��
  * @param  s: ָ��Ҫ������ַ�
  */
static void rtt_warning(unsigned char TerminalId,const char * sFormat, ...)
{
    SEGGER_RTT_SetTerminal(TerminalId);
    SEGGER_RTT_WriteString(0,RTT_CTRL_BG_BRIGHT_YELLOW RTT_CTRL_TEXT_BLACK"RTT_WARNING: ");
    SEGGER_RTT_WriteString(0,RTT_CTRL_RESET"");
    SEGGER_RTT_printf(0, sFormat);
}

/**
  * @brief  ������Ϣ
  * @param  TerminalId: Ҫ������ն˺ţ���1-10��
  * @param  s: ָ��Ҫ������ַ�
  */
static void rtt_error(unsigned char TerminalId,const char * sFormat, ...)
{
    SEGGER_RTT_SetTerminal(TerminalId);
    SEGGER_RTT_WriteString(0,RTT_CTRL_BG_BRIGHT_RED RTT_CTRL_TEXT_BLACK"RTT_ERROR: ");
    SEGGER_RTT_WriteString(0,RTT_CTRL_RESET"");
    SEGGER_RTT_printf(0, sFormat);
}







