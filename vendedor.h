#ifndef VENDEDOR_H
#define VENDEDOR_H

// Definición de la estructura para registrar ventas
struct venta {
  char n_vendedor[30];
  char fecha[15];
  char local[15];
};

extern int contVentas;
extern struct venta ventas[50];

// Prototipos de las funciones del vendedor
void menuVendedor(void);
void registrarVenta(void);
void agregarVenta(struct venta v);
void mostrarVentas(void);
void imprimirVentas(struct venta v);

#endif // VENDEDOR_H
