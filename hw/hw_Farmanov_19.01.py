import random


def task1(lst: list):
    result = 1
    for i in range(len(lst)):
        result = result * lst[i]

    return result


def task2(lst: list):
    minimum = lst[0]

    for i in range(len(lst)):
        if lst[i] < minimum:
            minimum = lst[i]
        else:
            continue

    return minimum


def task3(lst: list):
    prime_list = list()

    for i in range(len(lst)):
        prime_check = 0
        for j in range(2, abs(lst[i])):
            if lst[i] % j == 0:
                prime_check += 1
            else:
                continue

        if prime_check == 0:
            prime_list.append(lst[i])

    return len(prime_list)


def task4(lst: list):
    count = 0

    for i in range(len(lst)):
        rm_element = str(input("Введите элемент для удаления (для выхода оставьте строку пустой): "))

        if rm_element == '':
            break
        elif int(rm_element) in lst:
            lst.remove(int(rm_element))
            count += 1
        else:
            print(f"Элемента {rm_element} нет в исходном списке")

    return count


def task5(lst1: list, lst2: list):
    merged_list = list()

    merged_list.extend(lst1)
    merged_list.extend(lst2)

    return merged_list


def task6(lst: list, power: int):
    result_list = list()

    for i in range(len(lst)):
        result_list.append(lst[i])

        for j in range(power - 1):
            result_list[i] *= lst[i]

    return result_list


task = int(input("Выберите задание: "))

match task:
    case 1:
        nums = [random.randint(-10, 10) for i in range(5)]
        print(f"Исходный список - {nums}")

        print(f"Произведение элементов списка - {task1(nums)}")

    case 2:
        nums = [random.randint(-10, 10) for i in range(5)]
        print(f"Исходный список - {nums}")

        print(f"Минимальный элемент в списке - {task2(nums)}")

    case 3:
        nums = [random.randint(-10, 10) for i in range(5)]
        print(f"Исходный список - {nums}")

        print(f"Количество простых элементов в списке - {task3(nums)}")

    case 4:
        nums = [random.randint(-10, 10) for i in range(5)]
        print(f"Исходный список - {nums}")

        print(f"Список после удаления - {nums}")
        print(f"Удалено элементов - {task4(nums)}")

    case 5:
        task5_nums1 = [random.randint(-10, 10) for i in range(5)]
        task5_nums2 = [random.randint(-10, 10) for j in range(5)]

        print(f"Первый список - {task5_nums1}")
        print(f"Второй список - {task5_nums2}")

        print(f"Объединенный список - {task5(task5_nums1, task5_nums2)}")

    case 6:
        nums = [random.randint(-10, 10) for i in range(5)]
        print(f"Исходный список - {nums}")

        power = int(input("Введите степень: "))

        print(f"Список после преобразований - {task6(nums, power)}")











