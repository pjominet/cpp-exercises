#include <c++/cmath>
#include <c++/sstream>
#include <c++/iomanip>
#include "Vector2D.h"

Vector2D::Vector2D(double x, double y) : x(x), y(y) {}

double Vector2D::magnitude() const {
    return sqrt(x * x + y * y);
}

Vector2D operator+(Vector2D &current, Vector2D &other) {
    Vector2D result{};
    result.x = current.x + other.x;
    result.y = current.y + other.y;
    return result;
}

Vector2D operator-(Vector2D &current, Vector2D &other) {
    Vector2D result{};
    result.x = current.x - other.x;
    result.y = current.y - other.y;
    return result;
}

Vector2D operator*(Vector2D &current, double scalar) {
    Vector2D result{};
    result.x = current.x * scalar;
    result.y = current.y * scalar;
    return result;
}

Vector2D operator/(Vector2D &current, double scalar) {
    Vector2D result{};
    result.x = current.x / scalar;
    result.y = current.y / scalar;
    return result;
}

bool Vector2D::operator==(const Vector2D &other) const {
    return magnitude() == other.magnitude() && heading() == other.heading();
}

bool Vector2D::operator!=(const Vector2D &other) const {
    return magnitude() != other.magnitude() || heading() != other.heading();
}

bool Vector2D::operator<(const Vector2D &other) const {
    return magnitude() < other.magnitude();
}

bool Vector2D::operator>(const Vector2D &other) const {
    return other.magnitude() < magnitude();
}

bool Vector2D::operator<=(const Vector2D &other) const {
    return other.magnitude() >= magnitude();
}

bool Vector2D::operator>=(const Vector2D &other) const {
    return magnitude() >= other.magnitude();
}

void Vector2D::normalize() {
    double m = magnitude();
    if (m != 0 && m != 1) {
        x /= m;
        y /= m;
    }
}

double Vector2D::euclid(Vector2D &other) const {
    double ex = x - other.x;
    double ey = y - other.y;
    return sqrt(ex * ex + ey * ey);
}

void Vector2D::limit(double max) {
    if(magnitude() > max){
        normalize();
        x *= max;
        y *= max;
    }
}

double Vector2D::heading() const {
    double angle = atan2(-y, x);
    return angle * -1;
}

std::string Vector2D::toString() {
    std::stringstream stream;
    stream << "x = " << std::fixed << std::setprecision(3) << x << ", " << "y = " << std::fixed << std::setprecision(3) << y;
    std::string result = stream.str();
    return result;
}

double Vector2D::angleBetween(Vector2D &other) {
    double dot = x * other.x + y * other.y;
    return acos(dot / magnitude() * other.magnitude());
}
