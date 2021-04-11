#include <mysql.h>
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

int q_estado;


void menu();
void repetir()
{
    string opc;
    cout << endl << endl << "Desea probar otra opcion (s/n): ";
    cin >> opc;
    cin.ignore();
    if (opc == "S" || opc=="s")
    {
        system("cls");
        menu();
    }
}


//      FUNCIONANDO
void insert_marcas()
{
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "root", "crud", 3309, NULL, 0);
    if (conectar)
    {
        string marca;
        cout << "ingrese la marca: ";
        getline(cin, marca);
        //cin >> marca;
        string insert = "insert into marcas(marca) values ('" + marca + "')";
        const char* i = insert.c_str();
        q_estado = mysql_query(conectar, i);
        if (!q_estado)
        {
            cout << "insert exitoso" << endl;
        }
        else
        {
            cout << "error en insert" << endl;
        }
    }
}


//      FUNCIONANDO
void insert_productos()
{
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "root", "crud", 3309, NULL, 0);
    if (conectar)
    {
        string producto, descripcion,fecha_ingreso="now()";
        string id_marca, existencia, precio_costo, precio_venta;
        cout << "\ningrese el producto: ";
        getline(cin,producto);
        cout << "\ningrese el id_marca: ";
        cin >> id_marca;
        cin.ignore();
        cout << "\ningrese la descripcion: ";
        getline(cin, descripcion);
        cout << "\ningrese el precio costo: ";
        cin >> precio_costo;
        cin.ignore();
        cout << "\ningrese el precio venta: ";
        cin >> precio_venta;
        cin.ignore();
        cout << "\ningrese las existencias: ";
        cin >> existencia;
        cout << "\nla hora actual sera la fecha que aparecerá en fecha_ingreso" << endl<<endl;

        string insert = "insert into productos(producto,id_marca,descripcion,precio_costo,precio_venta,existencia,fecha_ingreso) values ('" + producto + "' , " + id_marca + " , '" + descripcion + "' , "+precio_costo+","+precio_venta+","+existencia+","+fecha_ingreso+")";
        const char* i = insert.c_str();
        q_estado = mysql_query(conectar, i);
        if (!q_estado)
        {
            cout << "insert exitoso" << endl;
        }
        else
        {
            cout << "error en insert" << endl;
        }
    }
}


//      FUNCIONANDO
void select_marcas()
{
    MYSQL* conectar;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "root", "crud", 3309, NULL, 0);
    if (conectar)
    {
        string consulta = "select * from marcas";
        const char* c = consulta.c_str();
        q_estado = mysql_query(conectar, c);
        if (!q_estado)
        {
            resultado = mysql_store_result(conectar);
            while (fila = mysql_fetch_row(resultado))
            {
                cout << fila[0] << ", " << fila[1] << endl;
            }
        }
    }
    
}


//      FUNCIONANDO
void select_productos()
{
    MYSQL* conectar;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "root", "crud", 3309, NULL, 0);
    if (conectar)
    {
        string consulta = "select * from productos";
        const char* c = consulta.c_str();
        q_estado = mysql_query(conectar, c);
        cout << "id_prod  producto      id_marca       descripcion        precio_costo   precio_venta  existencia   fecha_ingreso" << endl;
        cout << "____________________________________________________________________________________________________________________" << endl;
        if (!q_estado)
        {
            resultado = mysql_store_result(conectar);
            while (fila = mysql_fetch_row(resultado))
            {
                cout << fila[0] << ",    " << fila[1] << ",  "<<fila[2]<<", "<<fila[3]<<", "<<fila[4]<<",    "<<fila[5]<<",    "<<fila[6]<<",    "<<fila[7]<<endl<<endl;
            }
        }
    }
}

//      FUNCIONANDO
void update_marcas()
{
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "root", "crud", 3309, NULL, 0);
    if (conectar)
    {
        string marca,id;
        cout << "ingrese el id del registro que desea modificar: ";
        cin >> id;
        cin.ignore();
        cout << "ingrese la nueva marca: ";
        getline(cin, marca);
        string update = "update marcas set marca= '" + marca + "' where id_marca= "+id;
        const char* i = update.c_str();
        q_estado = mysql_query(conectar, i);
        if (!q_estado)
        {
            cout << "update exitoso" << endl;
        }
        else
        {
            cout << "error en el update" << endl;
        }
    }
}



