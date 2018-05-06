/*
 ****************************************************************************
 *
 *                   "DHRYSTONE" Benchmark Program
 *                   -----------------------------
 *                                                                            
 *  Version:    C, Version 2.1
 *                                                                            
 *  File:       dhry_1.c (part 2 of 3)
 *
 *  Date:       May 25, 1988
 *
 *  Author:     Reinhold P. Weicker
 *
 ****************************************************************************
 */

#include "dhry.h"
// ※適当にヘッダファイル追加
#include <xc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ※シミュレータなのでコンフィグはわりとどうでもいいが、最低限WDTを無効化しておかないと途中で止まる
#pragma config WDTE=OFF

/* Global Variables: */

Rec_Pointer     Ptr_Glob,
                Next_Ptr_Glob;
int             Int_Glob;
Boolean         Bool_Glob;
char            Ch_1_Glob,
                Ch_2_Glob;
// ※メモリが少ないため値を減らす
int             Arr_1_Glob [25]; //Arr_1_Glob [50];
int             Arr_2_Glob [7][6]; //Arr_2_Glob [50] [50];

// ※mallocは使えなかったので消す
//extern char     *malloc ();
Enumeration     Func_1 ();
  /* forward declaration necessary since Enumeration may not simply be int */

#ifndef REG
        Boolean Reg = false;
#define REG
        /* REG becomes defined as empty */
        /* i.e. no register variables   */
#else
        Boolean Reg = true;
#endif

/* variables for time measurement: */
// ※時間計測用のコードは使わないのでコメントアウト
/*
#ifdef TIMES
struct tms      time_info;
extern  int     times ();
                /* see library function "times" * /
#define Too_Small_Time (2*HZ)
                /* Measurements should last at least about 2 seconds * /
#endif
#ifdef TIME
extern long     time();
                /* see library function "time"  * /
#define Too_Small_Time 2
                /* Measurements should last at least 2 seconds * /
#endif
#ifdef MSC_CLOCK
extern clock_t	clock();
#define Too_Small_Time (2*HZ)
#endif
        
long            Begin_Time,
                End_Time,
                User_Time;
float           Microseconds,
                Dhrystones_Per_Second;
*/

/* end of variables for time measurement */

// ※printfから呼ばれる。シミュレータで止めて引数を見るためだけのコード。
void putch(char c)
{
	volatile PORTB = c;
}

