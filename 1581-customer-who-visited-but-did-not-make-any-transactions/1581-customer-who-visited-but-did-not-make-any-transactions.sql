# Write your MySQL query statement below

-- select customer_id ,count(*) as count_no_trans
-- from Visits
-- where visit_id NOT IN (
--     select visit_id from Transactions
-- )
-- group by customer_id;

SELECT v.customer_id, COUNT(v.visit_id) AS count_no_trans
FROM Visits v
LEFT JOIN Transactions t
ON v.visit_id = t.visit_id
WHERE t.transaction_id IS NULL  -- Filter out rows with transactions
GROUP BY v.customer_id;          -- Group by customer_id to count no-transaction visits
