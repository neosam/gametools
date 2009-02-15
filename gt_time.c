/*
 * File gt_time.c
 *
 * This is the legal property of Simon Goller (neosam@gmail.com).
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "gt_time.h"
#include <SDL.h>

unsigned int GT_time_fps;
unsigned int GT_time_sleeptime;
unsigned int GT_time_maxFrames;

void (*GT_time_waitFunc)(int mills);
void (*GT_time_maxFramesFunc)();

unsigned int GT_time_lastTick;
unsigned int GT_time_nextTick;
unsigned int GT_time_frames;
int GT_time_waitTime;

int GT_time_InitTime(unsigned int flags)
{
	GT_time_SetFps(30);
	GT_time_Reset();
	GT_time_Mode(flags);
	GT_time_maxFrames = 150;
	GT_time_maxFramesFunc = GT_time_PrintAVG;

	return 0;
}

void GT_time_SetFps(int fps)
{
	GT_time_fps = fps;
	GT_time_sleeptime = 1000 / fps;
}

void GT_time_Reset()
{
	GT_time_lastTick = GT_time_nextTick = SDL_GetTicks();
	GT_time_frames = 0;
	GT_time_waitTime = 0;
}

void GT_time_Mode(unsigned int flags)
{
	if (!(flags & 0x1)) {
		GT_time_waitFunc = GT_time_Nothing;
		return;
	}

	if (flags & 0x2)
		GT_time_waitFunc = GT_time_WaitWhile;
	else
		GT_time_waitFunc = GT_time_Delay;
}


int GT_time_WaitForFrame()
{
	int waitTime = GT_time_nextTick - SDL_GetTicks();
	
	if (waitTime > 0)
		GT_time_waitFunc(waitTime);
	
	if (GT_time_maxFrames <= GT_time_frames) {
		GT_time_maxFramesFunc();
		GT_time_Reset();
	}

	GT_time_lastTick = GT_time_nextTick;
	GT_time_nextTick = SDL_GetTicks() + GT_time_sleeptime;
	GT_time_frames++;
	GT_time_waitTime += waitTime;

	return waitTime;
}

void GT_time_Delay(int mills)
{
	SDL_Delay(mills);
}


void GT_time_WaitWhile(int mills)
{
	int nextTick = SDL_GetTicks() + mills;

	while (SDL_GetTicks() < nextTick);
}

void GT_time_Nothing(int mills)
{
	/* nothing */
}

void GT_time_PrintAVG()
{
	printf("AVG wait time: %i\n", GT_time_waitTime / GT_time_frames);
}

double GT_time_PastTime()
{
	return ((double) GT_time_nextTick - GT_time_lastTick) / 1000;
}