main ()
/*****/

  /* main program, corresponds to procedures        */
  /* Main and Proc_0 in the Ada version             */
{
    
// ※シミュレータでブレークポイントを置くため
    asm("nop");

	// ※乗算のテストコード
//	char temp01 = 38;
//	char temp02 = 100;
//	int temp03 = temp01*temp02;

	// ※アドレス上下分割のテストコード
//	int address = 0x1234;
//	char addressh = address >> 6;
//	char addressl = address & 0x3F;
    
    /**/
    
        One_Fifty       Int_1_Loc;
  REG   One_Fifty       Int_2_Loc;
        One_Fifty       Int_3_Loc;
  REG   char            Ch_Index;
        Enumeration     Enum_Loc;
        Str_30          Str_1_Loc;
        Str_30          Str_2_Loc;
  REG   int             Run_Index;
  REG   int             Number_Of_Runs;

  /* Initializations */
  // ※mallocが使えなかったので直接指定に書き換え
/*
  Next_Ptr_Glob = (Rec_Pointer) malloc (sizeof (Rec_Type));
  Ptr_Glob = (Rec_Pointer) malloc (sizeof (Rec_Type));
*/
  Rec_Type temp1;
  Rec_Type temp2;
  Next_Ptr_Glob = &temp1;
  Ptr_Glob = &temp2;
  
  
  Ptr_Glob->Ptr_Comp                    = Next_Ptr_Glob;
  Ptr_Glob->Discr                       = Ident_1;
  Ptr_Glob->variant.var_1.Enum_Comp     = Ident_3;
  Ptr_Glob->variant.var_1.Int_Comp      = 40;
  strcpy (Ptr_Glob->variant.var_1.Str_Comp, 
          "DHRYSTONE PROGRAM, SOME STRING");
  strcpy (Str_1_Loc, "DHRYSTONE PROGRAM, 1'ST STRING");
  
  // ※ポインタのビット数を合わせるため
  Next_Ptr_Glob->Ptr_Comp = Ptr_Glob;
  

  Arr_2_Glob [8][7] = 10;
  //Arr_2_Glob[4][3]=10; // ※配列の範囲内をアクセスさせる場合の値
        /* Was missing in published program. Without this statement,    */
        /* Arr_2_Glob [8][7] would have an undefined value.             */
        /* Warning: With 16-Bit processors and Number_Of_Runs > 32000,  */
        /* overflow may occur for this array element.                   */
  
  // ※文字出力は最小限に
/*
  printf ("\n");
  printf ("Dhrystone Benchmark, Version 2.1 (Language: C)\n");
  printf ("\n");
  
  if (Reg)
  {
    printf ("Program compiled with 'register' attribute\n");
    printf ("\n");
  }
  else
  {
    printf ("Program compiled without 'register' attribute\n");
    printf ("\n");
  }
 */
  // ※入力を扱うのは面倒なので実行回数は直書き
/*
  printf ("Please give the number of runs through the benchmark: ");
  {
    int n;
    scanf ("%d", &n);
    Number_Of_Runs = n;
  }
  printf ("\n");
*/
  Number_Of_Runs = 1000; /**/
  
  // ※文字出力は最小限に
  printf ("[");//("Execution starts, %d runs through Dhrystone\n", Number_Of_Runs);

  /***************/
  /* Start timer */
  /***************/
// ※実行時間の測定はシミュレータで行うので不要
 /*
#ifdef TIMES
  times (&time_info);
  Begin_Time = (long) time_info.tms_utime;
#endif
#ifdef TIME
  Begin_Time = time ( (long *) 0);
#endif
#ifdef MSC_CLOCK
  Begin_Time = clock();
#endif
*/
  
  for (Run_Index = 1; Run_Index <= Number_Of_Runs; ++Run_Index)
  {

    Proc_5();
    Proc_4();
      /* Ch_1_Glob == 'A', Ch_2_Glob == 'B', Bool_Glob == true */
    Int_1_Loc = 2;
    Int_2_Loc = 3;
    strcpy (Str_2_Loc, "DHRYSTONE PROGRAM, 2'ND STRING");
    Enum_Loc = Ident_2;
    Bool_Glob = ! Func_2 (Str_1_Loc, Str_2_Loc);
      /* Bool_Glob == 1 */
    while (Int_1_Loc < Int_2_Loc)  /* loop body executed once */
    {
      Int_3_Loc = 5 * Int_1_Loc - Int_2_Loc;
        /* Int_3_Loc == 7 */
      Proc_7 (Int_1_Loc, Int_2_Loc, &Int_3_Loc);
        /* Int_3_Loc == 7 */
      Int_1_Loc += 1;
    } /* while */
      /* Int_1_Loc == 3, Int_2_Loc == 3, Int_3_Loc == 7 */
    Proc_8 (Arr_1_Glob, Arr_2_Glob, Int_1_Loc, Int_3_Loc);
      /* Int_Glob == 5 */
    Proc_1 (Ptr_Glob);
    for (Ch_Index = 'A'; Ch_Index <= Ch_2_Glob; ++Ch_Index)
                             /* loop body executed twice */
    {
      if (Enum_Loc == Func_1 (Ch_Index, 'C'))
          /* then, not executed */
        {
        Proc_6 (Ident_1, &Enum_Loc);
        strcpy (Str_2_Loc, "DHRYSTONE PROGRAM, 3'RD STRING");
        Int_2_Loc = Run_Index;
        Int_Glob = Run_Index;
        }
    }
      /* Int_1_Loc == 3, Int_2_Loc == 3, Int_3_Loc == 7 */
    Int_2_Loc = Int_2_Loc * Int_1_Loc;
    Int_1_Loc = Int_2_Loc / Int_3_Loc;
    Int_2_Loc = 7 * (Int_2_Loc - Int_3_Loc) - Int_1_Loc;
      /* Int_1_Loc == 1, Int_2_Loc == 13, Int_3_Loc == 7 */
    Proc_2 (&Int_1_Loc);
      /* Int_1_Loc == 5 */

  } /* loop "for Run_Index" */

  /**************/
  /* Stop timer */
  /**************/
// ※実行時間の測定はシミュレータで行うので不要
  /*
#ifdef TIMES
  times (&time_info);
  End_Time = (long) time_info.tms_utime;
#endif
#ifdef TIME
  End_Time = time ( (long *) 0);
#endif
#ifdef MSC_CLOCK
  End_Time = clock();
#endif
*/

// ※文字出力は最小限に
  printf ("]\n"); //printf ("Execution ends\n");
//  printf ("\n");
//  printf ("Final values of the variables used in the benchmark:\n");
//  printf ("\n");
  printf ("a:%d\n", Int_Glob);
//  printf ("        should be:   %d\n", 5);
  printf ("b:%d\n", Bool_Glob);
//  printf ("        should be:   %d\n", 1);
  printf ("c:%c\n", Ch_1_Glob);
//  printf ("        should be:   %c\n", 'A');
  printf ("d:%c\n", Ch_2_Glob);
//  printf ("        should be:   %c\n", 'B');
  printf ("e:%d\n", Arr_1_Glob[8]); //Arr_1_Glob[4]);
//  printf ("        should be:   %d\n", 7);
  printf ("f:%d\n", Arr_2_Glob[8][7]); //Arr_2_Glob[4][3]);
//  printf ("        should be:   Number_Of_Runs + 10\n");
  printf ("g:%d\n", (int) Ptr_Glob->Ptr_Comp);
//  printf ("        should be:   (implementation-dependent)\n");
  printf ("h:%d\n", Ptr_Glob->Discr);
//  printf ("        should be:   %d\n", 0);
  printf ("i:%d\n", Ptr_Glob->variant.var_1.Enum_Comp);
//  printf ("        should be:   %d\n", 2);
  printf ("j:%d\n", Ptr_Glob->variant.var_1.Int_Comp);
//  printf ("        should be:   %d\n", 17);
  printf ("k:%s\n", Ptr_Glob->variant.var_1.Str_Comp);
//  printf ("        should be:   DHRYSTONE PROGRAM, SOME STRING\n");
  printf ("l:%d\n", (int) Next_Ptr_Glob->Ptr_Comp);
//  printf ("        should be:   (implementation-dependent), same as above\n");
  printf ("m:%d\n", Next_Ptr_Glob->Discr);
//  printf ("        should be:   %d\n", 0);
  printf ("n:%d\n", Next_Ptr_Glob->variant.var_1.Enum_Comp);
//  printf ("        should be:   %d\n", 1);
  printf ("o:%d\n", Next_Ptr_Glob->variant.var_1.Int_Comp);
//  printf ("        should be:   %d\n", 18);
  printf ("p:%s\n",
                                Next_Ptr_Glob->variant.var_1.Str_Comp);
//  printf ("        should be:   DHRYSTONE PROGRAM, SOME STRING\n");
  printf ("q:%d\n", Int_1_Loc);
//  printf ("        should be:   %d\n", 5);
  printf ("r:%d\n", Int_2_Loc);
//  printf ("        should be:   %d\n", 13);
  printf ("s:%d\n", Int_3_Loc);
//  printf ("        should be:   %d\n", 7);
  printf ("t:%d\n", Enum_Loc);
//  printf ("        should be:   %d\n", 1);
  printf ("u:%s\n", Str_1_Loc);
//  printf ("        should be:   DHRYSTONE PROGRAM, 1'ST STRING\n");
  printf ("v:%s\n", Str_2_Loc);
//  printf ("        should be:   DHRYSTONE PROGRAM, 2'ND STRING\n");
  printf ("\n");

// ※実行時間の測定はシミュレータで行うので不要
/*
  User_Time = End_Time - Begin_Time;
  if (User_Time < Too_Small_Time)
  {
    printf ("Measured time too small to obtain meaningful results\n");
    printf ("Please increase number of runs\n");
    printf ("\n");
  }
  else */
  {
      /*
#ifdef TIME
    Microseconds = (float) User_Time * Mic_secs_Per_Second 
                        / (float) Number_Of_Runs;
    Dhrystones_Per_Second = (float) Number_Of_Runs / (float) User_Time;
#else
    Microseconds = (float) User_Time * Mic_secs_Per_Second 
                        / ((float) HZ * ((float) Number_Of_Runs));
    Dhrystones_Per_Second = ((float) HZ * (float) Number_Of_Runs)
                        / (float) User_Time;
#endif
       */
      /*
    printf ("Microseconds for one run through Dhrystone: ");
    printf ("%6.1f \n", Microseconds);
    printf ("Dhrystones per Second:                      ");
    printf ("%6.1f \n", Dhrystones_Per_Second);
    printf ("\n");
       * */
  }
  
}


