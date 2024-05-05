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

function reduceFraction(frac) {
  let numeratorDivisors = getDivisors(frac.Numerator);
  let denominatorDivisors = getDivisors(frac.Denominator);

  numeratorDivisors.forEach((n) => {
    if (denominatorDivisors.includes(n)) {
      denominatorDivisors.pop(n);
      numeratorDivisors.pop(n);
    }
  });
}

Fraction.prototype.add = function (other) {
  let newDenominator = getDenominator(this, other);

  let newNumerator =
    this.Denominator === other.Denominator
      ? this.Numerator + other.Numerator
      : (newDenominator / other.Denominator) * this.Numerator +
        (newDenominator / this.Denominator) * other.Numerator;

  return new Fraction(newNumerator, newDenominator);
};

Fraction.prototype.subtract = function (other) {
  let newDenominator = getDenominator(this, other);

  let newNumerator =
    this.Denominator === other.Denominator
      ? this.Numerator - other.Numerator
      : (newDenominator / other.Denominator) * this.Numerator -
        (newDenominator / this.Denominator) * other.Numerator;

  return new Fraction(newNumerator, newDenominator);
};

Fraction.prototype.multiply = function (other) {
  return new Fraction(
    this.Numerator * other.Numerator,
    this.Denominator * other.Denominator
  );
};

Fraction.prototype.divide = function (other) {
  return this.multiply(new Fraction(other.Denominator, other.Numerator));
};

let f1 = new Fraction(1, 2);
let f2 = new Fraction(1, 2);

console.log(f1.add(f2));
console.log(f1.subtract(f2));
console.log(f1.divide(f2));

//#endregion
