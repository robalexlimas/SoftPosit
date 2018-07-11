/*============================================================================

This C source file is part of the SoftPosit Posit Arithmetic Package
by S. H. Leong (Cerlane).

Copyright 2017 A*STAR.  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice,
    this list of conditions, and the following disclaimer.

 2. Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions, and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

 3. Neither the name of the University nor the names of its contributors may
    be used to endorse or promote products derived from this software without
    specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS "AS IS", AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, ARE
DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=============================================================================*/

#include "platform.h"
#include "internals.h"


void printBinary(uint64_t * s, int size) {
	int i;
	uint64_t number = *s;
	int bitSize = size -1;
	for(i = 0; i < size; ++i)
	{
		if(i%8 == 0)
			putchar(' ');
		printf("%lld", (number >> (bitSize-i))&1);
	}
	printf("\n");

}

void printHex(uint64_t s) {
	printf("0x%x\n", s);

}
quire16_t q16_TwosComplement(quire16_t q){
	if (!isQ16Zero(q) && !isNaRQ16(q)){
		if (q.v[1]==0){
			q.v[0] = -q.v[0];
		}
		else{
			q.v[1] = - q.v[1];
			q.v[0] = ~q.v[0];
		}
	}
	return q;

}




