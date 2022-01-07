/*
 * $Header:   X:/pcc14/sql/h/sqlda.h_v   1.1   03 Feb 1992 10:54:34   BFOTEDAR  $ sqlda.h 
 */

/***************************************************************
*      The SQLDA descriptor definition                         *
*--------------------------------------------------------------*
*      VAX/3B Version                                          *
*                                                              *
*  Copyright (c) 1987 by Oracle Corporation                    *
***************************************************************/

/*  MODIFIED
    bfotedar   02/03/92 - Put in far cast to support farcall option
    Morse      12/01/87 - undef L and S for v6 include files
    Richey     07/13/87 - change int defs to long 
    Clare      09/13/84 - Port: Ch types to match SQLLIB structs
    Clare      10/02/86 - Add ifndef SQLDA
*/

#ifndef SQLDA_
#define SQLDA_ 1
 
#ifdef T
# undef T
#endif
#ifdef F
# undef F
#endif

#ifdef S
# undef S
#endif
#ifdef L
# undef L
#endif

#ifdef __IBMC__
#   define FAR
#else
#   ifndef FAR
#   define FAR far
#   endif
#endif /* __IBMC__ */
 
struct SQLDA {
  long             N;   /* Descriptor size in number of entries         */
  char  FAR * FAR *V;   /* Ptr to Arr of addresses of main variables    */
  long  FAR       *L;   /* Ptr to Arr of lengths of buffers             */
  short FAR       *T;   /* Ptr to Arr of types of buffers               */
  short FAR * FAR *I;   /* Ptr to Arr of addresses of indicator vars    */
  long             F;   /* Number of variables found by DESCRIBE        */
  char  FAR * FAR *S;   /* Ptr to Arr of variable name pointers         */
  short FAR       *M;   /* Ptr to Arr of max lengths of var. names      */
  short FAR       *C;   /* Ptr to Arr of current lengths of var. names  */
  char  FAR * FAR *X;   /* Ptr to Arr of ind. var. name pointers        */
  short FAR       *Y;   /* Ptr to Arr of max lengths of ind. var. names */
  short FAR       *Z;   /* Ptr to Arr of cur lengths of ind. var. names */
  };
 
typedef struct SQLDA SQLDA;
 
#endif
