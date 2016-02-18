#include <stdio.h>
#include <string.h>

typedef struct arv arvore;
struct arv {
	int ordenar;
	char alfa;
	char bin[7];
	struct arv* pai;
	struct arv* esq;
	struct arv* dir;
};

//arvore *inicializarArvore(arvore *r);
void emordem (arvore *r);
int retornaAltura (arvore *r);
void traduzirQualquer(arvore *r);
void traduzirPredefinidos(arvore *r);
arvore *insere(arvore *a, int ordenar, char alfa, char bin[7]);

int main(int argc, char const *argv[])
{
	arvore *alfaToBin, a;
	int menu, lock = 1;
	alfaToBin = &a;
	alfaToBin->ordenar = 17; alfaToBin->alfa = 'H'; alfaToBin->bin[5] = '0';alfaToBin->bin[4] = '1';alfaToBin->bin[3] = '0';alfaToBin->bin[2] = '0';alfaToBin->bin[1] = '0';alfaToBin->bin[0] = '1';
	alfaToBin->esq = NULL;
	alfaToBin->dir = NULL;
	printf("%d  %c %s\n",alfaToBin->ordenar,alfaToBin->alfa,alfaToBin->bin);
	//alfaToBin = insere(alfaToBin,alfaToBin->ordenar,alfaToBin->alfa,alfaToBin->bin);
	//	alfaToBin=inicializarArvore(alfaToBin);
	while (lock ==1) {
		printf("Criar Menu : ");
		scanf("%d", &menu);
		switch (menu) {
		case 1: printf ("Indo pro em ordem \n"); emordem(alfaToBin); break;
		case 2: traduzirPredefinidos(alfaToBin); break;
		case 3: traduzirQualquer(alfaToBin); break;
		case 4: break;
		}
	}
	return 0;
}

void emordem(arvore *r) {
	if (r != NULL) {
		emordem(r->esq);
		printf("Ordenar:%d Caractere Alfanumérico:%c Caractere Binário:%s  \n",r->ordenar, r->alfa, r->bin);
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

arvore *buscaAlfa (arvore *r, char d){
	if (r == NULL) return NULL;
	else if (r->alfa > d) return buscaAlfa(r->dir, d);
	else if (r->alfa < d) return buscaAlfa(r->esq, d);
	else return r;

}

// arvore *buscaBin (arvore *r, char d){
// 	if (r == NULL) return NULL;
// 	else if (r->bin > d) return buscaAlfa(r->dir, d);
// 	else if (r->bin < d) return buscaBin(r->esq, d);
// 	else return r;

// }

arvore *insere(arvore *a, int ordenar, char alfa, char bin[7]) {
	arvore *no, b;
	no = &b;
	no->ordenar = ordenar; no->alfa = alfa; strcpy(no->bin,bin);
	if (a == NULL) a = no;
	else if (a->ordenar >= no->ordenar) {
		if (a->esq == NULL) {
			a->esq = no;
			no->pai = a;
		}
		else
			insere(a->esq, ordenar, alfa, bin);
	}
	else {
		if (a->dir == NULL) {
			a->dir = no;
			no->pai = a;
		}
		else
			insere(a->dir, ordenar, alfa, bin);
	}
	return a;
}


// arvore *inicializarArvore(arvore *r) {
// 	arvore *no, n;
// 	no = &n;
// 	no->esq = NULL;
// 	no->dir = NULL;
// 	no->bin[6]= '\0';
// 	no->ordenar = 0; no->alfa = '0'; no->bin[5] = '0';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]=  '0'; insere(r, no);
// 	printf("INICIALIZANDO Ordenar:%d Caractere Alfanumérico:%c Caractere Binário:%s  \n",no->ordenar, no->alfa, no->bin);
// 	no->ordenar = 1; no->alfa = '1'; no->bin[5] = '0';no->bin[4]= '0';no->bin[3] = '0';no->bin[2]='0';no->bin[1]= '0';no->bin[0]=  '0'; insere(r, no);
// 	printf("INICIALIZANDO Ordenar:%d Caractere Alfanumérico:%c Caractere Binário:%s  \n",no->ordenar, no->alfa, no->bin);
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
	//return r;
//}
