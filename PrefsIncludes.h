/*
**
** PrefsIncludes.h
**
*/

#include <libraries/mui.h>
#ifdef HAVE_XPK
#include <libraries/xpk.h>
#endif
#include <dos.h>
#include <dos/dos.h>
#include <dos/dostags.h>
#include <graphics/gfxmacros.h>
#include <workbench/workbench.h>
#include <exec/memory.h>
#include <exec/types.h>
#include <exec/execbase.h>
#include <proto/alib.h>
#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/icon.h>
#include <proto/graphics.h>
#include <proto/intuition.h>
#include <proto/gadtools.h>
#include <proto/utility.h>
#include <proto/asl.h>
#include <proto/muimaster.h>
#include <proto/locale.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

#include "WBPath.h"

extern struct ExecBase * SysBase;
extern struct Library * LocaleBase;
extern struct Library * IntuitionBase;
extern struct Library * UtilityBase;
extern struct Library * GfxBase;
extern struct Library * DOSBase;
extern struct Library * IconBase;
#ifdef HAVE_XPK
extern struct Library * XpkBase;
#endif
extern struct Library * MUIMasterBase;

#define ASM    __asm
#define SAVEDS __saveds
#define REG(x) register __ ## x

enum Ids
{
	ID_dummy,

	ID_Save_Btn, ID_Use_Btn, ID_MenuOpen, ID_MenuSaveAs, ID_MenuAbout, ID_MenuReset, ID_MenuLast, ID_MenuRestore,
	ID_EventSelect, ID_DirEnter, ID_CommandEnter, ID_CommandtypeChange, ID_EventtypeChange, ID_EnterEvent,
	ID_AddEvent, ID_DelEvent, ID_FiletypeSelect, ID_FiletypeDisabled, ID_FiletypeEnabled, ID_AddFiletype,
	ID_DelFiletype, ID_FiletypeEnter, ID_RecogEnter, ID_PatternEnter, ID_CommandAEnter, ID_CommandBEnter,
	ID_FiletypeChange, ID_FormatRightEnter, ID_FormatLeftEnter, ID_FunctionEnter, ID_MenuIconify, ID_MUIPrefs
};
