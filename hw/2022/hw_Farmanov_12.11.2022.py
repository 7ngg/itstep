task = int(input('Выберите задание: '))

match task:
    case 1:
        x = int(input('Введите x: '))
        y = int(input('Введите y: '))
        result = 1
        degree = 1

        if y > 0:
            while degree <= y:
                result = result * x
                degree += 1
        elif y == 0:
            print(int(1))
        else:
            degree = 0
            while degree > y:
                result = result / x
                degree -= 1
            print(result)

    case 2:
        start = 100
        end = 999
        result = 0

        while start <= end:
            first_digit = start // 100
            second_digit = start // 10 % 10
            third_digit = start % 10

            if first_digit == second_digit or first_digit == third_digit:
                result += 1
                start += 1
            elif second_digit == third_digit:
                result += 1
                start += 1
            else:
                start += 1
        print(result)

    case 3:
        start = 100
        mid = 999
        end = 9999
        result = 0

        while start <= mid:
            first_digit = start // 100
            second_digit = start // 10 % 10
            third_digit = start % 10

            if first_digit != second_digit and first_digit != third_digit:
                if second_digit != third_digit:
                    result += 1
                    start += 1
                else:
                    start += 1
            else:
                start += 1

        mid = 1000

        while mid <= end:
            first_digit = mid // 1000
            second_digit = mid // 100 % 10
            third_digit = mid % 100 // 10
            fourth_digit = mid % 10

            if first_digit != second_digit and first_digit != third_digit:
                if first_digit != fourth_digit and second_digit != third_digit:
                    if second_digit != fourth_digit and third_digit != fourth_digit:
                        result += 1
                        mid += 1
                    else:
                        mid += 1
                else:
                    mid += 1
            else:
                mid += 1

        print(result)

    case 4:
        num0 = int(input('Введите число: '))
        divisor1 = 100
        divisor2 = 10

        while True:
            if (num0 - 3) % 10 == 0 or (num0 - 6) % 10 == 0:
                num0 = (num0 - (num0 % 10)) / 10


            elif num0 % divisor1 // divisor2 == 3 or num0 % divisor1 // divisor2 == 6:
                num0 = num0 - (num0 % divisor1) + 10 * (num0 % divisor2)
                num0 = num0 / 10


            elif num0 % divisor1 == num0:
                break


            else:
                divisor1 = divisor1 * 10
                divisor2 = divisor2 * 10
        print(int(num0))
input()