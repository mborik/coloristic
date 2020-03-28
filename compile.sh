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
${ASM} --nologo --lst coloristic.a80
LZX coloristic.bin coloristic.pak

${ASM} --nologo --longptr --lst=final.lst final.a80
