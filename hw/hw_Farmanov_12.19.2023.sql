-- Задание 1
SELECT Teachers.Name AS TeacherName, Teachers.Surname AS TeacherSurname, Groups.Name AS GroupName
FROM Teachers
CROSS JOIN Groups;

-- Задание 2
SELECT F1.Name AS FacultyName, D1.Name AS DepartmentName
FROM Faculties F1
JOIN Departments D1 ON F1.Id = D1.FacultyId
WHERE D1.Financing > F1.Financing;

-- Задание 3
SELECT Curators.Surname AS CuratorSurname, Groups.Name AS GroupName
FROM Curators
JOIN GroupsCurators ON Curators.Id = GroupsCurators.CuratorId
JOIN Groups ON GroupsCurators.GroupId = Groups.Id;

-- Задание 4
SELECT DISTINCT Teachers.Name, Teachers.Surname
FROM Teachers
JOIN Lectures ON Teachers.Id = Lectures.TeacherId
JOIN GroupsLectures ON Lectures.Id = GroupsLectures.LectureId
JOIN Groups ON GroupsLectures.GroupId = Groups.Id
WHERE Groups.Name = 'P107';

-- Задание 5
SELECT Teachers.Surname AS TeacherSurname, Faculties.Name AS FacultyName
FROM Teachers
JOIN Lectures ON Teachers.Id = Lectures.TeacherId
JOIN Subjects ON Lectures.SubjectId = Subjects.Id
JOIN Departments ON Subjects.Id = Departments.FacultyId
JOIN Faculties ON Departments.FacultyId = Faculties.Id;

-- Задание 6
SELECT Departments.Name AS DepartmentName, Groups.Name AS GroupName
FROM Departments
JOIN Groups ON Departments.Id = Groups.DepartmentId;

-- Задание 7
SELECT Subjects.Name AS SubjectName
FROM Subjects
JOIN Lectures ON Subjects.Id = Lectures.SubjectId
JOIN Teachers ON Lectures.TeacherId = Teachers.Id
WHERE Teachers.Name = 'Samantha' AND Teachers.Surname = 'Adams';

-- Задание 8
SELECT Departments.Name AS DepartmentName
FROM Departments
JOIN Subjects ON Departments.Id = Subjects.Id
JOIN Lectures ON Subjects.Id = Lectures.SubjectId
WHERE Subjects.Name = 'Database Theory';

-- Задание 9
SELECT Groups.Name AS GroupName
FROM Groups
JOIN Departments ON Groups.DepartmentId = Departments.Id
JOIN Faculties ON Departments.FacultyId = Faculties.Id
WHERE Faculties.Name = 'Computer Science';

-- Задание 10
SELECT Groups.Name AS GroupName, Faculties.Name AS FacultyName
FROM Groups
JOIN Departments ON Groups.DepartmentId = Departments.Id
JOIN Faculties ON Departments.FacultyId = Faculties.Id
WHERE Groups.Year = 5;

-- Задание 11
SELECT Teachers.Name AS TeacherName, Teachers.Surname AS TeacherSurname,
       Lectures.LectureRoom, Subjects.Name AS SubjectName, Groups.Name AS GroupName
FROM Teachers
JOIN Lectures ON Teachers.Id = Lectures.TeacherId
JOIN Subjects ON Lectures.SubjectId = Subjects.Id
JOIN GroupsLectures ON Lectures.Id = GroupsLectures.LectureId
JOIN Groups ON GroupsLectures.GroupId = Groups.Id
WHERE Lectures.LectureRoom = 'B103';
