
#ifdef __cplusplus
extern "C"
{
#endif

#define FLAG_SET(x,flag) (x |= flag)
#define FLAG_CLEAR(x,flag) (x &= ~flag)
#define FLAG_CHECK(x,flag) ((x & flag) == (flag))

#define APDU_CLA(buff)  (buff[0])
#define APDU_INS(buff)  (buff[1])
#define APDU_P1(buff)   (buff[2])
#define APDU_P2(buff)   (buff[3])
#define APDU_P3_LX(buff)(buff[4])
#define APDU_DATA(buff) (buff[5])

#define INFINITE            0xFFFFFFFF  // Infinite timeout
/*! \def VLT_MACRO_SWAP_16

 */
#define VLT_MACRO_SWAP_16(x)    ((((UInt16)x >> 8) & 0x00FF) | (((UInt16)x << 8) & 0xFF00))

/*! \def VLT_MACRO_SWAP_32

 */
#define VLT_MACRO_SWAP_32(x)    ((((UInt32)x >> 24) & 0x000000FF) | \
                                (((UInt32)x >> 8) & 0x0000FF00) |   \
                                (((UInt32)x << 8) & 0x00FF0000) |   \
                                (((UInt32)x << 24) & 0xFF000000))

/*! \def VLT_MACRO_MIN

 */
#define VLT_MACRO_MIN(a, b)     ((a<b)?a:b)

/*! \def VLT_MACRO_MAX

 */
#define VLT_MACRO_MAX(a, b)     ((a>b)?a:b)

/*! \def VLT_MACRO_ARRAY_SIZE

 */
#define VLT_MACRO_ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

/*! \def VLT_MACRO_HEX_TO_BCD_8

 */
#define VLT_MACRO_HEX_TO_BCD_8(x)   ((x % 10) | \
                                ((x / 10) %10) << 4))

/*! \def VLT_MACRO_BCD_TO_HEX_8

 */
#define VLT_MACRO_BCD_TO_HEX_8(x)   (((x >> 4)*10) + (x & 0x0F))

/*! \def VLT_MACRO_HEX_TO_BCD_16

 */
#define VLT_MACRO_HEX_TO_BCD_16(x)  ((x % 10) | (((x / 10) %10) << 4) | \
                                (((x / 100) %10) << 8) | (((x / 1000) %10) << 12))

/*! \def VLT_MACRO_BCD_TO_HEX_16

 */
#define VLT_MACRO_BCD_TO_HEX_16(x)  (((x >> 12)*10) + (x >> 8) + ((x >> 4)*1000) + ((x & 0x000F)*100))

/*! \def VLT_MACRO_HEX_TO_BCD_32

 */
#define VLT_MACRO_HEX_TO_BCD_32(x)  (((x) % 10) | ((((x) / 10) %10) << 4)                           \
                                | ((((x) / 100) %10) << 8) | ((((x) / 1000) %10) << 12)         \
                                | ((((x) / 10000) %10) << 16) | ((((x) / 100000) %10) << 20)    \
                                | ((((x) / 1000000) %10) << 24) | ((((x) / 10000000) %10) << 28))

/*! \def VLT_MACRO_BCD_TO_HEX_32

 */
#define VLT_MACRO_BCD_TO_HEX_32(x)  (((x >> 4)*10000000) + ((x & 0x0000000F)*1000000) + \
                                ((x >> 12)*100000) + ((x >> 8)*10000) + \
                                ((x >> 20)*1000) + ((x >> 16)*100) + \
                                ((x >> 28)*10) + (x >> 24))

/*! \def VLT_MACRO_CHECK_RETURN_FN

 */
#define VLT_MACRO_CHECK_RETURN_FN(ret, expectedRet) if (ret != expectedRet) {return ret;}

/*! \def VLT_MACRO_CHECK_NULL

 */
#define VLT_MACRO_CHECK_NULL(x)                     (x == Null)

/*! \def VLT_MACRO_CHECK_NOT_NULL

 */
#define VLT_MACRO_CHECK_NOT_NULL(x)                 (x != Null)

/*! \def VLT_MACRO_ASSERT

 */
#define VLT_MACRO_ASSERT(ret, expectedRet)          if (ret != expectedRet) while(1);

/*! \def VLT_MACRO_ASSERT_IF_NULL

 */
#define VLT_MACRO_ASSERT_IF_NULL(x)                 if (x == Null) while(1);

/*! \def VLT_MACRO_ASSERT_IF_NULL2

 */
#define VLT_MACRO_ASSERT_IF_NULL2(x, y)             if ((x == Null) || (y == Null)) while(1);

/*! \def VLT_MACRO_ASSERT_IF_NULL3

 */
#define VLT_MACRO_ASSERT_IF_NULL3(x, y, z)          if ((x == Null) || (y == Null) || (z == Null)) while(1);

/*! \def VLT_MACRO_UINT32_BYTE1

 */
#define VLT_MACRO_UINT32_BYTE1(x)   (UInt8(x>>8))

/*! \def VLT_MACRO_UINT32_BYTE2

 */
#define VLT_MACRO_UINT32_BYTE2(x)   (UInt8(x>>16))

/*! \def VLT_MACRO_UINT32_BYTE3

 */
#define VLT_MACRO_UINT32_BYTE3(x)   (UInt8(x>>24))

/*! \def VLT_MACRO_UNUSE_PARAM

 */
#define VLT_MACRO_UNUSE_PARAM(x)    (x = 0)

/*! \def VLT_MACRO_UNUSE_PPARAM

 */
#define VLT_MACRO_UNUSE_PPARAM(x)   (x = (void *) NULL)

/*! \def VLT_MACRO_CHECK_BREAK

 */
#define VLT_MACRO_CHECK_BREAK(status)             {if ((status) != 0) {break;}}

/*! \def VLT_MACRO_CHECK_BREAK_FCT

 */
#define VLT_MACRO_CHECK_BREAK_FCT(status,fct) {(status) = (fct); VLT_MACRO_CHECK_BREAK(status);}

#define MLS_ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

#define MLS_DEBUG   0
#define MLS_RELEASE

#define FIRMWARE_DATE   __DATE__
#define FIRMWARE_TIME   __TIME__

#ifndef CHECK_SUCCESS
#define CHECK_SUCCESS(status)           {if ((status) != 0) {return (status);}}
#endif
/*! \def CHECK_SUCCESS_FCT(status,fct)

 */
#ifndef CHECK_SUCCESS_FCT
#define CHECK_SUCCESS_FCT(status,fct)   {(status) = (fct); CHECK_SUCCESS(status);}
#endif

#ifdef __cplusplus
}
#endif