//variables
extern unsigned char gfx_x;
extern unsigned char gfx_y;
extern unsigned int gfx_xy;
extern unsigned int gfx_yx;

extern unsigned char pixel_on;

//routines


//Fastcall only supports one parameter in DEHL
//L = 8 bit
//HL = 16 bit
//DEHL = 32 bit

//All need adjustment to push de/hl


extern void __FASTCALL__ Get_Pixel_Address(void);//uses BC/hl

extern void __FASTCALL__ dejavuPOINT(void);//uses BC/de/hl

extern void __FASTCALL__ rtunes_pixel(void);//uses de/hl good


extern void __FASTCALL__ joffa_pixel2(void);//uses de/hl good

extern void __FASTCALL__ hellaPlot(void);//uses BC/de/hl

extern void __FASTCALL__ hellaPlot2(void);//uses de/hl

extern void __FASTCALL__ hellaPlot3(void);//uses de/hl

extern void __FASTCALL__ einar_table(void);


extern void __FASTCALL__ dmsmith(void);

extern void __FASTCALL__ Kolotov_POINT(void);

extern void __FASTCALL__ hellaPoint(void);


