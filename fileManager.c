#include<stdio.h>
#include <string.h>

#include "fileManager.h"
#include "usuarios.h"
#include "administrador.h"
#include "data.h"
#include "bodeguero.h"
#include "vendedor.h"

const char *fusers;
const char *fventas;
const char *fproductos;


void procesarUsuarios() {
	FILE *file = fopen(fusers, "r");
	if(file == NULL) {
		printf("Error abriendo archivo\n");
		return;
	}
	struct user u;
	while(fscanf(file, " %14[^,],%9[^,],%9[^\n]", u.type, u.username, u.password) == 3){
		agregarUsuario(u);
	}
	fclose(file);
}

void procesarVentas() {
	FILE *file = fopen(fventas, "r");
	if(file == NULL) {
		printf("Error abriendo archivo\n");
		return;
	}
	struct venta v;
	while(fscanf(file, " %19[^,],%19[^,],%19[^\n]", v.n_vendedor, v.fecha, v.local) == 3){
		agregarVenta(v);
	}
	fclose(file);
}

void procesarProductos() {
	FILE *file = fopen(fproductos, "r");
	if(file == NULL) {
		printf("Error abriendo archivo\n");
		return;
	}
	struct producto p;
	while(fscanf(file, " %49[^,],%d,%49[^,],%49[^,],%49[^,],%f,%f", p.nombre, &p.cantidad, p.categoria, p.marca, p.codigo, &p.precioCompra, &p.precioVenta) == 7){
		agregarProducto(p);
	}
	fclose(file);
}

void actualizarUsuarios(struct user *usuarios) {
	FILE *file = fopen(fusers, "w");
	for(int i = 0; i < contUsuarios; i++) {
		fprintf(file, "%s,%s,%s\n", (usuarios + i)->type, (usuarios + i)->username, (usuarios + i)->password);
	}
	fclose(file);
}

void actualizarVentas(struct venta *ventas) {
	FILE *file = fopen(fventas, "w");
	for(int i = 0; i < contVentas; i++) {
		fprintf(file, "%s,%s,%s\n", (ventas + i)->n_vendedor, (ventas + i)->fecha, (ventas + i)->local);
	}
	fclose(file);
}

void actualizarProductos(struct producto *productos) {
	FILE *file = fopen(fproductos, "w");
	for(int i = 0; i < contProductos; i++) {
		fprintf(file, "%s,%d,%s,%s,%s,%.2f,%.2f\n", (productos + i)->nombre, (productos + i)->cantidad, (productos + i)->categoria, (productos + i)->marca, (productos + i)->codigo, (productos + i)->precioCompra, (productos + i)->precioVenta);
	}
	fclose(file);
}




