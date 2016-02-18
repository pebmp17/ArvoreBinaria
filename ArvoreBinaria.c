#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct informacoes {
	int ordenar;
	char alfa;
	int bin;
};

struct arv {
	struct informacoes info;
	struct arv* esq;
	struct arv* dir;
};

typedef struct informacoes Info;
typedef struct arv arvore;


void emordem (arvore *r);
int retornaAltura (arvore *r);
void traduzirQualquer(arvore *r, int modo);
void traduzirPredefinidos(arvore *r);
int insere (arvore **raiz, Info i);
arvore *buscaAlfa (arvore *r, char d);
void inicializarArvore(arvore** r);

int main(int argc, char const *argv[])
{
	arvore *alfaToBin;
	alfaToBin = NULL;
	Info i = {17, 'H', 010101};
	int menu, lock = 1;
	insere(&alfaToBin, i);
	inicializarArvore(&alfaToBin);
	printf("Arvore inicializado \n");
	while (lock == 1) {
		printf("Falta criar o Menu : ");
		//printf("Ordenar: %d  Alfa: %c Bin :%s\n", alfaToBin->info.ordenar, alfaToBin->info.alfa, alfaToBin->info.bin);
		scanf("%d", &menu);
		switch (menu) {
		case 1: emordem(alfaToBin); break;
		case 2: traduzirPredefinidos(alfaToBin); break;
		case 3: traduzirQualquer(alfaToBin,0); break;
		case 4: break;
		}
	}
	return 0;
}

void emordem(arvore *r) {
	if (r != NULL) {
		emordem(r->esq);
		printf("Caractere Alfanumérico:%c Caractere Binário:%d  \n", r->info.alfa, r->info.bin);
		emordem(r->dir);
	}
}

int retornaAltura(arvore* r) {
	int hesq, hdir;
	if (r == NULL) return -1;
	else {
		hesq = retornaAltura(r->esq);
		hdir = retornaAltura(r->dir);
		if (hesq >= hdir) return hesq + 1;
		else return hdir + 1;
	}
}

void traduzirPredefinidos(arvore *r) {
	char* string, traducao[100], temp[20];
	string = "Bsfixpfl";
	printf("Traduzindo %s para binário: \n",string);
	for (int i = 0; i < strlen(string); ++i)
	{
		sprintf(temp, "%d", (buscaAlfa(r, string[i])->info).bin);
		strcat(traducao,temp);strcat(traducao," ");
	}
	printf("%s\n", traducao);
}

void traduzirQualquer (arvore *r, int modo) {
	if (modo == 0) {

	}
	else if (modo == 1) {

	}
	else if (modo == 2) {

	}
	else if (modo == 3) {

	}
}

arvore *buscaAlfa (arvore *r, char d) {
	if (r == NULL) return NULL;
	else if (r->info.alfa > d) return buscaAlfa(r->dir, d);
	else if (r->info.alfa < d) return buscaAlfa(r->esq, d);
	else return r;

}

arvore *buscaBin (arvore *r, int d) {
	if (r == NULL) return NULL;
	else if (r->info.bin < d) return buscaAlfa(r->dir, d);
	else if (r->info.bin > d) return buscaBin(r->esq, d);
	else return r;

}

int insere (arvore **raiz, Info i) {
	arvore *temp = NULL;
	if (*raiz == NULL) {
		temp = (arvore *) malloc(sizeof(arvore));
		temp->info = i; temp->esq = NULL; temp->dir = NULL;
		*raiz = temp;
		return 1;
	}
	else if (i.ordenar == (*raiz)->info.ordenar) return 0;
	else if (i.ordenar < (*raiz)->info.ordenar) return insere(&(*raiz)->esq, i);
	else if (i.ordenar > (*raiz)->info.ordenar) return insere(&(*raiz)->dir, i);
	else return 0;
}

