#!/bin/sh

ASM="sjasmplus"
function LZX() {
	rm -f $2
	lzxpack -t34o3 $1
	mv -f ${2%.*}-t34o3.lzx $2
}

OUTPUT=coloristic.tap

rm -f ${OUTPUT}
zmakebas -a 10 -o $OUTPUT -n COLORISTIC coloristic.bas

cd gfx
LZX plan.scr plan.pak
LZX win.scr win.pak

cd ../src

# build ROM version
${ASM} --nologo -DBUILDROM --exp=xchg.inc --lst=coloristic.rom.lst coloristic.a80
LZX coloristic.bin coloristic.pak
${ASM} --nologo -DBUILDROM --longptr --lst=final.rom.lst final.a80

# build standard TAP version
${ASM} --nologo --lst=coloristic.lst coloristic.a80
LZX coloristic.bin coloristic.pak
${ASM} --nologo --longptr --lst=final.lst final.a80
