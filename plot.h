#ifndef PLOT_H
#define PLOT_H

void unplot(int x, int y, unsigned char colour)
{
	unsigned char *address;

	//just in case you are testing a new algorithm
	/*if (x < 0)		return;
	if (x > 255)	return;
	if (y < 0)		return;*/
	if (y > 191)	return;

	address = zx_pxy2saddr(x,y);

	*address &= ~zx_px2bitmask(x);

	*zx_saddr2aaddr(address) = colour;
}










void dejavuPOINT_routine (void)
{
    zx_cls(PAPER_WHITE | INK_BLACK);

    for (yy = 0; yy < 192; yy++)
    {
        for (xx = 0; xx < 255 ; xx++)
        {
            gfx_xy = (yy << 8) | xx;
            dejavuPOINT();
        }
    }
}



//https://worldofspectrum.org/forums/discussion/472/line-routine/p1
void rtunes_pixelRoutine (void)
{
    zx_cls(PAPER_WHITE | INK_BLACK);
    for (yy = 0; yy < 192; yy++)
    {
        for (xx = 0; xx < 255 ; xx++)
        {
            gfx_xy = (yy << 8) | xx;
            rtunes_pixel();
        }
    }
}



void hellaPlotter1 (void)
{
    zx_cls(PAPER_WHITE | INK_BLACK);
    for (yy = 0; yy < 192; yy++)
    {
        for (xx = 0; xx < 255 ; xx++)
        {
            //gfx_xy = xx << 8;
            //gfx_xy = gfx_xy | yy;

            gfx_xy = (xx << 8) | yy;
            hellaPlot();
        }
    }
}


//----------------------------------------


//outside of the loop
    /*gfx_x = 75;
    gfx_y = 95;
    gfx_xy = gfx_y << 8;
    gfx_xy = gfx_xy | gfx_x;
    testPlot1();*/





#endif
//leave blank line after
