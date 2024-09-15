# Write your MySQL query statement below
-- 1. We creat the table grouped by a subquery, which count the number of exams each student attended for each subject.

-- SELECT 
--     student_id, subject_name, COUNT(*) AS attended_exams
-- FROM 
--     Examinations
-- GROUP BY
--     student_id, subject_name;

-- 2. To get all the combinations of (student_id, subject_name), we use cross join to combine each row from table Student with each row from table Subject, resulting in every possible combination of student_id and subject_name from both tables.
-- The CROSS JOIN keyword returns all matching records from both tables whether the other table matches or not.

-- SELECT * FROM Students s CROSS JOIN Subjects sub;

SELECT 
    s.student_id, s.student_name, sub.subject_name, COUNT(e.student_id) AS attended_exams
FROM 
    Students s
CROSS JOIN 
    Subjects sub
    LEFT JOIN Examinations e ON s.student_id = e.student_id AND sub.subject_name = e.subject_name
GROUP BY
    s.student_id, s.student_name, sub.subject_name
ORDER BY 
    s.student_id, sub.subject_name;