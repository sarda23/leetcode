# Write your MySQL query statement below
-- select salary as SecondHighestSalary
-- from Employee
-- order by salary DESC
-- limit 1 offset 1;

select MAX(salary) as SecondHighestSalary
from Employee
where salary < (select MAX(salary) from Employee);