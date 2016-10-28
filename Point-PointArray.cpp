#include <iostream>
#include <cmath>
#include "Punt-PuntArray.h"

using std::cout;
using std::endl;

//Clase Point

Point::Point (Point &p)
    {
        x=p.x; y=p.y;
    }
Point::Point()
    {
        x=0.0; y=0.0;
    }
Point::Point(double nx, double ny)
    {
        this->x=nx; this->y= ny;
    }
double Point::getX()
{
    return x;
}
double Point::getY()
{
    return y;
}
void Point::setX(double new_x)
{
    this->x=new_x;
}
void Point::setY(double new_y)
{
    this->y=new_y;
}
void Point::printpoint()
{
    cout<<"("<<getX ()<<","<<getY ()<<")";
}
void Point::modifypoint(double new_x, double new_y)
{
    setX(new_x);
    setY(new_y);
}

//Clase PointArray

PointArray::PointArray(){
    this->Size = 0;
    data = new Point[0];
}

PointArray::PointArray(const Point points[], const int &newSize){
    this->Size = newSize;
    data = new Point[newSize];
    for (int i = 0; i < newSize; i++){
        data[i] = points[i];
    }
}

PointArray::PointArray(const PointArray &pv){
    this->Size = pv.Size;
    data = new Point[Size];   //separa mem para el ancho de pv
    for (int i = 0; i <Size; i++){
        data[i] = pv.data[i];  //el iesimo de pv
    }
}

PointArray::~PointArray(){
    delete[] data;  //con corchetes porque es un arreglo
}

void PointArray::resize(const int &newSize){  //por parametro resize
    if (newSize >= 0 ){
        Point *aux = new Point[newSize];  //para 3 newLength
        int actualSize = (newSize  < Size ? newSize : Size);   //si el nuevo ancho es menor que el anterior tomamos en menor
        for (int i = 0; i < actualSize; i++){
            aux[i] = data[i];
        }
        delete[] data;
        data=new Point[actualSize];
        data = aux;
        this->Size = newSize;
    }
    else{
        cout << "Ingrese un tamaño valido" << endl;
    }
}

void PointArray::push_back(const Point &p){ //aumenta en 1 el arreglo
    resize(Size + 1);                          //Dentro de resize length aumenta en 1
    data[Size - 1] = p; //asignamos lo que recibimos como parametro al ultimo
}


void PointArray::insert(const int &position, const Point &p){
    resize(Size + 1);
    for (int i = Size - 1; i > position; i--){  //Desplazamiento en 1 a la derecha de todos los elementos
        data[i] = data[i - 1];        //que estan despues de position
    }
    data[position] = p;
}

void PointArray::remove(const int &pos){
    if (pos >= 0 && pos < Size){
        for (int i = pos; i < Size - 1; i++){
            data[i] = data[i + 1];
        }
        resize(Size - 1);
    }
    else{
        cout << "Ingrese una posicion valida" << endl;
    }
}



const int PointArray::getSize() const{  //devuelve la cantidad de puntos
    return Size;
}

void PointArray::clear(){
    resize(0);
}

Point* PointArray::get(const int &position){    //retorna un puntero a punto(x,y)
    if (position >= 0 && position < Size){
        return data + position;
    }
    else{
        return NULL;
    }
}

const Point* PointArray::get(const int &position) const{    //no se puede recorrer
    if (position >= 0 && position < Size){
        return data + position;
    }
    else{
        return NULL;
    }
}

void PointArray::showPoint(const int &pos){
    cout << "x: " << data[pos].getX() << endl;
    cout << "y: " << data[pos].getY() << endl;
}
