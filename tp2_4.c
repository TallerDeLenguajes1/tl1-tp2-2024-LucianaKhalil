#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"}; // Tipos de procesador

struct compu {
  float velocidad; // Entre 1 y 3 GHz
  int anio; // Entre 2015 y 2023
  int cantidad; // Entre 1 y 8
  char *tipo_cpu; // Valores del arreglo tipos
};

void mostrar(struct compu *pc) {
  printf("Velocidad: %.1f GHz\n", pc->velocidad);
  printf("Anio: %d\n", pc->anio);
  printf("Cantidad de nucleos: %d\n", pc->cantidad);
  printf("Tipo de procesador: %s\n", pc->tipo_cpu);
  printf("\n");
}

void pcMasVieja(struct compu *pcs) {
  struct compu *mayor = pcs;
  for (int i = 1; i < 5; i++) {
    if ((pcs + i)->anio < mayor->anio) {
      mayor = pcs + i;
    }
  }
  printf("---------PC mas vieja:---------\n");
  mostrar(mayor);
}

void pcMasRapida(struct compu *pcs) {
  struct compu *rapida = pcs;
  for (int i = 1; i < 5; i++) {
    if ((pcs + i)->velocidad > rapida->velocidad) {
      rapida = pcs + i;
    }
  }
  printf("---------PC mas rapida:---------\n");
  mostrar(rapida);
}

int main() {
  srand(time(NULL));

  struct compu pcs[5]; // Para 5 computadoras diferentes
  struct compu *punt = pcs; // Puntero al arreglo de 5 pcs

  /**************Cargar datos**********/
  for (int i = 0; i < 5; i++) {
    punt->velocidad = 1 + rand() % 3;
    punt->anio = 2015 + rand() % (2023 - 2015 + 1);
    punt->cantidad = 1 + rand() % 8;
    punt->tipo_cpu = tipos[rand() % 6]; // Elige aleatoriamente del arreglo tipos procesador
    punt++;
  }

  for (int i = 0; i < 5; i++) {
    printf("********PC %d:**********\n", i + 1);
    mostrar(pcs + i);
  }

  pcMasVieja(pcs);
  pcMasRapida(pcs);

  return 0;
}