Proc_1 (Ptr_Val_Par)
/******************/

REG Rec_Pointer Ptr_Val_Par;
    /* executed once */
{
  REG Rec_Pointer Next_Record = Ptr_Val_Par->Ptr_Comp;  
                                        /* == Ptr_Glob_Next */
  /* Local variable, initialized with Ptr_Val_Par->Ptr_Comp,    */
  /* corresponds to "rename" in Ada, "with" in Pascal           */
  
  structassign (*Ptr_Val_Par->Ptr_Comp, *Ptr_Glob); 
  Ptr_Val_Par->variant.var_1.Int_Comp = 5;
  Next_Record->variant.var_1.Int_Comp 
        = Ptr_Val_Par->variant.var_1.Int_Comp;
  Next_Record->Ptr_Comp = Ptr_Val_Par->Ptr_Comp;
  Proc_3 (&Next_Record->Ptr_Comp);
    /* Ptr_Val_Par->Ptr_Comp->Ptr_Comp 
                        == Ptr_Glob->Ptr_Comp */
  if (Next_Record->Discr == Ident_1)
    /* then, executed */
  {
    Next_Record->variant.var_1.Int_Comp = 6;
    Proc_6 (Ptr_Val_Par->variant.var_1.Enum_Comp, 
           &Next_Record->variant.var_1.Enum_Comp);
    Next_Record->Ptr_Comp = Ptr_Glob->Ptr_Comp;
    Proc_7 (Next_Record->variant.var_1.Int_Comp, 10, 
           &Next_Record->variant.var_1.Int_Comp);
  }
  else /* not executed */
    structassign (*Ptr_Val_Par, *Ptr_Val_Par->Ptr_Comp);
} /* Proc_1 */


