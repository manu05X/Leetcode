# Write your MySQL query statement below

SELECT
    d.name AS 'Department', e.name AS 'Employee', e.Salary
FROM
    Employee e
JOIN
    Department d ON e.DepartmentId = d.Id
WHERE
    (e.DepartmentId , Salary) IN
    (
        SELECT
            DepartmentId, MAX(Salary) 
        FROM
            Employee
        GROUP BY
            departmentId
    );
