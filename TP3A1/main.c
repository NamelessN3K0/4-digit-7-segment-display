/*
 * TP3A1.c
 *
 * Created: 06/05/2022 12:59:48
 * Author : ##########
 */ 

#include <avr/io.h>
#include "OS.h"

#define F_CPU 16000000
#include <util/delay.h>


// VARIAVEIS GLOBAIS
uint16_t counter = INIT;						 //variavel do numero a escrever
uint16_t temp= INIT;							 //variavel temporaria para calc
char conver[10]={N0,N1,N2,N3,N4,N5,N6,N7,N8,N9}; //array para conversao do digitos


void write(void){
	/************************************************************************/
	/* FUNÇÃO VOID PARA ESCRITA DOS DIGITOS NO DISPLAY                      */
	/************************************************************************/
	temp= counter;								//copia o valor do counter
	sel0;										//desceleciona tudo no display
	PORTD=conver[temp %10];						//converte o numero para a macro correspondente
	sel4;										//escreve a macro no 4 numero
	temp= temp /10;
	
	sel0;										//desceleciona tudo no display
	PORTD=conver[temp %10];						//converte o numero para a macro correspondente
	sel3;										//escreve a macro no 3 numero
	temp= temp /10;
	
	sel0;										//desceleciona tudo no display
	PORTD=conver[temp %10];						//converte o numero para a macro correspondente
	sel2;										//escreve a macro no 2 numero
	temp= temp /10;
	
	sel0;										//desceleciona tudo no display
	PORTD=conver[temp %10];						//converte o numero para a macro correspondente
	sel1;										//escreve a macro no 1 numero
	temp= temp /10;
	
}


int main(void)
{
	/************************************************************************/
	/*  Funçao main (btns / write )                                         */
	/************************************************************************/
	DDRD = setDDRD;														//DDRD como output
	DDRB = setDDRB;														//DDRB como input e output
	
	char estadoBTN_UP = SOLTO;											//inicia o estado do btn_up como solto
	char estadoBTN_DOWN = SOLTO;										//inicia o estado do btn_down como solto
	
	
	while (1)
	{
		if(BTN_UPisPressed){
			estadoBTN_UP = PRESSED;										//altera o estado do btn_up para pressed
		}
		if((BTN_UPisPressed) == SOLTO && estadoBTN_UP == PRESSED){		//BTN_UP (funcionamento)
			if(counter>=MAX){											//se counter >= maximo
				counter = MIN;											//passa para o minimo
			}
			else{counter++;}											//se nao incrementa o counter
			
			estadoBTN_UP=SOLTO;											//altera o estado do btn_up para solto
		}
		if(BTN_DOWNisPressed){
			estadoBTN_DOWN = PRESSED;									//altera o estado do btn_down para pressed
		}
		if((BTN_DOWNisPressed) == SOLTO && estadoBTN_DOWN == PRESSED){	//BTN_DOWN (funcionamento)
			if(counter<=MIN){											//se counter <= minimo
				counter = MAX;											//passa para o maximo
			}
			else{counter--;}											//se nao decrementa o counter
			estadoBTN_DOWN=SOLTO;										//altera o estado do btn_down para solto
		}
		write();														//chama write() para ecrever no display
	}
}

