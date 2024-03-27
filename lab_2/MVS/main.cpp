#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <string>
#include <omp.h>

using namespace std;

void multiply_matrices(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C)
{
    #pragma omp parallel for
        for (int i = 0; i < C.size(); i++) {
            for (int j = 0; j < C[i].size(); j++) {
                C[i][j] = 0;
                for (int k = 0; k < C.size(); k++) {
                    C[i][j] += B[i][k] * A[k][j];
                }
            }
        }
}

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
    int size[9]{ 10, 50, 100, 500, 600, 700, 800, 900, 1000 };

    int** A, ** B, ** C;
    string res;
    vector<vector<string>> rez_txt;
    string res_filename, filename1, filename2;
    string filename[3]{ "E:\\УЧЕБА\\parallel programming\\lab1\\lab_1\\VS\\data_matrix_2\\",
        "E:\\УЧЕБА\\parallel programming\\lab1\\lab_1\\VS\\data_matrix_1\\",
        "E:\\УЧЕБА\\parallel programming\\lab1\\lab_2\\result_matrix\\" };

    int threads;
    omp_set_num_threads(4);
    
    
    for(int i = 0; i < 9; i++)
    {
        int current_size = size[i];
        res.append("Размер матрицы: ").append(to_string(size[i])).append("х").append(to_string(size[i])).append("\n");           
        res.append("Время перемножения: ");
        A = resize_matrix(size[i]);
        B = resize_matrix(size[i]);
        C = resize_matrix(size[i]);
        filename1 = filename[0];
        filename2 = filename[1];
        read_data(A, size[i], filename1.append(to_string(size[i])).append(".txt"));
        read_data(B, size[i], filename2.append(to_string(size[i])).append(".txt"));

        for (int j = 0; j < 10; j++)
        {        
        
        chrono::steady_clock::time_point begin = chrono::steady_clock::now();
        double wtime = omp_get_wtime();
        #pragma omp parallel shared(threads) num_threads(2)
        {
            threads = omp_get_num_threads();     
            //multiply_matrices(A, B, C);
        #pragma omp parallel for
            for (int i = 0; i < current_size; i++) {
                for (int j = 0; j < current_size; j++) {
                    C[i][j] = 0;
                    for (int k = 0; k < current_size; k++) {
                        C[i][j] += B[i][k] * A[k][j];
                    }
                    
                }
            }
        }
        chrono::steady_clock::time_point end = chrono::steady_clock::now();
        
        res_filename = filename[2];
        write_result_matrix(res_filename.append(to_string(size[i])).append("_").append(to_string(j)).append(".txt"), C, size[i]);
        wtime = omp_get_wtime() - wtime;
        cout << "Elapsed omp time: " << wtime << " seconds" << endl;
        res.append(to_string(wtime)).append("; ");
        
        }
        res.append("\n--------------------------------------\n");
    }

    ofstream data("rez_mul.txt");
    data << res;
    data.close();

	return 0;
}