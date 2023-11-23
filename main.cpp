//el include es como el import
//no hay paquetes por defecto por lo que siempre se debe incluir
#include <iostream>
//para paralelizacion se usa el  immintrin 
//immintrin es un soporte para vectorizacion h
#include <immintrin.h>
//para importar: 
//importar de la aplicacion ""
//importar del sistema <>

//todos los lenguajes de programacion tienen main 
//main tambien puede recibir parametros
//int main(int argv,char** argc) { 
//si no recibe parametros queda asi
int main() {

    //declarar tipos de datos vectoriales 
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
    std::cout << "Hello, World!" << std::endl;
    std::printf("Hola Mundo\n");
    return 0;
}
