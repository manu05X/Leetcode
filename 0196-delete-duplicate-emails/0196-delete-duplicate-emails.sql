# Write your MySQL query statement below
DELETE p1
FROM person p1, person p2
WHERE p1.Email = p2.Email
AND p1.Id > p2.Id;


-- Input: 
-- Person table:
-- +----+------------------+
-- | id | email            |
-- +----+------------------+
-- | 1  | john@example.com |
-- | 2  | bob@example.com  |
-- | 3  | john@example.com |
-- +----+------------------+

-- => From Person p1, Person p2 : it would look like:
-- 1|john@example.com|1|john@example.com
-- 1|john@example.com|2|bob@example.com 
-- 1|john@example.com|3|john@example.com

-- 2|bob@example.com|1|john@example.com
-- 2|bob@example.com|2|bob@example.com
-- 2|bob@example.com|3|john@example.com

-- 3|john@example.com|1|john@example.com
-- 3|john@example.com|2|bob@example.com
-- 3|john@example.com|3|john@example.com

-- => From Person p1, Person p2 where p1.email=p2.email and p1.id>p2.id:
-- It would look like:
-- 3|john@example.com|1|john@example.com

-- Now delete this row's matching row in p1 using p1:  delete p1
