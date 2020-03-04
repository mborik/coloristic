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
${ASM} --nologo --lst coloristic.a80
LZX coloristic.bin coloristic.pak
${ASM} --nologo --lst --longptr final.a80

cd ..
rm -f ${OUTPUT}
zmakebas -a 10 -o $OUTPUT -n COLORISTIC coloristic.bas
bin2tap -a 32768 screen/introscr.pak -append -o $OUTPUT
bin2tap -a 24576 src/final.bin -append -o $OUTPUT
