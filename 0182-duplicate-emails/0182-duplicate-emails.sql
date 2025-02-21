# Write your MySQL query statement below

SELECT Email FROM
(
    SELECT 
        email, COUNT(email) as NUM
    FROM 
        PERSON
    GROUP BY
        Email
) as statictic
WHERE num > 1
