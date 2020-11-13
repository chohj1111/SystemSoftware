.globl getBoxVolume
.text
getBoxVolume:
  movl %edi, %eax
  imul %esi, %eax
  imul %edx, %eax
  ret
