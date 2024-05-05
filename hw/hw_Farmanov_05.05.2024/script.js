//#region Task1

/*
let Vehicle = {
  Manufacturer: "Vehicle",
  Model: "Model 1",
  ManufactureYear: "1337",
  AvgSpeed: "100",
  print: function () {
    console.log(
      `Manufacturer: ${this.Manufacturer}\nModel: ${this.Model}\nYear: ${this.ManufactureYear}\nAvg Speed: ${this.AvgSpeed}`
      );
    },
    calculateTime: function (distance) {
      let time = distance / this.AvgSpeed;
      time += Math.floor(time / 4);
      
      return time;
    },
  };
  
  Vehicle.print();
  console.log(Vehicle.calculateTime(500));
*/

//#endregion

//#region Task2


function Fraction(numerator, denominator) {
    this.Numerator = numerator;
    this.Denominator = denominator;
}

function getDenominator(frac_1, frac_2) {
    return frac_1.Denominator === frac_2.Denominator
        ? frac_1.Denominator
        : frac_1.Denominator * frac_2.Denominator;
}

function getDivisors(num) {
    let divisors = [];
    for (let i = 1; i < num - 1; i++) {
        if (num % i === 0) {
            divisors.push(i);
        }
    }

    return divisors;
}

Fraction.prototype.reduce = function() {
    if (this.Numerator === 0) {
        this.Denominator = 0;
        return;
    }

    let gcd = (a, b) => {
        while (b !== 0) {
            let temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    };

    let greatestCommonDivisor = gcd(this.Numerator, this.Denominator);
    this.Numerator /= greatestCommonDivisor;
    this.Denominator /= greatestCommonDivisor;
};



Fraction.prototype.add = function(other) {
    let newDenominator = getDenominator(this, other);

    let newNumerator =
        this.Denominator === other.Denominator
            ? this.Numerator + other.Numerator
            : (newDenominator / other.Denominator) * this.Numerator +
            (newDenominator / this.Denominator) * other.Numerator;

    this.Numerator = newNumerator;
    this.Denominator = newDenominator;

    this.reduce();
    return this;
};

Fraction.prototype.subtract = function(other) {
    let newDenominator = getDenominator(this, other);

    let newNumerator =
        this.Denominator === other.Denominator
            ? this.Numerator - other.Numerator
            : (newDenominator / other.Denominator) * this.Numerator -
            (newDenominator / this.Denominator) * other.Numerator;

    this.Numerator = newNumerator;
    this.Denominator = newDenominator;

    this.reduce();
    return this;
};

Fraction.prototype.multiply = function(other) {
    this.Numerator *= other.Numerator;
    this.Denominator *= other.Denominator
    this.reduce();

    return this;
};

Fraction.prototype.divide = function(other) {
    return this.multiply(new Fraction(other.Denominator, other.Numerator));
};

let f1 = new Fraction(1, 2);
let f2 = new Fraction(1, 2);

//console.log(f1.add(f2));
console.log(f1.subtract(f2));
//console.log(f1.multiply(f2));
//console.log(f1.divide(f2));


//#endregion


//#region Task3

/*
let time = {
    hours: 0,
    minutes: 0,
    seconds: 0,
    print: function() {
        console.log(`${this.hours === 0 ? '00' : this.hours}:${this.minutes === 0 ? '00' : this.minutes}:${this.seconds === 0 ? '00' : this.seconds}`);
    },
    editHours: function(amount) {
        this.hours += amount;
        this.prettify();
    },
    editMinutes: function(amount) {
        this.minutes += amount;
        this.prettify();
    },
    editSeconds: function(amount) {
        this.seconds += amount;
        this.prettify();
    },
    prettify: function() {
        this.hours += Math.floor(this.minutes / 60);
        this.minutes = this.minutes % 60;

        this.minutes += Math.floor(this.seconds / 60);
        this.seconds = this.seconds % 60;
    }
}

time.editMinutes(20);
time.editSeconds(70);
time.print();
time.editSeconds(-20);
time.print();
*/

//#endregion
