/*
**
** Application.h
**
*/

HOOKPROTONH(AppMsgFunc, LONG, APTR obj, struct AppMessage **x );
HOOKPROTONHNP(ButtonFunc, LONG, APTR obj );
HOOKPROTONHNP(DriveFunc, LONG, APTR obj );
HOOKPROTONHNO(ActionRexxFunc, LONG, ULONG *arg );
HOOKPROTONHNO(ActivateRexxFunc, LONG, ULONG *arg );
HOOKPROTONHNO(LoadRexxFunc, LONG, ULONG *arg );
HOOKPROTONHNO(PathRexxFunc, LONG, ULONG *arg );
HOOKPROTONHNO(RefreshRexxFunc, LONG, ULONG *arg );
HOOKPROTONHNO(MessageRexxFunc, LONG, ULONG *arg );
HOOKPROTONHNO(ChoiceRexxFunc, LONG, ULONG *arg );
HOOKPROTONHNO(StringRexxFunc, LONG, ULONG *arg );
HOOKPROTONHNO(NumEntriesRexxFunc, LONG, ULONG *arg );
HOOKPROTONHNO(GetEntryRexxFunc, LONG, ULONG *arg );
HOOKPROTONHNO(CommandRexxFunc, LONG, ULONG *arg );
HOOKPROTONHNO(FunctionRexxFunc, LONG, ULONG *arg );
HOOKPROTONHNO(ChangeRexxFunc, LONG, ULONG *arg );

extern char * GetCatStr( int num, char *defstring );

extern struct Catalog *global_Catalog;
extern LONG cfg_SortType[2];
extern LONG cfg_FirstType[2];
extern BOOL cfg_SortHighLow[2];
extern char cfg_MenuEntryText[20][41];
extern char cfg_ButtonText[120][81];
extern char cfg_Format[2][256];
extern char cfg_HotKey[50][41];
extern BOOL cfg_PageType;
extern LONG cfg_MultiSelect;

APTR app_RumorOpus;
APTR wi_Main;
APTR wi_Progress;
APTR wi_String;
APTR lv_Directory[2];
APTR sb_Vertical[2];
APTR sb_Horizontal[2];
APTR lv_Dir[2];
APTR lv_Buffers[2];
APTR lv_Volumes[2];
APTR st_PathGadget[2];
APTR bt_StatusText[2];
APTR bt_StatusBar;
APTR bt_Button[120];
APTR bt_Drive[32];
APTR pg_Page[2];
APTR Row[2];
APTR ga_Gauge;
APTR men_UserMenu;
APTR ButtonPage;
APTR Menu;
APTR st_StringGadget;
APTR bt_StringOkay;
APTR bt_StringCancel;
APTR bt_StringSkip;
APTR bt_StringAll;
APTR sg_Scroll[2];
/*
APTR gr_List[2];
*/
APTR bl_Balance;
APTR FoldGroup;

static char *Pages[] = {
"Directory",
"Buffers",
"Volumes",
NULL };

char ShortHelp[5][256];
char MenuStrings[25][31];

struct NewMenu MenuData[] =
{
	{ NM_TITLE, MenuStrings[0] , 0 ,0,0,(APTR)0             },
	{ NM_ITEM , MenuStrings[21],"U",0,0,(APTR)ID_UpdateAll  },
	{ NM_ITEM , MenuStrings[20],"M",0,0,(APTR)ID_Message    },
	{ NM_ITEM , NM_BARLABEL    , 0 ,0,0,(APTR)0             },
	{ NM_ITEM , MenuStrings[1] ,"?",0,0,(APTR)ID_About      },
	{ NM_ITEM , MenuStrings[22],"A",0,0,(APTR)ID_AboutMUI   },
	{ NM_ITEM , NM_BARLABEL    , 0 ,0,0,(APTR)0             },
	{ NM_ITEM , MenuStrings[2] ,"I",0,0,(APTR)ID_Iconify    },
	{ NM_ITEM , MenuStrings[3] ,"Q",0,0,(APTR)MUIV_Application_ReturnID_Quit },

