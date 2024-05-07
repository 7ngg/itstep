//#region Task 1

let purchases = [
  { name: "Product 1", quantity: 5, isPurchased: false },
  { name: "Product 2", quantity: 4, isPurchased: true },
  { name: "Product 3", quantity: 3, isPurchased: false },
  { name: "Product 4", quantity: 2, isPurchased: true },
];

function print(purchases) {
  let ls = [];

  for (let p of purchases) {
    if (p.isPurchased) {
      ls.push(p);
    } else {
      ls.unshift(p);
    }
  }

  console.log(ls);
}

function add(list, purchase) {
  let exists = false;

  for (let p of list) {
    if (p.name === purchase.name) {
      p.quantity += purchase.quantity;
      exists = true;
    }
  }

  if (!exists) {
    list.push(purchase);
  }
}

function purchase(list, name) {
  for (let p of list) {
    if (p.name === name) {
      p.isPurchased = true;
    }
  }
}

// add(purchases, { name: "Product 1", quantity: 2, isPurchased: false });
// add(purchases, { name: "Product 5", quantity: 1, isPurchased: true });
// purchase(purchases, "Product 1");

// print(purchases);

//#endregion

//#region  Task 2

let bill = [
  { name: "Item 1", quantity: 1, pricePerPc: 100 },
  { name: "Item 2", quantity: 12, pricePerPc: 300 },
  { name: "Item 3", quantity: 5, pricePerPc: 500 },
  { name: "Item 4", quantity: 3, pricePerPc: 20 },
];

function print(bill) {
  let overallPrice = getOverallPrice(bill);

  for (let i of bill) {
    console.log(`${i.name}:\t${i.quantity * i.pricePerPc}`);
    console.log(`\t${i.pricePerPc}`);
  }
  console.log(`\nTotal:\t${overallPrice}`);
}

function getOverallPrice(bill) {
  return bill.reduce((acc, p) => acc + p.pricePerPc * p.quantity, 0);
}

function getMostExpensiveItem(bill) {
  bill.sort((a, b) => b.pricePerPc - a.pricePerPc);
  return bill[0];
}

function getAvgPrice(bill) {
  return getOverallPrice(bill) / bill.length;
}

// print(bill);
// console.log(getMostExpensiveItem(bill));
// console.log(getAvgPrice(bill));

//#endregion

//#region Task 3



//#endregion