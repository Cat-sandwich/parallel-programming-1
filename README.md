# Описание к лабораторным работам
Выполнила студентка группы 6311-100503D Белякова Вероника
Характеристики компьютера:
* Процессор -  Intel(R) Xeon(R) CPU E5-2667 v2 @ 3.30GHz   3.30 GHz (8 ядер и 16 потоков)
* Оперативная память - 64,0 ГБ 
* Тип системы - 64-разрядная операционная система, процессор x64
* Видеокарта - AMD Radeon RX 570

## Лабораторная 1
### Описание файлов
* `main.cpp` - чтение данных из файла, запись результата в файл и подсчет времени перемножения матриц (С++)
* `create_data.py` - создание и заполнение входных файлов для перемножения матриц (Python)
* `create_data.py` - перемножение матриц из тех же исходных файлов с помощью numpy, проверка перемноженных матриц
### Результаты
Проверка перемножения матриц, написанная на python, успешно пройдена (результаты проверки отражены в файле `res_check.txt`).
Также для визуального отображения зависимости времени перемножения от размеров матриц был построе график:
![dependence](https://github.com/Cat-sandwich/parallel-programming-1/assets/113890061/d0a370ba-58ce-48b5-ac21-07824d9dfd00)

## Лабораторная 2
В данной л/р я модифицировала программу из л/р №1 для параллельной работы по технологии OpenMP. ТАкже учла замечания: посчитала доверительные интервалы для граничных измерений, а также написала технические характеристики устройства.
### Описание файлов
* `lab_2\VS\confidence_interval.ipynb` содержится расчет доверительных интервалов для 1 и 16 потоков
* `lab_2\MVS\rez_mul.txt` проверка правильности перемножения
Результаты зависимости времени от числа потоков представлены на графике:
![alt text](lab_2\image.png)

## Лабораторная 3
### Описание работы на ПК
В данной л/р я модифицировала программу из л/р №1 для параллельной работы по технологии MPI. Сначала я прверила корректность работы кода у себя на компьютере, предварительно подгрузив необходимые файлы для работы с mpi. Запуск кода происходил через терминал. Также сделала проверку на корректность значений.
### Описание работы на суперкомпьютере
* Установила необходимые программки (PuTTY и WinSCP)
* Перенесла на удаленный компьютер свои файлы, а потом с помощью WinSCP скопировала их на суперкомпьютер
* Скомпилировала программу (дополнительно понадобилось -std=c++11)
![alt text](lab_3\королев2.png)
* Запустила скомпилированный бинарник через PuTTY (проделала эту работу для разного числа потоков)
![alt text](lab_3\королев3.png)
* Перенесла итоговые файлы обратно на удаленный рабочий стол
![alt text](lab_3\королев1.png)
* Перенесла итоговые файлы на свой ПК
* Посчитала доверительные интервалы и построила график зависимости времени от размера матриц (один график для разного числа потоков)
![alt text](lab_3\график.png)