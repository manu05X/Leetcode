# Write your MySQL query statement below
SELECT class
FROM (
    SELECT 
        class, COUNT(student) AS NUM
    FROM
        courses
    GROUP BY class) AS temp_table
WHERE
    num >= 5;