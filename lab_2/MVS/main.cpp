#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <string>
#include <omp.h>

using namespace std;


void read_data(int** A, int size, string filename)
{
    ifstream data;
    data.open(filename);
    
    if (data.is_open()) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                data >> A[i][j];
            }
            
        }
    }
    data.close();
}

void write_result_matrix(string filename, int** C, int size)
{
    ofstream data(filename);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            data << C[i][j] << "\n";
        }
    }

    data.close();
}

int** resize_matrix(int size)
{
    int** matrix = new int* [size];
    for (int i = 0; i < size; ++i)
        matrix[i] = new int[size];
    return matrix;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    //int size[3]{ 50, 100, 500 };
    int sizes[9]{ 10, 50, 100, 500, 600, 700, 800, 900, 1000 };

    int** A, ** B, ** C;
    string res;
    vector<vector<string>> rez_txt;
    string res_filename, filename1, filename2;
    string filename[3]{ "E:\\УЧЕБА\\parallel programming\\lab1\\lab_1\\VS\\data_matrix_2\\",
        "E:\\УЧЕБА\\parallel programming\\lab1\\lab_1\\VS\\data_matrix_1\\",
        "E:\\УЧЕБА\\parallel programming\\lab1\\lab_2\\result_matrix\\" };
    int threads = 1;

    for (int t = 0; t < 5; t++)
    {
        
        omp_set_num_threads(threads);
        cout << "Кол-во Потоков: " << omp_get_max_threads() << endl;

        for (int size : sizes)
        {
            cout << "Размер матриц: " << size << endl;
            int current_size = size;
            res.append("Количество потоков: ").append(to_string(threads)).append("\n");
            res.append("Размер матрицы: ").append(to_string(size)).append("х").append(to_string(size)).append("\n");
            res.append("Время перемножения: ");
            A = resize_matrix(size);
            B = resize_matrix(size);
            C = resize_matrix(size);
            filename1 = filename[0];
            filename2 = filename[1];
            read_data(A, size, filename1.append(to_string(size)).append(".txt"));
            read_data(B, size, filename2.append(to_string(size)).append(".txt"));

            for (int m = 0; m < 10; m++)
            {


                int i, j, k;
                double wtime = omp_get_wtime();
#pragma omp parallel for  shared(A, B, C) private(i, j, k) 
                for (i = 0; i < current_size; i++)
                {
                    for (j = 0; j < current_size; j++)
                    {
                        C[i][j] = 0;
                        for (k = 0; k < current_size; k++)
                            C[i][j] += B[i][k] * A[k][j];

                    }
                }
                wtime = omp_get_wtime() - wtime;
                res_filename = filename[2];

                write_result_matrix(res_filename.append(to_string(size)).append("_").append(to_string(m)).append(".txt"), C, size);


                cout << "Время: " << wtime << " сек." << endl;
                
                res.append(to_string(wtime)).append("; ");

            }
            res.append("\n--------------------------------------\n");

        }
        threads *= 2;
    }
    ofstream data("rez_mul.txt");
    data << res;
    data.close();

	return 0;
}