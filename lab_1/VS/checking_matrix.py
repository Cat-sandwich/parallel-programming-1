import numpy as np

def read(filename, matrix):
    with open(filename) as file:
        lines = [int(line.rstrip()) for line in file]
    k = 0    
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            matrix[i][j] = int(lines[k])
            k +=1
    return matrix

if __name__ == "__main__":
    list_size = [ 10, 50, 100, 500, 600, 700, 800, 900, 1000]
    list_folder_name = ["data_matrix_1/", "data_matrix_2/", "e:\УЧЕБА\parallel programming\lab1\lab_1\\result_matrix/"]
    list_res_check = []

    for i in list_size:
        a =  np.empty([i, i], dtype=int)
        a = read(list_folder_name[0] + str(i) + ".txt",a)

        b =  np.empty([i, i], dtype=int)
        b = read(list_folder_name[1] + str(i) + ".txt", b)
        res = np.empty([i, i], dtype=int)
        res = np.dot(a, b)
        c = np.empty([i, i], dtype=int)
        c = read(list_folder_name[2] + str(i) + ".txt", c)
        list_res_check.append(np.array_equal(res, c))

    f1 = open("res_check.txt", "w+")
    for i in range(len(list_res_check)):
        if (i != len(list_res_check) - 1):
            f1.write("Для матрицы размером "+ str(list_size[i]) + " x " + str(list_size[i]) +" результат проверки: " + str(list_res_check[i]) + "\n")
        else:
            f1.write("Для матрицы размером "+ str(list_size[i]) + " x " + str(list_size[i]) +" результат проверки: " + str(list_res_check[i]))
    f1.close()