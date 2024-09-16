# Write your MySQL query statement below
-- Select the manager's employee ID, name, number of direct reports, and average age of the direct reports


-- SELECT 
--     mgr.employee_id,  -- The employee_id of the manager (mgr)
--     mgr.name,         -- The name of the manager (mgr)
--     COUNT(emp.employee_id) AS reports_count,  -- The count of employees (emp) reporting to this manager (mgr)
--     ROUND(AVG(emp.age)) AS average_age        -- The average age of the employees (emp) reporting to this manager, rounded to the nearest whole number
-- FROM 
--     Employees emp    -- The 'emp' alias refers to the employees who are being grouped by their manager
-- JOIN
--     Employees mgr    -- The 'mgr' alias refers to the employees who are managers (i.e., who have direct reports)
-- ON 
--     emp.reports_to = mgr.employee_id   -- The 'reports_to' column indicates that 'emp' reports to the 'mgr' employee_id
-- GROUP BY
--     employee_id      -- Group the results by manager's employee_id (the 'mgr' employee_id) to perform the aggregations for each manager
-- ORDER BY
--     employee_id;     -- Order the results by the manager's employee_id


-- Select the reports_to field (which represents the manager) and alias it as employee_id
SELECT 
  reports_to AS employee_id, -- Get the employee_id of the manager (reports_to represents the manager)
  
  -- Subquery to get the name of the manager
  (
    SELECT name 
    FROM employees e1  -- Reference the same employees table, using alias e1 to refer to it
    WHERE e.reports_to = e1.employee_id  -- Find the manager's name based on the employee_id in the main query
  ) AS name, -- Alias the result of the subquery as name (this gets the name of the manager)

  COUNT(reports_to) AS reports_count, -- Count how many employees report to this manager (reports_to field)
  
  ROUND(AVG(age)) AS average_age -- Calculate the average age of employees reporting to the manager, rounded to the nearest whole number
FROM 
  employees e -- Main query works with the employees table, aliased as e
GROUP BY 
  reports_to -- Group by reports_to (i.e., the manager's employee_id)
HAVING 
  reports_count > 0 -- Filter to only include managers who have more than 0 direct reports
ORDER BY 
  employee_id; -- Sort the result by employee_id (which is the manager's employee_id)


-- Summary of Key Differences:
-- Subquery vs. JOIN: The current query uses a subquery to fetch the manager's name, while the previous query uses a JOIN, which is more efficient.
-- HAVING clause: The current query explicitly filters out managers with reports_count > 0, while the previous query relies on the natural behavior of the grouping and counting.
-- Efficiency: The current query may be slower due to the subquery being executed for every row, while the previous query with a JOIN would typically be faster in retrieving the manager's details.