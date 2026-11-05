#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <shellapi.h>
#include <tlhelp32.h>

using namespace std;

LPCTSTR gEX;
LPCTSTR oID;
HANDLE GetHndl(LPCTSTR pName);
int Start(LPCTSTR pName, LPCTSTR pArgs);
bool IsRunning(LPCTSTR pName);
void Kill(LPCTSTR pName);

int main(int argc, char **argv)
{
	FreeConsole();
	//Return error if no parameter is specified
	if (argv[1] == NULL) {
		MessageBox(0, "Specify which game to launch: \n\nBlizzard Arcade Collection = rtro\nCall of Duty HQ = codhq\nCall of Duty: Black Ops 4 = codbo4\nCall of Duty: Black Ops Cold War = codbocw\nCall of Duty: Modern Warfare = codmw2019\nCall of Duty: Modern Warfare 2 Campaign Remastered = codmw2cr\nCall of Duty: MWII | WZ2.0 = codmw2\nCall of Duty: Vanguard = codvg\nCrash Bandicoot 4: It's About Time = cb4\nDiablo 2: Resurrected = d2r\nDiablo 3 = d3\nDiablo 3 Public Test Realm = d3ptr\nDiablo 4 = d4\nDiablo Immortal = di\nHearthstone = hs\nHeroes of the Storm = hots\nHeroes of the Storm Public Test Realm = hotsptr\nOverwatch = ow\nOverwatch Public Test Realm = owptr\nStarcraft 2 = sc2\nStarcraft Remastered = scr\nWarcraft 1: Orcs & Humans = w1\nWarcraft 1: Remastered = w1r\nWarcraft 2: Battle.net Edition = w2\nWarcraft 2: Remastered = w2r\nWarcraft 3: Reforged = w3\nWorld of Warcraft = wow\nWorld of Warcraft Classic = wowclassic\nWorld of Warcraft Forever = wowf\nWorld of Warcraft Public Test Realm = wowptr\nTony Hawk Pro Skater 3+4 = thps34", "Error", MB_OK);
		return TRUE;
	}
	//determine which battlefield to start
	if (_stricmp(argv[1], "rtro") == 0) {
		//name=Blizzard Arcade Collection
		oID = "--exec=\"launch rtro\"";
		gEX = "client.exe";
	}
	else if (_stricmp(argv[1], "codmw2") == 0) {
		//name=Call of Duty: MWII | WZ2.0
		oID = "--exec=\"launch AUKS\"";
		gEX = "cod22-cod.exe";
	}
	else if (_stricmp(argv[1], "codhq") == 0) {
		//name=Call of Duty HQ
		oID = "--exec=\"launch AUKS\"";
		gEX = "cod.exe";
	}
	else if (_stricmp(argv[1], "codbo4") == 0) {
		//name=Call of Duty: Black Ops 4
		oID = "--exec=\"launch VIPR\"";
		gEX = "BlackOps4.exe";
	}
	else if (_stricmp(argv[1], "codbocw") == 0) {
		//name=Call of Duty: Black Ops Cold War
		oID = "--exec=\"launch ZEUS\"";
		gEX = "BlackOpsColdWar.exe";
	}
	else if (_stricmp(argv[1], "codmw2019") == 0) {
		//name=Call of Duty: Modern Warfare
		oID = "--exec=\"launch ODIN\"";
		gEX = "ModernWarfare.exe";
	}
	else if (_stricmp(argv[1], "codmw2cr") == 0) {
		//name=Call of Duty: Modern Warfare 2 Campaign Remastered
		oID = "--exec=\"launch LAZR\"";
		gEX = "MW2CR.exe";
	}
	else if (_stricmp(argv[1], "codvg") == 0) {
		//name=Call of Duty: Vanguard
		oID = "--exec=\"launch FORE\"";
		gEX = "Vanguard.exe";
	}
	else if (_stricmp(argv[1], "cb4") == 0) {
		//name=Crash Bandicoot 4: It's About Time
		oID = "--exec=\"launch WLBY\"";
		gEX = "CrashBandicoot4.exe";
	}
	else if (_stricmp(argv[1], "d2r") == 0) {
		//name=Diablo 2: Resurrected
		oID = "--exec=\"launch OSI\"";
		gEX = "D2R.exe";
	}
	else if (_stricmp(argv[1], "d3") == 0) {
		//name=Diablo 3
		oID = "--exec=\"launch D3\"";
		gEX = "Diablo III%.exe";
	}
	else if (_stricmp(argv[1], "d3ptr") == 0) {
		//name=Diablo 3 Public Test Realm
		oID = "--exec=\"launch d3t\"";
		gEX = "Diablo III%.exe";
	}
	else if (_stricmp(argv[1], "d4") == 0) {
		//name=Diablo 4
		oID = "--exec=\"launch Fen\"";
		gEX = "Diablo IV.exe";
	}
	else if (_stricmp(argv[1], "di") == 0) {
		//name=Diablo Immortal
		oID = "--exec=\"launch ANBS\"";
		gEX = "DiabloImmortal.exe";
	}
	else if (_stricmp(argv[1], "hs") == 0) {
		//name=Hearthstone
		oID = "--exec=\"launch WTCG\"";
		gEX = "Hearthstone.exe";
	}
	else if (_stricmp(argv[1], "hots") == 0) {
		//name=Heroes of the Storm
		oID = "--exec=\"launch Hero\"";
		gEX = "HeroesSwitcher%.exe";
	}
	else if (_stricmp(argv[1], "hotsptr") == 0) {
		//name=Heroes of the Storm Public Test Realm
		oID = "--exec=\"launch herot\"";
		gEX = "HeroesSwitcher%.exe";
	}
	else if (_stricmp(argv[1], "ow") == 0) {
		//name=Overwatch
		oID = "--exec=\"launch Pro\"";
		gEX = "Overwatch.exe";
	}
	else if (_stricmp(argv[1], "owptr") == 0) {
		//name=Overwatch Public Test Realm
		oID = "--exec=\"launch prot\"";
		gEX = "Overwatch.exe";
	}
	else if (_stricmp(argv[1], "scr") == 0) {
		//name=Starcraft Remastered
		oID = "--exec=\"launch S1\"";
		gEX = "StarCraft.exe";
	}
	else if (_stricmp(argv[1], "sc2") == 0) {
		//name=Starcraft 2
		oID = "--exec=\"launch S2\"";
		gEX = "SC2Switcher%.exe";
	}
	else if (_stricmp(argv[1], "w1") == 0) {
		//name=Warcraft I: Orcs & Humans
		gEX = "DOSBox.exe";
		oID = "--exec=\"launch W1\"";
		}
	else if (_stricmp(argv[1], "w1r") == 0) {
		//name=Warcraft I Remastered
		gEX = "Warcraft.exe";
		oID = "--exec=\"launch W1R\"";
	}
	else if (_stricmp(argv[1], "w2") == 0) {
		//name=Warcraft II Battle.net Edition
		gEX = "Warcraft II BNE.exe";
		oID = "--exec=\"launch W2\"";
		}
	else if (_stricmp(argv[1], "w2r") == 0) {
		//name=Warcraft II Remastered
		gEX = "Warcraft II.exe";
		oID = "--exec=\"launch W2R\"";
	}
	else if (_stricmp(argv[1], "w3") == 0) {
		//name=Warcraft 3: Reforged
		oID = "--exec=\"launch W3\"";
		gEX = "Warcraft III.exe";
	}
	else if (_stricmp(argv[1], "wow") == 0) {
		//name=World of Warcraft
		oID = "--exec=\"launch WoW\"";
		gEX = "Wow.exe";
	}
	else if (_stricmp(argv[1], "wowclassic") == 0) {
		//name=World of Warcraft Classic
		oID = "--exec=\"launch WoWC\"";
		gEX = "WowClassic.exe";
	}
	/* Not currently functional, classic era/season of discovery doesn't use the normal launch code system. Not entirely sure where to start on this one.
	else if (_stricmp(argv[1], "wowclassicera") == 0) {
		//name=World of Warcraft Classic Era
		oID = "--exec=\"launch wow_classic_era\"";
		gEX = "WowClassic.exe";
	}*/ 
	else if (_stricmp(argv[1], "wowf") == 0 || _stricmp(argv[1], "wowforever") == 0) {
		//name=World of Warcraft Forever. The exec code is the case-sensitive game family id "WoWF"
		//(agent uid "wowf" selects nothing, so Battle.net falls back to its default game). Installs to "_forever_".
		oID = "--exec=\"launch WoWF\"";
		gEX = "Wow.exe";
	}
	else if (_stricmp(argv[1], "wowptr") == 0) {
		//name=World of Warcraft Public Test Realm
		oID = "--exec=\"launch wowt\"";
		gEX = "WowT.exe";
	}
	else if (_stricmp(argv[1], "thps34") == 0) {
		//name=Tony Hawk Pro Skater 3+4
		oID = "--exec=\"launch LBRA\"";
		gEX = "Base.exe";
	}
	else {
		MessageBox(0, "Please specify a valid parameter: \n\nBlizzard Arcade Collection = rtro\nCall of Duty HQ = codhq\nCall of Duty: Black Ops 4 = codbo4\nCall of Duty: Black Ops Cold War = codbocw\nCall of Duty: Modern Warfare = codmw2019\nCall of Duty: Modern Warfare 2 Campaign Remastered = codmw2cr\nCall of Duty: MWII | WZ2.0 = codmw2\nCall of Duty: Vanguard = codvg\nCrash Bandicoot 4: It's About Time = cb4\nDiablo 2: Resurrected = d2r\nDiablo 3 = d3\nDiablo 3 Public Test Realm = d3ptr\nDiablo 4 = d4\nDiablo Immortal = di\nHearthstone = hs\nHeroes of the Storm = hots\nHeroes of the Storm Public Test Realm = hotsptr\nOverwatch = ow\nOverwatch Public Test Realm = owptr\nStarcraft 2 = sc2\nStarcraft Remastered = scr\nWarcraft 1: Orcs & Humans = w1\nWarcraft 1: Remastered = w1r\nWarcraft 2: Battle.net Edition = w2\nWarcraft 2: Remastered = w2r\nWarcraft 3: Reforged = w3\nWorld of Warcraft = wow\nWorld of Warcraft Classic = wowclassic\nWorld of Warcraft Forever = wowf\nWorld of Warcraft Public Test Realm = wowptr\nTony Hawk Pro Skater 3+4 = thps34", "Error", MB_OK);
		return TRUE;
		}
	//determine battlenet directory
	LPCTSTR oDir;
	if (argv[2]!=NULL){
		oDir = argv[2];
	}
	else oDir = "C:/Program Files (x86)/Battle.net/Battle.net.exe";
	//check if battlenet is running
	if (IsRunning("Battle.net.exe")){
		Kill("Battle.net.exe");
	}
	//start battlenet with the launch command as its startup argument. Some games (WoW Forever) are only selected,
	//not started, when the command comes on the command line, so keep sending it every 10s until the game runs.
	//A command sent to an instance that is still loading is passed on over IPC and dropped (harmless);
	//under Wine/Proton Battle.net takes 10-30 seconds before it can launch a game.
	if (Start(oDir, oID) <= 32) {
		MessageBox(0, "Failed to launch Battle.net. \nMake sure it's installed in its default location.", "Error", MB_OK);
		return TRUE;
	}
	for (int i = 1; i <= 150 && !IsRunning(gEX); i++) {
		Sleep(1000);
		if (i % 10 == 0 && !IsRunning(gEX)) {
			Start(oDir, oID);
		}
	}
	//exit if game does not start within 150s
	if (!IsRunning(gEX)) {
		MessageBox(0, "Game doesn't appear to be running. Closing launcher.", "Error", MB_OK);
		Kill("Battle.net.exe");
		return TRUE;
	}
	LPCTSTR WindowName = "Battle.net";
	HWND Find = FindWindow(NULL, WindowName);
	//close all the battle.net client windows that open up when you launch a game. gross.
	while (Find) {
		PostMessage(Find, WM_CLOSE, 0, 0);
		Sleep(1);
		Find = FindWindow(NULL, WindowName);
	}
	//wait for game to close. Some games (WoW Forever) are relaunched by Battle.net right after the first start,
	//so only stop once the game has been gone for 10 seconds in a row.
	for (int gone = 0; gone < 10; ) {
		Sleep(1000);
		gone = IsRunning(gEX) ? 0 : gone + 1;
	}
	//usually we'd sleep here before closing the client to allow for cloudsave syncing, but battle.net's saves are typically handled by the games themselves.
	//Close battlenet
	Kill("Battle.net.exe");
	return FALSE;
}

