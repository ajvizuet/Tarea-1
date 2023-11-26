#include "bodeguero.h"
#include "fileManager.h"
//#include "usuarios.h"
#include <stdio.h>
#include <string.h>

struct producto productos[50];
void imprimirProductos(struct producto prod);
void mostrarProductos();
int contProductos = 0;
/*-------------------------------------------------------------------------*/
void menuBodeguero() {
  int op;
  char nombre[20];
  /*
  int cantidad;
  char categoria[50];
  char marca[50];
  char codigo[50];
  float precioCompra;
  float precioVenta;
  */
  printf("1. Crear Productos\n");
  printf("2. Actualizar Productos\n");
  printf("3. Listar Productos\n");
  printf("Opcion a escoger: ");
  scanf("%d", &op);

  /*dijo que no pongamos las validaciones*/
  switch (op) {
  case 1:
    crearProducto();
    break;
  case 2:
    printf("Ingrese el producto para actualizar: ");
    scanf("%s", nombre);
    /*
    printf("Ingrese los siguientes nuevos datos");
    printf("cantidad: ");
    scanf("%d", cantidad);
    printf("categoria; ");
    scanf("%s", categoria);
    printf("Marca: ");
    scanf("%s", marca);
    printf("Código");
    scanf("%s", codigo);
    printf("Precio de compra");
    scanf("%f", precioCompra);
    printf("Precio de venta");
    scanf("%f", precioVenta);
    */
    actualizarRegistrosProducto(nombre);
    break;
  case 3:
  	mostrarProductos();
  default:
    printf("Opcion invalida\n");
    break;
  }
}

void crearProducto() {
  struct producto nuevoProducto;
  printf("Ingrese el nombre del producto: ");
  scanf("%s", nuevoProducto.nombre);
  printf("Ingrese la cantidad del producto: ");
  scanf("%d", &nuevoProducto.cantidad);
  printf("Ingrese la categoria del producto: ");
  scanf("%s", nuevoProducto.categoria);
  printf("Ingrese la marca del producto: ");
  scanf("%s", nuevoProducto.marca);
  printf("Ingrese la codigo del producto: ");
  scanf("%s", nuevoProducto.codigo);
  printf("Ingrese el precio de compra del producto: ");
  scanf("%f", &nuevoProducto.precioCompra);
  printf("Ingrese el precio de venta del producto: ");
  scanf("%f", &nuevoProducto.precioVenta);
  agregarProducto(nuevoProducto);
  actualizarProductos(productos);
  menuBodeguero();
}

void actualizarRegistrosProducto(char name[20]) {
  int op;
  int index;

  // struct producto productUP;
  for (int i = 0; i < contProductos; i++) {
    if (strcmp(productos[i].nombre, name) == 0) {
      index = i;
      //  productos[i] =productUP;
    }
  }

  printf("1. Cambiar nombre\n");
  printf("2. Cambiar cantidad en stock\n");
  printf("3. Cambiar catergoria\n");
  printf("4. Cambiar marca\n");
  printf("5. Cambiar codigo\n");
  printf("4. Cambiar precio de compra\n");
  printf("5. Cambiar precio de venta\n");
  printf("Opcion a escoger: ");
  scanf("%d", &op);
  switch (op) {
  case 1:
    printf("Ingrese el nuevo nombre: ");
    scanf("%s", productos[index].nombre); // productUP.nombre
    break;
  case 2:
    printf("Ingrese la nueva cantidad(entero): ");
    scanf("%d", &productos[index].cantidad);
    break;
  case 3:
    printf("Ingrese la nueva categoria: ");
    scanf("%s", productos[index].categoria);
    break;
  case 4:
    printf("Ingrese la nueva marca: ");
    scanf("%s", productos[index].marca);
    break;
  case 5:
    printf("Ingrese la nueva codigo: ");
    scanf("%s", productos[index].codigo);
    break;
  case 6:
    printf("Ingrese el nuevo precio de compra (formato 0.0): ");
    scanf("%f", &productos[index].precioCompra);
    break;
  case 7:
    printf("Ingrese el nuevo precio de venta(formato 0.0); ");
    scanf("%f", &productos[index].precioVenta);
    break;
  default:
    printf("Opcion invalida\n");
    break;
  }
  actualizarProductos(productos);
  menuBodeguero();
}
void mostrarProductos() {
  for (int i = 0; i < contProductos; i++) {
    imprimirProductos(productos[i]);
  }
  menuBodeguero();
}

void imprimirProductos(struct producto prod) {
  printf("Nombre: %s\n", prod.nombre);
  printf("Cantidad: %d\n", prod.cantidad);
  printf("Categoria: %s\n", prod.categoria);
  printf("Marca: %s\n", prod.marca);
  printf("Código: %s\n", prod.codigo);
  printf("Precio de compra: %.2f\n", prod.precioCompra);
  printf("Precio de venta: %.2f\n", prod.precioVenta);
  printf("----------------------\n");
}

void actualizarProdPorVenta(char nombreProducto[20], int cantidad) {
  int userIndex;
  for (int i = 0; i < contProductos; i++) {
    if (strcmp(productos[i].nombre, nombreProducto) == 0) {
      // userIndex = i;
      if (cantidad < productos[i].cantidad) {
        productos[i].cantidad = productos[i].cantidad - cantidad;
        printf("Se vendieron %d unidades del producto \n", cantidad);
//        printf("Se vendieron %d unidades del producto %s\n", cantidad);
        
      } else {
        printf("No hay cantidad suficiente");
      }
    }
  }
}

void agregarProducto(struct producto p) {
    productos[contProductos] = p;
  	contProductos++;
}

