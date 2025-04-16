#include "PrefsIncludes.h"
#include "PrefsRequest.h"

/*
**
** AboutRequester()
**
*/

BOOL AboutRequester ( void )
{
	char About_String[512];

	strcpy( About_String, "" );
	strcat( About_String, "\33c\33uRO Prefs 0.86 (5.12.98)\n\33n" );
	strcat( About_String, "Copyright � 1994-1998 by Oliver Rummeyer\n\n" );
	strcat( About_String, "\33b- Special Edition for amigaOS CD Vol.1 -\33n\n\n" );
	strcat( About_String, "This is a MUI-Application\n" );
	strcat( About_String, "MUI is copyrighted by Stefan Stuntz" );

	MUI_Request( app_RumorOpusPrefs, wi_Main, 0, "About RO Prefs", "_Okay", About_String, TAG_END );

	return( TRUE );
}
