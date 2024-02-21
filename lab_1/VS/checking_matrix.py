import numpy as np

def read(filename):
    with open(filename) as file:
        lines = [line.rstrip() for line in file]
    return lines

if __name__ == "__main__":
    list_size = [10, 50, 100, 500, 1000]
    list_folder_name = ["data_matrix_1/", "data_matrix_2/", "rez.txt"]
    list_res_check = []
    
    for i in list_size:
        a = np.array(read(list_folder_name[0] + str(i) + ".txt"))
        b = np.array(read(list_folder_name[1] + str(i) + ".txt"))
        rez = np.dot(a, b)
        c = np.array(read(list_folder_name[2] + str(i) + ".txt"))
        list_res_check.append(np.array_equal(rez, c))

    f1 = open("res_check.txt", "w+")
    for i in range(list_res_check.count()):
        if (i != list_res_check.count() - 1):
            f1.write(str(list_res_check[i]) + "\n")
        else:
            f1.write(str(list_res_check[i]))
    f1.close()