# Write your MySQL query statement below

-- SELECT name ,COUNT(managerId)>= 5 FROM Employee

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