void inicializarArvore(arvore *r) {
 Info i;
// arvore *no, n;
// no = &n;
// no->esq = NULL;
// no->dir = NULL;
// no->bin[6]= '\0';
// no->ordenar = 0; no->alfa = '0'; no->bin[5] = '0';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]=  '0'; insere(r, no);
// printf("INICIALIZANDO Ordenar:%d Caractere Alfanumérico:%c Caractere Binário:%s  \n",no->ordenar, no->alfa, no->bin);
// no->ordenar = 1; no->alfa = '1'; no->bin[5] = '0';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]=  '0'; insere(r, no);
// printf("INICIALIZANDO Ordenar:%d Caractere Alfanumérico:%c Caractere Binário:%s  \n",no->ordenar, no->alfa, no->bin);
// no->ordenar = 0; no->alfa = '2'; no->bin[5] = '0';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]=  '0'; insere(r, no);
// printf("INICIALIZANDO Ordenar:%d Caractere Alfanumérico:%c Caractere Binário:%s  \n",no->ordenar, no->alfa, no->bin);
// no->ordenar = 3; no->alfa = '3'; no->bin[5] = '0';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]= '0'; insere(r, no);
// printf("INICIALIZANDO Ordenar:%d Caractere Alfanumérico:%c Caractere Binário:%s  \n",no->ordenar, no->alfa, no->bin);
// no->ordenar = 4; no->alfa = '4'; no->bin[5] = '0';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]= '0';  insere(r, no);
// printf("INICIALIZANDO Ordenar:%d Caractere Alfanumérico:%c Caractere Binário:%s  \n",no->ordenar, no->alfa, no->bin);
// no->ordenar = 5; no->alfa = '5'; no->bin[5] = '0';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]= '0'; insere(r, no);
// printf("INICIALIZANDO Ordenar:%d Caractere Alfanumérico:%c Caractere Binário:%s  \n",no->ordenar, no->alfa, no->bin);
// no->ordenar = 6; no->alfa = '6'; no->bin[5] = '0';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]= '0'; insere(r, no);
// printf("INICIALIZANDO Ordenar:%d Caractere Alfanumérico:%c Caractere Binário:%s  \n",no->ordenar, no->alfa, no->bin);
// no->ordenar = 7; no->alfa = '7'; no->bin[5] = '0';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]= '0'; insere(r, no);
// printf("INICIALIZANDO Ordenar:%d Caractere Alfanumérico:%c Caractere Binário:%s  \n",no->ordenar, no->alfa, no->bin);
// no->ordenar = 8; no->alfa = '8'; no->bin[5] = '0';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]= '0'; insere(r, no);
// printf("INICIALIZANDO Ordenar:%d Caractere Alfanumérico:%c Caractere Binário:%s  \n",no->ordenar, no->alfa, no->bin);
// no->ordenar = 9; no->alfa = '9'; no->bin[5] = '0';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]= '0'; insere(r, no);
// printf("INICIALIZANDO Ordenar:%d Caractere Alfanumérico:%c Caractere Binário:%s  \n",no->ordenar, no->alfa, no->bin);
// no->ordenar = 10; no->alfa = 'A'; no->bin[5] = '0';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]= '0'; insere(r, no);
// no->ordenar = 11; no->alfa = 'B'; no->bin[5] = '0';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]= '0'; insere(r, no);
// no->ordenar = 12; no->alfa = 'C'; no->bin[5] = '0';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]= '0'; insere(r, no);
// no->ordenar = 13; no->alfa = 'D'; no->bin[5] = '0';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]= '0'; insere(r, no);
// no->ordenar = 14; no->alfa = 'E'; no->bin[5] = '0';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]= '0'; insere(r, no);
// no->ordenar = 15; no->alfa = 'F'; no->bin[5] = '0';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]= '0'; insere(r, no);
// no->ordenar = 16; no->alfa = 'G'; no->bin[5] = '0';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]= '0'; insere(r, no);
// no->ordenar = 18; no->alfa = 'I'; no->bin[5] = '0';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]= '0'; insere(r, no);
// no->ordenar = 19; no->alfa = 'J'; no->bin[5] = '0';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]= '0'; insere(r, no);
// no->ordenar = 20; no->alfa = 'K'; no->bin[5] = '0';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]= '0'; insere(r, no);
// no->ordenar = 21; no->alfa = 'L'; no->bin[5] = '0';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]= '0'; insere(r, no);
// no->ordenar = 22; no->alfa = 'M'; no->bin[5] = '0';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]= '0'; insere(r, no);
// no->ordenar = 23; no->alfa = 'N'; no->bin[5] = '0';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]= '0'; insere(r, no);
// no->ordenar = 24; no->alfa = 'O'; no->bin[5] = '0';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]= '0'; insere(r, no);
// no->ordenar = 25; no->alfa = 'P'; no->bin[5] = '0';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]= '0'; insere(r, no);
// no->ordenar = 26; no->alfa = 'Q'; no->bin[5] = '0';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]= '0'; insere(r, no);
// no->ordenar = 27; no->alfa = 'R'; no->bin[5] = '0';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]= '0'; insere(r, no);
// no->ordenar = 28; no->alfa = 'S'; no->bin[5] = '0';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]= '0'; insere(r, no);
// no->ordenar = 29; no->alfa = 'T'; no->bin[5] = '0';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]= '0'; insere(r, no);
// no->ordenar = 30; no->alfa = 'U'; no->bin[5] = '0';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]= '0'; insere(r, no);
// no->ordenar = 31; no->alfa = 'W'; no->bin[5] = '0';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]= '0'; insere(r, no);
// no->ordenar = 32; no->alfa = 'X'; no->bin[5] = '1';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]= '0'; insere(r, no);
// no->ordenar = 33; no->alfa = 'X'; no->bin[5] = '1';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]= '0'; insere(r, no);
// no->ordenar = 34; no->alfa = 'Y'; no->bin[5] = '1';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]= '0'; insere(r, no);
// no->ordenar = 35; no->alfa = 'Z'; no->bin[5] = '1';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]= '0'; insere(r, no);
	
	i.ordenar = 0; i.alfa = '0'; i.bin = 000000; insere(&r, i);
	i.ordenar = 1; i.alfa = '1'; i.bin = 000001; insere(&r, i);
	i.ordenar = 2; i.alfa = '2'; i.bin = 000010; insere(&r, i);
	i.ordenar = 3; i.alfa = '3'; i.bin = 000011; insere(&r, i);
	i.ordenar = 4; i.alfa = '4'; i.bin = 000100; insere(&r, i);
	i.ordenar = 5; i.alfa = '5'; i.bin = 000101; insere(&r, i);
	i.ordenar = 6; i.alfa = '6'; i.bin = 000110; insere(&r, i);
	i.ordenar = 7; i.alfa = '7'; i.bin = 000111; insere(&r, i);
	i.ordenar = 8; i.alfa = '8'; i.bin = 001000; insere(&r, i);
	i.ordenar = 9; i.alfa = '9'; i.bin = 001001; insere(&r, i);
	i.ordenar = 10; i.alfa = 'A'; i.bin = 001010; insere(&r, i);
	i.ordenar = 11; i.alfa = 'B'; i.bin = 001011; insere(&r, i);
	i.ordenar = 12; i.alfa = 'C'; i.bin = 001100; insere(&r, i);
	i.ordenar = 13; i.alfa = 'D'; i.bin = 001101; insere(&r, i);
	i.ordenar = 14; i.alfa = 'E'; i.bin = 001110; insere(&r, i);
	i.ordenar = 15; i.alfa = 'F'; i.bin = 001111; insere(&r, i);
	i.ordenar = 16; i.alfa = 'G'; i.bin = 010000; insere(&r, i);
	i.ordenar = 18; i.alfa = 'I'; i.bin = 010010; insere(&r, i);
	i.ordenar = 19; i.alfa = 'J'; i.bin = 010011; insere(&r, i);
	i.ordenar = 20; i.alfa = 'K'; i.bin = 010100; insere(&r, i);
	i.ordenar = 21; i.alfa = 'L'; i.bin = 010101; insere(&r, i);
	i.ordenar = 22; i.alfa = 'M'; i.bin = 010110; insere(&r, i);
	i.ordenar = 23; i.alfa = 'N'; i.bin = 010111; insere(&r, i);
	i.ordenar = 24; i.alfa = 'O'; i.bin = 011000; insere(&r, i);
	i.ordenar = 25; i.alfa = 'P'; i.bin = 011001; insere(&r, i);
	i.ordenar = 26; i.alfa = 'Q'; i.bin = 011010; insere(&r, i);
	i.ordenar = 27; i.alfa = 'R'; i.bin = 011011; insere(&r, i);
	i.ordenar = 28; i.alfa = 'S'; i.bin = 011100; insere(&r, i);
	i.ordenar = 29; i.alfa = 'T'; i.bin = 011101; insere(&r, i);
	i.ordenar = 30; i.alfa = 'U'; i.bin = 011110; insere(&r, i);
	i.ordenar = 31; i.alfa = 'W'; i.bin = 011111; insere(&r, i);
	i.ordenar = 32; i.alfa = 'X'; i.bin = 100000; insere(&r, i);
	i.ordenar = 33; i.alfa = 'X'; i.bin = 100001; insere(&r, i);
	i.ordenar = 34; i.alfa = 'Y'; i.bin = 100010; insere(&r, i);
	i.ordenar = 35; i.alfa = 'Z'; i.bin = 100011; insere(&r, i);
}
