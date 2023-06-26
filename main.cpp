#include <iostream>
#include <cmath>

class Vector {
public:
    Vector()
    {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }

    Vector(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    // Cast operations
    operator float ()
    {
        return sqrt(x * x + y * y + z * z);
    }

    // Math operations
    friend Vector operator+(const Vector& a, const Vector& b);
    friend Vector operator-(const Vector& a, const Vector& b);
    friend Vector operator*(const Vector& a, int c);

    // Stream operations
    friend std::ostream& operator<<(std::ostream& out, const Vector& v);
    friend std::istream& operator>>(std::istream& in, Vector& v);

    // Logic operations
    friend bool operator>(const Vector& a, const Vector& b);

    float operator[](int index)
    {
        switch (index) {
            case 0: return x;
            case 1: return y;
            case 2: return z;
            default:
                std::cout << "Index error";
                return 0;
        }
    }

private:
    float x, y, z;

};

Vector operator+(const Vector& a, const Vector& b)
{
    return Vector(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vector operator-(const Vector& a, const Vector& b)
{
    return Vector(a.x - b.x, a.y - b.y, a.z - b.z);
}

Vector operator*(const Vector& a, int c)
{
    return Vector(a.x * c, a.y * c, a.z * c);
}

std::ostream& operator<<(std::ostream& out, const Vector& v)
{
    out << v.x << ' ' << v.y << ' ' << v.z;
    return out;
}

std::istream& operator>>(std::istream& in, Vector& v)
{
    in >> v.x >> v.y >> v.z;
    return in;
}

bool operator>(const Vector& a, const Vector& b)
{
    return false;
}

int main() {
    Vector v1(0, 1, 2);
    Vector v2(3, 4, 5);

    Vector v3;
    v3 = v1 + v2;

    std::cout << v3 << '\n';
    std::cout << "v3 length " << static_cast<float>(v3) << '\n';
    std::cout << "v1 + v2 = " << v1 + v2 << '\n';
    std::cout << "v1 - v2 = " << v1 - v2 << '\n';
    std::cout << "v2 * 2 = " << v2 * 2 << '\n';
    std::cout << "Please, enter v3 params:" << '\n';

    Vector v4;
    std::cin >> v4;
    std::cout << "v4: " << v4;
}
