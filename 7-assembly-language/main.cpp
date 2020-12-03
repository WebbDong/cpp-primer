#include <iostream>

/**
    寄存器与内存
        1、通常，CPU会先将内存中的数据存储到寄存器中，然后再对寄存器中的数据进行运算，计算完后，在重新写入内存

    寄存器
        1、16位操作系统环境：AX\BX\CX\DX为通用寄存器，每个寄存器占2个字节
        2、X86 32位操作系统环境：EAX\EBX\ECX\EDX为通用寄存器，每个寄存器占4个字节
        3、X64 64位操作系统环境：RAX\RBX\RCX\RDX为通用寄存器，每个寄存器占8个字节

        对寄存器的兼容：
            |63..32|31..16|15-8|7-0|
                          |AH..|AL.|
                          |AX......|
                   |EAX............|
            |RAX...................|

            RAX包含EAX，EAX包含AX，AX又包含AH和AL，AX是EAX的一半，EAX是RAX的一半

        一般规律
            1、R开头的寄存器是64位的，占8个字节
            2、E开头的寄存器是32位的，占4个字节

    内联汇编
        1、在VS中使用__asm {}代码块，在GCC中使用asm("汇编代码")

    每一个字节都有自己的一个内存地址

    mov指令
        mov dest, src
            将src的内容赋值给dest，类似于dest = src
        [地址值]
            中括号里放的都是内存地址
        word是2个字节，dword(double word)是4个字节，qword(quad word)是8个字节

        mov dword ptr [ebp-8], 3
            这条指令，将3的值存储到地址为ebp-8，以4个字节为单位，ptr为固定写法
 * @return
 */
int main() {
    asm("movl $10, %eax");
    system("pause");
    return 0;
}
