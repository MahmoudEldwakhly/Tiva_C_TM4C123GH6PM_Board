///////////////////////////////////////////////////////////////////////////////
//
// IAR ANSI C/C++ Compiler V9.10.1.308/W64 for ARM        23/Oct/2024  11:53:46
// Copyright 1999-2021 IAR Systems AB.
//
//    Cpu mode     =  thumb
//    Endian       =  little
//    Source file  =
//        E:\Engineer\TA Work\04-Fall-24\CSE211 Introduction to
//        Embedded\2_Hands-on_Projects\Lab_Projects\2_Embedded_C\3_LED_Toggle_TivaC\main.c
//    Command line =
//        -f "E:\Engineer\TA Work\04-Fall-24\CSE211 Introduction to
//        Embedded\2_Hands-on_Projects\Lab_Projects\2_Embedded_C\3_LED_Toggle_TivaC\Debug\Obj\main.o.rsp"
//        ("E:\Engineer\TA Work\04-Fall-24\CSE211 Introduction to
//        Embedded\2_Hands-on_Projects\Lab_Projects\2_Embedded_C\3_LED_Toggle_TivaC\main.c"
//        -lcN "E:\Engineer\TA Work\04-Fall-24\CSE211 Introduction to
//        Embedded\2_Hands-on_Projects\Lab_Projects\2_Embedded_C\3_LED_Toggle_TivaC\Debug\List\\"
//        -lb "E:\Engineer\TA Work\04-Fall-24\CSE211 Introduction to
//        Embedded\2_Hands-on_Projects\Lab_Projects\2_Embedded_C\3_LED_Toggle_TivaC\Debug\List\\"
//        --remarks -o "E:\Engineer\TA Work\04-Fall-24\CSE211 Introduction to
//        Embedded\2_Hands-on_Projects\Lab_Projects\2_Embedded_C\3_LED_Toggle_TivaC\Debug\Obj\\"
//        --no_cse --no_unroll --no_inline --no_code_motion --no_tbaa
//        --no_clustering --no_scheduling --debug --endian=little
//        --cpu=Cortex-M4 -e --fpu=VFPv4_sp --dlib_config "C:\Program Files\IAR
//        Systems\Embedded Workbench 9.0\arm\inc\c\DLib_Config_Normal.h" -On)
//        --dependencies=n "E:\Engineer\TA Work\04-Fall-24\CSE211 Introduction
//        to
//        Embedded\2_Hands-on_Projects\Lab_Projects\2_Embedded_C\3_LED_Toggle_TivaC\Debug\Obj\main.o.d"
//    Locale       =  C
//    List file    =
//        E:\Engineer\TA Work\04-Fall-24\CSE211 Introduction to
//        Embedded\2_Hands-on_Projects\Lab_Projects\2_Embedded_C\3_LED_Toggle_TivaC\Debug\List\\main.s
//
///////////////////////////////////////////////////////////////////////////////

        #define SHT_PROGBITS 0x1

        PUBLIC delay
        PUBLIC main


        SECTION `.text`:CODE:NOROOT(1)
        THUMB
delay:
        SUB      SP,SP,#+4      
        MOVS     R1,#+0         
        STR      R1,[SP, #+0]   
??delay_0:
        LDR      R1,[SP, #+0]   
        CMP      R1,R0          
        BGE.N    ??delay_1      
        LDR      R1,[SP, #+0]   
        ADDS     R1,R1,#+1      
        STR      R1,[SP, #+0]   
        B.N      ??delay_0      
??delay_1:
        ADD      SP,SP,#+4      
        BX       LR             

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
main:
        PUSH     {R7,LR}        
        LDR.N    R0,??DataTable1
        LDR      R0,[R0, #+0]   
        ORRS     R0,R0,#0x20    
        LDR.N    R1,??DataTable1
        STR      R0,[R1, #+0]   
        LDR.N    R0,??DataTable1_1
        LDR      R0,[R0, #+0]   
        ORRS     R0,R0,#0x2     
        LDR.N    R1,??DataTable1_1
        STR      R0,[R1, #+0]   
        LDR.N    R0,??DataTable1_2
        LDR      R0,[R0, #+0]   
        ORRS     R0,R0,#0x2     
        LDR.N    R1,??DataTable1_2
        STR      R0,[R1, #+0]   
??main_0:
        LDR.N    R0,??DataTable1_3
        LDR      R0,[R0, #+0]   
        EORS     R0,R0,#0x2     
        LDR.N    R1,??DataTable1_3
        STR      R0,[R1, #+0]   
        LDR.N    R0,??DataTable1_4
        BL       delay          
        B.N      ??main_0       

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable1:
        DATA32
        DC32     0x400fe608     

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable1_1:
        DATA32
        DC32     0x40025400     

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable1_2:
        DATA32
        DC32     0x4002551c     

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable1_3:
        DATA32
        DC32     0x400253fc     

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable1_4:
        DATA32
        DC32     0xf4240        

        SECTION `.iar_vfe_header`:DATA:NOALLOC:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
        DC32 0

        END
// 
// 102 bytes in section .text
// 
// 102 bytes of CODE memory
//
//Errors: none
//Warnings: 1
