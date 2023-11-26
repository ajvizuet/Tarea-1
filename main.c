#include <stdio.h>
#include<string.h>
#include "usuarios.h"
#include "administrador.h"
#include "bodeguero.h"
#include "vendedor.h"
#include "data.h"

struct user actualUser;

int verificarUsuario(char name[10], char pass[10]);
void inicializarProductos();
void inicializarUsuarios();

int main(void) {
  char name[10], pass[10];
  inicializarUsuarios();
  inicializarProductos();

  printf("Ingrese usuario: ");
  scanf("%s", name);
  printf("Contraseña: ");
  scanf("%s", pass);
  if(verificarUsuario(name, pass) == 1) {
    if(strcmp(actualUser.type, "admin") == 0) {
      menuAdministrador();
    }else if(strcmp(actualUser.type, "vendedor") == 0) {
      menuVendedor();
    }else if(strcmp(actualUser.type, "bodeguero") == 0) {
      menuBodeguero();
    }
  }else {
    printf("Usuario no existente en el sistema\n\n");
    main();
  }
}

int verificarUsuario(char name[10], char pass[10]) {
  for(int i = 0; i < contUsuarios; i++) {
    if(strcmp(usuarios[i].username, name) == 0 && strcmp(usuarios[i].password, pass) == 0) {
      actualUser = usuarios[i];
      return 1;
    }
  }
  return 0;
}

void inicializarProductos() {
    for(int i = 0; i < 50; i++) {
        struct producto prod;

        // Asignar datos a prod (Ejemplo)
        sprintf(prod.nombre, "Producto%d", i + 1);
        prod.cantidad = 100; // Ejemplo de cantidad
        strcpy(prod.categoria, "CategoriaEjemplo");
        strcpy(prod.marca, "MarcaEjemplo");
        sprintf(prod.codigo, "C%d", i + 1);
        prod.precioCompra = i * 10.0; // Precio de compra ejemplo
        prod.precioVenta = prod.precioCompra + 5.0; // Precio de venta ejemplo

        // Guardar producto en el arreglo productos
        productos[i] = prod;
    }
}
/////////////////
  void inicializarUsuarios(){
    struct user usuariosEjemplo[10] = {
        {"admin1", "123", "admin"},
        {"admin2", "456", "admin"},
        {"vendedor1", "123", "vendedor"},
        {"vendedor2", "456", "vendedor"},
        {"bodeguero1", "123", "bodeguero"},
        {"bodeguero2", "456", "bodeguero"},
        {"usuario1", "123", "usuario"},
        {"usuario2", "456", "usuario"},
        {"usuario3", "789", "usuario"},
        {"usuario4", "159", "usuario"},
    };

  for(int i = 0; i < 10; i++) {
        usuarios[contUsuarios++] = usuariosEjemplo[i];
    }
  }
