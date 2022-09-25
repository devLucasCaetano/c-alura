#pragma once

#define tchute 25 // tamanho máximo dos chutes
#define tpalavra 17

void chute(char chutes[tchute], int *tentativas);
int ja_chutou(char letra, char chutes[tchute], int tentativas);
void forca(char palavra[tpalavra], char chutes[tchute], int tentativas);
int ganhou (char palavra[tpalavra], char chutes[tchute], int *tentativas);
int errou(char palavra[tpalavra], char chutes[tchute], int *tentativas);