# Battle.net Steam Overlay Launcher


Launcher utility to help start battle.net games with the steam overlay.

Thanks to [dafzor](https://github.com/dafzor) for making the original [bnetlauncher](https://github.com/dafzor/bnetlauncher) years ago. 
Sadly the original program no longer functions (for me at least), and they no longer maintain nor merge PR's for fixes. 
Likewise, launchpad, the only other alternative, no longer works either due to dead external dependancies. 

This is a continutation using my previous [rumbleverse-launcher](https://github.com/ShizCalev/rumbleverse-launcher) / [fortnite launcher](https://github.com/ShizCalev/fortnite-launcher) framework as a more reliable 
/ futureproof method (assuming Blizzard doesn't change Battle.net's launch parameters.)

## Purpose

This application is intended to facilitate the launch of battle.net games from steam with overlay
with minimal/no interaction with the battle.net client while still being automatically logged in.


## Usage

1. Extract the included exe to any location you want (ex: steam folder)
2. Add the exe to steam as a non-steam game shortcut
3. On the shortcut properties add one of the following parameters:

| game          | launch code                                                  |
| ------------- | ----------------------------------------------------- |
|Blizzard Arcade Collection | rtro|
|Call of Duty HQ| codhq|
|Call of Duty: Black Ops 4 | codbo4|
|Call of Duty: Black Ops Cold War | codbocw|
|Call of Duty: Modern Warfare | codmw2019|
|Call of Duty: Modern Warfare 2 Campaign Remastered | codmw2cr|
|Call of Duty: MWII / WZ2.0 | codmw2|
|Call of Duty: Vanguard | codvg|
|Crash Bandicoot 4: It's About Time | cb4|
|Diablo 2: Resurrected | d2r|
|Diablo 3 | d3|
|Diablo 3 Public Test Realm | d3ptr|
|Diablo 4 | d4|
|Diablo Immortal | di|
|Hearthstone | hs|
|Heroes of the Storm | hots|
|Heroes of the Storm Public Test Realm | hotsptr|
|Overwatch | ow|
|Overwatch Public Test Realm | owptr|
|Starcraft 2 | sc2|
|Starcraft Remastered | scr|
|Warcraft 1: Orcs & Humans | w1|
|Warcraft 1: Remastered | w1r|
|Warcraft 2: Battle.net Edition | w2|
|Warcraft 2: Remastered | w2r|
|Warcraft 3: Reforged | w3|
|World of Warcraft | wow|
|World of Warcraft Classic | wowclassic|
|World of Warcraft Forever | wowf|
|World of Warcraft Public Test Realm | wowptr|
|Tony Hawk Pro Skater 3+4 | thps34|


The result should look something like the example below:

`"G:\Steam\Battlenet-Launcher.exe" ow`

If your Battle.net isn't installed at the default location, add the full path to Battle.net.exe as a secondary argument;

ie; `"G:\Steam\Battlenet-Launcher.exe" ow "C:/PROGRA~2/Battle.net/Battle.net.exe"`

## World of Warcraft Classic - Season of Discovery

Not currently supported, I'm looking into how to fix it. ♥
