//
//  dukeunix.h
//  Duke3D
//
//  Created by fabien sanglard on 12-12-12.
//  Copyright (c) 2012 fabien sanglard. All rights reserved.
//

#ifndef Duke3D_dukeplan9_h
#define Duke3D_dukeplan9_h


#define cdecl
#define __far
#define __interrupt


//#define STUBBED(x)
#ifdef __SUNPRO_C
#define STUBBED(x) fprintf(stderr,"STUB\n")
#else
#define STUBBED(x) fprintf(stderr,"STUB\n")
#endif

#define PATH_SEP_CHAR '/'
#define PATH_SEP_STR  "/"
#define ROOTDIR       "/"
#define CURDIR        "./"

#ifndef O_BINARY
#define O_BINARY 0
#endif

#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <assert.h>

struct find_t
{
    DIR *dir;
    char  pattern[MAX_PATH];
    char  name[MAX_PATH];
};
int _dos_findfirst(char  *filename, int x, struct find_t *f);
int _dos_findnext(struct find_t *f);

struct dosdate_t
{
    uint8_t  day;
    uint8_t  month;
    unsigned int year;
    uint8_t  dayofweek;
};

void _dos_getdate(struct dosdate_t *date);

#ifndef min
#define min(x, y) ((x) < (y) ? (x) : (y))
#endif

#ifndef max
#define max(x, y) ((x) > (y) ? (x) : (y))
#endif

#ifdef DC
#undef stderr
#undef stdout
#undef getchar
/* kos compat */
#define stderr ((FILE*)2)
#define stdout ((FILE*)2)
#define Z_AvailHeap() ((10 * 1024) * 1024)
#else
// 64 megs should be enough for anybody.  :)  --ryan.
#define Z_AvailHeap() ((64 * 1024) * 1024)
#endif

#define printchrasm(x,y,ch) printf("%c", (uint8_t ) (ch & 0xFF))

#ifdef __GNUC__
#define GCC_PACK1_EXT __attribute__((packed,aligned(1)))
#endif

#define getch getchar

#define clock() nsec()
#define CLOCKS_PER_SEC 1000000000

// fuck it
#define alloca malloc
#define lseek seek

#endif
