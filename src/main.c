/*------------------------------------------------------------
 * FileName: main.c
 * Author: LuX
 * Date: 2013-10-24
 * Example of how to use Prolin OSAL API. It can only run on Prolin OS 2.4 or higher.
 *
 *	 						Warning
 * This code is for reference only. I do not guarantee the correctness, safety, efficiency or completeness.
 * You are welcome to send an e-mail to me(lux@paxsz.com) if you have any questions.
 ------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <osal.h>
#include <xui.h>

XuiFont *font;
XuiColor COLOR_BLUE={0xff, 0, 0, 0xff};
XuiColor COLOR_BLACK={0, 0, 0, 0xff}; //COLOR_BLACK,COLOR_BLUE,COLOR_RED,COLOR_YELLOW
char text[50]={};

static int GuiInit(int statusbar_height) {
	char value[128];
	char rotate_str[32];
	char statusbar_str[32];
	int ret;
	char *xui_argv[10];
	int xui_argc;

	ret = OsRegGetValue("ro.fac.lcd.rotate", value);
	if (ret > 0) {
		snprintf(rotate_str, sizeof(rotate_str), "ROTATE=%s", value);
	} else {
		strcpy(rotate_str, "ROTATE=0");
	}

	if (statusbar_height > 0) {
		snprintf(statusbar_str, sizeof(statusbar_str), "STATUSBAR=%d",
				statusbar_height);
	} else {
		strcpy(statusbar_str, "STATUSBAR=0");
	}

	xui_argv[0] = rotate_str;
	xui_argv[1] = statusbar_str;
	xui_argv[2] = NULL;
	xui_argc = 2;

	ret = XuiOpen(xui_argc, xui_argv);
	if (ret == XUI_RET_OK) {
		return RET_OK;
	} else {
		return -1;
	}
}

static void GuiDeinit(void) {
	XuiClose();
}


static void CrashReportInit(void) {
	signal(SIGILL, OsSaveCrashReport);
	signal(SIGABRT, OsSaveCrashReport);
	signal(SIGBUS, OsSaveCrashReport);
	signal(SIGFPE, OsSaveCrashReport);
	signal(SIGSEGV, OsSaveCrashReport);
	signal(SIGSTKFLT, OsSaveCrashReport);
	signal(SIGPIPE, OsSaveCrashReport);
}


void TestesRec(){
	char bufferteste [128];
	int ret;

	ret= OsRegGetValue("ro.fac.wifi", bufferteste);
	OsLog(LOG_DEBUG,"Modulo de Wifi: %s", bufferteste);

	/*
	 * Check the battery level.
	 * @returns 1 to 4 when the load percentage.
	 */
//	ret= OsCheckBattery();
//	OsLog(LOG_DEBUG,"Teste de Bateria: %d", ret);
}

int main(int argc, char **argv) {
	CrashReportInit();
	GuiInit(18);
	int i =0;
	int key;

	font = XuiCreateFont("/usr/font/paxfont.ttf", 0, 0);
	OsLogSetTag("DEBUG");

	XuiCanvasSetBackground(XuiRootCanvas(), XUI_BG_NORMAL, NULL, COLOR_BLUE );

	GuiDeinit();
	TestesRec();
	return 0;
}
