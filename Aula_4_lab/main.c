#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vector.h"


double get_timestamp()
{
    struct timespec now;
    timespec_get(&now, TIME_UTC);
    return now.tv_sec + (((double)now.tv_nsec) / 1e9);
}

/*

double start = get_timestamp(); 

// trecho que queremos medir

double end = get_timestamp(); 

// tempo passado entre os dois pontos do código
double dt = (end - start);

*/

static const int NUM_BUSCAS = 1000;

//Versao com busca linear
// int main() {
//     srand(time(NULL));
    
//     double menor_tempo, maior_tempo, soma_tempos;

    
//     printf("N menor maior media\n");
//     for (int N = 200; N <= 2000; N +=200) {
//         //A cada ciclo sera criado um vetor maior
//         Vector *v = vector_construct();

//         for (int i = 0; i < N /*tamanho do vetor*/; i++) {
//             //preencher
//             int x = rand();
//             vector_push_back(v, x);
//         }

//         //realizar buscas
//         menor_tempo = RAND_MAX;
//         maior_tempo = 0;
//         soma_tempos = 0;
//         for (int M = 0; M < NUM_BUSCAS; M++) {
//             // Gera um índice aleatório
//             int idx = rand() % N;

//             // Seleciona o item daquela posição 
//             int valor = vector_get(v, idx);

//             // Meça o tempo para encontrar o índice do item usando a busca linear 
//             double inicio = get_timestamp();
//             vector_find(v, valor);
//             double fim = get_timestamp();
//             double duracao = fim - inicio; 

//             if (duracao <= menor_tempo) {
//                 menor_tempo = duracao;
//             }

//             if (duracao >= maior_tempo) {
//                 maior_tempo = duracao;
//             }
//             soma_tempos += duracao;
//         }
        
//         double media_tempo = soma_tempos / NUM_BUSCAS;
//         vector_destroy(v);
//         printf("%d %.7lf %.7lf %.7lf\n", N, menor_tempo, maior_tempo, media_tempo);
//     }




//     return 0;
   
// }


int main() {
    srand(time(NULL));
    
    double menor_tempo, maior_tempo, soma_tempos;

    
    printf("N menor maior media\n");
    for (int N = 200; N <= 2000; N +=200) {
        //A cada ciclo sera criado um vetor maior
        Vector *v = vector_construct();

        for (int i = 0; i < N /*tamanho do vetor*/; i++) {
            //preencher
            int x = rand();
            vector_push_back(v, x);
        }

        //realizar buscas
        menor_tempo = RAND_MAX;
        maior_tempo = 0;
        soma_tempos = 0;



            // Meça o tempo para encontrar o índice do item usando a busca linear 
            double inicio = get_timestamp();
            vector_sort(v);
            double fim = get_timestamp();
            double duracao = fim - inicio; 

            if (duracao <= menor_tempo) {
                menor_tempo = duracao;
            }

            if (duracao >= maior_tempo) {
                maior_tempo = duracao;
            }
            soma_tempos += duracao;
        
        
        double media_tempo = soma_tempos / NUM_BUSCAS;
        vector_destroy(v);
        printf("%d %.7lf %.7lf %.7lf\n", N, menor_tempo, maior_tempo, media_tempo);
    }




    return 0;
   
}
