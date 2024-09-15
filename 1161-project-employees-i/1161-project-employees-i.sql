# Write your MySQL query statement below
-- SELECT 
--     project_id, 
--     ROUND(AVG(experience_years),2) AS average_years
-- FROM
--     Project p
-- LEFT JOIN
--     Employee e
-- ON
--     p.employee_id = e.employee_id


-- In the first query, without the GROUP BY, the query treats the entire result set as a single group. Therefore, it calculates the overall average of experience_years for all rows in the joined result, regardless of the project_id.

SELECT 
    project_id, 
    ROUND(AVG(experience_years),2) AS average_years
FROM
    Project p
LEFT JOIN
    Employee e
ON
    p.employee_id = e.employee_id
GROUP BY
     project_id;

-- In the second query, the GROUP BY project_id clause groups the results by each project_id. This means that for each distinct project_id, it calculates the average experience_years of all employees associated with that project.