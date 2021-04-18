import time
import random
from AVLtree import AVLTree


def time_measure(switch: int, path: str):
    with open(path, 'w') as file:
        for i in range(1, 101):
            maxi_result = -1
            tree = AVLTree(0)
            with open(f'tests/{i}.txt', 'r') as test:
                # создание дерева
                data = test.read().split()
                size = int(data.pop(0))
                for j in data:
                    tree.insert(int(j))
                # Замеры времени
                for q in range(500):
                    start = time.time()
                    if switch == 1:
                        tree.insert(random.randint(-1 * size, size))
                    elif switch == 2:
                        tree.find(random.randint(-1 * size, size))
                    elif switch == 3:
                        tree.remove(random.randint(-1 * size, size))
                    maxi_result = max(maxi_result, time.time() - start)
            file.write(f'{size}:{maxi_result}\n')
            print('Ready:', i)


def main():
    print("Напиши:\n "
          "1 чтобы измерить добавление в дерево\n "
          "2 чтобы измерить поиск элемента\n "
          "3 чтобы измерить удаление элемента")
    switch = int(input("Ввод: "))
    if switch == 1:
        path = 'tests_measurements_results/insert.txt'
    elif switch == 2:
        path = 'tests_measurements_results/find.txt'
    elif switch == 3:
        path = 'tests_measurements_results/remove.txt'
    else:
        print('и что ты ожидал?')
        return 0
    start = time.time()
    time_measure(switch, path)
    print('Всe это заняло', (time.time() - start) // 60, "мин")


if __name__ == '__main__':
    main()
