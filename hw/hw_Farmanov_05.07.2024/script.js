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

let rooms = [
    { name: "315", placesCount: 20, facultyName: "Math" },
    { name: "1008", placesCount: 40, facultyName: "History" },
    { name: "411", placesCount: 10, facultyName: "CompSci" },
];

function print(rooms) {
    for (let room of rooms) {
        console.log(`Name: ${room.name}`);
        console.log(`Places count: ${room.placesCount}`);
        console.log(`Faculty: ${room.facultyName}`);
        console.log('\n');
    }
}

function getFacultyRooms(roomsList, facultyName) {
    for (let r of roomsList) {
        if (r.facultyName === facultyName) {
            console.log(`${r.name}`);
        }
    }
}

function findRoomsForGroup(roomsList, group) {
    roomsList.forEach(room => {
        if (group.studentsCount <= room.placesCount && room.facultyName === group.facultyName) {
            console.log(`${room.name}`);
        }
    });
}

function sortByPlacesCount(rooms) {
    for (let i = 0; i < rooms.length; i++) {
        let maxIndex = 0;
        for (let j = 0; j < rooms.length - i; j++) {
            if (rooms[maxIndex].placesCount < rooms[j].placesCount) {
                maxIndex = j;
            }
        }
        let tmp = rooms[rooms.length - i - 1];
        rooms[rooms.length - i - 1] = rooms[maxIndex];
        rooms[maxIndex] = tmp;
    }
}

function sortByName(rooms) {
    for (let i = 1; i < rooms.length; i++) {
        let index = i;
        while (index > 0 && rooms[index - 1].name[0].toLowerCase().charCodeAt(0) > rooms[index].name[0].toLowerCase().charCodeAt(0)) {
            let tmp = rooms[index - 1];
            rooms[index - 1] = rooms[index];
            rooms[index] = tmp;
            index -= 1;
        }
    }
}

let group = { name: "FBAS_3_22_11", studentsCount: 13, facultyName: "CompSci" };

//getFacultyRooms(rooms, "CompSci");
//findRoomsForGroup(rooms, group);
print(rooms);
sortByName(rooms)
print(rooms);

//#endregion
