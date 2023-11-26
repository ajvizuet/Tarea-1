#include "vendedor.h"
// actualizar parte bodega
#include "bodeguero.h"
#include "fileManager.h"
#include <stdio.h>
#include <string.h>

/*
// implementacion de funcion
void venta(char nombre[20], int cantidad) {
  // struct de bodeguero.h
  struct producto producto;
  //------------
  // iteracion sobre un arreglo de productos de bodeguero.h.
  int size = sizeof(productos) / sizeof(productos[0]);
  for (int i = 0;) {
  }
  if (strcmp(producto.nombre, nombre) == 0) {
    if (cantidad < producto.cantidad) {
      producto.cantidad = producto.cantidad - cantidad;
      printf("Se vendieron %d unidades del producto %s\n", cantidad);
      // llama funcion actualizar bodega
      actualizarProducto(nombre, cantidad);
    }
  }
  printf("No hay cantidad suficiente");
}

void venta&Registros(){

}

// la venta registra el local que vende, el nombre del vendedor, fecha

---------*------------------------------------------------------------------------------------------------------------
cuando vende debe registrar mas que


*/
// lista para registrar las ventas
// deberia registrar las ventas directo en la bodega con los productos

int contVentas = 0;

void registrarVenta();
struct venta ventas[50];

void menuVendedor() {
  int op;
  char name[5];
  printf("1. Registrar Venta\n");
  printf("2. Mostrar ventas\n");
  printf("Opcion a escoger: ");
  scanf("%d", &op);

  switch (op) {
  case 1:
    registrarVenta();
    break;
  case 2:
  	mostrarVentas();
  	break;
  default:
    printf("Opcion invalida\n");
    break;
  }
}
/*
Local,
vendedor,
fecha de venta,
precio de venta y
reducir la cantidad de producto en bodega.
*/

void registrarVenta() {
  char nombreP[50];
  int cantidad;

  struct venta registroEnVentas;
  printf("Ingrese el nombre del vendedor: ");
  scanf("%s", registroEnVentas.n_vendedor);
  printf("Ingrese el nombre del producto: ");
  scanf("%s", nombreP);
  printf("Ingrese la cantidad productos de la venta: ");
  scanf("%d", &cantidad);
  printf("Ingrese la fecha de venta (formato(dia/mes/año): ");
  scanf("%s", registroEnVentas.fecha);
  printf("Ingrese el local que realiza la venta: ");
  scanf("%s", registroEnVentas.local);
  actualizarProdPorVenta(nombreP, cantidad);
  agregarVenta(registroEnVentas);
  actualizarVentas(ventas);
  menuVendedor();
}

void mostrarVentas() {
  for (int i = 0; i < contVentas; i++) {
    imprimirVentas(ventas[i]);
  }
  menuVendedor();
}

void imprimirVentas(struct venta v) {
  printf("Nombre del vendedor: %s\n", v.n_vendedor);
  printf("local: %s\n", v.local);
  printf("fecha de venta: %s\n", v.fecha);
  printf("----------------------\n");
}

void agregarVenta(struct venta v) {
	ventas[contVentas] = v;
	contVentas++;
}