	{ NM_TITLE, MenuStrings[4] , 0 ,0,0,(APTR)0             },
	{ NM_ITEM,  MenuStrings[5] , 0 ,0,0,(APTR)0             },
	{ NM_SUB,   MenuStrings[6] , 0 ,CHECKIT|MENUTOGGLE,0,(APTR)ID_CopyFlags  },
	{ NM_SUB,   MenuStrings[7] , 0 ,CHECKIT|MENUTOGGLE,0,(APTR)ID_CopyDate   },
	{ NM_SUB,   MenuStrings[8] , 0 ,CHECKIT|MENUTOGGLE,0,(APTR)ID_CopyNote   },
	{ NM_SUB,   NM_BARLABEL    , 0 ,0,0,(APTR)0             },
	{ NM_SUB,   MenuStrings[19],"F",CHECKIT|MENUTOGGLE,0,(APTR)ID_CopyVerify },
	{ NM_SUB,   MenuStrings[9] ,"D",CHECKIT|MENUTOGGLE,0,(APTR)ID_CheckSpace },
	{ NM_ITEM , MenuStrings[10], 0 ,0,0,(APTR)0             },
	{ NM_SUB ,  MenuStrings[12], 0 ,CHECKIT|MENUTOGGLE,0,(APTR)ID_Force      },
	{ NM_SUB ,  MenuStrings[11], 0 ,CHECKIT|MENUTOGGLE,0,(APTR)ID_Verify     },
	{ NM_ITEM,  NM_BARLABEL    , 0 ,0,0,(APTR)0             },
	{ NM_ITEM , MenuStrings[13], 0 ,0,0,(APTR)0             },
	{ NM_SUB ,  MenuStrings[14], 0 ,CHECKIT,2|4|8,(APTR)ID_OverYes    },
	{ NM_SUB ,  MenuStrings[15], 0 ,CHECKIT,1|4|8,(APTR)ID_OverNo     },
	{ NM_SUB ,  MenuStrings[16], 0 ,CHECKIT,1|2|8,(APTR)ID_OverOlder  },
	{ NM_SUB ,  MenuStrings[17], 0 ,CHECKIT,1|2|4,(APTR)ID_OverVerify },

	{ NM_TITLE, MenuStrings[18], 0 ,0,0,(APTR)0             },
	{ NM_ITEM,  MenuStrings[23], 0 ,0,0,(APTR)ID_ROPrefs },
	{ NM_ITEM,  NM_BARLABEL    , 0 ,0,0,(APTR)0             },
	{ NM_ITEM,  MenuStrings[24], 0 ,0,0,(APTR)ID_MUIPrefs },
	{ NM_END ,  NULL           , 0 ,0,0,(APTR)0             }
};

MakeStaticHook(ActionRexxHook, ActionRexxFunc);
MakeStaticHook(ActivateRexxHook, ActivateRexxFunc);
MakeStaticHook(LoadRexxHook, LoadRexxFunc);
MakeStaticHook(PathRexxHook, PathRexxFunc);
MakeStaticHook(RefreshRexxHook, RefreshRexxFunc);
MakeStaticHook(MessageRexxHook, MessageRexxFunc);
MakeStaticHook(ChoiceRexxHook, ChoiceRexxFunc);
MakeStaticHook(StringRexxHook, StringRexxFunc);
MakeStaticHook(NumEntriesRexxHook, NumEntriesRexxFunc);
MakeStaticHook(GetEntryRexxHook, GetEntryRexxFunc);
MakeStaticHook(CommandRexxHook, CommandRexxFunc);
MakeStaticHook(FunctionRexxHook, FunctionRexxFunc);
MakeStaticHook(ChangeRexxHook, ChangeRexxFunc);

static struct MUI_Command ARexxCommands[] =
{
	{"active",		"SIDE/A",					1,				&ActivateRexxHook},
	{"change",		"SIDE/A,SWITCH/A",			2,				&ChangeRexxHook},
	{"choicereq",	"STRING/A",					1,				&ChoiceRexxHook},
	{"command",		"STRING/A,FILE/A",			2,				&CommandRexxHook},
	{"fileaction",  "FILE/A",					1,				&ActionRexxHook},
	{"function",  	"NAME/A",					1,				&FunctionRexxHook},
	{"getentry",	"SIDE/A,TYPE/A",			2,				&GetEntryRexxHook},
	{"load",		"SIDE/A,DIR/A",				2,				&LoadRexxHook},
	{"message",		"STRING/A",					1,				&MessageRexxHook},
	{"numentries",	"SIDE/A,TYPE/A",			2,				&NumEntriesRexxHook},
	{"path",		"SIDE/A",					1,				&PathRexxHook},
	{"refresh",		"SIDE/A",					1,				&RefreshRexxHook},
	{"sleep",		MC_TEMPLATE_ID,				ID_Sleep,		NULL},
	{"stringreq",	"STRING/A",					1,				&StringRexxHook},
	{"wakeup",		MC_TEMPLATE_ID,				ID_WakeUp,		NULL},

	{NULL,			NULL,				0,				NULL}
};

struct Library *MUIMasterBase;

void Methods ( void );
BOOL StartApplication ( void );
BOOL StopApplication ( void );

extern char Status_String[1024];
extern LONG Active_Side;
extern int DoFunction ( int Operation, int side, char * Argument );
extern BOOL CheckMemory ( int bytes );
extern void Sleep ( BOOL Sleep_BOOL );
extern void SleepClock ( BOOL Sleep_BOOL );
extern void SleepWindow ( BOOL Sleep_BOOL );
extern char * Error ( int error_number );
extern BOOL global_DirLoaded[2];
extern int OtherSide( int side );
