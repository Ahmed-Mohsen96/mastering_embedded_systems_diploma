/*
 * macro.h
 *
 * Created: 12/6/2022 8:55:08 AM
 *  Author: soft
 */ 


#ifndef MACRO_H_
#define MACRO_H_

#define F_CPU 8000000

#define SETBIT(REG,BIT) REG|=1<<BIT
#define CLRBIT(REG,BIT) REG&=~(1<<BIT)
#define TOGBIT(REG,BIT) REG^=1<<BIT
#define GETBIT(REG,BIT) ((REG>>BIT)&1)  



#endif /* MACRO_H_ */