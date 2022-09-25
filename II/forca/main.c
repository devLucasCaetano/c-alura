#include <stdio.h>
#include <string.h>
#include "forca.h"

// o ponteiro guarda o valor do endereço da memória do parâmetro recebido.

void define_palavra(char palavra[tpalavra])
{
	sprintf(palavra, "abacate");
}

int main()
{
	char palavra[tpalavra];
	char chutes[tchute];

	int tentativas = 0;

	define_palavra(palavra);
	do
	{
		forca(palavra, chutes, tentativas);

		chute(chutes, &tentativas);

	} while (!ganhou(palavra, chutes, &tentativas) && !errou(palavra, chutes, &tentativas));

	return 0;
}