//-----------------------------------------------------------------------------
// @rgba8.org
//-----------------------------------------------------------------------------
#ifndef EMP_XX_ATTRIBUTE_H
#define EMP_XX_ATTRIBUTE_H

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#if defined(__GNUC__)
#define EMP_UNUSED __attribute__ ((unused))
#define EMP_WARN_UNUSED __attribute__ ((warn_unused_result))
#define EMP_ALWAYS_INLINE __attribute__ ((always_inline))
#define EMP_NOINLINE __attribute__ ((noinline))
#define EMP_NORETURN __attribute__ ((noreturn))
#else
#define EMP_UNUSED
#define EMP_WARN_UNUSED
#define EMP_ALWAYS_INLINE
#define EMP_NOINLINE
#define EMP_NORETURN
#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#define EMP_INLINE inline EMP_ALWAYS_INLINE
#define EMP_INTERN static
#define EMP_RETURN EMP_WARN_UNUSED

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif

