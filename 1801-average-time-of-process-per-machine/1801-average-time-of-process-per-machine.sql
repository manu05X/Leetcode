# Write your MySQL query statement below

-- SELECT a.machine_id,
--     ROUND(AVG(b.timestamp - a.timestamp), 3) AS processing_time
-- FROM 
--     Activity a, Activity b
-- WHERE 
--     a.machine_id = b.machine_id
-- AND
--     a.process_id = b.process_id
-- AND
--     a.activity_type = 'start'
-- AND
--     b.activity_type = 'end'
-- Group By machine_id;
    

SELECT a1.machine_id, ROUND(AVG(a2.timestamp-a1.timestamp),3) AS processing_time
FROM Activity a1 JOIN Activity a2 
ON a1.machine_id = a2.machine_id
AND a1.process_id = a2.process_id
AND a1.activity_type='start'
AND a2.activity_type='end'
AND a1.timestamp<a2.timestamp
GROUP BY a1.machine_id;