# Write your MySQL query statement below
SELECT 
    t2.id
FROM
    Weather t1, Weather t2
WHERE
    DATEDIFF(t2.recordDate, t1.recordDate) = 1 
AND 
    t2.temperature > t1.temperature;