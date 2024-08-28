#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H


typedef struct {
    float x, y;
} Vec2;

typedef struct {
    float m[3][3];
} Matrix3x3;

// Utility functions for vector operations
Vec2 vec2Add(Vec2 a, Vec2 b) {
    return (Vec2){ a.x + b.x, a.y + b.y };
}

Vec2 vec2Subtract(Vec2 a, Vec2 b) {
    return (Vec2){ a.x - b.x, a.y - b.y };
}

Vec2 vec2Scale(Vec2 v, float scale) {
    return (Vec2){ v.x * scale, v.y * scale };
}

// Utility functions for matrix operations
Matrix3x3 identityMatrix() {
    return (Matrix3x3){{
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    }};
}

Matrix3x3 vec2Translate(Vec2 v) {
    return (Matrix3x3){{
        {1, 0, v.x},
        {0, 1, v.y},
        {0, 0, 1}
    }};
}

Matrix3x3 matrix3x3Multiply(Matrix3x3 a, Matrix3x3 b) {
    Matrix3x3 result = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                result.m[i][j] += a.m[i][k] * b.m[k][j];
            }
        }
    }
    return result;
}

Vec2 matrix3x3TransformPoint(Matrix3x3 m, Vec2 p) {
    return (Vec2){
        m.m[0][0] * p.x + m.m[0][1] * p.y + m.m[0][2],
        m.m[1][0] * p.x + m.m[1][1] * p.y + m.m[1][2]
    };
}


#endif // LINEAR_ALGEBRA_H
