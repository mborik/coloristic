K_SYMB	= #1
K_CAPS	= #2
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

keys		db	"bnm",K_SYMB,K_SPACE
		db	"hjkl",K_ENTER
		db	"yuiop"
		db	"67890"
		db	"54321"
		db	"trewq"
		db	"gfdsa"
		db	"vcxz",0

.caps		db	"BNM",K_EXT,K_BREAK
		db	"HJKL",K_ENTER
		db	"YUIOP"
		db	K_DOWN,K_UP,K_RIGHT,K_GRAPH,K_DEL
		db	K_LEFT,K_INV,K_TRUE,K_LOCK,K_EDIT
		db	"TREWQ"
		db	"GFDSA"
		db	"VCXZ",K_CAPS
