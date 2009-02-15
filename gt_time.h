/*
 * File gt_time.h
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

/*
 * In this file all the time functions are stored
 */

#ifndef GT_TIME_H
#define GT_TIME_H

/* Flags */
#define GT_TIME_USEDELAY 0x1  /* Use SDL_Delay to wait for the next frame */
#define GT_TIME_USEWHILE 0x3  /* Use while loop to wait */

/*
 * GT_Time Attributes
 *
 * GT_time_nextTick - wait until this tick has reached
 * GT_time_frames - drawn frames
 * GT_time_waitTime - waited milliseconds till the next frame
 */
extern unsigned int GT_time_fps;
extern unsigned int GT_time_sleeptime;

extern unsigned int GT_time_maxFrames;

extern void (*GT_time_waitFunc)(int mills);
extern void (*GT_time_maxFramesFunc)();

extern unsigned int GT_time_lastTick;
extern unsigned int GT_time_nextTick;
extern unsigned int GT_time_frames;
extern int GT_time_waitTime;


/*
 * Call this before you start the gameloop 
 */
int GT_time_Init(unsigned int flags);


void GT_time_SetFps(int fps);
void GT_time_Mode(unsigned int flags);
void GT_time_Reset();


/*
 * This should be the first call in the gameloop
 */

inline int GT_time_WaitForFrame();

/*
 * Default wait functions
 */

void GT_time_Delay(int mills);
void GT_time_WaitWhile(int mills);
void GT_time_Nothing(int mills);


/*
 * Prints average waittime
 */

void GT_time_PrintAVG();

/*
 * Returns past time since the last frame in seconds
 */

double GT_time_PastTime();

#endif
