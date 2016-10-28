//Clase Point

class Point{
private:
    double x, y;
public:
    Point (Point &p);
    Point();
    Point(double nx, double ny);
    double getX();
    double getY();
    void setX(double new_x);
    void setY(double new_y);
    void printpoint();
    void modifypoint(double new_x, double new_y);

};

//Clase PointArray

class PointArray
{
private:
    void resize(const int &newSize);
    Point* data;
    int Size;

public:
    PointArray();
    PointArray(const Point points[], const int &newSize);
    PointArray(const PointArray &pv);
    ~PointArray();
    void showPoint(const int &pos);
    void push_back(const Point &p);
    void insert(const int &position, const Point &p);
    void remove(const int &pos);
    const int getSize() const;
    void clear();
    Point* get(const int &position);                //Permite modificar al PointArray, ya que nos devuelve un puntero a Point.
    const Point* get(const int &position) const;    //Solo para leer la informacion del Point, pero no para cambiarla.

};
