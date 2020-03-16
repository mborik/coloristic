K_SYMB	= 0
K_TRUE	= #4
K_INV	= #5
K_LOCK	= #6
K_EDIT	= #7
K_LEFT	= #8
K_RIGHT	= #9
K_DOWN	= #A
K_UP	= #B
K_DEL	= #C
K_ENTER	= #D
K_EXT	= #E
K_GRAPH	= #F
K_BREAK	= #1B
K_SPACE	= #20

ctrldefs	db	"zxcv"
		db	K_SPACE,K_SYMB,"mnb"
		db	K_ENTER,"lkjh"
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
