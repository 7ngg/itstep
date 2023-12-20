create database Academy
go;

use Academy
go;

create table Groups(
    Id int primary key not null identity(1, 1),
    Name nvarchar(10) not null unique check (len(Name) > 0),
    Rating int not null  unique,
    Year int not null check (Year between 1 and 5),
);
go;

create table Departments(
    Id int primary key not null identity (1, 1),
    Financing money not null default 0 check (Financing >= 0),
    Name nvarchar(100) not null unique check (len(Name) > 0),
);
go;

create table Faculties(
    Id int primary key not null identity (1, 1),
    Name nvarchar(100) not null unique check (len(Name) > 0),
);
go;

create table Teachers(
    Id int primary key not null identity (1, 1),
    EmploymentDate date not null check (EmploymentDate >= '1990-01-01'),
    Name nvarchar(max) not null check (len(Name) > 0),
    Premium money not null default 0 check (Premium >= 0),
    Salary money not null check (Salary > 0),
    Surname nvarchar(max) not null check (len(Surname) > 0)
);