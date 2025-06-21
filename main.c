//  zcc +zx -vn -SO3 -m -lm -clib=new main.c -o main -create-app

// using sccz80 1.99c

//https://github.com/z88dk/z88dk/wiki/Classic-GenericConsole

#define ABS(N) ((N<0)?(-N):(N))
#define abs(N) ((N<0)?(-N):(N))
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

#define z80_bpoke(a,b)  (*(unsigned char *)(a) = b)

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')
//this is lifted from
//https://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format

#pragma printf "%f %ld %d %c"
#pragma scanf  "%f %ld %d %c"

#define CHARACTER_WIDTH 31

#define SHR3 (jz=jsr, jsr^=(jsr<<7), jsr^=(jsr>>5), jsr^=(jsr<<3),jz+jsr)

#include <arch/zx.h>
#include <math.h>
#include <float.h>
#include <stdio.h>
#include <input.h>
#include <intrinsic.h>//temp to place labels
//powerful troubleshooting tool
        //intrinsic_label(border_start);
        //intrinsic_label(border_end);

#include "externs.h"

#include "variables.h"
#include "plot.h"

#include "timer.h"
#include "routines.h"



//#include "attributes.h"

void printOptions (void);


void set_x()
{
	zx_cls(PAPER_WHITE | INK_BLUE);
	zx_border (2);
	printf("Input a setting  0-255 Current = %d\n", x_plot);
	printf("\n");
	scanf("%d", &x_plot);
}

void set_y()
{
	zx_cls(PAPER_WHITE | INK_BLUE);
	zx_border (2);
	printf("Input a setting  0-191 Current = %d\n", y_plot);
	printf("\n");

	scanf("%d", &y_plot);
	if (y_plot > 191)
        y_plot = 191;
}

void set_random()
{
	//our random number from the macro , range is 1 to 254
    x_plot = (SHR3 % 254);
    //our random number from the macro , range is 1 to 191
    y_plot = (SHR3 % 191);
}


