#ifndef MATRIX_H
#define MATRIX_H
#include <ostream>

/**
 * @brief Духмерный массив чисел 
 * 
 * @param n количество строк в матрице
 * @param m количество столбцов в матрице 
 */
class matrix{
public:
        int n, m;
        int **arr;
        /**
         * @brief Создаёт новый объект типа матрицы заполненный нулями
         * 
         */
        matrix();
        /**
         * @brief Создаёт новый объект типа матрицы innХinm заполненный нулями
         * 
         * @param inn количество строк в матрице
         * @param inm количество столбцов в матрице
         */
        matrix(int inn, int inm);
        ~matrix();
        matrix operator + (matrix& m2);
        matrix operator - (matrix& m2);
        matrix operator * (int a);
        matrix operator * (matrix& m2);
        void operator = (matrix& m2);
        bool operator == (matrix& m2);
        friend std::ostream& operator << (std::ostream& out, matrix& m1);
        friend std::istream& operator >> (std::istream& in, matrix& m1);
        /**
         * @brief Возвращает наибольший элемент матрицы
         * 
         * @return  наибольший элемент матрицы
         */
        int max();
};

#endif