/*----------------------------------------------------------------------------------------------------*-

										  Weapon Admin
										Official Script

										Author & Developer:
								   	  Thiradev Byp (dosuser)
							        https://discord.gg/HNxzGaJu

-*----------------------------------------------------------------------------------------------------*/

#include    <YSI_Coding\y_hooks>
#include    <discord-connector>

new online;

hook OnGameModeInit()
{
    SetTimer("OnBotActivity", 10000, true);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    online ++;
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    online --;
    return 1;
}

forward OnBotActivity();
public OnBotActivity()
{
    new str[256];
    format(str, sizeof str, "SAMP ONLINE | ผู้เล่นออนไลน์ %d / %d", MAX_PLAYERS);
    DCC_SetBotActivity(str);
    return 1;
}