# Write your MySQL query statement below

-- SELECT 
--     p.product_id, ROUND(SUM(u.units * p.price)/SUM(u.units),2) as average_price
-- FROM 
--     prices AS p JOIN unitssold AS u
-- WHERE
--     u.product_id = p.product_id AND
--     u.purchase_date <= p.end_date AND
--     u.purchase_date >= p.start_date
-- GROUP BY p.product_id;

SELECT 
    p.product_id, 
    COALESCE(ROUND(SUM(us.units * p.price) / SUM(us.units), 2),0) AS average_price
FROM 
    Prices p
LEFT JOIN 
    UnitsSold us
ON 
    p.product_id = us.product_id 
    AND us.purchase_date BETWEEN p.start_date AND p.end_date
GROUP BY 
    p.product_id
ORDER BY 
    p.product_id;
