K_SYMB	= #03
K_TRUE	= #04
K_INV	= #05
K_LOCK	= #06
K_EDIT	= #07
K_LEFT	= #08
K_RIGHT	= #09
K_DOWN	= #0A
K_UP	= #0B
K_DEL	= #0C
K_ENTER	= #0D
K_EXT	= #0E
K_GRAPH	= #0F
K_FIRE	= #10
K_BREAK	= #1B
K_SPACE	= #20

ctrldefs	db	"zxcv"
		db	K_FIRE,K_FIRE,"mnb"
		db	K_FIRE,"lkjh"
		db	K_RIGHT,K_LEFT,"iuy"
		db	"09",K_RIGHT,K_UP,K_DOWN ; Cursor joystick
		db	"1234",K_LEFT
		db	K_UP,"wert"
		db	K_DOWN,"sdfg"

keys		db	"zxcv"
		db	K_SPACE,K_SYMB,"mnb"
		db	K_ENTER,"lkjh"
		db	"poiuy"
		db	"09876"
		db	"12345"
		db	"qwert"
		db	"asdfg"

.caps		db	"ZXCV"
		db	K_SPACE,K_SYMB,"MNB"
		db	K_ENTER,"LKJH"
		db	"POIUY"
		db	K_DEL,K_GRAPH,K_RIGHT,K_UP,K_DOWN ; Cursor joystick
		db	K_EDIT,K_LOCK,K_TRUE,K_INV,K_LEFT
		db	"QWERT"
		db	"ASDFG"
