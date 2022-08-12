//starup.c
//Eng.Ahmed MOhsen

#include<stdint.h>
extern int main();
extern int _stack_top;
void Reset_Handeler();

void Default_Handeler(){
	Reset_Handeler();
}
void NMI_Handeler() __attribute__((weak,alias("Default_Handeler")));;
void H_Fault_Handeler() __attribute__((weak,alias("Default_Handeler")));;
void MM_Fault_Handeler()  __attribute__((weak,alias("Default_Handeler")));;
void Bus_Fault()  __attribute__((weak,alias("Default_Handeler")));;
void Usage_Fault_Handeler() __attribute__((weak,alias("Default_Handeler")));;

uint32_t vectors[] __attribute__((section(".vectors"))) = {
	(uint32_t)&_stack_top,
	(uint32_t)&NMI_Handeler,
	(uint32_t)&H_Fault_Handeler,
	(uint32_t)&MM_Fault_Handeler,
	(uint32_t)&Bus_Fault,
	(uint32_t)&Usage_Fault_Handeler
};

extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;
extern unsigned int _E_text;

void Reset_Handeler(){
	//copy data from rom to ram
	unsigned int data_size=(unsigned char*)&_E_data - (unsigned char*)&_S_data;
	unsigned char* p_src =(unsigned char*)&_E_text;
	unsigned char* p_dst =(unsigned char*)&_S_data;
	int i;
	for(i=0;i<data_size;i++){
		*((unsigned char*)p_dst++)=*((unsigned char*)p_src++);
	}
	//init bss with zero
	unsigned int bss_size=(unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	
	p_dst =(unsigned char*)&_S_bss;
	
	for(i=0;i<bss_size;i++){
		*((unsigned char*)p_dst++)=(unsigned char) 0;

	}
	// jump to main 
	main();
}