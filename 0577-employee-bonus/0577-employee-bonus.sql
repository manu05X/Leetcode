# Write your MySQL query statement below
-- SELECT 
--     Employee.name, Bonus.bonus
-- FROM 
--     Employee 
-- LEFT OUTER JOIN 
--     Bonus
-- ON 
--     Employee.empId = Bonus.empId
-- WHERE
--     bonus < 1000 OR bonus IS NULL;


Select e.name , b.bonus
from Employee e 
LEFT JOIN Bonus b
On e.empId = b.empId
where b.bonus < 1000 OR b.bonus IS NULL;