Proc_2 (Int_Par_Ref)
/******************/
    /* executed once */
    /* *Int_Par_Ref == 1, becomes 4 */

One_Fifty   *Int_Par_Ref;
{
  One_Fifty  Int_Loc;  
  Enumeration   Enum_Loc;

  Int_Loc = *Int_Par_Ref + 10;
  do /* executed once */
    if (Ch_1_Glob == 'A')
      /* then, executed */
    {
      Int_Loc -= 1;
      *Int_Par_Ref = Int_Loc - Int_Glob;
      Enum_Loc = Ident_1;
    } /* if */
  while (Enum_Loc != Ident_1); /* true */
} /* Proc_2 */


Proc_3 (Ptr_Ref_Par)
/******************/
    /* executed once */
    /* Ptr_Ref_Par becomes Ptr_Glob */

Rec_Pointer *Ptr_Ref_Par;

{
  if (Ptr_Glob != Null)
    /* then, executed */
    *Ptr_Ref_Par = Ptr_Glob->Ptr_Comp;
  Proc_7 (10, Int_Glob, &Ptr_Glob->variant.var_1.Int_Comp);
} /* Proc_3 */


Proc_4 () /* without parameters */
/*******/
    /* executed once */
{
  Boolean Bool_Loc;

  Bool_Loc = Ch_1_Glob == 'A';
  Bool_Glob = Bool_Loc | Bool_Glob;
  Ch_2_Glob = 'B';
} /* Proc_4 */


Proc_5 () /* without parameters */
/*******/
    /* executed once */
{
  Ch_1_Glob = 'A';
  Bool_Glob = false;
} /* Proc_5 */


        /* Procedure for the assignment of structures,          */
        /* if the C compiler doesn't support this feature       */
#ifdef  NOSTRUCTASSIGN
// ※memcpyは使っているのでこちらは消す
/*
memcpy (d, s, l)
register char   *d;
register char   *s;
register int    l;
{
        while (l--) *d++ = *s++;
}
 */
#endif


