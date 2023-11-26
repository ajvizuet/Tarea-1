

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "usuarios.h"
#include "vendedor.h"
#include "bodeguero.h"
extern const char *fusers;
extern const char *fventas;
extern const char *fproductos;


void procesarUsuarios();
void procesarVentas();
void procesarProductos();

void actualizarUsuarios(struct user *usuarios);
void actualizarVentas(struct venta *ventas);
void actualizarProductos(struct producto *productos);
#endif
