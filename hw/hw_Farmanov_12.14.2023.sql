-- Задание 1
select AVG(GPA) from Students where StudentID in(
    select StudentID from Enrollments where CourseID = 101
);
go;

-- Задание 2
select MAX(Age) from Students where GPA > 3.5;
go;

-- Задание 3
select count(*) as Count from Courses where Difficulty > 3;

-- Задание 4
select AVG(Grade) as Математика from Enrollments where CourseID = 101;
select AVG(Grade) as Физика from Enrollments where CourseID = 102;
select AVG(Grade) as Лиетратура from Enrollments where CourseID = 103;
select AVG(Grade) as История from Enrollments where CourseID = 104;
select AVG(Grade) as Биология from Enrollments where CourseID = 105;
go;

-- SELECT
--     Courses.CourseID,
--     CourseName,
--     AVG(Grade) AS AverageGrade
-- FROM
--     Courses
-- JOIN
--     Enrollments ON Courses.CourseID = Enrollments.CourseID
-- GROUP BY
--     Courses.CourseID, CourseName;

-- Задание 5
select MAX(Difficulty) as 'Max Difficulty' from Courses;