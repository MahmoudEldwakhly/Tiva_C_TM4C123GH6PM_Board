﻿param([String]$debugfile = "");

# This powershell file has been generated by the IAR Embedded Workbench
# C - SPY Debugger, as an aid to preparing a command line for running
# the cspybat command line utility using the appropriate settings.
#
# Note that this file is generated every time a new debug session
# is initialized, so you may want to move or rename the file before
# making changes.
#
# You can launch cspybat by typing Powershell.exe -File followed by the name of this batch file, followed
# by the name of the debug file (usually an ELF / DWARF or UBROF file).
#
# Read about available command line parameters in the C - SPY Debugging
# Guide. Hints about additional command line parameters that may be
# useful in specific cases :
#   --download_only   Downloads a code image without starting a debug
#                     session afterwards.
#   --silent          Omits the sign - on message.
#   --timeout         Limits the maximum allowed execution time.
#


if ($debugfile -eq "")
{
& "C:\Program Files\IAR Systems\Embedded Workbench 9.0\common\bin\cspybat" -f "D:\Work\TA Work\03-Fall-24\CSE211 Introduction to Embedded\2_Hands-on_Projects\Lecture_Projects\IAR-Projects-Second-Half\lec 9 _ systick_interrupt\settings\lec9 _ systick_interrupt.Debug.general.xcl" --backend -f "D:\Work\TA Work\03-Fall-24\CSE211 Introduction to Embedded\2_Hands-on_Projects\Lecture_Projects\IAR-Projects-Second-Half\lec 9 _ systick_interrupt\settings\lec9 _ systick_interrupt.Debug.driver.xcl" 
}
else
{
& "C:\Program Files\IAR Systems\Embedded Workbench 9.0\common\bin\cspybat" -f "D:\Work\TA Work\03-Fall-24\CSE211 Introduction to Embedded\2_Hands-on_Projects\Lecture_Projects\IAR-Projects-Second-Half\lec 9 _ systick_interrupt\settings\lec9 _ systick_interrupt.Debug.general.xcl" --debug_file=$debugfile --backend -f "D:\Work\TA Work\03-Fall-24\CSE211 Introduction to Embedded\2_Hands-on_Projects\Lecture_Projects\IAR-Projects-Second-Half\lec 9 _ systick_interrupt\settings\lec9 _ systick_interrupt.Debug.driver.xcl" 
}
