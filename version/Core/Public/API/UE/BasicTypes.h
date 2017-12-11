#ifndef __BASICTYPES_H
#define __BASICTYPES_H

#ifdef _MSC_VER
typedef __int8 SBYTE;
typedef unsigned __int8 BYTE;
typedef __int16 SWORD;
typedef unsigned __int16 WORD;
typedef __int32 SDWORD;
typedef unsigned __int32 uint32;
typedef __int64 SQWORD;
typedef unsigned __int64 QWORD;
#else
#include <stdint.h>

typedef int8_t					SBYTE;
typedef uint8_t					BYTE;
typedef int16_t					SWORD;
typedef uint16_t				WORD;
typedef int32_t					SDWORD;
typedef uint32_t				uint32;
typedef int64_t					SQWORD;
typedef uint64_t				QWORD;
#endif

typedef SDWORD int32;
typedef float real32;
typedef double real64;

// [BC] New additions.
typedef unsigned short USHORT;
typedef short SHORT;
#ifdef __WINE__
typedef unsigned int ULONG;
typedef int LONG;
#else
typedef unsigned long ULONG;
typedef long LONG;
#endif
typedef unsigned int UINT;
typedef int INT;

// windef.h, included by windows.h, has its own incompatible definition
// of DWORD as a long. In files that mix Doom and Windows code, you
// must define USE_WINDOWS_DWORD before including doomtype.h so that
// you are aware that those files have a different DWORD than the rest
// of the source.

#ifndef USE_WINDOWS_DWORD
typedef uint32 UINT32;
typedef __int8 int8;
typedef unsigned __int8 uint8;
typedef __int16 int16;
typedef unsigned __int16 uint16;
typedef __int64 int64;
typedef unsigned __int64 uint64;
#endif
typedef uint32 BITFIELD;
typedef int INTBOOL;

// a 64-bit constant
#ifdef __GNUC__
#define CONST64(v) (v##LL)
#define UCONST64(v) (v##ULL)
#else
#define CONST64(v) ((SQWORD)(v))
#define UCONST64(v) ((QWORD)(v))
#endif

#if !defined(GUID_DEFINED)
#define GUID_DEFINED
typedef struct _GUID
{
	UINT32	Data1;
    WORD	Data2;
    WORD	Data3;
    BYTE	Data4[8];
} GUID;
#endif

union QWORD_UNION
{
	QWORD AsOne;

	struct
	{
#ifdef __BIG_ENDIAN__
		unsigned int Hi, Lo;
#else
		unsigned int Lo, Hi;
#endif
	};
};

//
// Fixed point, 32bit as 16.16.
//
#define FRACBITS						16
#define FRACUNIT						(1<<FRACBITS)

typedef SDWORD fixed_t;

#define FIXED_MAX						(signed)(0x7fffffff)
#define FIXED_MIN						(signed)(0x80000000)

#define DWORD_MIN						((uint32)0)
#define DWORD_MAX						((uint32)0xffffffff)


#ifdef __GNUC__
#define GCCPRINTF(stri,firstargi)		__attribute__((format(printf,stri,firstargi)))
#define GCCFORMAT(stri)					__attribute__((format(printf,stri,0)))
#define GCCNOWARN						__attribute__((unused))
#else
#define GCCPRINTF(a,b)
#define GCCFORMAT(a)
#define GCCNOWARN
#endif

enum { INDEX_NONE = -1 };

typedef TCHAR WIDECHAR;
typedef CHAR ANSICHAR;

#endif
