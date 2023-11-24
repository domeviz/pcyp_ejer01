#include <iostream>
#include <immintrin.h>
#include <cstdlib>
#include <ctime>

int main() {

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    const int tam = 1000000;

    float* vector_a = new float[tam];
    float* vector_b = new float[tam];
    float* vector_c = new float[tam];

    for (int i = 0; i < tam; ++i) {
        vector_a[i] = static_cast<float>(std::rand());
        vector_b[i] = static_cast<float>(std::rand());
    }

    const int vector_size = 8;
    int i = 0;
    for (; i < tam - vector_size + 1; i += vector_size) {
        __m256 a = _mm256_loadu_ps(&vector_a[i]);
        __m256 b = _mm256_loadu_ps(&vector_b[i]);

        __m256 c = _mm256_add_ps(a, b);

        _mm256_storeu_ps(&vector_c[i], c);
    }

    for (; i < tam; ++i) {
        vector_c[i] = vector_a[i] + vector_b[i];
    }

    std::printf("10 primeros resultados:\n");
    for (int i = 0; i < 10; ++i) {
        std::printf("vector_a[%d]=%.0f", i, vector_a[i]);
        std::printf(" + ");
        std::printf("vector_b[%d]=%.0f", i, vector_b[i]);
        std::printf(" = ");
        std::printf("vector_c[%d]=%.0f\n", i, vector_c[i]);
    }

    delete[] vector_a;
    delete[] vector_b;
    delete[] vector_c;

    return 0;
}
