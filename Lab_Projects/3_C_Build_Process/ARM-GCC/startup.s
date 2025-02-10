.global _start
_start:
    ldr r0, =_estack
    mov sp, r0

    bl main
    b .

_estack = 0x20008000
