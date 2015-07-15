//pe15-6.c 的头文件
#define BUFFER_SIZE 81 //行缓冲大小
#define MSTR	"f)change font s)change size   a)change alignment"
#define MSTR1   "b)toggle bold i)toggle italic u)toggle underline"
#define MSTR2   "q)quit"
#define SSTR	"l)left c)center r)right"

const char *  ALG[3] = {"left", "right", "center"};
const char *  TOG[2] = {"off", "on"};

typedef struct{
	unsigned int fontId:   8;
	unsigned int fontSize: 7;
    unsigned int 		 : 1;
    unsigned int algnMen:  2;
    unsigned int bold   :  1;
    unsigned int italic :  1;
    unsigned int underline:1;
} FONT;

void showInformation(FONT *);
char get_let(const char *);
int get_int(int);
void showMenu(FONT *);
void showStr(FONT *);
void change_font(FONT *);
void change_size(FONT *);
void change_aligment(FONT *);
void eatLine(void);