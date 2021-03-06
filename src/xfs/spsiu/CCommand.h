#pragma once
#include<Windows.h>
#include<XFSSPI.H>
#include "CSession.h"
class CCommand
{
private:
	REQUESTID m_reqId;
	HSERVICE m_hService;
	HWND m_hWnd;
	DWORD m_dTimeout;
	DWORD m_Command;
	int m_spiFunction;
	LPVOID m_buffer;
	int m_bufferSize;	
	LPVOID m_result;
	char* m_BufferLszExtra;
	DWORD m_EventClass;
	HWND m_hWndReg;
	CSession* m_session;
	DWORD m_TraceLevel;
	
public:
	CCommand(	REQUESTID reqId,
				HSERVICE hService,
				HWND hWnd,
				int spiFunction,
				long timeout,
				DWORD command,
				LPVOID buffer,
				int size
			);

	CCommand(REQUESTID reqId,
		HSERVICE hService,
		HWND hWnd,
		int spiFunction,
		long timeout,
		DWORD dEventClass,
		HWND hWndReg,
		DWORD command,
		LPVOID buffer,
		int size,
		CSession* session
	);
	~CCommand();

	void freeBuffer();

	void copyInputBuffer(int spiFunction, DWORD command, LPVOID in_buffer);

	unsigned int getLpszExtraSize(const char* lpszExtra);

	REQUESTID getReqId();
	HSERVICE getHService();
	HWND getHWND();
	DWORD getTimeout();
	DWORD getCommand();
	int getSPIFunction();
	LPVOID getBuffer();
	int getBufferSize();
	LPVOID getResult();
	char* getLpszExtra();
	DWORD getEventClass();
	HWND getWndReg();
	CSession* getSession();

	void setResult(LPVOID result);

	void setTraceLevel(DWORD dwTraceLevel);
	DWORD getTraceLevel();

};

