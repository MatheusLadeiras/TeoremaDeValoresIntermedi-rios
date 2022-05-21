#include <stdio.h>
#include <locale.h>
#include <math.h>

// Exemplo usado para testes:
// y = 1x³-2x²-11x+12, f(a) = 10 e f(b) = -5
// Exemplo baseado em https://keisan.casio.com/exec/system/1181809414
// https://www.onlinegdb.com/online_c_compiler

int nOperacao = 1;
int nRaizes = 1;

int calcularFuncao(int a,char op1,int b,char op2,int c,char op3,int d,int x) {
	int resultado = a * pow(x, 3);

	switch(op1) { 
			case '+': resultado = resultado + (b * pow(x, 2)); 
			break;
			case '-': resultado = resultado - (b * pow(x, 2)); 
			break;
	} 
	switch(op2) { 
			case '+': resultado = resultado + (c*x); 
			break;
			case '-': resultado = resultado - (c*x); 
			break;
	} 
	switch(op3) { 
			case '+': resultado = resultado + d; 
			break;
			case '-': resultado = resultado - d; 
			break;
	}
	if(resultado == 0) {
		printf("%i) f(%i)\n", nRaizes, x);
		nRaizes++;
	}
	return 0;
} 

char validarSinais() {
	int i = 0;
	char operacao;
	do {
		printf("Escolha o valor da %i° operação (adição e subtração apenas): ", nOperacao); 
		scanf(" %c", &operacao);
		switch(operacao) { 
			case '+': i++; 
			break;
			case '-': i++; 
			break;
			default: printf("Esse valor é inválido, por favor, se abster a + ou -.\n\n");
			break;
		}
	} while (i < 1);
		
	nOperacao++;
	return operacao;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int a, b, c, d, fA, fB, f0, fvar;
    char op1, op2, op3;
    
    printf("Para começar é necessário montar a equação de 3º grau, lembre-se que ela deve ser contínua!\n");
	printf("Digite o valor de a: ");
	scanf("%i", &a);
	op1 = validarSinais();
	printf("Digite o valor de b: ");
	scanf("%i", &b); 
	op2 = validarSinais(); 
	printf("Digite o valor de c: ");
	scanf("%i", &c);
	op3 = validarSinais();
	printf("Digite o valor de d: ");
	scanf("%i", &d); 
	printf("O formato da equação terminou sendo y = %ix³%c%ix²%c%ix%c%i\n\n", a, op1, b, op2, c, op3, d);
	
	do {
		printf("Agora escolha o valor de f(a), lembre-se, ele deve ser maior que 0 pelo teorema do valor intermediário: ");
		scanf("%i", &fA);
		if (fA <= 0) {  
			printf("O valor selecionado é inválido, ele deve ser maior que 0! \n");
		}
	} while (fA <= 0);

	do {
		printf("Por ultimo escolha o valor de f(b), lembre-se, ele deve ser menor que 0 pelo teorema do valor intermediário: ");
		scanf("%i", &fB);
		if (fB >= 0) {  
			printf("O valor selecionado é inválido, ele deve ser menor que 0! \n");
		}
	} while (fB >= 0);
	
	printf("Sendo F(a) e f(b) reespectivamente %i e %i, as seguintes raízes podem ser achadas no intervalo: \n", fA, fB); 
	for(int i = fB+1; i < fA; i++) {
		calcularFuncao(a, op1, b, op2, c, op3, d, i);
	}

    return 0;
}

