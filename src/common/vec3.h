#include <iostream>
#include <math.h>
#include <stdlib.h>

class vec3 {
public: 
    vec3 () {}
    vec3 (float e0, float e1, float e2) { e[0] = e0; e[1] = e1; e[2] = e2;}
    inline float x() const { return e[0];}
    inline float y() const { return e[1];}
    inline float z() const { return e[2];}
    inline float r() const { return e[0];}
    inline float g() const { return e[1];}
    inline float b() const { return e[2];}

    inline const vec3& operator+() const { return *this; }
    inline vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
    inline float operator[](int i) const { return e[i]; }
    inline float& operator[](int i) { return e[i]; }

    inline vec3& operator+=(const vec3 &v2); 
    inline vec3& operator-=(const vec3 &v2); 
    inline vec3& operator*=(const vec3 &v2); 
    inline vec3& operator/=(const vec3 &v2); 
    inline vec3& operator*=(const float t);
    inline vec3& operator/=(const float t);

    inline float length() const {
        return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);}
    inline float squared_length() const{
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];} 
    inline void make_unit_vector();

    float e[3];
};

//read in vector
inline std::istream& operator>>(std::istream &is, vec3 &t){
    is >> t.e[0] >> t.e[1] >> t.e[2];
    return is;
}

//output vector
inline std::ostream& operator>>(std::ostream &os, vec3 &t){
    os << t.e[0] << " " << t.e[1] << " " << t.e[2];
    return os;
}

//make unit vector
inline void vec3::make_unit_vector() {
    float k = 1.0 / sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
    e[0] *= k; e[1] *= k; e[2] *= k;
}

//add two vectors
inline vec3 operator+(const vec3 &v1, const vec3 &v2){
    return vec3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}

//subtract two vectors
inline vec3 operator-(const vec3 &v1, const vec3 &v2){
    return vec3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}

//multiply two vectors
inline vec3 operator*(const vec3 &v1, const vec3 &v2){
    return vec3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}

//divide two vectors
inline vec3 operator/(const vec3 &v1, const vec3 &v2){
    return vec3(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]);
}

//scale vector
inline vec3 operator*(float t, const vec3 &v){
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vec3 operator/(vec3 v, float t){
    return vec3(v.e[0]/t, v.e[1]/t, v.e[2]/t);
}

inline vec3 operator*(const vec3 &v, float t){
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

//dot product
inline float dot(const vec3 &v1, const vec3 &v2){
    return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2];
}

//cross product
inline vec3 cross(const vec3 &v1, const vec3 &v2){
    return vec3( (v1.e[1]  *v2.e[2] - v1.e[2]  *v2.e[1]),(-(v1.e[0]  *v2.e[2] - v1.e[2]  *v2.e[0])), (v1.e[0]  *v2.e[1] - v1.e[1]  *v2.e[0]));
}

inline vec3& vec3::operator+=(const vec3 &v){
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}

inline vec3& vec3::operator*=(const vec3 &v){
    e[0] *= v.e[0];
    e[1] *= v.e[1];
    e[2] *= v.e[2];
    return *this;
}

inline vec3& vec3::operator/=(const vec3 &v){
    e[0] /= v.e[0];
    e[1] /= v.e[1];
    e[2] /= v.e[2];
    return *this;
}

inline vec3& vec3::operator-=(const vec3 &v){
    e[0] -= v.e[0];
    e[1] -= v.e[1];
    e[2] -= v.e[2];
    return *this;
}

inline vec3& vec3::operator*=(const float t){
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

inline vec3& vec3::operator/=(const float t){
    float k = 1.0/t;

    e[0] *= k;
    e[1] *= k;
    e[2] *= k;
    return *this;
}

inline vec3 unit_vector(vec3 v){
    return v / v.length();
}

inline vec3 reflect(const vec3& v, const vec3& n) {
    return v - 2*dot(v,n)*n;
}

inline vec3 random_in_unit_sphere(){
    vec3 p;
    do{
        p = 2.0*vec3(drand48(), drand48(), drand48()) - vec3(1, 1, 1);
    } while (p.squared_length() >= 1.0);
    return p;
}

inline float clamp(const vec3 &v){
    if (v[0] < v[1]){
        return v[1];
    }
    else if (v[0] > v[2]){
        return v[2];
    }
    else{
        return v[0];
    }
}