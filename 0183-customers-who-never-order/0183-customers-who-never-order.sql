# Write your MySQL query statement below
select c.name as Customers
from Customers c
left join Orders o ON c.id = o.customerId
where o.customerId IS NULL;