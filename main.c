#include <stdio.h>
#define M 100
#define N 100

typedef struct
{
    int jumlahKolom;
    int jumlahBaris;
    int elemen[M][N];
} matriks;

void createMatriks(matriks *m, int ordo);
void appendMatriks(matriks *m);
void showMatriks(matriks m);
int cariNilai(matriks m, int x);
void cariMinMax(matriks m);

int main()
{
    matriks m;
    int ordo;
    int x;

    puts("Code by : EruChi");
    puts("ADT Matriks");
    puts("================");

    do
    {
        printf("Masukkan Ordo Matriks : ");
        scanf(" %d", &ordo);
    } while (ordo < 2 || ordo > 100);
    createMatriks(&m, ordo);
    appendMatriks(&m);
    showMatriks(m);

    printf("Nilai X yang dicari dalam matriks : ");
    scanf(" %d", &x);
    if (cariNilai(m, x))
    {
        puts("Nilai X tedapat pada matriks");
    }
    else
    {
        puts("Nilai X tidak ditemukan dalam matriks");
    }
    puts("");
    cariMinMax(m);
    puts("");
}

void createMatriks(matriks *m, int ordo)
{
    m->jumlahBaris = ordo;
    m->jumlahKolom = ordo;
}

void appendMatriks(matriks *m)
{
    int elemen;

    for (int i = 0; i < m->jumlahBaris; i++)
    {
        for (int j = 0; j < m->jumlahKolom; j++)
        {
            printf("M%d%d = ", i + 1, j + 1);
            scanf("%d", &elemen);
            m->elemen[i][j] = elemen;
        }
    }
    puts("");
}

void showMatriks(matriks m)
{
    for (int i = 0; i < m.jumlahBaris; i++)
    {
        for (int j = 0; j < m.jumlahKolom; j++)
        {
            printf("%d ", m.elemen[i][j]);
        }
        puts("");
    }
    puts("");
}

int cariNilai(matriks m, int x)
{
    for (int i = 0; i < m.jumlahBaris; i++)
    {
        for (int j = 0; j < m.jumlahKolom; j++)
        {
            if (m.elemen[i][j] == x)
                return 1;
        }
    }
    return 0;
}

void cariMinMax(matriks m)
{
    int min = m.elemen[0][0];
    int max = m.elemen[0][0];

    for (int i = 0; i < m.jumlahBaris; i++)
    {
        for (int j = 0; j < m.jumlahKolom; j++)
        {
            if (m.elemen[i][j] < min)
                min = m.elemen[i][j];
            if (m.elemen[i][j] > max)
                max = m.elemen[i][j];
        }
    }
    printf("Nilai Minimum dari Matriks = %d\n", min);
    printf("Nilai Maximal dari Matriks = %d\n", max);
}