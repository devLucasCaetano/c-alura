#include <stdio.h>
#include <string.h>
#include "forca.h"

void chute(char chutes[tchute], int *tentativas) 
{
	char chute;
	printf("\nQual letra? ");
	scanf(" %c", &chute);

	chutes[(*tentativas)] = chute;
	(*tentativas)++; // (*tentativas) = (*tentativas) + 1;
}

int ja_chutou(char letra, char chutes[tchute], int tentativas)
{

	int achou = 0;

	for (int i = 0; i < tentativas; i++)
	{
		if (chutes[i] == letra)
		{
			achou = 1;
			return achou;
			break;
		}
	}

	return achou;
}

void forca(char palavra[tpalavra], char chutes[tchute], int tentativas)
{
	for (int i = 0; i < strlen(palavra); i++)
	{
		int encontrado = ja_chutou(palavra[i], chutes, tentativas);

		if (encontrado)
		{
			printf("%c ", palavra[i]);
		}
		else
		{
			printf("_ ");
		}
	}
	printf("\n");
}

int ganhou (char palavra[tpalavra], char chutes[tchute], int *tentativas)
{
    for (int i = 0; i < strlen(palavra); i++)
    {
        if (!ja_chutou(palavra[i], chutes, *tentativas))
        {
            return 0;
        }
    }
    return 1;
}

int errou(char palavra[tpalavra], char chutes[tchute], int *tentativas)
{
	int erros = 0;

	for (int i = 0; i < *tentativas; i++)
	{
		int existe = 0;	

		for (int j = 0; j < strlen(palavra); j++)
		{
			if (chutes[i] == palavra[j])
			{
				existe = 1;
				break;
			}
		}

		if (!existe)
		{
			erros++;
		}
	}

	return erros >= (tchute - tpalavra) ;
}
