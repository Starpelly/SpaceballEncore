#include "Engine.hpp"

#include <stdlib.h>
#include <stdio.h>
#include <wiiuse/wpad.h>
#include <gccore.h>
#include <asndlib.h>

#include "Game.hpp"

#include "spaceball_ogg.h"

int main(void)
{
	ASND_Init();

	GRRLIB_Init();

	WPAD_Init();
	WPAD_SetDataFormat(WPAD_CHAN_0, WPAD_FMT_BTNS_ACC_IR);

	Game game;

	PlayOgg(spaceball_ogg, spaceball_ogg_size, 0, OGG_ONE_TIME);

	while (1)
	{
		WPAD_ScanPads();

		game.Update();


		GRRLIB_FillScreen(WHITE);

		game.Draw();

		GRRLIB_Render();
	}

	GRRLIB_Exit();
	StopOgg();

	exit(0);
}