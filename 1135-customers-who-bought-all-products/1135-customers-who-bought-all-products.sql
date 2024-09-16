# Write your MySQL query statement below
-- Select customer_id from the Customer table
SELECT 
    customer_id
FROM
    Customer
-- Group the results by customer_id to aggregate the purchases made by each customer
GROUP BY 
    customer_id
-- Filter the grouped results to include only those customers who bought all distinct products
HAVING
    -- The count of distinct products bought by the customer must be equal to the total count of products in the Product table
    COUNT(DISTINCT product_key) = (
        -- Subquery to get the total count of distinct products from the Product table
        SELECT
            COUNT(product_key)
        FROM
            Product
    );

-- The HAVING clause compares the number of distinct products each customer purchased to the total number of products available, ensuring that only customers who bought every product are included in the result.