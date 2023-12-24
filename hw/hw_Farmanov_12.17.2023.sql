insert into People(Name, Surname, Age) values
    (N'Магомед', N'Фарманов', 23),
    (N'Эльвин', N'Азимов', 22),
    (N'Юсиф', N'Байрамов', 20),
    (N'Бахтияр', N'Мирзоев', 17),
    (N'Ермакова', N'Татьяна', 25),
    (N'Гариба', N'Дадашова', 19),
    (N'Анвер', N'Мамедов', 19),
    (N'Алина', N'Оруджова', 15),
    (N'Вагиф', N'Алиев', 16);

insert into Employee(Salary, Experience) values(4000, 5);

insert into Faculty(Name) values(N'Software Engineering');

insert into Students(PersonId, GPA) values
    (1, 0),
    (3, 11),
    (4, 9),
    (5, 12),
    (6, 11),
    (7, 9),
    (8, 10),
    (9, 12);

insert into Teachers(PersonId, EmployeeId) values (2, 1)

insert into Groups(Name, Course, FacultyId) values (N'FBAS_3_22_11', 3, 1)

insert into GroupData (StudentId, GroupId) values
    (1, 1),
    (2, 1),
    (3, 1),
    (4, 1),
    (5, 1),
    (6, 1),
    (7, 1),
    (8, 1);

insert into StudyPlan(TeacherId, GroupId) values (1, 1);
