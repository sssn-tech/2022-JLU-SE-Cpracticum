#include"..\Headfiles\GetTime.h"
#include "time.h"

//--------------------
//以下为获取时间的功能函数
void getCurrentTime(int* year, int* month, int* day)
{
	time_t now = time(NULL);
	struct tm t;
	localtime_s(&t, &now);
	*year = t.tm_year + 1900;
	*month = t.tm_mon + 1;
	*day = t.tm_mday;
}
//--------------------