/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Users/jonnyTest/colector/clock.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_3620187407;

unsigned char ieee_p_2592010699_sub_1690584930_503743352(char *, unsigned char );
unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );
char *ieee_p_3620187407_sub_436279890_3965413181(char *, char *, char *, char *, int );


static void work_a_3767688416_3796425048_p_0(char *t0)
{
    char t18[16];
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    int t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned char t9;
    unsigned char t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;

LAB0:    xsi_set_current_line(17, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 2832);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(18, ng0);
    t3 = (t0 + 1352U);
    t4 = *((char **)t3);
    t5 = (23 - 23);
    t6 = (t5 * -1);
    t7 = (1U * t6);
    t8 = (0 + t7);
    t3 = (t4 + t8);
    t9 = *((unsigned char *)t3);
    t10 = (t9 == (unsigned char)3);
    if (t10 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(22, ng0);
    t1 = (t0 + 1352U);
    t3 = *((char **)t1);
    t1 = (t0 + 4516U);
    t4 = ieee_p_3620187407_sub_436279890_3965413181(IEEE_P_3620187407, t18, t3, t1, 1);
    t11 = (t18 + 12U);
    t6 = *((unsigned int *)t11);
    t7 = (1U * t6);
    t2 = (24U != t7);
    if (t2 == 1)
        goto LAB8;

LAB9:    t12 = (t0 + 2912);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    memcpy(t16, t4, 24U);
    xsi_driver_first_trans_fast(t12);

LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(19, ng0);
    t11 = xsi_get_transient_memory(24U);
    memset(t11, 0, 24U);
    t12 = t11;
    memset(t12, (unsigned char)2, 24U);
    t13 = (t0 + 2912);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    memcpy(t17, t11, 24U);
    xsi_driver_first_trans_fast(t13);
    xsi_set_current_line(20, ng0);
    t1 = (t0 + 1192U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t9 = ieee_p_2592010699_sub_1690584930_503743352(IEEE_P_2592010699, t2);
    t1 = (t0 + 2976);
    t4 = (t1 + 56U);
    t11 = *((char **)t4);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = t9;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB6;

LAB8:    xsi_size_not_matching(24U, t7, 0);
    goto LAB9;

}


extern void work_a_3767688416_3796425048_init()
{
	static char *pe[] = {(void *)work_a_3767688416_3796425048_p_0};
	xsi_register_didat("work_a_3767688416_3796425048", "isim/main_isim_beh.exe.sim/work/a_3767688416_3796425048.didat");
	xsi_register_executes(pe);
}
