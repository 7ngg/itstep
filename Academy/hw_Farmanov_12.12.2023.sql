-- Задание 1
select Name, Financing, Id from Departments;
go;

-- Задание 2
select Name as GroupName, Rating as GroupRating from Groups;
go;

-- Задание 3
select
    Surname,
    Premium / (Salary + Teachers.Premium) * 100 as 'По отношению к зарплате',
    Salary / (Premium + Teachers.Salary) * 100 as 'По отношению к надбавке'
from Teachers
go;

-- Задание 4
select 'The dean of faculty ' + Name + ' is ' + Dean from Faculties;
go;

-- Задание 5
select Surname from Teachers where IsProfessor = 1 and Salary > 1050;
go;

-- Задание 6
select Name from Departments where Financing < 11000 or Financing > 25000;
go;

-- Задание 7
select Name from Faculties where Name <> 'Computer Science';

-- Задание 8
select Surname, Position from Teachers where IsProfessor = 0;
go;

-- Задание 9
select Surname, Position, Salary, Premium from Teachers where IsAssistant = 1 and (Premium > 160 and Premium < 550);
go;

-- Задание 10
select Surname, Salary from Teachers where IsAssistant = 1;
go;

-- Задание 11
select Surname, Position from Teachers where EmploymentDate < '2000-01-01';
go;

-- Задание 12
select Name as 'Name of Department' from Departments where Name < 'Software Development' order by Name;
go;

-- Задание 13
select Surname from Teachers where IsAssistant = 1 and Salary <= 1200;
go;

-- Задание 14
select Name from Groups where Year = 5 and Rating between 2 and 4;
go;

-- Задание 15
select Surname from Teachers where IsAssistant = 1 and (Salary < 550 or Premium > 200);
go;