#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <iomanip>
using namespace std;

void multiply_matrices(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C)
{
    for (int i = 0; i < C.size(); i++) {
        for (int j = 0; j < C[i].size(); j++) {
            for (int k = 0; k < C.size(); k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void read_data(vector<vector<int>>& A, string filename)
{
    ifstream data;
    data.open(filename);

    if (data.is_open()) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                data >> A[i][j];
            }
        }
    }
    data.close();
}

void write_result(string filename, vector<vector<int>>& C)
{
    ofstream data(filename);

    for (int i = 0; i < C.size(); i++) {
        for (int j = 0; j < C[i].size(); j++) {
            data << C[i][j] << "\n";
        }
        data << endl;
    }

    data.close();
}



int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    string filename;
    int size = std::atoi(filename.c_str());
    cout << "¬ведите им€ файла, из которого прочитать матрицы (без .txt): ";
    cin >> filename;
    filename += ".txt";

    vector<vector<int>> v1(size, std::vector<int>(size))
        , v2(size, std::vector<int>(size))
        , v3(size, std::vector<int>(size));
   

    read_data(v1, filename);
    read_data(v2, filename);

    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    multiply_matrices(v1, v2, v3);
    chrono::steady_clock::time_point end = chrono::steady_clock::now();

    string rez_filename = "rez_" + filename;
    write_result(rez_filename, v3);

    cout << "Diff(ms) = " << chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << endl;

	return 0;
}