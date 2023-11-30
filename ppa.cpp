#include <iostream>
#include <string>
#include <vector>

using namespace std;

class producto {
public:
    string descripcion;
    int cantidad;
    double precio;

    producto(string descripcion, int cantidad, double precio) {
        this->descripcion = descripcion;
        this->cantidad = cantidad;
        this->precio = precio;
    }
};

class factura {
private:
    vector<producto> productos;

public:
    void agregar_producto(const producto& p) {
        productos.push_back(p);
    }

    void imprimir() const {
        double total = 0;

        cout << "**********************************" << endl;
        cout << "         FACTURA DE VENTA          " << endl;
        cout << "**********************************" << endl;

        for (int i = 0; i < productos.size(); i++) {
            double subtotal = productos[i].cantidad * productos[i].precio;
            total += subtotal;
            cout << productos[i].descripcion << " - Cantidad: " << productos[i].cantidad << " - Precio: $" << productos[i].precio << endl;
            cout << "Subtotal: $" << subtotal << endl;
            cout << "----------------------------------" << endl;
        }

        cout << "TOTAL: $" << total << endl;
    }

    double obtener_total() const {
        double total = 0;
        for (const auto& p : productos) {
            total += p.cantidad * p.precio;
        }
        return total;
    }

    void limpiar() {
        productos.clear();
    }
};

int main() {
   cout<<"*----------------------------------------------------------------*"<<endl;
   cout<<" | #######                                                        |"<<endl;
   cout<<"  | #          ##     ####   #####  #    #  #####     ##     ####  |"<<endl;
   cout<<"   | #         #  #   #    #    #    #    #  #    #   #  #   #      |"<<endl;
   cout<<"    | #####    #    #  #         #    #    #  #    #  #    #   ####  |"<<endl;
   cout<<"     | #        ######  #         #    #    #  #####   ######       # |"<<endl;
   cout<<"      | #        #    #  #    #    #    #    #  #   #   #    #  #    # |"<<endl;
   cout<<"       | #        #    #   ####     #     ####   #    #  #    #   ####  |"<<endl;
   cout<<"        |                                                                |"<<endl;
   cout<<"         |    Desarrollado por Andres Huertas, Royeiro Mejia y ChatGPT    |"<<endl;
   cout<<"          *----------------------------------------------------------------*"<<endl;


    string descripcion;
    int cantidad;
    double precio;
    char salchipapa = '.';

    vector<factura> todas_las_facturas;

    do {
        factura factura_actual;

        while (true) {
            cout<<"Para cerrar la factura oprima ("<<salchipapa<<")"<<endl;
            cout << "Nombre del producto: ";
            getline(cin, descripcion);

            if (descripcion[0] == salchipapa) {
                break;
            }

            cout << "Cantidad del producto: ";
            cin >> cantidad;
            cout << "Precio del producto: ";
            cin >> precio;

            producto p(descripcion, cantidad, precio);
            factura_actual.agregar_producto(p);

            cin.ignore();
        }

        factura_actual.imprimir();

        if (!factura_actual.obtener_total() == 0) {
            todas_las_facturas.push_back(factura_actual);
        } else {
            cout << "No se ingresaron productos." << endl;
        }

        cout << "Desea agregar otra factura? (S/N): ";
        char respuesta;
        cin >> respuesta;

        cin.ignore();

        if (respuesta != 'S' && respuesta != 's') {
            break;
        }

    } while (true);

    double suma_total = 0;
    for (const auto& f : todas_las_facturas) {
        suma_total += f.obtener_total();
    }

    cout << "\nSuma total de todas las facturas: $" << suma_total << endl;

    cout << "Chao todo bn" << endl;

    return 0;
}


