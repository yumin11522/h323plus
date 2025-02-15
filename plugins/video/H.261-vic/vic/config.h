/************ Change log
 *
 * $Id $
 *
 *
 *
 ********/

#include <string.h>

typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int  u_int;
typedef unsigned char BYTE;
typedef unsigned long u_long;

#if _WIN32 || _WIN64
#include <netinet/in.h>
#endif



/*
 * Largest (user-level) packet size generated by our rtp applications.
 * Individual video formats may use smaller mtu's.
 */
#define RTP_MTU 1024

#if defined(_MSC_VER) && !defined(_WIN64)
  #define INT_64 __int64 // uncomment for 64 bit word machines
#elif defined(__GNUC__) || defined (sun)
  #define INT_64 long long
#endif

#ifdef _WIN32_WCE
typedef int intptr_t;
#endif

#if BYTE_ORDER == LITTLE_ENDIAN
  #define SWAP32(left,right) \
      ((char*)(left))[0] = ((const char*)(right))[3], \
      ((char*)(left))[1] = ((const char*)(right))[2], \
      ((char*)(left))[2] = ((const char*)(right))[1], \
      ((char*)(left))[3] = ((const char*)(right))[0]
#else
  #define SWAP32(left,right) *(long*)(left)=*(const long*)(right)
#endif
