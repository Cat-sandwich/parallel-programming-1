# Технологии и методы программирования
[Таблица с успеваемостью](https://docs.google.com/spreadsheets/d/1_UR7YXMhR4u9ysyfWyKSb8l4D-3DE_kWhoXdivvOudk/edit?usp=sharing)
## Лабораторная 3 "Regular expressions"
В рамках данной лабораторной работы требуется продемонстрировать свои таланты к написанию регулярных выражений.
## Варианты выполнения лабораторной работы
В вариантах сдачи данной лабораторной предусмотрена некоторая гибкость:
1. Решить собвственную задачу, связанную с написанием регулярных выражений и сделать pr c ее кодом в данный репозиторий (примерный вариант такой задачи продемонстрирован лектором в телеграм-чате предмета - с unicode emoji).
2. Решить подготовленную для вас в данном репозитории задачу по регулярным выражениям, условие которой описано ниже.
## Задание на лабораторную работу
1. Сделать fork данного репозитория.
2. Получить csv-файл в соответствии со своим вариантом.
3. Произвести валидацию файла с использованием регулярных выражений.
4. На основе номеров невалидных строк подсчитать контрольную сумму.
## Условия сдачи
* Корректность вашей контрольной суммы подтверждена github action,
* В коде имеются 10 вменяемых регулярных выражений для валидации данных,
* Ваш код оформлен в соотвествии с РЕР8, грамотно декомпозирован и не нуждается в рефакторинге.
## Условие лабораторной
### Исходные данные
Для каждого студента сгенерирован персональный csv-файл с данными. Свой вариант задания можно узнать в [таблице с успеваемостью](https://docs.google.com/spreadsheets/d/1_UR7YXMhR4u9ysyfWyKSb8l4D-3DE_kWhoXdivvOudk/edit?usp=sharing).  

Файл содержит **10000** строк данных, сгенерированных при помощи [mimesis](https://mimesis.name/en/master/). Данные имеют **10** столбцов различного формата. Среди данных имеются невалидные - по **100** записей на поле. Суммарно **1000** невалидных записей. Искажения в данные для каждого столбца имеют случайный характер. Такой объем данных должен, в идеале, отбить у вас любое желание провалидировать записи вручную.  
Свой csv-файл можно скачать из [этой папки на драйве](https://drive.google.com/drive/folders/1o3JISAzmDNnkjQK1YzlRLFAY0RmuS3s5?usp=sharing).

По итогам обработки файла с данными вам необходимо вычислить контрольную сумму при помощи функции в модуле [checksum.py](checksum.py), после чего заполнить [result.json](result.json) полученной контрольной суммой и номером своего варианта. Подбробное описание использования этого модуля дано в его докстрингах.
### Проверка результатов
Корректность контрольной суммы проверяется при помощи [github action](.github/workflows/result-check.yml). Правильные знечения достаются из секретов репозитория, среди них ищется значение для вашего варианта и сравнивается с вашим ответом.  

Акшон запускается при открытии пул-риквеста, а также при добавлении каждого последующего коммита в пул-риквест. Если ваша контрольная сумма не совпала с верной, акшон покажет вам корректное значение. Так что вы сможете локально отладить свой код для валидации, добиться корректного значения и только потом коммитить в pr.
### Описание данных
Под катом вы найдете описания всех возможных форматов данных в этой лабораторной работе с примерами и комментариями.

<details>
  <summary>Типы используемых данных</summary>
  <br>
<table>
  <tr>
    <th>№</th>
    <th>Название поля</th>
    <th>Пример значения</th>
    <th>Комментарий</th>
  </tr>
  <tr>
    <td>1</td>
    <td>email</td>
    <td>operators.1947@protonmail.com, relate1878@sub.domain.ru</td>
    <td>Типичный имейл. Состоит из латинских букв, цифр, символов "." и "@".Обратите внимание, что адрес может иметь поддомен.</td>
  </tr>
    <tr>
    <td>2</td>
    <td>telephone</td>
    <td>+7-(969)-765-17-05</td>
    <td>Номер телефона должен иметь строго заданный формат как в примере. Скобки, тире и +7 должны обязательно присутствовать.</td>
  </tr>
    <tr>
    <td>3</td>
    <td>http_status_message</td>
    <td>200 OK, 226 IM Used</td>
    <td>Статус должен начинаться с трехзначного кода, отделенного пробелом от текстового описания.</td>
  </tr>
    <tr>
    <td>4</td>
    <td>height</td>
    <td>1.76, 2.00</td>
    <td>Высота имеет точку в качестве разделителя целой и дробной части и имеет точность в два знака после него. В задании подразумевается, что это рост человека. В задании подразумевается, что 10/20/30 и т.д. -метровых людей не существует.</td>
  </tr>
    <tr>
    <td>5</td>
    <td>snils</td>
    <td>90534478510</td>
    <td>СНИЛС состоит из 11 цифровых символов. В данном задании символы СНИЛСа они указаны подряд без пробелов/тире и т.д.</td>
  </tr>
    <tr>
    <td>6</td>
    <td>inn</td>
    <td>733499833600</td>
    <td>ИНН состоит из 12 цифровых символов. В данном задании символы ИНН они указаны подряд без пробелов/тире и т.д.</td>
  </tr>
    <tr>
    <td>7</td>
    <td>passport</td>
    <td>27 17 117724</td>
    <td>В данном задании пробелами разделены первые 2 и последние 2 цифры серии, а также серия и номер паспорта.</td>
  </tr>
    <tr>
    <td>8</td>
    <td>identifier</td>
    <td>62-71/26</td>
    <td>Это поле - некоторый абстрактный идентификатор. Он содержит только цифры, разделенные определенными спецсимволами в определенных местах.</td>
  </tr>
    <tr>
    <td>9</td>
    <td>ip_v4</td>
    <td>19.121.223.58</td>
    <td>IP-адрес указывается без маски подсети. Не забывайте, что он 32-битный.</td>
  </tr>
    <tr>
    <td>10</td>
    <td>occupation</td>
    <td>'Web-программист', 'Слесарь-механик', 'Ассистент менеджера по продажам'</td>
    <td>Название профессии может иметь в своем составе как кириллические символы, так и латинские. А вот спецсимволы кроме дефиса там встречаться не должны.</td>
  </tr>
    <tr>
    <td>11</td>
    <td>longitude</td>
    <td>92.264847, -63.65076 </td>
    <td>Это долгота в системе координат WGS94 <a href="https://epsg.io/4326">(srid 4326)</a>. Обратите внимание на ограничения на значение, которые она имеет. Должна быть числовым значением без единиц измерения и прочей текстовой информации.</td>
  </tr>
    <tr>
    <td>12</td>
    <td>latitude</td>
    <td>-8.287791, 32.223374 </a></td>
    <td>Это широта в системе координат WGS94 <a href="https://epsg.io/4326">(srid 4326)</a>. Обратите внимание на ограничения на значение, которые она имеет. Должна быть числовым значением без единиц измерения и прочей текстовой информации.</td>
  </tr>
    <tr>
    <td>13</td>
    <td>hex_color</td>
    <td>#d8346b</td>
    <td>Это представление веб-цвета в виде трех пар 16-ричных цифр. Наличие хештега перед ними обязательно.</td>
  </tr>
    <tr>
    <td>14</td>
    <td>blood_type</td>
    <td>AB+, O-</td>
    <td>Это группа крови <a href="https://ru.wikipedia.org/wiki/%D0%93%D1%80%D1%83%D0%BF%D0%BF%D0%B0_%D0%BA%D1%80%D0%BE%D0%B2%D0%B8#%D0%93%D1%80%D1%83%D0%BF%D0%BF%D1%8B_%D0%BA%D1%80%D0%BE%D0%B2%D0%B8_%D1%81%D0%B8%D1%81%D1%82%D0%B5%D0%BC%D1%8B_ABO">в системе АВО</a> с указанием резус-фактора. Обратите внимание, что отрицательный резус-фактор в исходных данных обозначен символом \u2212 </td>
  </tr>
    <tr>
    <td>15</td>
    <td>isbn</td>
    <td>018-1-50114-053-6</td>
    <td>13-значный <a href="https://ru.wikipedia.org/wiki/%D0%9C%D0%B5%D0%B6%D0%B4%D1%83%D0%BD%D0%B0%D1%80%D0%BE%D0%B4%D0%BD%D1%8B%D0%B9_%D1%81%D1%82%D0%B0%D0%BD%D0%B4%D0%B0%D1%80%D1%82%D0%BD%D1%8B%D0%B9_%D0%BA%D0%BD%D0%B8%D0%B6%D0%BD%D1%8B%D0%B9_%D0%BD%D0%BE%D0%BC%D0%B5%D1%80">международный стандартный книжный номер</a></td>
  </tr>
    <tr>
    <td>16</td>
    <td>issn</td>
    <td>1931-0891</td>
    <td>8-значный <a href="https://ru.wikipedia.org/wiki/%D0%9C%D0%B5%D0%B6%D0%B4%D1%83%D0%BD%D0%B0%D1%80%D0%BE%D0%B4%D0%BD%D1%8B%D0%B9_%D1%81%D1%82%D0%B0%D0%BD%D0%B4%D0%B0%D1%80%D1%82%D0%BD%D1%8B%D0%B9_%D1%81%D0%B5%D1%80%D0%B8%D0%B0%D0%BB%D1%8C%D0%BD%D1%8B%D0%B9_%D0%BD%D0%BE%D0%BC%D0%B5%D1%80">международный стандартный сериальный номер</a></td>
  </tr>
    <tr>
    <td>17</td>
    <td>locale_code</td>
    <td>es-uy,xh</td>
    <td>Региональная настройка языка в формате <a href="https://learn.microsoft.com/en-us/openspecs/windows_protocols/ms-lcid/a9eac961-e77d-41a6-90a5-ce1a8b0cdb9c">MS-LCID</a>.</td>
  </tr>
    <tr>
    <td>18</td>
    <td>uuid</td>
    <td>3a7fb1ca-bdc6-4314-ad9a-6370f7a9657b</td>
    <td><a href="https://ru.wikipedia.org/wiki/UUID">Всемирно уникальный идентификатор</a> в каноническом представлении</td>
  </tr>
    <tr>
    <td>19</td>
    <td>time</td>
    <td>18:24:12.734883</td>
    <td>Время определенного формата с указанием часов, минут и секунд с точностью до 6 знаков. Не забывайте, что в сутках 24 часа, а в минуте - 60 секунд.</td>
  </tr>
    <tr>
    <td>20</td>
    <td>date</td>
    <td>2000-02-14</td>
    <td>Дата определенного формата. Напомню, что у нас только 12 месяцев, в которых максимум 31 день.</td>
  </tr>
</table>
</details>

## Ремарки
Касательно реализации лабораторной работы:
* Проведите предварительный анализ данных, что достались вам на валидацию, перед тем как бросаться писать код.
* Не пишите 10 отдельных методов/функций для валидации каждого отдельного столбца данных. Генерализуйте обработку ячеек csv файла.
* Не бомбите открытый pr коммитами. Отладьте код локально. На каждую неудачную отработку CI github шлет оповещение по почту. Вы загадите почту как себе, так и мне.

Если вы столкнулись с непреодолимыми трудностями в ходе выполнения лабораторной работы, вы можете задать вопрос в:
* телеграм-чате предмета,
* телеграм-чате вашего курса,
* канале в дискорде.
