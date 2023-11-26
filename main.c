#include <stdio.h>
#include<string.h>
#include "usuarios.h"
#include "administrador.h"
#include "bodeguero.h"
#include "vendedor.h"
#include "fileManager.h"
#include "data.h"

struct user actualUser;

int verificarUsuario(char name[10], char pass[10]);
void displayLogIn();

int main(int argc, char *argv[]) {
  if(argc != 4) {
  	fprintf(stderr, "Usage: %s\n", argv[0]);
  	return 1;
  }
  fusers = argv[1];
  fventas = argv[2];
  fproductos = argv[3];

  procesarUsuarios();
  procesarVentas();
  procesarProductos();
  displayLogIn();

}

void displayLogIn() {
  char name[10];
  char pass[10];
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
    displayLogIn();
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






