#include <stdio.h>
#include <string.h>

typedef struct arv arvore;
struct arv {
	int ordenar;
	char alfa;
	int bin;
	struct arv* pai;
	struct arv* esq;
	struct arv* dir;
};

arvore *inicializarArvore(arvore *r);
void emordem (arvore *r);
int retornaAltura (arvore *r);
void traduzirQualquer(arvore *r);
void traduzirPredefinidos(arvore *r);
arvore *insere(arvore *a, arvore *no);

int main(int argc, char const *argv[])
{
	arvore a, *alfaToBin;
	int menu;
	alfaToBin = &a;
	alfaToBin->ordenar = 17; alfaToBin->alfa = 'H'; alfaToBin->bin = 10001;
	alfaToBin->esq = NULL;
	alfaToBin->dir = NULL;
	alfaToBin = inicializarArvore(alfaToBin);
	while (true) {
		scanf("%d", &menu);
		switch (menu) {
		case 1: emordem(alfaToBin);
		case 2: traduzirPredefinidos(alfaToBin);
		case 3: traduzirQualquer(alfaToBin);
		case 4: break;
		}
	}
	return 0;
}

void emordem(arvore *r) {
	if (r != NULL) {
		emordem(r->esq);
		printf("Caractere Alfanumérico:%c Caractere Binário:%d  \n" , r->alfa, r->bin);
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

}

void traduzirQualquer (arvore *r) {

}

arvore *busca(**alfaToBin, char c, int i, char modo) {
	if (pRaiz != NULL) {
		if (modo == 'c') {
			if (c == (*alfaToBin)->alfa) {
				return alfaToBin;
			}
		} else {
			if (i == (*alfaToBin)->bin) {
				return alfaToBin;
			}
		}
	} else  if (ordenar < (*alfaToBin)->ordenar) {
		if ((*alfaToBin)->esq != NULL) {
			return busca(&(*alfaToBin)->esq, ordenar);
		}
	} else {
		if ((*alfaToBin)->dir != NULL) {
			return busca(&(*alfaToBin)->dir, ordenar);
		}
	}
	return NULL;
}

arvore *insere(arvore *a, arvore *no) {
	if (a == NULL) a = no;
	else if (a->ordenar >= no->ordenar) {
		if (a->esq == NULL) {
			a->esq = no;
			no->pai = a;
		}
		else
			insere(a->esq, no);
	}
	else {
		if (a->dir == NULL) {
			a->dir = no;
			no->pai = a;
		}
		else
			insere(a->dir, no);
	}
	return a;
}


arvore *inicializarArvore(arvore *r) {
	arvore no;
	noesq = NULL;
	no->dir = NULL;
	no->ordenar = 0; no->alfa = '0'; no->bin = 000000; r = insere(r, no);
	no->ordenar = 1; no->alfa = '1'; no->bin = 000001; r = insere(r, no);
	no->ordenar = 2; no->alfa = '2'; no->bin = 000010; r = insere(r, no);
	no->ordenar = 3; no->alfa = '3'; no->bin = 000011; r = insere(r, no);
	no->ordenar = 4; no->alfa = '4'; no->bin = 000100; r = insere(r, no);
	no->ordenar = 5; no->alfa = '5'; no->bin = 000101; r = insere(r, no);
	no->ordenar = 6; no->alfa = '6'; no->bin = 000110; r = insere(r, no);
	no->ordenar = 7; no->alfa = '7'; no->bin = 000111; r = insere(r, no);
	no->ordenar = 8; no->alfa = '8'; no->bin = 001000; r = insere(r, no);
	no->ordenar = 9; no->alfa = '9'; no->bin = 001001; r = insere(r, no);
	no->ordenar = 10; no->alfa = 'A'; no->bin = 001010; r = insere(r, no);
	no->ordenar = 11; no->alfa = 'B'; no->bin = 001011; r = insere(r, no);
	no->ordenar = 12; no->alfa = 'C'; no->bin = 001100; r = insere(r, no);
	no->ordenar = 13; no->alfa = 'D'; no->bin = 001101; r = insere(r, no);
	no->ordenar = 14; no->alfa = 'E'; no->bin = 001110; r = insere(r, no);
	no->ordenar = 15; no->alfa = 'F'; no->bin = 001111; r = insere(r, no);
	no->ordenar = 16; no->alfa = 'G'; no->bin = 010000; r = insere(r, no);
	no->ordenar = 18; no->alfa = 'I'; no->bin = 010010; r = insere(r, no);
	no->ordenar = 19; no->alfa = 'J'; no->bin = 010011; r = insere(r, no);
	no->ordenar = 20; no->alfa = 'K'; no->bin = 010100; r = insere(r, no);
	no->ordenar = 21; no->alfa = 'L'; no->bin = 010101; r = insere(r, no);
	no->ordenar = 22; no->alfa = 'M'; no->bin = 010110; r = insere(r, no);
	no->ordenar = 23; no->alfa = 'N'; no->bin = 010111; r = insere(r, no);
	no->ordenar = 24; no->alfa = 'O'; no->bin = 011000; r = insere(r, no);
	no->ordenar = 25; no->alfa = 'P'; no->bin = 011001; r = insere(r, no);
	no->ordenar = 26; no->alfa = 'Q'; no->bin = 011010; r = insere(r, no);
	no->ordenar = 27; no->alfa = 'R'; no->bin = 011011; r = insere(r, no);
	no->ordenar = 28; no->alfa = 'S'; no->bin = 011100; r = insere(r, no);
	no->ordenar = 29; no->alfa = 'T'; no->bin = 011101; r = insere(r, no);
	no->ordenar = 30; no->alfa = 'U'; no->bin = 011110; r = insere(r, no);
	no->ordenar = 31; no->alfa = 'W'; no->bin = 011111; r = insere(r, no);
	no->ordenar = 32; no->alfa = 'X'; no->bin = 100000; r = insere(r, no);
	no->ordenar = 33; no->alfa = 'X'; no->bin = 100001; r = insere(r, no);
	no->ordenar = 34; no->alfa = 'Y'; no->bin = 100010; r = insere(r, no);
	no->ordenar = 35; no->alfa = 'Z'; no->bin = 100011; r = insere(r, no);
	return r;
}
