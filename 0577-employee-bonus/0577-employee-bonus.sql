# Write your MySQL query statement below
SELECT 
    Employee.name, Bonus.bonus
FROM 
    Employee 
LEFT OUTER JOIN 
    Bonus
ON 
    Employee.empId = Bonus.empId
WHERE
    bonus < 1000 OR bonus IS NULL;