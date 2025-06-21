rem SET PATH=c:\z88dk199c;c:\z88dk199c\bin;c:\z88dk199c\lib\;c:\z88dk199c\lib\clibs;c:\z88dk199c\lib\config

SET PATH=c:\z88dk;c:\z88dk\bin;c:\z88dk\lib\;c:\z88dk\lib\clibs;c:\z88dk\lib\config




del "1_point.tap"
cls

@rem -pragma-include:zpragma.inc
@rem zcc +zx -vn -SO3 -m -lm -clib=new -o 1_plot @plot.lst -pragma-include:zpragma.inc -startup=9 -create-app


zcc +zx -vn -SO3 -m -lm -clib=new -o 1_point @point.lst -startup=9 -create-app







del "1_point_CODE.bin"
del "1_point_UNASSIGNED.bin"

rem rename main.tap sine.tap

call beep.bat