void options1 (void)
{
    //key presses
    while (1)
    {
        //IN_KEY_SCANCODE_SPACE

        if (in_key_pressed( IN_KEY_SCANCODE_1 ))
		{
			in_wait_nokey();
			set_x();//routine
            in_wait_key();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_2 ))
		{
			in_wait_nokey();
			set_y();//routine
            in_wait_key();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_3 ))
		{
			in_wait_nokey();
			set_random();//routine
            in_wait_key();
            break;
		}

        if (in_key_pressed( IN_KEY_SCANCODE_q ))
		{   //hella_plot   T-state
		    zx_cls(PAPER_WHITE | INK_BLUE);
            printf("\x16\x01\x02");


		    gfx_xy = (x_plot << 8) | y_plot;
            hellaPlot();

            timerStart();

		    for (yy = 0; yy < 192; yy++)
            {
                for (xx = 0; xx < 255 ; xx++)
                {
                    gfx_xy = (yy << 8) | xx;
                    Kolotov_POINT();
                    if (pixel_on == 1)
                    {
                        point_X = xx;
                        point_Y = yy;
                    }
                }
            }

            timerEnd();
            printf("Pixel Found x=%d  y=%d\n",point_X,point_Y);
            printf("? T-states per pixel\n");
            waitForKey ();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_z ))
		{   //hella_plot   T-state
		    zx_cls(PAPER_WHITE | INK_BLUE);
            printf("\x16\x01\x02");


		    gfx_xy = (x_plot << 8) | y_plot;
            hellaPlot();

            yy = y_plot;
            xx = x_plot + 1;
            gfx_xy = (yy << 8) | xx;
            hellaPoint();
            if (pixel_on == 1)
            {
                printf("Drat 1\n");
            }
            if (pixel_on == 0)
            {
                printf("good\n");
            }

            yy = y_plot;
            xx = x_plot - 1;
            gfx_xy = (yy << 8) | xx;
            hellaPoint();
            if (pixel_on == 1)
            {
                printf("Drat 2\n");
            }
            if (pixel_on == 0)
            {
                printf("good\n");
            }

            yy = y_plot + 1;
            xx = x_plot;
            gfx_xy = (yy << 8) | xx;
            hellaPoint();
            if (pixel_on == 1)
            {
                printf("Drat 3\n");
            }
            if (pixel_on == 0)
            {
                printf("good\n");
            }

            yy = y_plot - 1;
            xx = x_plot;
            gfx_xy = (yy << 8) | xx;
            hellaPoint();
            if (pixel_on == 1)
            {
                printf("Drat 4\n");
            }
            if (pixel_on == 0)
            {
                printf("good\n");
            }

            yy = y_plot;
            xx = x_plot;
            gfx_xy = (yy << 8) | xx;
            hellaPoint();
            if (pixel_on == 0)
            {
                printf("Drat 5\n");
            }
            if (pixel_on == 1)
            {
                printf("match\n");
            }



            waitForKey ();

            break;
		}

        if (in_key_pressed( IN_KEY_SCANCODE_w ))
		{   //hella_plot   T-state
		    zx_cls(PAPER_WHITE | INK_BLUE);
            printf("\x16\x01\x02");




		    gfx_xy = (x_plot << 8) | y_plot;
            hellaPlot();

		    timerStart();

		    point_X = 0;
            point_Y = 0;

		    for (yy = 0; yy < 192; yy++)
            {
                for (xx = 0; xx < 255 ; xx++)
                {
                    gfx_xy = (xx << 8) | yy;
                    hellaPoint();
                    if (pixel_on == 1)
                    {
                        point_X = xx;
                        point_Y = yy;
                    }
                }
            }

            timerEnd();

            printf("Pixel Found x=%d  y=%d\n",point_X,point_Y);
            printf("? T-states per pixel\n");
            waitForKey ();
            break;
		}



        if (in_key_pressed( IN_KEY_SCANCODE_f ))
		{   //dejavuPOINT   T-state
		    zx_cls(PAPER_WHITE | INK_BLACK);
		    printf("\x16\x01\x02");
		    timerStart();

            dejavuPOINT_routine();

            timerEnd();
            printf("177 T-states per pixel\n");
            waitForKey ();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_g ))
		{   //hella_plot   T-state
		    zx_cls(PAPER_WHITE | INK_BLUE);
		    printf("\x16\x01\x02");

		    gfx_xy = (x_plot << 8) | y_plot;
            hellaPlot();


		    timerStart();

		    //hellaPlotter1();

            timerEnd();
            printf("166 T-states per pixel\n");
            waitForKey ();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_h ))
		{   //rtunes_pixel w/ table
		    zx_cls(PAPER_WHITE | INK_BLUE);
		    printf("\x16\x01\x02");
		    timerStart();

		    rtunes_pixelRoutine();

            timerEnd();
            printf("170 T-states per pixel\n");
            waitForKey ();

            break;
		}


    }//end while
}//end options1



void printOptions (void)
{
    {
        zx_cls(PAPER_WHITE | INK_BLUE);
        zx_border (2);
        printf("\x16\x01\x02");

        printf ("Welcome to the Plot tester V0.3\n");
        printf ("press a key for test\n");
        printf ("\n");

        printf ("X = %d\n", x_plot);
        printf ("Y = %d\n", y_plot);
        printf ("\n\n");

        printf ("1 - X plot point\n");
        printf ("2 - Y plot point\n");
        printf ("3 - Random plot point\n");
        printf ("\n\n");

        printf ("f - dejavuPOINT Optimized w/ table\n");
        printf ("g - hella_plot w/ table\n");
        printf ("h - rtunes_pixel w/ table\n");
    }
    options1();
}


void main()
{
	__asm
	ei
	__endasm

	zx_cls(PAPER_WHITE | INK_BLUE);


    while (1)
    {
        printOptions();
    }

}

//leave blank line after


