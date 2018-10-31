
#ifndef AUFGABE09_VECTOR2D_H
#define AUFGABE09_VECTOR2D_H


class Vector2D {
private:
    double x, y;

public:
    /**
     * Trivial Constructor
     * All values are set to 0
     */
    Vector2D() = default;

    /**
     * Constructor for a 2D vector
     * @param x, the x coordinate
     * @param y, the y coordinate
     */
    Vector2D(double x, double y);

    /**
     * Trivial Destructor
     */
    ~Vector2D() = default;

    /**
     * Trivial Copy Constructor
     * @param other, a reference to another vector
     */
    Vector2D(const Vector2D &other) = default;

    /**
     * Trivial Move Constructor
     * @param other, a reference to a reference of another vector
     */
    Vector2D(Vector2D &&other) noexcept = default;

    /**
    * Trivial Copy Assignment Operator
    * @param other, a reference to another vector
    */
    Vector2D &operator=(const Vector2D &other) = default;

    /**
     * Trivial Move Assignment Operator
     * @param other, a reference to a reference of another vector
     */
    Vector2D &operator=(Vector2D &&other) noexcept = default;

    /**
     * Calculates magnitude (length) of the vector
     * @return the magnitude of the vector
     */
    double magnitude() const;

    /**
     * Allows the addition of 2 vectors
     * @param current, a reference to a vector
     * @param other, a reference to another vector
     * @return a new vector that is the sum of current and other
     */
    friend Vector2D operator+(Vector2D &current, Vector2D &other);

    /**
     * Allows the substraction of 2 vectors
     * @param current, a reference to a vector
     * @param other, a reference to another vector
     * @return a new vector that is the difference of current and other
     */
    friend Vector2D operator-(Vector2D &current, Vector2D &other);

    /**
     * Allows up scaling of a vector
     * @param current, a reference to a vector
     * @param scalar, the scalar (multiplier)
     * @return a new vector, scaled up by the amount of the scalar
     */
    friend Vector2D operator*(Vector2D &current, double scalar);

    /**
     * Allows down scaling of a vector
     * @param current, a reference to a vector
     * @param scalar, the scalar (divider)
     * @return a new vector, scaled down by the amount of the scalar
     */
    friend Vector2D operator/(Vector2D &current, double scalar);

    /**
     * Checks if this vector is equal to another
     * @param other, a reference to another vector
     * @return true if both vectors are equal
     */
    bool operator==(const Vector2D &other) const;

    /**
     * Checks if this vector is not equl to another
     * @param other, a reference to another vector
     * @return true if both vectors are not equal
     */
    bool operator!=(const Vector2D &other) const;

    /**
     * Checks if this vectors magnitude is smaller than the others magnitude
     ** @param other, a reference to another vector
     * @return true if this vectors magnitude is smaller
     */
    bool operator<(const Vector2D &other) const;

    /**
     * Checks if this vectors magnitude is bigger than the others magnitude
     * @param other, a reference to another vector
     * @return true if this vectors magnitude is bigger
     */
    bool operator>(const Vector2D &other) const;

    /**
     * Checks if this vectors magnitude is smaller or equal than the others magnitude
     * @param other, a reference to another vector
     * @return true if this vectors magnitude is smaller or equal
     */
    bool operator<=(const Vector2D &other) const;

    /**
     * Checks if this vectors magnitude is bigger or equal than the others magnitude
     * @param other, a reference to another vector
     * @return true if this vectors magnitude is bigger or equal
     */
    bool operator>=(const Vector2D &other) const;

    /**
     * Normalizes a vector to length 1 (unit vector)
     */
    void normalize();

    /**
     * Calculates the Euclidean Distance between this and another vector
     * @param other, a reference to another vector
     * @return the Euclidean Distance
     */
    double euclid(Vector2D &other) const;

    /**
     * Limits the magnitude of a vector the a given maximum
     * @param max, the maximum length of the vector
     */
    void limit(double max);

    /**
     * Calculates the heading (direction) of a vector expressed as an angle
     * @return the heading angle in radians
     */
    double heading() const;

    /**
     * Transforms the vector in a readable string
     * @return a readable string
     */
    std::string toString();

    /**
     * Calculates the angle between this and another vector
     * @param other, a reference to another vector
     * @return the angle between vectors in radians
     */
    double angleBetween(Vector2D &other);

};


#endif //AUFGABE09_VECTOR2D_H
