# Write your MySQL query statement below
select p.product_id,
       p.product_name
from 
    Product p
--  this will be inner join
JOIN 
    Sales s
ON
    p.product_id = s.product_id
GROUP BY
    p.product_id, p.product_name
Having 
    MIN(s.sale_date) >= '2019-01-01'
    AND MAX(s.sale_date) <= '2019-03-31';


