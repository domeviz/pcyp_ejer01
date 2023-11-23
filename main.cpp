#include <iostream>
#include <immintrin.h>

int main() {

    __m256 a= _mm256_set_ps(1,2,3,4,5,6,7,8);
    __m256 b=_mm256_set_ps(1,2,3,4,5,6,7,8);;

    /**
     * c =[1,2,3,4,5,6,7,8]+[1,2,3,4,5,6,7,8]
     */

    __m256 c= _mm256_add_ps(a,b);

    float res[8];
    _mm256_storeu_ps(res,c);

    std::printf("Resultado:\n");
    for (int i = 0; i < 8; ++i) {
        std::printf("d[%d]=%.0f\n",i,res[i]);
    }
}
