#ifndef BODEGUERO_H
#define BODEGUERO_H
#include <stdio.h>
#define MAX 50
struct producto {
  // en que bodega está
  char nombre[50];
  int cantidad;
  char categoria[50];
  char marca[50];
  char codigo[50];
  float precioCompra;
  float precioVenta;
  // local como nombre_
};

// ARREGLO CON TODOS LOS PRODUCTOS
struct producto productos[50];
void menuBodeguero();
void crearProducto();

void actualizarRegistrosProducto(char nombreProducto[20]);

void actualizarProdPorVenta(char nombreProducto[20], int cantidad);

#endif

