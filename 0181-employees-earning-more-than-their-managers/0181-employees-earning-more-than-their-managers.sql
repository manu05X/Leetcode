# Write your MySQL query statement below
SELECT 
    a.name AS Employee
FROM 
    Employee AS a JOIN Employee AS b
ON 
    a.ManagerId = b.Id
AND 
    a.Salary > b.Salary
