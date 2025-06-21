SECTION code_user

PUBLIC _gfx_x
_gfx_x:
defb 0       ; coordinates


PUBLIC _gfx_y
_gfx_y:
defb 0


PUBLIC _gfx_xy
_gfx_xy:
defw 0

PUBLIC _gfx_yx
_gfx_yx:
defw 0

PUBLIC _pixel_on
_pixel_on:
defb 0

;;;
;X_PositionBits: defb 128,64,32,16,8,4,2,1
X_PositionBits: defb $80,$40,$20,$10,$08,$04,$02,$01

;DEFC X_PositionBits = 128,64,32,16,8,4,2,1
;X_PositionBits1 equ $80,$40,$20,$10,$08,$04,$02,$01
;defc X_PositionBits1 equ $80,$40,$20,$10,$08,$04,$02,$01
;;;

; WORKING ROUTINES
;Fastcall only supports one parameter in DEHL
;L = 8 bit
;HL = 16 bit
;DEHL = 32 bit
;;;;;;;;;;;;;;;;;;
;read up on
;https://worldofspectrum.org/forums/discussion/472/line-routine/p1


include "asm_files\dejavuPOINT.asm"
include "asm_files\rtunes.asm"
;include "asm_files\joffa_pixel.asm"
include "asm_files\hella_plot.asm"
include "asm_files\hella_point.asm"
include "asm_files\Kolotov.asm"




