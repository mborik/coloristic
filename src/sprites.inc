	struct directions
L:		ds 32
U:		ds 32
R:		ds 32
D:		ds 32
	ends

	macro s2fn fn?, sprite?, attr?
		db	fn?
		db	attr?
		dw	sprite?
	endm

	macro sgap cnt?
	dup cnt?
		dd	TILE_NOP
	edup
	endm

	macro s2path tile?, color?
		s2fn	tile?, spr_path_H, color?
		s2fn	tile?, spr_path_V, color?
		sgap 2
		s2fn	tile?, spr_path_point.L, color?
		s2fn	tile?, spr_path_point.U, color?
		s2fn	tile?, spr_path_point.R, color?
		s2fn	tile?, spr_path_point.D, color?
		s2fn	tile?, spr_path_corn.L, color?
		s2fn	tile?, spr_path_corn.U, color?
		s2fn	tile?, spr_path_corn.R, color?
		s2fn	tile?, spr_path_corn.D, color?
		sgap 4
	endm

;;-----------------------------------------------------------------------------

TILE_BASE	= 0
TILE_TICK	= 2
TILE_WRAP	= 4
TILE_PATHSW	= 6
TILE_NOP	= 8

sprite2fntab:	dd	TILE_NOP			; 000
		s2fn	TILE_BASE, spr_base, 0q170	; 001
		s2fn	TILE_BASE, spr_switch, 0q170	; 002
		s2fn	TILE_BASE, spr_blocked, 0q070	; 003
		s2fn	TILE_BASE, spr_base, 0q160	; 004
		s2fn	TILE_BASE, spr_base, 0q120	; 005
		s2fn	TILE_BASE, spr_base, 0q150	; 006
		s2fn	TILE_BASE, spr_base, 0q140	; 007
		s2fn	TILE_TICK, spr_tick, 0q176	; 008
		s2fn	TILE_TICK, spr_tick, 0q172	; 009
		s2fn	TILE_TICK, spr_tick, 0q175	; 010
		s2fn	TILE_TICK, spr_tick, 0q174	; 011
		s2fn	TILE_BASE, spr_arrow.L, 0q170	; 012
		s2fn	TILE_BASE, spr_arrow.U, 0q170	; 013
		s2fn	TILE_BASE, spr_arrow.R, 0q170	; 014
		s2fn	TILE_BASE, spr_arrow.D, 0q170	; 015
		s2fn	TILE_WRAP, spr_wrap.L, 1	; 016
		s2fn	TILE_WRAP, spr_wrap.U, 2	; 017
		s2fn	TILE_WRAP, spr_wrap.R, 4	; 018
		s2fn	TILE_WRAP, spr_wrap.D, 8	; 019
		sgap 13					; 020 ... 032
		s2fn	TILE_BASE, spr_powerups + 0, 0q170	; 033
		s2fn	TILE_BASE, spr_powerups + 32, 0q170	; 034
		s2fn	TILE_BASE, spr_powerups + 64, 0q170	; 035
		s2fn	TILE_BASE, spr_powerups + 96, 0q170	; 036
		s2fn	TILE_BASE, spr_powerups + 128, 0q170	; 037
		sgap 27					; 038 ... 064
		s2fn	TILE_BASE, spr_blocked, 0q070	; 065
		sgap 10					; 066 ... 075
		s2fn	TILE_BASE, spr_blk_arrow.L, 0q070	; 076
		s2fn	TILE_BASE, spr_blk_arrow.U, 0q070	; 077
		s2fn	TILE_BASE, spr_blk_arrow.R, 0q070	; 078
		s2fn	TILE_BASE, spr_blk_arrow.D, 0q070	; 079
		sgap 48					; 080 ... 127
		s2path	TILE_BASE, 0q160		; 128 ... 143
		s2path	TILE_BASE, 0q120		; 144 ... 159
		s2path	TILE_BASE, 0q150		; 160 ... 175
		s2path	TILE_BASE, 0q140		; 176 ... 191
		s2path	TILE_PATHSW, 0q160		; 192 ... 207
		s2path	TILE_PATHSW, 0q120		; 208 ... 223
		s2path	TILE_PATHSW, 0q150		; 224 ... 239
		s2path	TILE_PATHSW, 0q140		; 240 ... 255


shade_right:	incbin "../gfx/shade_right.spr"
shade_bottom:	incbin "../gfx/shade_bottom.spr"
.length = ($-shade_bottom) / 2
shade_corner:	incbin "../gfx/shade_corner.spr"
.length = $-shade_corner

spr_base:	incbin "../gfx/001_base.spr"
spr_switch:	incbin "../gfx/002_switch.spr"
spr_blocked:	incbin "../gfx/003_blocked.spr"
spr_tick:	incbin "../gfx/008_tick.spr"
spr_arrow:	directions: org spr_arrow
		incbin "../gfx/012_arrows.spr"
spr_blk_arrow:	directions: org spr_blk_arrow
		incbin "../gfx/076_arrows_blocked.spr"
spr_wrap.L:	incbin "../gfx/016_wrap_L.spr"
spr_wrap.U:	incbin "../gfx/017_wrap_U.spr"
spr_wrap.R:	incbin "../gfx/018_wrap_R.spr"
spr_wrap.D:	incbin "../gfx/019_wrap_D.spr"
spr_powerups:	incbin "../gfx/033_powerups.spr"
spr_path_H:	incbin "../gfx/128_path_H.spr"
spr_path_V:	incbin "../gfx/129_path_V.spr"
spr_path_point:	directions: org spr_path_point
		incbin "../gfx/132_path_points.spr"
spr_path_corn:	directions: org spr_path_corn
		incbin "../gfx/136_path_dirs.spr"
spr_path_swtch:	incbin "../gfx/192_path_switch.spr"

spr_num_mask:	incbin "../gfx/numerals_mask.spr"
spr_numerals:	incbin "../gfx/numerals.spr"
