# Write your MySQL query statement below
-- select c.name as Customers
-- from Customers c
-- left join Orders o ON c.id = o.customerId
-- where o.customerId IS NULL;


-- using NOT IN

select name as Customers
From Customers
where id NOT IN (select customerId from Orders);