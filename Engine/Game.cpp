/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brd( gfx ),
	rng( std::random_device()()),
	slipperyboi({ 2, 2 }),
	goal( rng, brd, slipperyboi),
	AllObstacles(rng, brd, slipperyboi, goal, {5, 5})
{
	
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if ( wnd.kbd.KeyIsPressed(VK_RETURN) ) {
		gameIsStarted = true;
	}

	if (gameIsStarted) {
		brd.DrawBorder();
		if (!gameIsOver) {
			if (wnd.kbd.KeyIsPressed('W') || wnd.kbd.KeyIsPressed(VK_UP)) {

				delta_loc = { 0, -1 };
			}

			if (wnd.kbd.KeyIsPressed('S') || wnd.kbd.KeyIsPressed(VK_DOWN)) {

				delta_loc = { 0, 1 };
			}

			if (wnd.kbd.KeyIsPressed('D') || wnd.kbd.KeyIsPressed(VK_RIGHT)) {

				delta_loc = { 1, 0 };
			}
			if (wnd.kbd.KeyIsPressed('A') || wnd.kbd.KeyIsPressed(VK_LEFT)) {

				delta_loc = { -1, 0 };
			}

			snake_move_counter++;
			if (snake_move_counter >= snake_move_period) {

				snake_move_counter = 0;
				Location next = slipperyboi.GetNextHeadLocation(delta_loc);
				if (!brd.isInsideBoard(next) ||
					slipperyboi.IsInTileExceptEnd(next) || AllObstacles.IsInTile(next)) {
					gameIsOver = true;
				}
				else {

					bool isEating = next == goal.GetLocation();

					if (isEating) {
						snake_move_period = (0.90) * snake_move_period;
						snake_move_period = snake_move_period < 5.0 ? 5.0 : snake_move_period;
						AllObstacles.SpawnNewObstacle(rng, brd, slipperyboi, goal);
						slipperyboi.Grow();
					}
					slipperyboi.MoveBy(delta_loc);

					if (isEating) {
						goal.Respawn(rng, brd, slipperyboi);
					}
				}

			}
		}
	}
	else {
		gameIsStarted = wnd.kbd.KeyIsPressed(VK_RETURN);
	}
}

void Game::ComposeFrame()
{
	if (gameIsStarted) {
		slipperyboi.Draw(brd);
		goal.Draw(brd);

		AllObstacles.Draw(brd);

		if (gameIsOver) {
			SpriteCodex::DrawGameOver(200, 200, gfx);
		}
		
	}
	else {
		SpriteCodex::DrawTitle(200, 200, gfx);
	}
}
