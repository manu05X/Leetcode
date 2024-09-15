# Write your MySQL query statement below

-- SELECT name ,COUNT(managerId)>= 5 FROM Employee

-- The HAVING clause was added to SQL because the WHERE keyword cannot be used with aggregate functions.

-- The GROUP BY statement is often used with aggregate functions (COUNT(), MAX(), MIN(), SUM(), AVG()) to group the result-set by one or more columns.

-- SELECT 
--     managerId FROM Employee 
-- GROUP BY 
--     managerId
-- HAVING
--     COUNT(managerId) >= 5;

SELECT 
    name
FROM
    Employee As t1
JOIN
    (SELECT managerId
     FROM
        Employee
     GROUP BY 
        managerId
     HAVING 
        COUNT(managerId)>=5) AS t2
ON
    t1.id = t2.managerId;
