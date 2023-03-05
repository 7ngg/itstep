task = int(input('Выберите задание: '))

match task:
    case 1:
        start = int(input('Введите начало диапазона: '))
        end = int(input('Введите конец диапазона: '))
        even_sum = odd_sum = 0
        even_count = odd_count = 0

        for i in range(start, end + 1):
            if i % 2 == 0:
                even_sum = even_sum + i
                even_count += 1
            else:
                odd_sum = odd_sum + i
                odd_count += 1
        print(f"Cумма четных чисел диапазона равна {even_sum}.\nСреднеарифметическое четных чисел диапазона равно {even_sum / even_count}\n")
        print(f"Cумма нечетных чисел диапазона равна {odd_sum}.\nСреднеарифметическое нечетных чисел диапазона равно {odd_sum / odd_count}")

    case 2:
        length = int(input('Введите длину линии: '))
        sym = input('Введите символ для заполнения: ')

        for i in range(length):
            print(sym)

    case 3:
        for _ in iter(int, 1):
            num0 = int(input('Введите число: '))
            if num0 == 7:
                print('Good bye!')
                break
            elif num0 == 0:
                print('Number is equal to zero.')
            elif num0 > 0:
                print('Number is positive.')
            else:
                print('Number is negative.')

    case 4:
        num0 = int(input('Введите число: '))
        sum_var = 0
        min_var = max_var = num0

        for _ in iter(int, 1):

            if num0 == 7:
                break

            sum_var = sum_var + num0

            if max_var < num0:
                max_var = num0
            elif num0 < min_var:
                min_var = num0

            print(f"\nСумма чисел равна {sum_var}")
            print(f"Максимум чисел равен {max_var}")
            print(f"Минимум чисел равен {min_var}")

            num0 = int(input('Введите число: '))