void update_productos()
{
    MYSQL* conectar;

    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "root", "crud", 3309, NULL, 0);
    cout << endl << endl;
    if (conectar)
    {
        string producto, id_marca, descripcion,precio_costo,precio_venta,existencias,id_producto, update_id_prod, update;
        int opcion;
        cout << "Ingrese el id del registro que desea modificar: ";
        cin >> id_producto;
        cin.ignore();
        Sleep(500);
        system("cls");
        cout << "----------LISTADO DE DATOS DE LA TABLA PRODUCTOS ----------" << endl;
        cout << "   1. id_producto" << endl;
        cout << "   2. Producto" << endl;
        cout << "   3. Id_marca" << endl;
        cout << "   4. Descripcion" << endl;
        cout << "   5. Precio_costo" << endl;
        cout << "   6. Precio_venta" << endl;
        cout << "   7. Existencias" << endl;
        cout << "Que elemento desea modificar: ";
        cin >> opcion;
        cin.ignore();
        switch (opcion)
        {
        case 1:
            cout << "ingrese la modificacion del id_producto: ";
            getline(cin, update_id_prod);
            update = "update productos set id_producto= " + update_id_prod + " where id_producto= " + id_producto;
            break;
        case 2:
            cout << "ingrese la modificacion de producto: ";
            getline(cin, producto);
            update = "update productos set producto= '" + producto + "' where id_producto= " + id_producto;
            break;
        case 3:
            cout << "ingrese la modificacion de id_marca: ";
            cin >> id_marca;
            update = "update productos set id_marca= " + id_marca + " where id_producto= " + id_producto;
            break;
        case 4:
            cout << "ingrese la modificacion de descripcion: ";
            getline(cin, descripcion);
            update = "update productos set descripcion= '" + descripcion + "' where id_producto= " + id_producto;
            break;
        case 5:
            cout << "ingrese la modificacion de precio_costo: ";
            cin >> precio_costo;
            update = "update productos set precio_costo= " + precio_costo + " where id_producto= " + id_producto;
            break;
        case 6:
            cout << "ingrese la modificacion de precio_venta: ";
            cin >> precio_venta;
            update = "update productos set precio_venta= " + precio_venta + " where id_producto= " + id_producto;
            break;
        case 7:
            cout << "ingrese la modificacion de existencias: ";
            cin >> existencias;
            update = "update productos set existencia= " + existencias + " where id_producto= " + id_producto;
            break;
        default:
            cout << "esa opcion no existe" << endl;
            break;
        }
        
        const char* i = update.c_str();
        q_estado = mysql_query(conectar, i);
        if (!q_estado)
        {
            cout << "update exitoso" << endl;
        }
        else
        {
            cout << "error en el update" << endl;
        }
    }
}


void delete_marcas()
{
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "root", "crud", 3309, NULL, 0);
    if (conectar)
    {
        string marca, id;
        cout << "ingrese el id del registro que desea eliminar: ";
        cin >> id;
        cin.ignore();
        string update = "delete from marcas where id_marca= " + id;
        const char* i = update.c_str();
        q_estado = mysql_query(conectar, i);
        if (!q_estado)
        {
            cout << "delete exitoso" << endl;
        }
        else
        {
            cout << "error en el delete" << endl;
        }
    }
}



void delete_productos()
{
    MYSQL* conectar;

    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "root", "crud", 3309, NULL, 0);

    if (conectar)
    {
        string id_producto, delete_productos;
        int opcion;
        cout << "____________________________________________________________________________________________________________________" << endl;
        cout << "\n\nIngrese el id del registro que desea eliminar: ";
        cin >> id_producto;
        cin.ignore();
       
        delete_productos = "delete from productos where id_producto= " + id_producto;
        const char* i = delete_productos.c_str();
        q_estado = mysql_query(conectar, i);
        if (!q_estado)
        {
            cout << "delete exitoso" << endl;
        }
        else
        {
            cout << "error en el delete" << endl;
        }
    }
}



void operaciones_tablas()
{
    system("cls");
    cout << "__________ ESCOJA LA OPCION QUE DESEE __________" << endl;
    cout << "1. INSERTAR DATOS" << endl;
    cout << "2. VER DATOS" << endl;
    cout << "3. MODIFICAR DATOS" << endl;
    cout << "4. ELIMINAR DATOS" << endl;
}

void menu()
{
    int opcion,opcion2;
    cout << "________________ Menu de opciones ________________" << endl;
    cout << "1. Tabla de marcas" << endl;
    cout << "2. tabla de productos" << endl;
    cout << "Ingrese su opcion: ";
    cin >> opcion;
    cin.ignore();
    if (opcion == 1)
    {
        cout << "---------- TABLA MARCAS ----------" << endl;
        operaciones_tablas();
        cout << "ingrese su opcion: ";
        cin >> opcion2;
        cin.ignore();
        switch (opcion2)
        {
        case 1:
            cout << endl;
            insert_marcas();
            repetir();
            break;
        case 2:
            system("cls");
            select_marcas();
            Sleep(600);
            repetir();
            break;
        case 3:
            system("cls");
            cout << "_________ Estos son los registros de la tabla marcas __________" << endl;
            select_marcas();
            update_marcas();
            repetir();
            break;
        case 4:
            system("cls");
            cout << "_________ Estos son los registros de la tabla marcas __________" << endl;
            select_marcas();
            delete_marcas();
            repetir();
            break;
        }
    }
    if (opcion == 2)
    {
        cout << "---------- TABLA PRODUCTOS ----------" << endl;
        operaciones_tablas();
        cout << "ingrese su opcion: ";
        cin >> opcion2;
        cin.ignore();
        switch (opcion2)
        {
        case 1:
            insert_productos();
            repetir();
            break;
        case 2:
            system("cls");
            select_productos();
            Sleep(600);
            repetir();
            break;
        case 3:
            system("cls");
            select_productos();
            update_productos();
            repetir();
            break;
        case 4:
            system("cls");
            select_productos();
            delete_productos();
            repetir();
            break;
        }
    }
}

int main()
{
    menu();
}

