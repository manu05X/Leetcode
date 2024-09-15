# Write your MySQL query statement below

-- SELECT * FROM Cinema
-- WHERE
--     description != "boring"
-- AND
--     id = (id%2 = 1);

SELECT * FROM Cinema
WHERE
    description != "boring"
AND
    mod(id,2)=1
ORDER BY
    rating DESC;