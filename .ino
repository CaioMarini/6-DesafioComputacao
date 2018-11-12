/*
  *
*/
#include <Ultrasonic.h>
// Biblioteca reponsavel pelo sensor

#define RELE_1 4
#define RELE_2 3
#define BOTAO 6
/*
  * RELE_1 Responsavel pelo Rele ultilizado pelo SENSOR ULTRASONICO
  * RELE_2 Responsavel pelo Rele de que sempre vai se manter aberto
  * para a agua ser controlada manualmente.
  * BOTAO responsavel por pegar os dados da entrada do BOTAO que muda
  * de modo manual para automatico e vise versa.
*/

Ultrasonic ultrassom(8,7);
//Definicao das portas usadas pelo sensor.

long distancia;
/*
  * Variavel responsavel pelo armazenamento da distancia
  * que o sensor esta captando.
*/

 int botao_ON_OFF = 0;
 /*
  * Variavel responsavel por alterar o modo que o sistema esta operando
  * como Automatico(sensor) ou Manual
 */

 void setup() {
   Serial.begin(9600);
   pinMode(BOTAO , INPUT);
   pinMode(RELE_1 , OUTPUT);
   pinMode(RELE_2 , OUTPUT);
 }
/*
  * Definindo o que deve ser feito pelo arquino.
  * RELE_1 modo saida.
  * RELE_2 modo saida.
  * BOTAO modo entrada.
*/
void loop(){
  int status_botao = digitalRead(BOTAO);
  if(status_botao == 1){
    if(botao_ON_OFF == 0){
      botao_ON_OFF = 1;
    } else {
      botao_ON_OFF = 0;
  }
  delay(250);
}
/*
  * A variavel status_botao guarda o valor da porta digital
  * no qual o BOTAO esta associado.
  * A variavel botao_ON_OFF guarda qual o estado que o RELE vai estar (LIGADO/DESLIGADO).
*/

  if(botao_ON_OFF == 1){
    digitalWrite(RELE_1 , LOW);
    digitalWrite(RELE_2 , HIGH);
  } else {
    if(distancia < 25){
      digitalWrite(RELE_1 , HIGH);
      digitalWrite(RELE_2 , LOW);
    } else {
      digitalWrite(RELE_1 , HIGH);
      digitalWrite(RELE_2 , HIGH);
    }
  }
/*
  * No caso da variavel botao_ON_OFF ser igual a 1
  * a torneira vai se manter em modo manual, ou seja o sensor sera inulizido
  * e a torneira passara a ser controlada apenas pelo abrimento e fechamento da mesma.
  * Caso seja igual a 0, a torneira entrara em modo automatico, assim habilitando novamente
  * o sensor.
  * No caso da torneira estar em modo automatico, o sensor ira retornar o valor da distancia
  * por ele recebido, E caso esse valor seja MAIOR que 25 centimetros, a torneira sera desligada
  * e caso a distancia por ele recebido seja MENOR que 25 centimetros a torneira sera ligada.
*/
 delay(100);
/*
  * Foi adicionado um delay de 100 ms para que quando o botao for precionado, ele nao faça o que nao deve
  * assim por causa da funcao LOOP ele ficaria alternando o modo MUITO rapidamente, assim podendo dar algum
  * problema nos equipamentos
*/
}
