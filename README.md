**Структура данных**
-----
**АВЛ дерево (AVL Tree)** - сбалансированное по высоте двоичное дерево поиска: для каждой его вершины высота её двух поддеревьев различается не более чем на 1.

**Установка**
-----
**Клонирование**
###
Чтобы склонировать этот репозиторий на свое устройство, откройте командную строку, перейдите в каталог, в котором хотите его (репозиторий) видеть, и наберите команду
```
git clone https://gitlab.com/etimesoy/avl-trees.git
```
**Скачивание тестов**
###
Чтобы скачать тесты с Dropbox, перейдите в репозиторий с помощью команды
```
cd avl-trees
```
и запустите файл `download_data_from_dropbox.py`
```
python download_data_from_dropbox.py
```
После этого тесты скачаются в папку `/tests`

**Запуск**
-----
**С++**
###
Чтобы прогнать скачанные тесты, скомпилируйте и запустите файл `C++/MeasureTimeComplexity.cpp`:
```
cd C++
g++ AVLTree.cpp MeasureTimeComplexity.cpp -o MeasureTimeComplexity
./MeasureTimeComplexity
```
Также непосредственно в файле MeasureTimeComplexity.cpp можно самому задать количество прогонов каждой из операций (поиск, добавление, удаление). Для этого откройте этот файл, найдите переменную countOfTestsForOperation и присвойте ей нужное значение. Для точности рекомендуем ставить минимум 5000.

Результаты замеров времени выполнения операций появятся в директории `C++/testsMeasurementsResults/` в соответствующих файлах, которые имеют следующую структуру: <размер входных данных>: <время выполнения операции>.

**Python**
###
Чтобы прогнать скачанные тесты, запустите файл `AvlPython/MeasureTimeComplexity.py`:
```
cd AvlPython
python MeasureTimeComplexity.py
```
Результаты замеров времени выполнения операций появятся в директории `AvlPython/testsMeasurementsResults/` в соответствующих файлах.

> P.S. Вы можете посмотреть пример работы со структурой в файлах `C++/Main.cpp` и `AvlPython/AVLtree.py`.

**Графики**
-----
Красивые графики, отображающие зависимость времени выполнения операций от размеров входных данных можно найти по [ссылке](https://docs.google.com/spreadsheets/d/18y4g3hgtcuOwFHHKmVB-YHMnh3D9U0hwcu6IyPxGyco/edit?usp=sharing).

**Видео-презентация**
-----
Видеопрезентацию этой структуры данных можно найти по [ссылке](https://www.youtube.com/watch?v=b2N9YPuPNMw).
