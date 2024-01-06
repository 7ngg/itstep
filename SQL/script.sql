create database Vehicles
go;

use Vehicles
go;

create table ManufacturingCountries (
    country_id int primary key identity (1, 1),
    country_name nvarchar(30) not null unique check(len(country_name) > 0),
)

create table FuelTypes (
    fuel_type_id int primary key identity (1, 1),
    fuel_type nvarchar(30) not null unique check(len(fuel_type) > 0),
);

create table BodyTypes (
    body_type_id int primary key identity (1, 1),
    body_type nvarchar(30) not null unique check(len(body_type) > 0),
);

create table Colors (
    color_id  int primary key identity (1, 1),
    color_name nvarchar(30) not null unique check(len(color_name) > 0),
);
go;

create table Cars (
    car_id int primary key identity (1, 1),
    brand nvarchar(30) not null check (len(brand) > 0),
    model nvarchar(30) not null check (len(model) > 0),
    year date not null check (year > '1885-01-01'),
    fuel_type_id int foreign key references FuelTypes(fuel_type_id),
    body_type_id int foreign key references BodyTypes(body_type_id),
    color_type int foreign key references Colors(color_id),
    image_link nvarchar(max)
);
go

create table Users (
    user_id int primary key identity (1, 1),
    username nvarchar(16) not null unique check (len(username) > 2),
    password nvarchar(16) not null check (len(password) > 4),
    email nvarchar(50) not null unique check (email like '%_@__%.__%')
);
go;

create table Sellers (
    seller_id int primary key identity (1, 1),
    user_id int foreign key references Users(user_id),
    company_name nvarchar(30) unique,
    contact_number nvarchar(15) not null unique,
    country_id int foreign key references ManufacturingCountries(country_id),
    rating int not null check (rating between 0 and 5)
);
go;

create table ProductList (
    product_id int primary key identity (1, 1),
    car_id int foreign key references Cars(car_id),
    seller_id int foreign key references Sellers(seller_id),
    price int not null check (price >= 0),
    quantity int not null check (quantity > 0),
);
go;

