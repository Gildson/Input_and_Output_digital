#include <avr/io.h>

int main(){
  
  //Torna os registradores PWM2, PWM3, PWM4 de saída
  DDRD |= 0b00011100;
  //Torna os registrados A0, A1, A2 de entrada
  //limpa os bits das portas de entrada específica, devido a operação AND
  DDRC &= 0b11111000;
  //PORTC |= (1<<0); (desloca o bit 1 para a porta A0)
  PORTC |= 0b00000001;
  PORTC |= 0b00000010;
  PORTC |= 0b00000100;
  while(1){
    //Para o led verde
    //PIN pega o valor de cada bit específico.
    if ((PINC & 0b00000001) == 0b00000000){
		PORTD = PORTD | 0b00000100;
		}else{
			PORTD = PORTD & 0b11111011;
		}
    //Para o led azul
    if ((PINC & 0b00000010) == 0b00000000){
		PORTD = PORTD | 0b00001000;
		}else{
			PORTD = PORTD & 0b11110111;
		}
	//Para o led vermelho
    if ((PINC & 0b00000100) == 0b00000000){
		PORTD = PORTD | 0b00010000;
		}else{
			PORTD = PORTD & 0b11101111;
		}
	}
}