//--------------- F U N C T I O N S ---------------//

HANDLE GetHndl(LPCTSTR pName){
	//caller must CloseHandle() the result
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (snapshot == INVALID_HANDLE_VALUE)
		return NULL;
	HANDLE hProcess = NULL;
	if (Process32First(snapshot, &entry) == TRUE){
		do {
			if (_stricmp(entry.szExeFile, pName) == 0){
				hProcess = OpenProcess(PROCESS_TERMINATE | PROCESS_QUERY_LIMITED_INFORMATION, FALSE, entry.th32ProcessID);
				break;
			}
		} while (Process32Next(snapshot, &entry) == TRUE);
	}
	CloseHandle(snapshot);
	return hProcess;
}

int Start(LPCTSTR pName, LPCTSTR pArgs){
	HINSTANCE h = ShellExecute(NULL,"open",pName,pArgs,NULL,SW_SHOW);
	return (int)(INT_PTR) h;
}

bool IsRunning(LPCTSTR pName){
	HANDLE hProcess = GetHndl(pName);
	if (hProcess == NULL)
		return FALSE;
	CloseHandle(hProcess);
	return TRUE;
}

void Kill(LPCTSTR pName){
	HANDLE hProcess = GetHndl(pName);
	if (hProcess == NULL)
		return;
	TerminateProcess(hProcess, 0);
	CloseHandle(hProcess);
}
