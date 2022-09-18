//startup.s
//Eng.Ahmed Mohsen

.section .vectors

.word	0x20001000		//stack top address
.word	_reset    		//1 reset
.word   vector_handeler //2 NMI
.word   vector_handeler //3 HARD FAULT
.word   vector_handeler //4 MM FAULT
.word   vector_handeler //5 BUS FAULT
.word   vector_handeler //6 USAGE FAULT
.word   vector_handeler //7 RESERVED
.word   vector_handeler //8 RESERVED
.word   vector_handeler //9 RESERVED
.word   vector_handeler //10 RESERVED
.word   vector_handeler //11 SV CALL
.word   vector_handeler //12 DEBUG RESERVED
.word   vector_handeler //13 RESERVED
.word   vector_handeler //14 PENDSV
.word   vector_handeler //15 SYS TICK
.word   vector_handeler //16 IRQ0
.word   vector_handeler //17 IRQ1
.word   vector_handeler //18 IRG2
.word   vector_handeler //19 ...
		// on to IRQ67

.section  .text
_reset:
	bl main
	b .

	.thumb_func   //enable 16 and 32 bit
vector_handeler:
	b  _reset