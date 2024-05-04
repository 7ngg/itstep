/**
 * @param {number} a 
 * @param {number} b
 * @returns {number}
 */
function CompareTwoNumbers(a, b) {
    if (a > b) {
        return 1;
    } else if (a < b) {
        return -1;
    }

    return 0;
}


/**
 * @param {number} a
 * @returns {number}
 */
function GetFactorial(a) {
    if (a === 0) {
        return 1;
    }

    return a * GetFactorial(a - 1);
}


/**
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @returns {number}
 */
function TieThreeNumbers(a, b, c) {
    return a * 100 + b * 10 + c;
}


function GetArea(length = 0, width = 0) {
    if (length === 0) {
        return width * width;
    }

    if (width === 0) {
        return length * length;
    }

    return length * width;
}


/**
 * @param {number} number 
 * @return {boolean}
 */
function IsPerfectNumber(number) {
    let divisors = [];
    for (let i = 1; i < number - 1; i++) {
        if (number % i === 0) {
            divisors.push(i);
        }    
    }

    let sum = 0;
    divisors.forEach(n => {
        sum += n;
    })

    if (sum != number) {
        return false;
    }

    return true;
}


/**
 * @param {number} minBound
 * @param {number} maxBound
 */
function PrintPerfectNumbers(minBound, maxBound) {
    while (minBound <= maxBound) {
        if (IsPerfectNumber(minBound)) {
            console.log('\t', minBound);
        }
        minBound += 1;
    }
}


/**
 * @param {number} hours
 * @param {number} minutes
 * @param {number} seconds
 */
function PrintTime(hours = 0, minutes = 0, seconds = 0) {
    return `${hours === 0 ? '00' : hours}:${minutes === 0 ? '00' : minutes}:${seconds === 0 ? '00' : seconds}`; 
}


/**
 * @param {number} hours
 * @param {number} minutes
 * @param {number} seconds
 * @returns {number}
 */
function CalculateSeconds(hours, minutes, seconds) {
    return hours * 60 * 60 + minutes * 60 + seconds; 
}


/**
 * @param {number} seconds
 * @returns {string}
 */
function CalculateFromSeconds(seconds) {
    let minutes = Math.floor(seconds / 60);
    seconds -= minutes * 60;

    let hours = Math.floor(minutes / 60);
    minutes -= hours * 60;

    return `${hours}:${minutes}:${seconds}`;
}


function CalculateDifference(
    hours_1, minutes_1, seconds_1,
    hours_2, minutes_2, seconds_2,
) {
    let inSeconds_1 = CalculateSeconds(hours_1, minutes_1, seconds_1);
    let inSeconds_2 = CalculateSeconds(hours_2, minutes_2, seconds_2);

    let difference = Math.abs(inSeconds_1 - inSeconds_2);

    return CalculateFromSeconds(difference);
}


console.log(`Task 1: ${CompareTwoNumbers(1, 3)}`);
console.log(`Task 2: ${GetFactorial(5)}`);
console.log(`Task 3: ${TieThreeNumbers(1, 2, 3)}`);
console.log(`Task 4: ${GetArea(6)}`);
console.log(`Task 5: ${IsPerfectNumber(7)}`);

console.log('Task 6: ');
PrintPerfectNumbers(1, 10);

console.log(`Task 7: ${PrintTime(1, 0, 12)}`)
console.log(`Task 8: ${CalculateSeconds(1, 30, 15)}`);
console.log(`Task 9: ${CalculateFromSeconds(5415)}`);
console.log(`Task 10: ${CalculateDifference(1, 30, 15, 1, 30, 0)}`)
