#!/bin/sh

ASM="sjasmplus"
function LZX() {
	rm -f $2
	lzxpack -t34o3 $1
	mv -f ${2%.*}-t34o3.lzx $2
}

OUTPUT=coloristic.tap

cd gfx
LZX plan.scr plan.pak

cd ../src
${ASM} --lst=coloristic.lst coloristic.a80
LZX coloristic.bin coloristic.pak
${ASM} final.a80

rm -f ${OUTPUT}
zmakebas -a 10 -o $OUTPUT -n COLORISTIC src/coloristic.bas
bin2tap -a 32768 gfx/introscr.pak -append -o $OUTPUT
bin2tap -a 32768 src/coloristic.bin -append -o $OUTPUT
