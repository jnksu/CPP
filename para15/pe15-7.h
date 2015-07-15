//pe15-7.c 的头文件
#define BUFFER_SIZE 81 //行缓冲大小
#define MSTR	"f)change font s)change size   a)change alignment"
#define MSTR1   "b)toggle bold i)toggle italic u)toggle underline"
#define MSTR2   "q)quit"
#define SSTR	"l)left c)center r)right"
//掩码
#define IDMASK 0xFF	
#define SIMASK 0x7F00 
#define ALMASK 0x30000
#define BFMASK 0x40000
#define IFMASK 0x80000
#define UFMASK 0x100000

const char *  ALG[3] = { "left", "right", "center" };
const char *  TOG[2] = { "off", "on" };

void showInformation(unsigned long int);
char get_let(const char *);
int get_int(int);
void showMenu(unsigned long int *);
void showStr(unsigned long int);
void change_font(unsigned long int *);
void change_size(unsigned long int *);
void change_aligment(unsigned long int *);
void eatLine(void);