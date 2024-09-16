# Write your MySQL query statement below
-- SELECT
--     num
-- FROM
--     MyNumbers
-- GROUP BY
--     num
-- HAVING COUNT(num) = 1;

-- Select the maximum value from the set of single numbers
SELECT MAX(num) AS num
FROM
    (
        -- Inner subquery to find numbers that appear exactly once
        SELECT
            num
        FROM
            MyNumbers
        -- Group the numbers to aggregate their occurrences
        GROUP BY num
        -- Filter to keep only those numbers that appear exactly once
        HAVING COUNT(num) = 1
    ) AS t;  -- Alias for the inner subquery



-- Summary:
-- The query first finds all numbers that appear only once in the MyNumbers table using the HAVING COUNT(num) = 1 clause.
-- It then selects the largest of these numbers using the MAX() function.
-- If no such numbers exist, it returns NULL.